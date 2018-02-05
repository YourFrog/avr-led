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
	uint8_t pin;				// Pin na którym znajduje siê dioda
	volatile uint8_t *ddr;		// Rejestr kierunku
	volatile uint8_t *port;		// Rejestr wyjœcia
} YourFrog_LED;

/**
 * 	Inicjalizacja diody :)
 */
YourFrog_LED *led_init(volatile uint8_t *ddr, volatile uint8_t *port, uint8_t pin);

/**
 * 	W³¹czenie diody
 */
void led_on(YourFrog_LED *led);

/**
 * 	Wy³¹czenie diody
 */
void led_off(YourFrog_LED *led);

/**
 * 	Przestawienie diody, W przypadku braku wiedzy w jakim stanie siê znajduje zostanie w³¹czona
 */
void led_toggle(YourFrog_LED *led);

#endif
