#include "led.h"

/**
 * 	Inicjalizacja diody :)
 */
YourFrog_LED *led_init(volatile uint8_t *ddr, volatile uint8_t *port, uint8_t pin)
{
	// Zalokowanie pamiêci na diodê
	YourFrog_LED *led = malloc(sizeof(YourFrog_LED));

	led->pin = pin;
	led->ddr = ddr;
	led->port = port;
	led->status = LED_STATUS_UNKNOWN;

	// Ustawienie rejestru kierunku na wyjœcie dla diody
	*led->ddr |= (1 << led->pin);

	return led;
}

/**
 * 	W³¹czenie diody
 */
void led_on(YourFrog_LED *led)
{
	*led->port &= ~(1 << led->pin);
	led->status = LED_STATUS_ON;
}

/**
 * 	Wy³¹czenie diody
 */
void led_off(YourFrog_LED *led)
{
	*led->port |= (1 << led->pin);
	led->status = LED_STATUS_OFF;
}

/**
 * 	Przestawienie diody, W przypadku braku wiedzy w jakim stanie siê znajduje zostanie w³¹czona
 */
void led_toggle(YourFrog_LED *led)
{
	if( led->status == LED_STATUS_ON ) {
		led_off(led);
		return;
	}

	led_on(led);
}
