
//Address of Clock Control(RCC): AHB1ENR = Base+Offset = 0x40023800 + 0x30 = 0x40023830
//Address for GPIOAMOD = Base+Offset = 0x40020000 + 0x00 = 0x40020000
//Address for GPIOAODR = Base+Offset = 0x40020000 + 0x14 = 0x40020014

#include <stdint.h>
#include <stdio.h>
#include"registers.h"


int main(void)
{
	volatile _Bool button;

	//Initialise the bus:
	GPIO_AHBENR|=0x05;

	//Configure Mode to output:
		//clear it:
	GPIOA_MOD &=  ~(0x00000C00);
		//set it:
	GPIOA_MOD |=  0x00000400;

	//configure output mod for port C
	GPIOC_MOD &=  ~((1UL<<27)|(1UL<<26));//(
	//configure pull-up resistor on port C pin13
	GPIOC_PUPDR &=  ~(1UL<<27);
	GPIOC_PUPDR |=  (1UL<<26);

	while(1)
	{
		button = GPIOC_IDR&(1UL<<13);

		if(button){
			GPIOA_ODR |= 0x0020;
		}
		else{
			GPIOA_ODR &= 0x0000;
		}
	}

/*
    //Works fine
    uint32_t* AHB1ENR = (uint32_t*)0x40023830;
	uint32_t* GPIOAMOD = (uint32_t*)0x40020000;
	uint32_t* GPIOAODR = (uint32_t*)0x40020014;

	//Initialise the bus:
	*AHB1ENR |=0x01;

	//Configure Mode to output:
	//clear it:
	*GPIOAMOD &=  ~(0x00000C00);
	//set it:
	*GPIOAMOD |=  0x00000400;

	while(1)
	{
		*GPIOAODR |= 0x0020;
		//delay();
		*GPIOAODR &= 0x0000;
	}
	*/

//############################################################//

/*
 	//Does not work simply because the variables on L-value are declared and then
 	//assigned the values contained in the addresses dereferenced with R-value.

 	uint32_t AHB1ENR = *((uint32_t*)0x40023830);
	uint32_t GPIOAMOD = *((uint32_t*)0x40020000);
	uint32_t GPIOAODR = *((uint32_t*)0x40020014);

	//Initialise the bus:
	AHB1ENR |=0x01;

	//Configure Mode to output:
	//clear it:
	GPIOAMOD &=  ~(0x00000C00);
	//set it:
	GPIOAMOD |=  0x00000400;

	while(1)
	{
		GPIOAODR |= 0x0020;
		//delay();
		GPIOAODR &= 0x0000;
	}
	*/

}

