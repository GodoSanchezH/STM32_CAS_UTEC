#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "stm32f4xx.h"                  /* Device header*/
#include <stm32f401xe.h>
/*RCC*/
/*GPIO*/

uint32_t i;

void Pin_Output(void);
void Pin_Input(void);
int main(void){

	Pin_Output();
	Pin_Input();
	
	
	for(;;){
	
	/*
		GPIOC->ODR ^=(1<<13);
		for(i=0;i<=10000;i++);*/
	
		if(!((GPIOB->IDR & (1<<5)))){
			GPIOC->ODR |=(1<<13);
	}
		else{
		
					GPIOC->ODR &= ~(1<<13);
		}
}

}
void Pin_Output(void){
	/*Habilitamos el clock*/
	RCC->AHB1ENR |= (1<<1)|(1<<2);
	
	/*Salida*/
	/*definimos el modo del PIN C13*/
	GPIOC->MODER |= (1<<26);
	GPIOC->MODER &= ~(1<<27);
	
	/*dEFINIMOS COMO PUSH PULL*/
	GPIOC->OTYPER &=  ~(1<<13);
	
	/*DEFINIMOS LA VELOCIDAD*/
	GPIOC->OSPEEDR &= ~(1<<27) & ~(1<<26);
	
	/*DESCACTIVO EL PULL UP - PULL DOWN */
	GPIOC->PUPDR  &= ~(1<<27) & ~(1<<26);
	
	
}
void Pin_Input(void){


	/*definimos el modo del PIN PB5*/
	GPIOB->MODER &= ~(1<<11) & ~(1<<10);
	
	
	/*DESCACTIVO EL PULL UP - PULL DOWN */
	GPIOB->PUPDR  &= ~(1<<11);
	GPIOB->PUPDR |= (1<<10);
	
	
}

