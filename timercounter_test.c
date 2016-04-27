#include <avr/io.h>
#include <avr/interrupt.h>

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))
#define CPU_16MHz       0x00
#define CPU_8MHz        0x01
#define CPU_4MHz        0x02
#define CPU_2MHz        0x03
#define CPU_1MHz        0x04
#define CPU_500kHz      0x05
#define CPU_250kHz      0x06
#define CPU_125kHz      0x07
#define CPU_62kHz       0x08


#define true 1
// initialize timer, interrupt and variable
void timer0_init()
{
    // set up timer with prescaler = 64 and CTC mode
    TCCR0A |= (0 << COM0A1)|(1 << COM0A0)|(0 << COM0B1)|(1<<COM0B0)|(1<<WGM01)|(0<<WGM00);
	TCCR0B |= (1 << CS01);
  
    // initialize counter
    TCNT0 = 0;
  
    // initialize compare value
    OCR0A = 39;
}
  
int main(void)
{
	CPU_PRESCALE(CPU_16MHz);

    DDRB = 0xFF;
  
    // initialize timer
    timer0_init();
	sei();
  
    // loop forever
    while(1)
    {
/*		if(TIFR0 & (1 << OCF0A))
			PORTB ^= (1 << 0)|(1 << 1);
		TIFR0 |= (1 << OCF1A);*/
    }
}