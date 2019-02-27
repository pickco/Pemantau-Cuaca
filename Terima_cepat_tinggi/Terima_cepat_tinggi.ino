#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define RxPin 2
#define TxPin 3

SoftwareSerial radio (RxPin, TxPin);
LiquidCrystal_I2C lcd(0x27, 16, 2);

char datachar;
bool terima_data = false;
long timer;
float numerik;
float lintang, bujur, longitude, latitude;
int temperature, humidity, pressure, tinggi;

void setup() {
  Serial.begin(9600);
  radio.begin(1200);
  pinMode(RxPin, INPUT);
  pinMode(TxPin, OUTPUT);
  // initialize the LCD
  lcd.begin();
}

void loop() {
  if (radio.available() > 0) {
    datachar = radio.read();
    terima_data = true;
    timer = millis() + 3000;
    data_masuk();
    lcd.setCursor(3, 0);
    lcd.print("Terhubung");
  }
  else if (!radio.available() && millis() >= timer) {
    terima_data = false;
    Serial.println(" Koneksi Terputus ");
    lcd.setCursor(0, 0);
    lcd.print("Koneksi Terputus");
    delay(100);
    lcd.clear();
  }

  if (terima_data) {
    lcd.setCursor(0, 1);
    lcd.print("-");
    lcd.setCursor(1, 1);
    lcd.print(latitude, 6);

    Serial.print("-"); Serial.print(latitude, 6);
    Serial.print(",");
    Serial.print(longitude, 6);
    Serial.print(",");
    Serial.print(temperature);
    Serial.print(",");
    Serial.print(humidity);
    Serial.print(",");
    Serial.print(pressure);
    Serial.print(",");
    Serial.println(tinggi);

  }
  //  if (terima_data == true && millis() >= timer) {
  //    Serial.println(" Koneksi Terputus ");
  //    longitude = 0.000000;
  //    latitude = 0.000000;
  //    tinggi = 0;
  //    temperature = 0;
  //    humidity = 0;
  //    pressure = 0;
  //    delay(10);
  //  }
}
