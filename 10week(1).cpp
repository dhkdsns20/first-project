#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;


//�ǽ� 8-1
class Circle {
private:
	int radius;
public:
	Circle() { this -> radius = 1; }
	Circle(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};
void SwapCircle(Circle &A, Circle & B) {
	Circle tmp;
	tmp = A;			//*�� ��, & �ּ�
	A = B;
	B = tmp;
}// &�� �ּҰ� �ƴ϶� �г���

void SwapCircle(Circle* A, Circle* B) {
Circle tmp;
tmp = *A;			//*�� �� ,& �ּ�
*A = *B;
*B = tmp;
}

void SwapCircle(Circle &A,Circle *B) {
	Circle tmp;
	tmp = A;			//*�� �� & �ּ�
	A = *B;
	*B = tmp;
}

void ex0801() {
	Circle A(10), B(20);

	cout << "A�� ���� =" << A.getArea() << endl;
	cout << "B�� ���� =" << B.getArea() << endl;


	SwapCircle(A, B);
	SwapCircle(&A, &B);
	SwapCircle(A, &B); 

	cout << "A�� ���� =" << A.getArea() << endl;
	cout << "B�� ���� =" << B.getArea() << endl;
}






//�ǽ� 8-2
void readRadius(Circle &donut) {
	int R;
	cout << "[1] ���� ������ �������� �Է��ϼ���>>" << endl;
	cin >> R;
	
	donut.setRadius(R);
}

void readRadius(Circle* donut) {
	int R;
	cout << "[2] ���� ������ �������� �Է��ϼ���>>" << endl;
	cin >> R;

	donut->setRadius(R);
}


void ex0802() {
	Circle donut;
	readRadius(donut);
	cout << "donut�� ���� = " << donut.getArea() << endl;
	readRadius(&donut);
	cout << "donut�� ���� = " << donut.getArea() << endl;
}



//�ǽ�8-3
class Accumulator {
	int value;
public:
	Accumulator(int value); // �Ű����� value�� ��� value�� �ʱ�ȭ�Ѵ�.
	Accumulator& add(int n); // value�� n�� ���� ���� �����Ѵ�.
	int getvalue(); // ������ �� value�� �����Ѵ�.
};

Accumulator::Accumulator(int value) { this->value = value;}
int Accumulator::getvalue() { return value; }
Accumulator& Accumulator::add(int n) {
	value += n;
	return *this; //Accumulator�� ��ü(value)�� ����
}


void ex0803() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7); // acc�� value ����� 28�� �ȴ�.
	cout << acc.getvalue() << endl; // 28 ���
}


 
//�����ǽ� 1��
void ex1() {
	int data[5] = { 1,2,3,4,5 };
	int* ptr;

	ptr = data;

	cout << (*ptr+1) << endl; //ptr[1]�� ���� 2�� ���
}

//�����ǽ� 2��
class Student {
	char name[100];
public:
	Student() { strcpy(this->name,""); }
	Student(char* name){ 
		strcpy(this->name, name); 
	}
	~Student();
	void showName() {
		cout << "�̸���" << name << endl;


	}
	void setName(char* name) {
		strcpy(this->name, name);
	}
};

int main() {
	Student A((char*)/*Ÿ���� ��ȯ*/ "HONG"), B((char*)"CHUNG");
	B = A;
	B.showName();
	B.setName((char*)"CHUNG");
	B.showName();

	
	return 0;
}

//�ǽ�8-4
class Accumulator {
	int value;
public:
	Accumulator(int value); // �Ű����� value�� ��� value�� �ʱ�ȭ�Ѵ�.
	Accumulator add(int n); // value�� n�� ���� ���� �����Ѵ�.
	int get(); // ������ �� value�� �����Ѵ�.
};

void ex0804() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7); // acc�� value ����� 28�� �ȴ�.
	cout << acc.get() << endl; // 28 ���
}


