const float batteryVoltagePin = A0; //analog input pin to measure battery voltage

const float batteryNominalVoltage = 3.7; //nominal voltage of the battery

const float batteryFullVoltage = 4.2; //fully charged voltage of the battery

const float batteryEmptyVoltage = 3.0; //empty voltage of the battery

float batteryPercentage = 0; //initialize battery percentage variable

void setup() {

  Serial.begin(9600); //initialize serial communication

}

void loop() {

  float batteryVoltage = analogRead(batteryVoltagePin) * (5.0 / 1023.0); //read the voltage from the voltage divider circuit

  batteryPercentage = ((batteryVoltage - batteryEmptyVoltage) / (batteryFullVoltage - batteryEmptyVoltage)) * 100; //calculate the battery percentage based on the voltage range

  Serial.println(batteryPercentage); //print the battery percentage to the serial monitor

  delay(5000); //wait for 5 seconds before taking the next reading

}

