# General:
This code uses the built-in hardware PWM module of the STM32 microcontroller to generate a PWM signal with a specific duty cycle. The PWM signal is then used to control the MOSFET switch in the buck converter circuit. The feedback loop consists of a TL431 and an op-amp, which together monitor the output voltage of the buck converter and adjust the duty cycle of the PWM signal to maintain a constant output voltage.

The ACS712 sensor is also used in the circuit to limit the output current to a maximum of 25A. The sensor sends an analog voltage signal to the ADC pin of the STM32, which reads the voltage and converts it to a digital value. The STM32 then compares this value to a pre-set threshold, which corresponds to the maximum allowable current. If the current exceeds this threshold, the duty cycle of the PWM signal is reduced to limit the output current.

Overall, this code provides a closed-loop control system that regulates the output voltage of the buck converter and limits the output current to a safe level.
# Used Pins:
PA8: TIM1_CH1 pin, used as the PWM output pin
PA0: ADC1 channel 0 pin, used to read the voltage feedback from the TL431
PA1: ADC1 channel 1 pin, used to read the current feedback from the ACS712
PB0: I2C1_SCL pin, used for communication with the OLED display
PB1: I2C1_SDA pin, used for communication with the OLED display
# Notes:
→ code I provided does not have a while(1) loop. However, the code is meant to be integrated into a larger program that includes the while(1) loop.

The HAL_TIM_PWM_Start function starts the PWM output on the designated pin, and the HAL_ADC_Start_DMA function starts the ADC conversions for reading the TL431 and ACS712 inputs. These functions set up the hardware to perform their designated tasks continuously in the background, without requiring the main program loop to constantly call them.

The HAL_I2C_Mem_Write and HAL_I2C_Mem_Read functions are used to communicate with the OLED display, which can be called whenever needed in the main program loop.

Therefore, while the code snippet I provided does not have a while(1) loop, it is designed to be used within a larger program that does have one, and the necessary functions are set up to run continuously in the background.
