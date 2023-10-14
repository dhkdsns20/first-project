#include <iostream> 
using namespace std;

class Calculator { // 계산기 클래스
public:
	void run();
};

class Adder {
	int op1, op2;
public:
	Adder(int a, int b);
	int process();
};

