#include <iostream>
using namespace std;
#include "7week(header).h"

int main() {
	Circle donut;
	donut.setRadius(1);
	double area = donut.getArea();
	cout << "donut ������ " << area << endl;

	Circle pizza;
	pizza.setRadius(30);
	area = pizza.getArea();
	cout << "pizza ������ " << area << endl;
}