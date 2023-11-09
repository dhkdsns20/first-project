#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;


//실습 8-1
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
	tmp = A;			//*은 값, & 주소
	A = B;
	B = tmp;
}// &는 주소가 아니라 닉네임

void SwapCircle(Circle* A, Circle* B) {
Circle tmp;
tmp = *A;			//*은 값 ,& 주소
*A = *B;
*B = tmp;
}

void SwapCircle(Circle &A,Circle *B) {
	Circle tmp;
	tmp = A;			//*은 값 & 주소
	A = *B;
	*B = tmp;
}

void ex0801() {
	Circle A(10), B(20);

	cout << "A의 면적 =" << A.getArea() << endl;
	cout << "B의 면적 =" << B.getArea() << endl;


	SwapCircle(A, B);
	SwapCircle(&A, &B);
	SwapCircle(A, &B); 

	cout << "A의 면적 =" << A.getArea() << endl;
	cout << "B의 면적 =" << B.getArea() << endl;
}






//실습 8-2
void readRadius(Circle &donut) {
	int R;
	cout << "[1] 정수 값으로 반지름을 입력하세요>>" << endl;
	cin >> R;
	
	donut.setRadius(R);
}

void readRadius(Circle* donut) {
	int R;
	cout << "[2] 정수 값으로 반지름을 입력하세요>>" << endl;
	cin >> R;

	donut->setRadius(R);
}


void ex0802() {
	Circle donut;
	readRadius(donut);
	cout << "donut의 면적 = " << donut.getArea() << endl;
	readRadius(&donut);
	cout << "donut의 면적 = " << donut.getArea() << endl;
}



//실습8-3
class Accumulator {
	int value;
public:
	Accumulator(int value); // 매개변수 value로 멤버 value를 초기화한다.
	Accumulator& add(int n); // value에 n을 더해 값을 누적한다.
	int getvalue(); // 누적된 값 value를 리턴한다.
};

Accumulator::Accumulator(int value) { this->value = value;}
int Accumulator::getvalue() { return value; }
Accumulator& Accumulator::add(int n) {
	value += n;
	return *this; //Accumulator의 객체(value)가 리턴
}


void ex0803() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7); // acc의 value 멤버가 28이 된다.
	cout << acc.getvalue() << endl; // 28 출력
}


 
//수업실습 1번
void ex1() {
	int data[5] = { 1,2,3,4,5 };
	int* ptr;

	ptr = data;

	cout << (*ptr+1) << endl; //ptr[1]의 값인 2가 출력
}

//수업실습 2번
class Student {
	char name[100];
public:
	Student() { strcpy(this->name,""); }
	Student(char* name){ 
		strcpy(this->name, name); 
	}
	~Student();
	void showName() {
		cout << "이름이" << name << endl;


	}
	void setName(char* name) {
		strcpy(this->name, name);
	}
};

int main() {
	Student A((char*)/*타입을 변환*/ "HONG"), B((char*)"CHUNG");
	B = A;
	B.showName();
	B.setName((char*)"CHUNG");
	B.showName();

	
	return 0;
}

//실습8-4
class Accumulator {
	int value;
public:
	Accumulator(int value); // 매개변수 value로 멤버 value를 초기화한다.
	Accumulator add(int n); // value에 n을 더해 값을 누적한다.
	int get(); // 누적된 값 value를 리턴한다.
};

void ex0804() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7); // acc의 value 멤버가 28이 된다.
	cout << acc.get() << endl; // 28 출력
}


