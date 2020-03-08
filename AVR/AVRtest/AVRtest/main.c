/*
 * AVRtest.c
 *
 * Created: 2020/03/07 13:08:38
 * Author : yohts
 */ 
#define F_CPU 1000000UL	//CPU1MHz
#define SW (1<<PB2)
#include <avr/io.h>
#include <util/delay.h>

void my_delay(unsigned int t){
	while(t--){
		_delay_ms(1);	
	}
}

unsigned char getSW(unsigned char mask){
	return (~PINB) & mask;
}

int main(void){
    /* Replace with your application code */
	DDRD = 0b00000001;	//PortDの入出力決定（0が入力、1が出力）
	//PD0が出力になった
	DDRB = 0b00000000;	//PB0入力
	
	PORTD = 0b00000001;	//0がGND（0V）、1がVcc（5V）
	//PD0がVccになった
	
	PORTB = SW;	//入力のPORT->プルアップ抵抗　1：有効、0：無効
	while (1) {
		
	/*	for (unsigned int t = 100; t < 500; t += 10){
			PORTD = 0b00000000;	//LED消す
			my_delay(t);
			PORTD = 0b00000001;	//LEDつける
			my_delay(t);
		}
	*/
	
		if (getSW(SW)){	//押されると1
			PORTD = 0b00000001;
		}else{
			PORTD = 0b00000000;
		}
	
    }
}

