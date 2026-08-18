#include "lib.c"

int main(void) {
	Circle red_circle = new(10, "Red");
	red_circle.format(&red_circle);
	Circle blue_circle = new(3, "Blue");
	blue_circle.format(&blue_circle);
	return 0;
}
