#include <iostream> 
using namespace std;
#include "cal.h"

void Calculator::run() {
	cout << "�� ���� ���� �Է��ϼ���>>";
	int a, b;
	cin >> a >> b; // ���� �� �� �Է�
	Adder adder(a, b); // ������ ����
	cout << adder.process(); // ���� ���
}

Adder::Adder(int a, int b) {
	op1 = a; op2 = b;
}
int Adder::process() {
	return op1 + op2;
}

