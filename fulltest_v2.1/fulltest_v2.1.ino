#include <TinyGPS++.h>
#include <DHT.h>
#include <Wire.h>
#include <SFE_BMP180.h>

char buff[40]; // variabel penampung untuk mengirim
int lembab, temp, satelit, ee;
float lin, buj, lintang, bujur, tinggi;

float Po = 1011.10;

// Pemanggian fungsi masing - masing sensor
SFE_BMP180 bmp180;
TinyGPSPlus gps;
DHT dht (8, DHT11);

// Inisialisasi for BMP180
double baseline; // baseline pressure
double T, P, alt; // T = Temperature BMP180, P = Pressure BMP180, alt = Altitude

void setup() {
  Serial.begin(9600);         // Serial port to computer
  Serial2.begin(9600);        // Serial2 for gps with baudrate 9600
  Serial3.begin(1200);        // Serial3 for HC12 with baudrate 9600
  dht.begin();
  Serial.println("REBOOT");

  // Initialize the sensor (it is important to get calibration values stored on the device).

  if (bmp180.begin())
    Serial.println("BMP180 init success");
  else
  {
    // Oops, something went wrong, this is usually a connection problem,
    // see the comments at the top of this sketch for the proper connections.

    Serial.println("BMP180 init fail (disconnected?)\n\n");
    while (1); // Pause forever.
  }

  // Get the baseline pressure:

  baseline = getPressure();

  Serial.print("baseline pressure: ");
  Serial.print(baseline);
  Serial.println(" mb");
  Serial.println(" CANSAT V.1.0 ");
  Serial.println(" Source Code v.2.1 "); 
}

void loop() {
  bool success = false;

  lintang = gps.location.lat(), gps.location.isValid();
  bujur = gps.location.lng(), gps.location.isValid();
  satelit = gps.satellites.value(), gps.satellites.isValid() ;
  smartDelay(300);
  //  feedgps();

  char status;
  status = bmp180.startTemperature();
  if (status != 0) {
    delay(1000);

    status = bmp180.getTemperature(T);
    if (status != 0) {
      status = bmp180.startPressure(3);

      if (status != 0) {
        delay(status);
        status = bmp180.getPressure(P, T);

        if (status != 0) {
          alt = bmp180.altitude(P, Po);

          Serial.print(" Temperature : ");
          Serial.print(T);
          Serial.print(" Pressure : ");
          Serial.print(P);
          Serial.print(" hPa // ");
          Serial.print(" Altitude: ");
          Serial.print(alt);
          Serial.println(" Meters");
        }
      }
    }
  }

  temp = dht.readTemperature();
  lembab = dht.readHumidity();

  strcat(buff, "A");
  dtostrf(lintang, 2, 6, &buff[strlen(buff)]);
  strcat(buff, "B");
  dtostrf(bujur, 3, 6, &buff[strlen(buff)]);
  strcat(buff, "C");
  dtostrf(alt, 4, 0, &buff[strlen(buff)]);
  strcat(buff, "D");
  dtostrf(lembab, 2, 0, &buff[strlen(buff)]);
  strcat(buff, "E");
  dtostrf(temp, 2, 0, &buff[strlen(buff)]);
  strcat(buff, "F");
  dtostrf(P, 4, 0, &buff[strlen(buff)]);
  strcat(buff, "G");

  Serial3.print(buff);
  Serial.print(strlen(buff) );
  Serial.print(" | ");
  Serial.print(buff);
  Serial.print(" | ");
  Serial.print(" Satelit ");
  Serial.println(satelit);

  //DEBUG FORMAT DATA
  //  Serial.print(lintang, 6);
  //  Serial.print(",");
  //  Serial.print(bujur, 6);
  //  Serial.print(",");
  //  Serial.print(tinggi);
  //  Serial.print(",");
  //  Serial.print(temp);
  //  Serial.print(",");
  //  Serial.println(lembab);
  //  Serial.print(",");
  //  Serial.println(P, 0);
  //  Serial.println("----------------------");

  buff[0] = '\0';
  Serial3.flush();
//  delay(400);
}

void feedgps() {
  while (Serial2.available()) {
    if (gps.encode(Serial2.read())) {
      if (gps.location.isValid() || gps.altitude.isValid() ||  gps.satellites.isValid()) {
        lintang = gps.location.lat();
        bujur = gps.location.lng();
        //        tinggi = gps.altitude.meters();
        satelit = gps.satellites.value();
      }
      else {
        Serial.println(" GPS not Locked ");
        feedgps();
      }
    }
  }
}

static void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do
  {
    while (Serial2.available())
      gps.encode(Serial2.read());
  } while (millis() - start < ms);
}


static void printFloat(float val, bool valid, int len, int prec)
{
  if (!valid)
  {
    while (len-- > 1)
      Serial.print('*');
    Serial.print(' ');
  }
  else
  {
    Serial.print(val, prec);
    int vi = abs((int)val);
    int flen = prec + (val < 0.0 ? 2 : 1); // . and -
    flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
    for (int i = flen; i < len; ++i)
      Serial.print(' ');
  }
  smartDelay(0);
}

double getPressure() {

}
