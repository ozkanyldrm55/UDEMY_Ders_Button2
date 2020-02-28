#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef LED;
int sayac=0;

void config(void)
{

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);

	//leds

	LED.GPIO_Mode = GPIO_Mode_OUT;
	LED.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	LED.GPIO_OType = GPIO_OType_PP; // PP YADA OD OLMA DURUMUNU SE�ER�Z.
	LED.GPIO_PuPd = GPIO_PuPd_NOPULL; /*PULL-UO,PULL-DOWN ,NOPULL SEC�M� YAP�L�YOR led islemi yaptigimiz icin
	button islemi yapm�yoruz*/
	LED.GPIO_Speed = GPIO_Speed_100MHz;

	GPIO_Init(GPIOD , &LED);//D portuna LED ad�nda bir structur atama islemi yapt�k.yukarda yapt�g�m�z islemleri d portuna aktarm�s olduk

	//button

	LED.GPIO_Mode = GPIO_Mode_IN;//veri girisi yapiyoruz.
	LED.GPIO_OType = GPIO_OType_PP;
	LED.GPIO_PuPd = GPIO_PuPd_DOWN;//buttona bas�ld�ginda 1 basilmadiginda 0 olur.
	LED.GPIO_Speed = GPIO_Speed_100MHz;
	LED.GPIO_Pin = GPIO_Pin_0;

	GPIO_Init(GPIOA , &LED);
}
void Delay(uint32_t time)
{
	while(time --)
	{

	}
}

int main(void)
{
	config();

  while (1)
  {
	  int ButtonDurum = GPIO_ReadInputDataBit(GPIOA , GPIO_Pin_0);

	  if(ButtonDurum)
	  {
		  Delay(1680000);
		  sayac++;

		  switch(sayac)
		  {

		  case 1:
			    GPIO_SetBits(GPIOD,GPIO_Pin_12);
	      break;

		  case 2:
			    GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 );
		  break;

		  case 3:
			    GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14);
		  break;

		  case 4:
			    GPIO_SetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
		  break;

		  case 5:
			    GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
			    sayac = 0;
		  break;
		  }
	  }


  }
}

void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
