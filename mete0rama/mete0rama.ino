/*
 * Mete0rama 
 * 
 * Weather station in a tupper box
 * 
 * NodeMCU v3 (ESP8266)
 * BME280 sensor for temperature, humidity and pressure (using I2C).
 * And an analog raindrop sensor for precipitation.
 * 
 * Using 3.3 V
 * 
 * Raindrop sensor -> A0
 * BME SCL -> D1, SDA -> D2
 * 
 * Find local IP via Serial monitor or your home router.
 * Open the IP address in your browser :)
 * 
 */

#include <ArduinoJson.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <Wire.h>

#define VOLTAGE 3.3
#define SEALEVELPRESSURE_HPA (1013.25)
#define RAINPIN A0
#define _SSID "PelicanTown"
#define _PW "visitstardewvalleyin2018"

Adafruit_BME280 bme; // I2C
ESP8266WebServer server(80);

void setup() {
  Serial.begin(9600);
  while(!Serial);
  
  WiFi.mode(WIFI_OFF);
  delay(500);

  // You can also pass in a Wire library object like &Wire2
  // status = bme.begin(0x76, &Wire2)
  unsigned bmeStatus = bme.begin(0x76); 
  if (!bmeStatus) {
      printBMEStatus();
      while (1) delay(10);
  }

  WiFi.mode(WIFI_STA);
  WiFi.hostname("Mete0rama");
  WiFi.begin(_SSID, _PW);

  Serial.print("Connecting to WiFi");
  int try_counter = 0;
  while (WiFi.status() != WL_CONNECTED && try_counter < 20) {
    delay(200);
    Serial.print(".");
    try_counter++;
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.print("Connected to ");
    Serial.println(_SSID);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());  //IP address assigned to your ESP
    Serial.print("Hostname: ");
    Serial.println(WiFi.hostname());
  } else {
    Serial.println("");
    Serial.println("Could not connect, please check ssid and pw");
  }

  server.on("/", handleRoot);
  server.on("/data", handleData);
  server.begin();
}

void loop() { 
  server.handleClient(); 
  // printDebug();
}

void handleRoot() {
  String webPage = "<html><head></head><body><h1>Mete0rama</h1><p>Up and running on <a href=\"/data\"><code>/data</code></a></p></body></html>";
  server.send(200, "text/html", webPage);
}

void handleData() {
  StaticJsonDocument<500> doc;  
  doc["temperature"] = bme.readTemperature(); // in ^C
  doc["humidity"] = bme.readHumidity(); // in %
  doc["pressure"] = (bme.readPressure() / 100.0F); // in hPa
  doc["altitude"] = bme.readAltitude(SEALEVELPRESSURE_HPA); // in m
  doc["rain"] = analogRead(RAINPIN) * VOLTAGE / 1024; // in V
  String payload;
  serializeJson(doc, payload);
  server.send(200, "application/json", payload);
}

void printBMEStatus() {
  Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
  Serial.print("SensorID was: 0x"); Serial.println(bme.sensorID(),16);
  Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
  Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
  Serial.print("        ID of 0x60 represents a BME 280.\n");
  Serial.print("        ID of 0x61 represents a BME 680.\n");
}

void printDebug() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" ^C");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.print("Rain? ");
  float rain = analogRead(RAINPIN);
  Serial.print(rain);
  if (rain < 200.) {
    Serial.print(" - Yes, Rain!");  
  } else if (rain < 400) {
    Serial.print(" - A drizzel"); 
  } else {
    Serial.print(" - Nope.");  
  }
  Serial.println("");
  Serial.println();
}
