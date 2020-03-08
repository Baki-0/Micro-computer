/*
 * Segmenttest.c
 *
 * Created: 2020/03/07 15:05:53
 * Author : yohts
 */ 
#define F_CPU 1000000UL	//CPU1MHz
#include <avr/io.h>

#define Sa 0b00000001
#define Sb 0b00000010
#define Sc 0b00000100
#define Sd 0b00001000
#define Se 0b00010000
#define Sf 0b00100000
#define Sg 0b01000000
#define Sdp 0b10000000

#define L_DIG (1<<PC0)
#define H_DIG (1<<PC1)

#define SWup (1<<PB1)
#define SWdwn (1<<PB2)

#include <util/delay.h>
#include <avr/interrupt.h>

unsigned char seg = 0;


unsigned char getSW(unsigned char mask){
	unsigned char key = (~PINB) & mask;	//�X�C�b�`���擾
	if(key == 0){
		return 0;	//���͓��Ȃ甲����
	}
	
	while((~PINB) & mask);	//�������܂ő҂�
	_delay_ms(10);	//�`���^�����O�h�~
	return key;
}


void my_delay(unsigned int t){
	while(t--){
		_delay_ms(1);
	}
}

void setnum(unsigned char num){
	if (num >9){
		return;	//10�ȏ�Ȃ狭���I��
	}
	static const unsigned char font[10] = {
		Sa|Sb|Sc|Sd|Se|Sf,	//0
		Sb|Sc,	//1
		Sa|Sb|Sd|Se|Sg,	//2
		Sa|Sb|Sc|Sd|Sg,	//3
		Sb|Sc|Sf|Sg,	//4
		Sa|Sc|Sd|Sf|Sg,	//5
		Sa|Sc|Sd|Se|Sf|Sg,	//6
		Sa|Sb|Sc|Sf,	//7
		Sa|Sb|Sc|Sd|Se|Sf|Sg,	//8 
		Sa|Sb|Sc|Sd|Sf|Sg	//9
	};
	PORTD = ~font[num];
}

ISR(TIMER0_COMPA_vect){
	static unsigned char dig = 0;	//static -> ��񂵂��Ă΂�Ȃ�
	PORTD = 0b11111111;	//�S����
	if (dig == 0){
		PORTC = L_DIG;	//���̌�������
		setnum(seg%10);
		dig = 1;	//�X�V
		}else{
		PORTC = H_DIG;	//��̌�������
		setnum((seg/10)%10);
		dig = 0;	//�X�V
	}
}

int main(void){
    DDRD = 0b11111111;
	DDRC = H_DIG|L_DIG;
	DDRB = 0b00000000;
	PORTB = SWup | SWdwn;
	
	TCCR0A = 0b00000010;	//CTC����
	TCCR0B = 0b00000011;	//�N���b�N64����
	OCR0A = 15;	//1kHz���荞��
	TIMSK0 = 1 << OCIE0A;	//�^�C�}�[0��r��v���荞��
	
	sei();	//CPU���荞�݋���
	
    while (1){
		if (getSW(SWup)){
			if (seg == 99){
				seg = 0;
			}else{
				seg++;
			}
		}else if(getSW(SWdwn)){
			if (seg == 0){
				seg = 99;
			}else{
				seg--;
			}
		}
    }
}

