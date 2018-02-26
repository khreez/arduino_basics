#include <Arduino.h>
#include <DHT.h>

#define DHTPIN    12
#define DHTTYPE   DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  delay(3000);
  float t = dht.readTemperature(), // read temperature in Celsius default scale is false
        h = dht.readHumidity();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.print(F(" ˚C \t"));
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.println(F(" % "));
}
