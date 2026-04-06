#include "stm32f10x.h"

void GPIO_Init(void)
{
    RCC->APB2ENR |= (1 << 2);   // Clock GPIOA

    // PA4 output push-pull 2MHz
    GPIOA->CRL &= ~(0xF << 16);
    GPIOA->CRL |=  (0x2 << 16);
}

void TIM2_Init(void)
{
    RCC->APB1ENR |= (1 << 0);   // Clock TIM2

    TIM2->PSC = 8000 - 1;       // 8MHz / 8000 = 1000 Hz
    TIM2->ARR = 1000 - 1;       // 1000 tick = 1s

    TIM2->DIER |= (1 << 0);     // Enable update interrupt
    TIM2->CR1  |= (1 << 0);     // Enable counter

    NVIC_EnableIRQ(TIM2_IRQn);
}

void TIM2_IRQHandler(void)
{
    if (TIM2->SR & (1 << 0))
    {
        TIM2->SR &= ~(1 << 0);      // Clear UIF

        GPIOA->ODR ^= (1 << 4);     // Toggle LED PA4
    }
}

int main(void)
{
    GPIO_Init();
    TIM2_Init();

    while(1)
    {
    }
}