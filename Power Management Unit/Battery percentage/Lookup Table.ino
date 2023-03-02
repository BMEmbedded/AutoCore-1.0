float batteryVoltage;

int batteryPercentage;

void setup() {

  // initialize analog input pin

  pinMode(A0, INPUT);

}

void loop() {

  // read battery voltage

  batteryVoltage = analogRead(A0) * (5.0 / 1023.0) * 4.0; // assuming 4x voltage divider

  // lookup battery percentage

  if (batteryVoltage >= 12.7) {

    batteryPercentage = 100;

  } else if (batteryVoltage >= 12.5) {

    batteryPercentage = 90;

  } else if (batteryVoltage >= 12.2) {

    batteryPercentage = 80;

  } else if (batteryVoltage >= 12.0) {

    batteryPercentage = 70;

  } else if (batteryVoltage >= 11.8) {

    batteryPercentage = 60;

  } else if (batteryVoltage >= 11.6) {

    batteryPercentage = 50;

  } else if (batteryVoltage >= 11.4) {

    batteryPercentage = 40;

  } else if (batteryVoltage >= 11.1) {

    batteryPercentage = 30;

  } else if (batteryVoltage >= 10.8) {

    batteryPercentage = 20;

  } else if (batteryVoltage >= 10.5) {

    batteryPercentage = 10;

  } else {

    batteryPercentage = 0;

  }

  // print battery percentage

  Serial.print("Battery Percentage: ");

  Serial.print(batteryPercentage);

  Serial.println("%");

  delay(1000); // wait for 1 second before taking the next reading

}

