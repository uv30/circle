#include <stdio.h>
#include <math.h>

const double PI = 3.14159;

typedef struct Circle Circle;

struct Circle {
	double radius;
	char *color;
	double (*circumference)(Circle *self);
	double (*area) (Circle *self);
	void (*format) (Circle *self);
};

Circle new(double radius, char *color);
double circumference(Circle *self);
double area(Circle *self);
void format(Circle *self);

int main(void) {
	Circle red_circle = new(10, "Red");
	red_circle.format(&red_circle);
	Circle blue_circle = new(3, "Blue");
	blue_circle.format(&blue_circle);
}

Circle new(double radius, char *color) {
	Circle self;
	self.radius = radius;
	self.color = color;
	self.circumference = circumference;
	self.area = area;
	self.format = format;
	return self;
}

double circumference(Circle *self) {
	return 2 * PI * self->radius;
}

double area(Circle *self) {
	return PI * pow(self->radius, 2);
}

void format(Circle *self) {
	printf(
		"Circle {\n\tradius: %f,\n\tcolor: %s,\n\tcircumference: %f,\n\tarea: %f,\n}\n",
		self->radius,
		self->color,
		self->circumference(self),
		self->area(self)
	);
	return;
}

