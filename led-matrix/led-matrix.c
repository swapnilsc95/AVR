/*
 * Jugando con la matrix de leds de 7x5
 * PC[0-4] x nivel alto
 * PD[0-6] y nivel bajo
 */

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define MAX_X 5
#define MAX_Y 7

void put_xy(int x, int y)
{
	PORTC = (1 << x);
	PORTD = ~(1 << y);
}

void rebota()
{
	int x, y, xx, yy;
    
	x = y = -1;
	xx = yy = 1;
    
	do {
		x += xx;
		y += yy;

		put_xy(x,y);
		_delay_ms(50);

		if (x == MAX_X-1)
			xx = -1;
		else if (x == 0)
			xx = 1;
		if (y == MAX_Y-1)
			yy = -1;
		else if (y == 0)
			yy = 2; /* truquito! deberia ser 1 */
	} while (1);
}

void barrer()
{
	int x,y;

	while(1) {
		for (y = 0; y < 7; y++) {
			for (x = 0; x < 5; x++) {
				put_xy(x, y);
				_delay_ms(300);
			}
		}
	}
}

int main(void)
{
	DDRC = 0x1f; /* PC[0-4] salidas x */
	DDRD = 0x7f; /* PD[0-6] salidas y */

	rebota();

	return 0;
}
