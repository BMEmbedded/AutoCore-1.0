#include <Arduino.h>

#include <math.h>

// Define the neural network weights

const float w0 = 0.5;

const float w1 = 0.25;

const float w2 = 0.25;

// Define the neural network bias

const float bias = -0.5;

// Define the input and output pins

const int crank_pin = A0;

const int ignition_pin = 2;

void setup() {

  // Initialize serial communication

  Serial.begin(9600);

  

  // Set the input pin as analog

  pinMode(crank_pin, INPUT);

  

  // Set the output pin as digital

  pinMode(ignition_pin, OUTPUT);

}

void loop() {

  // Read the analog input from the crank sensor

  int crank_value = analogRead(crank_pin);

  

  // Normalize the input value to a range of -1 to 1

  float x = (crank_value - 512) / 512.0;

  

  // Calculate the neural network output

  float y = w0*x + w1*pow(x,2) + w2*pow(x,3) + bias;

  

  // If the output is positive, turn on the ignition

  if (y > 0) {

    digitalWrite(ignition_pin, HIGH);

  } else {

    digitalWrite(ignition_pin, LOW);

  }

  

  // Print the input and output values to the serial monitor

  Serial.print("Input: ");

  Serial.print(x);

  Serial.print(", Output: ");

  Serial.println(y);

  

  // Wait for a short delay before repeating the loop

  delay(10);

}

