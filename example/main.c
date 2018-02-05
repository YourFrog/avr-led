#include "led.h"


int main( )
{
	YourFrog_LED *mainLED = led_init(&DDRB, &PORTB, PINB1);

	while( 1 ) {
		_delay_ms(1000);
		led_toggle(mainLED);
	}
}
