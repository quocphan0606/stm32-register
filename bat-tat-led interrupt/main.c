#include "stm32f1xx.h"
#include <stdio.h>

void EXTI_Config(void)
{
    //  clock GPIOA, GPIOB, AFIO
    RCC->APB2ENR |= (1<<2) | (1<<3) | (1<<0);

    // PA5 output push-pull (LED)
    GPIOA->CRL &= ~(0xF << (5*4));
    GPIOA->CRL |=  (0x1 << (5*4));

    // PA0 input pull-up
    GPIOA->CRL &= ~(0xF << (0*4));
    GPIOA->CRL |=  (0x8 << (0*4));
    GPIOA->ODR |= (1<<0);

    // PA1 input pull-up
    GPIOA->CRL &= ~(0xF << (1*4));
    GPIOA->CRL |=  (0x8 << (1*4));
    GPIOA->ODR |= (1<<1);

    // PB3 input pull-up
    GPIOB->CRL &= ~(0xF << (3*4));
    GPIOB->CRL |=  (0x8 << (3*4));
    GPIOB->ODR |= (1<<3);

    // AFIO mapping
    // PA0 -> EXTI0
    AFIO->EXTICR[0] &= ~(0xF << 0);

    // PA1 -> EXTI1
    AFIO->EXTICR[0] &= ~(0xF << 4);

    // PB3 -> EXTI3
    AFIO->EXTICR[0] &= ~(0xF << 12);
    AFIO->EXTICR[0] |=  (0x1 << 12);

    // C?u hình EXTI: RISING edge
    EXTI->RTSR |= (1<<0) | (1<<1) | (1<<3);
    EXTI->FTSR &= ~((1<<0) | (1<<1) | (1<<3));

    // Cho phép ngat
    EXTI->IMR |= (1<<0) | (1<<1) | (1<<3);

    // Enable NVIC
    NVIC_EnableIRQ(EXTI0_IRQn);
    NVIC_EnableIRQ(EXTI1_IRQn);
    NVIC_EnableIRQ(EXTI3_IRQn);
}
// DELAY MS 
void delay_ms(int ms) 
{ 
	for(int i =0 ; i < ms*8000; i++); 
}

//HAM XU LY NGAT
void EXTI0_IRQHandler(void)
{
	if(EXTI->PR &(1<<0))
	{
		EXTI->PR |= (1<<0);
		GPIOA->ODR |=(1<<5); //LED SANG 
	}
}
void EXTI1_IRQHandler(void)
{
	if(EXTI->PR &(1<<1))
	{
		EXTI->PR |= (1<<1);
		GPIOA->ODR &=~(1<<5); //LED SANG 
	}
}
void EXTI3_IRQHandler(void)
{
	if(EXTI->PR &(1<<3))
	{
		EXTI->PR |= (1<<3);
		GPIOA->ODR |=(1<<5);
		delay_ms(50);//LED SANG 
		GPIOA->ODR &=~(1<<5); //LED SANG 
		delay_ms(50);
	}
}

int main()
{
	EXTI_Config();
	while(1)
 {
 }
}



