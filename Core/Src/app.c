






#include "app.h"
#include <math.h>
// 장치 선언
extern TIM_HandleTypeDef htim1;

// time1의 duty 변경
void setDuty(uint8_t duty) {
	htim1.Instance->CCR1 = (duty)*10;
	htim1.Instance->CCR2 = (duty)*10;
	htim1.Instance->CCR3 = (duty)*10;
}
void app() {
	// 타이머 장치 시작
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
	while(1) {
		static int angleR = 0;
		static int angleG = 120;
		static int angleB = 240;
		angleR ++;
		angleG ++;
		angleB ++;
		angle %= 360;
		uint8_t valueSin = sin(angle * M_PI / 180) * 50 +49;
		setDuty(valueSin);
		HAL_Delay(100);
	}
}
