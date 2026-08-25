#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double PI = 3.14159;

typedef struct Circle Circle;

struct Circle {
	double radius;
	char *color;
	double (*circumference)(Circle *self);
	double (*area) (Circle *self);
	bool (*larger_than) (Circle *self, Circle *other);
	void (*format) (Circle *self);
};

Circle new(double radius, char *color);
void new_from_ptr(Circle *circle_ptr, double radius, char *color);
double circumference(Circle *self);
double area(Circle *self);
bool larger_than(Circle *self, Circle *other);
void format(Circle *self);

Circle new(double radius, char *color) {
	Circle self;
	self.radius = radius;
	self.color = color;
	self.circumference = circumference;
	self.area = area;
	self.larger_than = larger_than;
	self.format = format;
	return self;
}

double circumference(Circle *self) {
	return 2 * PI * self->radius;
}

double area(Circle *self) {
	return PI * pow(self->radius, 2);
}

bool larger_than(Circle *self, Circle *other) {
	return self->radius > other->radius;
}

void format(Circle *self) {
	printf(
		"Circle {\n\tradius: %f,\n\tcolor: %s\n}\n",
		self->radius,
		self->color
	);
	return;
}

void new_from_ptr(Circle *circle_ptr, double radius, char *color) {
	circle_ptr->radius = radius;
	circle_ptr->color = color;
	circle_ptr->area = area;
	circle_ptr->larger_than = larger_than;
	circle_ptr->circumference = circumference;
	circle_ptr->format = format;
	return;
}

