#include "stm32f4xx.h"

#define PWM_TIM				TIM2
#define PWM_TIM_CH			TIM_CHANNEL_1
#define PWM_GPIO			GPIOA
#define PWM_GPIO_PIN		GPIO_PIN_5
#define PWM_GPIO_AF			GPIO_AF1_TIM2

#define VOLTAGE_ADC			ADC1
#define VOLTAGE_ADC_CH		ADC_CHANNEL_0

#define CURRENT_ADC			ADC1
#define CURRENT_ADC_CH		ADC_CHANNEL_3

#define CURRENT_SENSOR_ZERO	2048
#define CURRENT_SENSOR_SENS	(0.185)

#define VOLTAGE_SETPOINT	124		// Corresponds to 12.4V, adjust as needed
#define VOLTAGE_TOLERANCE	1		// Tolerance in percent
#define CURRENT_LIMIT		25000	// Current limit in mA

#define KP					50
#define KI					100
#define KD					0

#define LOOP_DELAY_MS		100

volatile uint32_t current_ma = 0;

void TIM_Config(void)
{
  /* Timer initialization */
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  PWM_TIM->PSC = 71;
  PWM_TIM->ARR = 999;
  PWM_TIM->CCR1 = 0;

  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  HAL_TIM_PWM_ConfigChannel(PWM_TIM, &sConfigOC, PWM_TIM_CH);

  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  HAL_TIMEx_MasterConfigSynchronization(PWM_TIM, &sMasterConfig);

  HAL_TIM_PWM_Start(PWM_TIM, PWM_TIM_CH);
}

void ADC_Config(void)
{
  /* ADC initialization */
  ADC_ChannelConfTypeDef sConfig = {0};

  VOLTAGE_ADC->Instance = ADC1;
  VOLTAGE_ADC->Init.ScanConvMode = DISABLE;
  VOLTAGE_ADC->Init.ContinuousConvMode = ENABLE;
  VOLTAGE_ADC->Init.DiscontinuousConvMode = DISABLE;
  VOLTAGE_ADC->Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  VOLTAGE_ADC->Init.DataAlign = ADC_DATAALIGN_RIGHT;
  VOLTAGE_ADC->Init.NbrOfConversion = 1;
  HAL_ADC_Init(VOLTAGE_ADC);

  sConfig.Channel = VOLTAGE_ADC_CH;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_28CYCLES;
  HAL_ADC_ConfigChannel(VOLTAGE_ADC, &sConfig);

  CURRENT_ADC->Instance = ADC1;
  CURRENT_ADC->Init.ScanConvMode = DISABLE;
  CURRENT_ADC->Init.ContinuousConvMode = ENABLE;
  CURRENT_ADC->Init.DiscontinuousConvMode = DISABLE;
  CURRENT_ADC->Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  CURRENT_ADC->Init.DataAlign = ADC_DATAALIGN_RIGHT;
  CURRENT_ADC->Init.NbrOfConversion = 1;
  HAL_ADC_Init(CURRENT_ADC);

  sConfig.Channel = CURRENT_ADC_CH;
  HAL_ADC_ConfigChannel(CURRENT_ADC, &sConfig);

  HAL_ADC_Start(CURRENT_ADC);
  HAL_ADC_Start(VOLTAGE);
  
  
 //Not Sure if it's Completed 
  
}
