// DS1302 SETUP:
// DS1302 CLK/SCLK --> 5
// DS1302 DAT/IO --> 4
// DS1302 RST/CE --> 2

// SD CARD READER
// MOSI: pin 11
// MISO: pin 12
// SCK: pin 13
// CS: pin 10

// DS1307 SDA --> SDA
// DS1307 SCL --> SCL
// DS1307 VCC --> 5v
// DS1307 GND --> GND

// DHT: DATA --> 9

#include <DHT.h>
#include <SPI.h>
#include <SD.h>

// #include <RtcDS1302.h>
// ThreeWire myWire(4,5,2); // IO, SCLK, CE
// RtcDS1302<ThreeWire> rtc(myWire);

#include <Wire.h>  
#include <RtcDS1307.h>
RtcDS1307<TwoWire> rtc(Wire);

DHT dht(9, DHT11);

bool overwrite = false;

const String fileName = "data.txt";

float last_temp;
void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ;  // wait for serial port to connect. Needed for native USB port only
  }

  dht.begin();
  rtc.Begin();

  rtc.SetDateTime(RtcDateTime(__DATE__, __TIME__));

  Serial.print("Initializing SD card...");

  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1)
      ;
  }
  Serial.println("initialization done.");

  if (overwrite) {
    SD.remove(fileName);
    Serial.println("Overwrite");
  } else {
    Serial.println("Append");
  }
  last_temp = getLastTemp();
}


void sdWrite(String content) {
  File file = SD.open(fileName, O_CREAT | O_WRITE | O_APPEND);
  if (file) {
    Serial.println("Ghi '" + content + "' vao " + fileName);
    file.println(content);
    file.close();
  } else {
    Serial.println("error opening " + fileName);
  }
}

float getLastTemp() {
  File file = SD.open(fileName);
  if (file) {
    String content = "-1";
    while (file.available() && (content = file.readStringUntil('\n'))) {}
    content = content.substring(9, 13);
    file.close();
    return content.toFloat();
  }

  return -1;
}

String dateStr(RtcDateTime dt) {
  char datestring[26];

  snprintf_P(datestring,
             countof(datestring),
             PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
             dt.Day(),
             dt.Month(),
             dt.Year(),
             dt.Hour(),
             dt.Minute(),
             dt.Second());
  return datestring;
}
void loop() {
  float temp = dht.readTemperature();

  RtcDateTime now = rtc.GetDateTime();
  Serial.println(now.Second());
  sdWrite("Nhiet do: " + String(temp) + "°C - Thoi gian : " + dateStr(now));
  delay(1000);

  // if (temp != last_temp) {
  //   RtcDateTime now = rtc.GetDateTime();
  //   sdWrite("Nhiet do: " + String(temp) + "°C - Thoi gian: " + dateStr(now));
  //   delay(500);
  //   last_temp = temp;
  // }
}