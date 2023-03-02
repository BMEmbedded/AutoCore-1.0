#include <Wire.h>

#include <Adafruit_Sensor.h>

#include <Adafruit_BQ34Z100.h>

Adafruit_BQ34Z100 fuelGauge;

void setup() {

  Serial.begin(9600);

  Wire.begin();

  if (!fuelGauge.begin()) {

    Serial.println("Could not find a valid BQ34Z100 fuel gauge, check wiring!");

    while (1) {}

  }

}

void loop() {

  float soc = fuelGauge.soc();

  float voltage = fuelGauge.voltage();

  float current = fuelGauge.current();

  Serial.print("State of charge: ");

  Serial.print(soc);

  Serial.println("%");

  Serial.print("Voltage: ");

  Serial.print(voltage);

  Serial.println("V");

  Serial.print("Current: ");

  Serial.print(current);

  Serial.println("A");

  delay(1000);

}

