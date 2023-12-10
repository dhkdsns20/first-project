#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

//8장//

//실습 8-1
class Circle_81 {
private:
	int radius;
public:
	Circle_81() { this->radius = 1; }
	Circle_81(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

void SwapCircle(Circle_81& A, Circle_81& B) {
	Circle_81 tmp;
	tmp = A;
	A = B;
	B = tmp;
}

void SwapCircle(Circle_81* A, Circle_81* B) {
	Circle_81 tmp;
	tmp = *A;
	*A = *B;
	*B = tmp;
}

void SwapCircle(Circle_81& A, Circle_81* B) {
	Circle_81 tmp;
	tmp = A;
	A = *B;
	*B = tmp;
}

void ex0801() {
	Circle_81 A(10), B(20);
	cout << A.getArea() << endl;
	cout << B.getArea() << endl;

	SwapCircle(A, B);
	SwapCircle(&A, &B);
	SwapCircle(A, &B);
	cout << A.getArea() << endl;
	cout << B.getArea() << endl;
}

class Circle_82 {
	int radius;
public:
	Circle_82() { radius = 1; }
	Circle_82(int radius) { this->radius = radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
};

void readRadius(Circle_82& donut) {
	int num;
	cout << "정수 값으로 반지름을 입력하세요>>";
	cin >> num;
	donut.setRadius(num); //&donut인 경우에는 donut.
}

void readRadius(Circle_82* donut) {
	int num;
	cout << "정수 값으로 반지름을 입력하세요>>";
	cin >> num;
	donut->setRadius(num); //*donut이 포인터 이므로 ->.
}
void ex0802() {
	Circle_82 donut;
	readRadius(donut);
	cout << "donut의 면적 = " << donut.getArea() << endl;
	readRadius(&donut); //* donut
	cout << "donut의 면적 = " << donut.getArea() << endl;
}


class Accumulator_83 {
	int value;
public:
	Accumulator_83(int value) {  // 매개변수 value로 멤버 value를 초기화한다.
		this->value = value;
	}
	Accumulator_83& add(int n){  // value에 n을 더해 값을 누적한다.
		this->value += n;
		return *this;
	}
	int get() { // 누적된 값 value를 리턴한다.
		return value;
	}
};

void ex0803() {
	Accumulator_83 acc(10);
	acc.add(5).add(6).add(7); // acc의 value 멤버가 28이 된다.
	cout << acc.get() << endl; // 28 출력
}

class Book_0804 {
	char* title; // 제목 문자열
	int price; // 가격
public:
	Book_0804(const char* title, int price) {		
		this->title = new char[strlen(title) + 1];//메모리할당
		strcpy(this->title, title);
		this->price = price;
	}
	Book_0804(Book_0804& other) {
		this->title = new char[strlen(other.title) + 1];//메모리할당
		strcpy(this->title, other.title);
		this->price = other.price;
	}
	~Book_0804() {
		delete[] title;
	}
	void set(const char* title, int price){
		delete[] this->title;
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
		this->price = price;
	}
	void show() { cout << title << ' ' << price << "원" << endl; }
};

void ex0804() {
	Book_0804 cpp("명품C++", 10000);
	Book_0804 java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
}

//실습 9-0
class Complex {
	float re, im;
public:
	Complex() { re = im = 0; }
	Complex(float im, float re) { this->re = re; this->im = im; }
	Complex operator+(Complex in) {
		Complex tmp;
		tmp.re = this->re + in.re;
		tmp.im = this->im + in.im;
		return tmp;
	}
	Complex operator-(Complex in) {
		Complex tmp;
		tmp.re = this->re - in.re;
		tmp.im = this->im - in.im;
		return tmp;
	}
	void show(){
		cout.precision(5);
		if (im >= 0)
			cout << re << " + j" << im << endl;
		else
			cout << re << " - j" << -im << endl;
	}
};

void ex0900() {
	Complex X(2, 3), Y(3, 4), Z;
	Z = X + Y;
	Z.show();
	Z = X - Y;
	Z.show();
}

//실습 9-1&9-2


class Book {
	string title;
	int price;
	int pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() {
		return title;
	}
	void operator +=(int up);
	void operator -=(int up);
	bool operator == (int price) {
		if (this->price == price)
			return true;
		else
			return false;
	}
	bool operator == (string title) {
		if (this->title == title )
			return true;
		else
			return false;
	}
	bool operator !() {
		if (this->price == 0)
			return true;
		else
			return false;
	}
	friend bool operator == (Book a,Book b);
};

void Book::operator +=(int up) {
	this->price += up;
}
void Book::operator -=(int up) {
	this->price -= up;
}
bool operator == (Book a, Book b) {
	if (a.title == b.title && b.pages == b.pages)
		return true;
	else
		return false;
	
}

void ex090102() {
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500; // 책 a의 가격 500원 증가
	b -= 500; // 책 b의 가격 500원 감소
	a.show();
	b.show();
}

//실습9-3&9-4
void ex090304() {
	Book a("명품 C++", 30000, 500), b("명품 C++", 30000, 500);
	// price 비교
	if (a == 30000) cout << "정가 30000원" << endl;
	// 책 title 비교
	if (a == "명품 C++") cout << "명품 C++ 입니다." << endl;
	// title, price, pages 모두 비교
	if (a == b) cout << "두 책이 같은 책입니다." << endl;
}

//실습 9-5
void ex0905() {
	Book book("벼룩시장", 0, 50); // 가격은 0
	if (!book) cout << "공짜다" << endl;
}

class Base {
	int a;
protected:
	void setA(int a) { this->a = a; }
public:
	void showA() { cout << a; }
};
class Derived : private Base {
	int b;
protected:
	void setB(int b) { this->b = b; }
public:
	void showB() { cout << b; }
};

void ex01() {
	Derived x;
	x.showB(); // ⑥
}

//실습10-1
class Circle {
private:
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
	void setRadius(int r) { this->radius = r; }
	int getRadius() { return radius; }
};

class NamedCircle : public Circle {
	int x;
	string name;
public:
	NamedCircle();
	NamedCircle(int x, string name) {
		setRadius(x);
		this->name = name;
	}
	void show() {
		cout << getRadius();
	}
};

void ex1001() {
	NamedCircle waffle(3, "waffle"); // 반지름이 3이고 이름이 waffle인 원
	waffle.show();
}

//실습 10-2
class NamedCircle_2 : public Circle {   //Circle의 자식클래스 NamedCircle
	string name;
public:
	NamedCircle_2() {
		this->setRadius(0); //public이므로 접근가능
		//this->radius = 0; (X)
		this->name = "";
	}
	NamedCircle_2(int r, string name) {
		setRadius(r);
		this->name = name;
	}
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}

};

void ex1002() {
	NamedCircle_2 pizza[5];


	cout << "5개의 정수 반지름과 원의 이름을 입력하세요." << endl;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ">>";
		//cin >> pizza[i].radius >> pizza[i].name;
		int r;
		string name;
		cin >> r >> name;
		pizza[i].setRadius(r);
		pizza[i].setName(name);
	}

	int saved_index = 0;
	int r_max = pizza[0].getRadius();

	for (int i = 0; i < 5; i++) {
		if (r_max < pizza[i].getRadius()) {
			saved_index = i;
			r_max = pizza[saved_index].getRadius();
		}
	}

	cout << "가장 면적이 큰 피자는 " << pizza[saved_index].getName() << "입니다." << endl;
}

class BaseArray {
private:
	int capacity; // 동적 할당된 메모리 용량
	int* mem; // 정수 배열을 만들기 위한 메모리 포인터
public:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray() { delete[] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) { return mem[index]; }
	int getCapacity() { return capacity; }
};

//다시 코드 확인
class MyQueue : public BaseArray {
	int size;
	int* mem;
public:
	MyQueue(int capacity) : BaseArray(capacity) { size = 0; };

	void enqueue(int input) {
		put(size, input);
		size++;
	}
	int capacity() { return getCapacity(); } //capacity를 리턴하고 싶으나 private이므로 함수를 가져온다.
	int length() { return size; }

	int dequeue() {
		int tmp = get(0);
		size--;
		//구조에 대한 이해가 필요한 부분
		for (int index = 0; index < size; index++) {
			//mem[index] = mem[index + 1]; size--;
			put(index, get(index + 1));
		}
		return tmp;
	}
};

void ex1003() {
	MyQueue mQ(100);
	int n;
	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n); // 큐에 삽입
	}
	cout << "큐의 용량 : " << mQ.capacity() << ", 큐의 크기 : " << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
	}
	cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
}

//실습 11-1

class Shape {
	string name;
public:
	virtual float getArea() { return 0.0; }
	void setName(string name) { this->name = name; }
	string getName() { return name; }
	
};

class Oval :public Shape {
	float a, b;
public:
	Oval(string name, float a, float b) {
		this->a = a;
		this->b = b;
		setName(name);
		getName();
	}virtual float getArea(){ return 3.14 * a * b; }
};
class Rect :public Shape {
	float a, b;
public:
	Rect(string name, float a, float b) {
		this->a = a;
		this->b = b;
		setName(name);
		getName();
	}virtual float getArea() { return a * b; }
};
class Triangular :public Shape {
	float a, b;
public:
	Triangular(string name, float a, float b) {
		this->a = a;
		this->b = b;
		setName(name);
		getName();
	}virtual float getArea() { return 0.5 * a * b; }
};
void ex1101() {
	Shape* p[3];
	p[0] = new Oval("빈대떡", 10, 20); // upcasting
	p[1] = new Rect("찰떡", 30, 40); // upcasting 
	p[2] = new Triangular("토스트", 30, 40); // upcasting
	for (int i = 0; i < 3; i++)
		cout << p[i]->getName() << " 넓이는 " << p[i]->getArea() << endl;
	for (int i = 0; i < 3; i++) delete p[i];
}

class Calculator {
public:
	virtual int add(int a, int b) = 0; // 두 정수의 합 리턴
	virtual int subtract(int a, int b) = 0; // 두 정수의 차 리턴
	virtual double average(int a[], int size) = 0; // 배열 a의 평균 리턴. size는 배열의 크기
};

class GoodCalc : public Calculator {
public:
	virtual int add(int a, int b) { return a + b; }
	virtual int subtract(int a, int b) { return a - b; }
	virtual double average(int a[], int size) {
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += a[i];
		}return (double)sum / size; //double로 return됨
	}
};

void ex1102() {
	int a[] = { 1,2,3,4,5 };
	Calculator* p = new GoodCalc();
	cout << p->add(2, 3) << endl;
	cout << p->subtract(2, 3) << endl;
	cout << p->average(a, 5) << endl;
	delete p;
}

class Calculator_ {
	void input() {
		cout << "정수 2 개를 입력하세요>> ";
		cin >> a >> b;
	}
protected:
	int a, b;
	virtual int calc(int a, int b) = 0; // 두 정수의 합 리턴
public:
	void run() {
		input();
		cout << "계산된 값은 " << calc(a, b) << endl;
	}
};

class Adder : public Calculator_ {
public:
	virtual int calc(int a, int b) { return a + b; }
};

class Subtractor : public Calculator_ {
	virtual int calc(int a, int b) { return a - b; }
};
void ex1103() {
	Adder adder;
	Subtractor subtractor;
	adder.run();
	subtractor.run();
}

//수업실습 12장 템플릿

template <class T>
class Stack {
protected:
	int m_size;
	int m_top;
	T* m_buffer;
public:
	Stack(int size) {
		this->m_buffer = new T[size];
		this->m_size = size;
		this->m_top = 0;
	}
	~Stack() {
		m_size = 0;
		m_top = 0;
		delete[] m_buffer;
	}
	T Push(T value);
	/*
	 {
	m_buffer[m_top] = value;
	m_top++;
    }
	*/
	T Pop();/*
	 {
		T temp;
		temp = m_buffer[m_top];
		m_top--;
		return temp;
	}
	*/
};

template <class T>
T Stack<T>::Push(T value) {
	m_buffer[m_top] = value;
	m_top++;
	return m_buffer[m_top - 1];
}

template <class T>
T Stack<T>::Pop() {
	m_top--;
	return m_buffer[m_top];
}

void ex1200() {
	Stack<int> iStack(10);
	Stack<double> dStack(10);
	iStack.Push(3);
	int n = iStack.Pop();
	dStack.Push(3.5);
	double d = dStack.Pop();

	for (int i = 0; i < 10; i++) {
		iStack.Push(i);
	}
	for (int i = 0; i < 10; i++) {
		int n = iStack.Pop();
	}
}

//실습 12-1번
template <class T>
bool checkItem(T item, T minus[], int sizeMinus) {
	for (int i = 0; i < sizeMinus; i++) {
		if (minus[i] == item)
			return true;   //같은 원소가 존재.
	}return false; //같은 원소가 없다.
}

template <class T>
T* remove(T* src, int sizeSrc, T* minus, int sizeMinus, int& retSize) { //int minus[] = int* minus
	T* c = new T[sizeSrc];

	int count = 0;
	for (int i = 0; i < sizeSrc; i++) {
		if (false == checkItem(src[i], minus, sizeMinus)) {
			c[count] = src[i];
			count++;
		}
	}
	retSize = count;
	return c;
}

void ex11() {
	// remove() 함수를 int로 구체화하는 경우
	cout << "정수 배열 {1,2,3,4}에서 정수 배열 {-3,5,10,1,2}을 뺍니다" << endl;
	int x[] = { 1,2,3,4 };
	int y[] = { -3,5,10,1,2 };
	int retSize;
	int* p = remove(x, 4, y, 5, retSize);  //x와y의 교집합인 1,2 를 제거해야함! + int*로 일치

	if (retSize == 0) {
		cout << "모두 제거되어 리턴하는 배열이 없습니다." << endl;
		//return 0;
	}
	else {
		for (int i = 0; i < retSize; i++) // 배열의 모든 원소 출력
			cout << p[i] << ' ';
		cout << endl;
		delete[] p; // 할당받은 배열 반환
	}
	// remove() 함수를 double로 구체화하는 경우
	// 이곳에 작성
}


