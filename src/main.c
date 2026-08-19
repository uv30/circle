#include "lib.c"

int main(void) {
	Circle red_circle = new(10, "Red");
	red_circle.format(&red_circle);
	Circle blue_circle = new(3, "Blue");
	blue_circle.format(&blue_circle);
	printf(
		"Circle %s is bigger than %s: %s\n",
		red_circle.color, blue_circle.color,
		red_circle.larger_than(&red_circle, &blue_circle)? "true" : "false"
	);
	printf(
		"Because Circle %s has %f area square and Circle %s has %f area square\n",
		red_circle.color,
		red_circle.area(&red_circle),
		blue_circle.color,
		blue_circle.area(&blue_circle)
	);
	return 0;
}
