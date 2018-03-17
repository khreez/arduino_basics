#include <Arduino.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

#define WIFI_SSID ""
#define WIFI_PASS ""
#define EVENT_NAME ""
#define MAKER_KEY ""
#define TARGET_URL "http://maker.ifttt.com/trigger/" EVENT_NAME "/with/key/" MAKER_KEY // notice NOT HTTPS

void setup() {
  Serial.begin(115200);
  Serial.println(F("Initializing WIFI"));
  Serial.print(F("Connecting to "));
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(F("."));
  }

  Serial.println("");
  Serial.print(F("Connected to: "));
  Serial.println(WIFI_SSID);
  Serial.print(F("IP: "));
  Serial.println(WiFi.localIP());
}

void loop() {
  delay(10000);

  HTTPClient http;
  http.begin((String)TARGET_URL);
  int responseCode = http.GET();

  Serial.print(F("HTTP code: "));
  Serial.println(responseCode);

  if (responseCode == HTTP_CODE_OK) {
    String payload = http.getString();
    Serial.println(F("HTTP Response: "));
    Serial.println(payload);
  } else {
    Serial.print(F("HTTP error: "));
    Serial.println(http.errorToString(responseCode).c_str());
  }

  http.end();
}
