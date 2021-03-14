/*
 * registers.h
 *
 *  Created on: Mar 14, 2021
 *      Author: hatilima
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_

#include <stdint.h>
#include <stdio.h>

//define the base address for the GPIO block
#define GPIO_BASE 	0x40020000
#define RCC_BASE 	0x40023800

//define the port offsets from GPIO_BASE
#define GPIOA_OFFSET 0x000
#define GPIOB_OFFSET 0x400
#define GPIOC_OFFSET 0x800
#define GPIOD_OFFSET 0xC00

//define the register offsets within a port
#define GPIOx_AHBENR_OFFSET 	0x30
#define GPIOx_MOD_OFFSET 		0x00
#define GPIOx_ODR_OFFSET 		0x14
#define GPIOx_PUPDR_OFFSET 		0x0C
#define GPIOx_IDR_OFFSET 		0x10

//and now define the base for several ports using their offsets
#define GPIOA_BASE (GPIO_BASE+GPIOA_OFFSET)
#define GPIOB_BASE (GPIO_BASE+GPIOB_OFFSET)
#define GPIOC_BASE (GPIO_BASE+GPIOC_OFFSET)
#define GPIOD_BASE (GPIO_BASE+GPIOD_OFFSET)

//and now define clock register
#define GPIO_AHBENR 	*((volatile uint32_t*)(RCC_BASE+GPIOx_AHBENR_OFFSET))

//and now define PORTA registers
#define GPIOA_MOD 		*((volatile uint32_t*)(GPIO_BASE+GPIOA_OFFSET+GPIOx_MOD_OFFSET))
#define GPIOA_ODR 		*((volatile uint32_t*)(GPIO_BASE+GPIOA_OFFSET+GPIOx_ODR_OFFSET))
#define GPIOA_PUPDR 	*((volatile uint32_t*)(GPIO_BASE+GPIOA_OFFSET+GPIOx_PUPDR_OFFSET))
#define GPIOA_IDR 		*((volatile uint32_t*)(GPIO_BASE+GPIOA_OFFSET+GPIOx_IDR_OFFSET))

//and now define for PORTB registers


//and now define for PORTC registers
#define GPIOC_MOD 		*((volatile uint32_t*)(GPIO_BASE+GPIOC_OFFSET+GPIOx_MOD_OFFSET))
#define GPIOC_ODR 		*((volatile uint32_t*)(GPIO_BASE+GPIOC_OFFSET+GPIOx_ODR_OFFSET))
#define GPIOC_PUPDR 	*((volatile uint32_t*)(GPIO_BASE+GPIOC_OFFSET+GPIOx_PUPDR_OFFSET))
#define GPIOC_IDR 		*((volatile uint32_t*)(GPIO_BASE+GPIOC_OFFSET+GPIOx_IDR_OFFSET))


//and now define for PORTD registers

#endif /* REGISTERS_H_ */
