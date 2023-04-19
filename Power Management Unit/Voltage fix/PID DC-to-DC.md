To fix the alternator 3 phase AC voltage at 12.6V DC in a car, we can use a DC-DC buck-boost converter with feedback control.

Here are the basic steps to implement this method:

1-Install a 3-phase rectifier to convert the 3-phase AC voltage from the alternator to DC voltage.

2-Connect the output of the rectifier to the input of the DC-DC buck-boost converter.

3-Set the reference voltage of the DC-DC converter to 12.6V.

4-Use a feedback loop to adjust the duty cycle of the DC-DC converter and maintain the output voltage at 12.6V, regardless of the input voltage from the alternator.

5-The feedback loop should use a voltage sensor to measure the output voltage of the DC-DC converter, and compare it to the reference voltage. If the output voltage is too high, the duty cycle should be decreased, and if it is too low, the duty cycle should be increased.

6-Use a microcontroller or a dedicated controller chip to implement the feedback loop and control the duty cycle of the DC-DC converter.

7-The system should also include protection features to prevent overvoltage and overcurrent conditions, which can damage the battery and other components in the car.

8-Test the system under different operating conditions to ensure stable operation and accurate voltage regulation