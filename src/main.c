#include "lib.c"

int main(void) {
	Circle *circle_ptr = malloc(sizeof(Circle));
	if (circle_ptr == NULL) {
		printf("malloc call failed! Null pointer returned");
		return 0;
	}
	new_from_ptr(circle_ptr, 1, "Green");
	circle_ptr->format(circle_ptr);
	circle_ptr->color = "Red";
	circle_ptr->format(circle_ptr);

	return 0;
}
