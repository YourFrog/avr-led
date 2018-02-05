#ifndef LED_H_

#define LED_H_

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define LED_STATUS_UNKNOWN 0
#define LED_STATUS_ON 1
#define LED_STATUS_OFF 2


/**
 * 	Struktura opisujaca led'a
 */
typedef struct {
	uint8_t status;				// Aktualny stan diody
	uint8_t pin;				// Pin na którym znajduje się dioda
	volatile uint8_t *ddr;		// Rejestr kierunku
	volatile uint8_t *port;		// Rejestr wyjścia
} YourFrog_LED;

/**
 * 	Inicjalizacja diody :)
 */
YourFrog_LED *led_init(volatile uint8_t *ddr, volatile uint8_t *port, uint8_t pin);

/**
 * 	Włączenie diody
 */
void led_on(YourFrog_LED *led);

/**
 * 	Wyłączenie diody
 */
void led_off(YourFrog_LED *led);

/**
 * 	Przestawienie diody, W przypadku braku wiedzy w jakim stanie się znajduje zostanie włączona
 */
void led_toggle(YourFrog_LED *led);

#endif
