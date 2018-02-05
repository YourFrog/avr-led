#include "led.h"

/**
 * 	Inicjalizacja diody :)
 */
YourFrog_LED *led_init(volatile uint8_t *ddr, volatile uint8_t *port, uint8_t pin)
{
	// Zalokowanie pami�ci na diod�
	YourFrog_LED *led = malloc(sizeof(YourFrog_LED));

	led->pin = pin;
	led->ddr = ddr;
	led->port = port;
	led->status = LED_STATUS_UNKNOWN;

	// Ustawienie rejestru kierunku na wyj�cie dla diody
	*led->ddr |= (1 << led->pin);

	return led;
}

/**
 * 	W��czenie diody
 */
void led_on(YourFrog_LED *led)
{
	*led->port &= ~(1 << led->pin);
	led->status = LED_STATUS_ON;
}

/**
 * 	Wy��czenie diody
 */
void led_off(YourFrog_LED *led)
{
	*led->port |= (1 << led->pin);
	led->status = LED_STATUS_OFF;
}

/**
 * 	Przestawienie diody, W przypadku braku wiedzy w jakim stanie si� znajduje zostanie w��czona
 */
void led_toggle(YourFrog_LED *led)
{
	if( led->status == LED_STATUS_ON ) {
		led_off(led);
		return;
	}

	led_on(led);
}
