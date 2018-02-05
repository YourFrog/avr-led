#include "led.h"

YourFrog_LED *led_init(volatile uint8_t *ddr, volatile uint8_t *port, uint8_t pin)
{
	// Zalokowanie pamięci na diodę
	YourFrog_LED *led = malloc(sizeof(YourFrog_LED));

	led->pin = pin;
	led->ddr = ddr;
	led->port = port;
	led->status = LED_STATUS_UNKNOWN;

	// Ustawienie rejestru kierunku na wyjście dla diody
	*led->ddr |= (1 << led->pin);

	return led;
}

void led_on(YourFrog_LED *led)
{
	*led->port &= ~(1 << led->pin);
	led->status = LED_STATUS_ON;
}

void led_off(YourFrog_LED *led)
{
	*led->port |= (1 << led->pin);
	led->status = LED_STATUS_OFF;
}

void led_toggle(YourFrog_LED *led)
{
	if( led->status == LED_STATUS_ON ) {
		led_off(led);
		return;
	}

	led_on(led);
}
