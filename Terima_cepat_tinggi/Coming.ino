void data_masuk() {
  if (datachar == 'A')
  {
    while (datachar != 'B')
    {
      if (isdigit(datachar))
      {
        numerik = numerik * 10 + (datachar - '0');
      }
      datachar = radio.read();
      //      Serial.println(datachar);
    }
    lintang = numerik;
    latitude = lintang / 1000000;
    //    Serial.println(numerik);
    numerik = 0;
  }

  if (datachar == 'B')
  {
    while (datachar != 'C')
    {
      if (isdigit(datachar))
      {
        numerik = numerik * 10 + (datachar - '0');
      }
      datachar = radio.read();
    }
    bujur = numerik;
    longitude = bujur / 1000000;
    numerik = 0;
  }

  if (datachar == 'C')
  {
    while (datachar != 'D')
    {
      if (isdigit(datachar))
      {
        numerik = numerik * 10 + (datachar - '0');
      }
      datachar = radio.read();
    }
    tinggi = numerik;
    numerik = 0;
  }

  if (datachar == 'D')
  {
    while (datachar != 'E')
    {
      if (isdigit(datachar))
      {
        numerik = numerik * 10 + (datachar - '0');
      }
      datachar = radio.read();
    }
    humidity = numerik;
    numerik = 0;
  }

  if (datachar == 'E')
  {
    while (datachar != 'F')
    {
      if (isdigit(datachar))
      {
        numerik = numerik * 10 + (datachar - '0');
      }
      datachar = radio.read();
    }
    temperature = numerik;
    numerik = 0;
  }

  if (datachar == 'F')
  {
    while (datachar != 'G')
    {
      if (isdigit(datachar))
      {
        numerik = numerik * 10 + (datachar - '0');
      }
      datachar = radio.read();
    }
    pressure = numerik;
    numerik = 0;
  }
}
