//controling a wipermotor with 3 speeds:
// Define the pins for motor control
int in1 = 7;  // input pin 1 for motor A
int in2 = 8;  // input pin 2 for motor A
int enA = 9;  // enable pin for motor A

void setup() {
  // Set the motor control pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  // Read the analog input from a potentiometer to select motor speed
  int speed = analogRead(A0);  // convert 10-bit ADC value (0-1023) to speed selection (0-2)

  // Set the motor speed based on the selected speed
   if (speed <5 ) {  // if speed selection is less than 5
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA,0);  // set motor speed to 0 of maximum
  } else if (speed < 341) {  // if speed selection is less than 341 (approx. 1/3 of 1023)
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 100);  // set motor speed to 1/3 of maximum
  } else if (speed < 682) {  // if speed selection is less than 682 (approx. 2/3 of 1023)
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 200);  // set motor speed to 2/3 of maximum
  } else {  // if speed selection is greater than or equal to 682
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 255);  // set motor speed to maximum
  }
  }
