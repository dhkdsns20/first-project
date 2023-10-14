#include <iostream>
using namespace std;

#include "7week(header).h"

void Circle::setRadius(int r) {
	radius = r;
}
int getRadius(int radius) {
	return radius;
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}