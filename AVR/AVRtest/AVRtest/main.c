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
	DDRD = 0b00000001;	//PortD�̓��o�͌���i0�����́A1���o�́j
	//PD0���o�͂ɂȂ���
	DDRB = 0b00000000;	//PB0����
	
	PORTD = 0b00000001;	//0��GND�i0V�j�A1��Vcc�i5V�j
	//PD0��Vcc�ɂȂ���
	
	PORTB = SW;	//���͂�PORT->�v���A�b�v��R�@1�F�L���A0�F����
	while (1) {
		
	/*	for (unsigned int t = 100; t < 500; t += 10){
			PORTD = 0b00000000;	//LED����
			my_delay(t);
			PORTD = 0b00000001;	//LED����
			my_delay(t);
		}
	*/
	
		if (getSW(SW)){	//��������1
			PORTD = 0b00000001;
		}else{
			PORTD = 0b00000000;
		}
	
    }
}

