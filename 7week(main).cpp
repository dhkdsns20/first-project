#include <iostream>
using namespace std;
#include "7week(header).h"

int main() {
	Circle donut;
	donut.setRadius(1);
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;

	Circle pizza;
	pizza.setRadius(30);
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;
}