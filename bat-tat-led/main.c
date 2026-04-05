#include "stm32f1xx.h"
#include <stdio.h>
void delay_ms(int ms)
	{
		for(int i =0; i<ms*8000;i++);
	}
int main(void)
	{  
		//bat clock GPIOA
		RCC ->APB2ENR |= (1<<2);
		// PA5 = OUTPUT PUSH PULL 2MHZ  0010
		GPIOA ->CRL &= ~(0x7 <<(4*5));
		GPIOA ->CRL |= (0x2 <<(4*5));
		while(1)
		{
        GPIOA->BSRR = (1 << 5);  // LED ON
        delay_ms(5);

        GPIOA->BRR  = (1 << 5);  // LED OFF
        delay_ms(5);

		}
		
		
	}
		