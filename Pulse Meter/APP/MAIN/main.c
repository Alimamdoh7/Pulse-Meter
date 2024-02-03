/*
 * main.c
 *
 * Created: 1/22/2023 9:45:35 PM
 * Author : AliMamdoh
 */ 



#include "PulseMeter_Core.h"


int main(void)
{
   App_Init();
   PWM0_Generate(85);
      
   while (1)
   {
	   PulseMeterCaptureWave (); 
   }
   
}

