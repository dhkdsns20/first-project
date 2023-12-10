#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

//8��//

//�ǽ� 8-1
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
	cout << "���� ������ �������� �Է��ϼ���>>";
	cin >> num;
	donut.setRadius(num); //&donut�� ��쿡�� donut.
}

void readRadius(Circle_82* donut) {
	int num;
	cout << "���� ������ �������� �Է��ϼ���>>";
	cin >> num;
	donut->setRadius(num); //*donut�� ������ �̹Ƿ� ->.
}
void ex0802() {
	Circle_82 donut;
	readRadius(donut);
	cout << "donut�� ���� = " << donut.getArea() << endl;
	readRadius(&donut); //* donut
	cout << "donut�� ���� = " << donut.getArea() << endl;
}


class Accumulator_83 {
	int value;
public:
	Accumulator_83(int value) {  // �Ű����� value�� ��� value�� �ʱ�ȭ�Ѵ�.
		this->value = value;
	}
	Accumulator_83& add(int n){  // value�� n�� ���� ���� �����Ѵ�.
		this->value += n;
		return *this;
	}
	int get() { // ������ �� value�� �����Ѵ�.
		return value;
	}
};

void ex0803() {
	Accumulator_83 acc(10);
	acc.add(5).add(6).add(7); // acc�� value ����� 28�� �ȴ�.
	cout << acc.get() << endl; // 28 ���
}

class Book_0804 {
	char* title; // ���� ���ڿ�
	int price; // ����
public:
	Book_0804(const char* title, int price) {		
		this->title = new char[strlen(title) + 1];//�޸��Ҵ�
		strcpy(this->title, title);
		this->price = price;
	}
	Book_0804(Book_0804& other) {
		this->title = new char[strlen(other.title) + 1];//�޸��Ҵ�
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
	void show() { cout << title << ' ' << price << "��" << endl; }
};

void ex0804() {
	Book_0804 cpp("��ǰC++", 10000);
	Book_0804 java = cpp;
	java.set("��ǰ�ڹ�", 12000);
	cpp.show();
	java.show();
}

//�ǽ� 9-0
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

//�ǽ� 9-1&9-2


class Book {
	string title;
	int price;
	int pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title; this->price = price; this->pages = pages;
	}
	void show() {
		cout << title << ' ' << price << "�� " << pages << " ������" << endl;
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
	Book a("û��", 20000, 300), b("�̷�", 30000, 500);
	a += 500; // å a�� ���� 500�� ����
	b -= 500; // å b�� ���� 500�� ����
	a.show();
	b.show();
}

//�ǽ�9-3&9-4
void ex090304() {
	Book a("��ǰ C++", 30000, 500), b("��ǰ C++", 30000, 500);
	// price ��
	if (a == 30000) cout << "���� 30000��" << endl;
	// å title ��
	if (a == "��ǰ C++") cout << "��ǰ C++ �Դϴ�." << endl;
	// title, price, pages ��� ��
	if (a == b) cout << "�� å�� ���� å�Դϴ�." << endl;
}

//�ǽ� 9-5
void ex0905() {
	Book book("�������", 0, 50); // ������ 0
	if (!book) cout << "��¥��" << endl;
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
	x.showB(); // ��
}

//�ǽ�10-1
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
	NamedCircle waffle(3, "waffle"); // �������� 3�̰� �̸��� waffle�� ��
	waffle.show();
}

//�ǽ� 10-2
class NamedCircle_2 : public Circle {   //Circle�� �ڽ�Ŭ���� NamedCircle
	string name;
public:
	NamedCircle_2() {
		this->setRadius(0); //public�̹Ƿ� ���ٰ���
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


	cout << "5���� ���� �������� ���� �̸��� �Է��ϼ���." << endl;
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

	cout << "���� ������ ū ���ڴ� " << pizza[saved_index].getName() << "�Դϴ�." << endl;
}

class BaseArray {
private:
	int capacity; // ���� �Ҵ�� �޸� �뷮
	int* mem; // ���� �迭�� ����� ���� �޸� ������
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

//�ٽ� �ڵ� Ȯ��
class MyQueue : public BaseArray {
	int size;
	int* mem;
public:
	MyQueue(int capacity) : BaseArray(capacity) { size = 0; };

	void enqueue(int input) {
		put(size, input);
		size++;
	}
	int capacity() { return getCapacity(); } //capacity�� �����ϰ� ������ private�̹Ƿ� �Լ��� �����´�.
	int length() { return size; }

	int dequeue() {
		int tmp = get(0);
		size--;
		//������ ���� ���ذ� �ʿ��� �κ�
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
	cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n); // ť�� ����
	}
	cout << "ť�� �뷮 : " << mQ.capacity() << ", ť�� ũ�� : " << mQ.length() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' '; // ť���� �����Ͽ� ���
	}
	cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
}

//�ǽ� 11-1

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
	p[0] = new Oval("��붱", 10, 20); // upcasting
	p[1] = new Rect("����", 30, 40); // upcasting 
	p[2] = new Triangular("�佺Ʈ", 30, 40); // upcasting
	for (int i = 0; i < 3; i++)
		cout << p[i]->getName() << " ���̴� " << p[i]->getArea() << endl;
	for (int i = 0; i < 3; i++) delete p[i];
}

class Calculator {
public:
	virtual int add(int a, int b) = 0; // �� ������ �� ����
	virtual int subtract(int a, int b) = 0; // �� ������ �� ����
	virtual double average(int a[], int size) = 0; // �迭 a�� ��� ����. size�� �迭�� ũ��
};

class GoodCalc : public Calculator {
public:
	virtual int add(int a, int b) { return a + b; }
	virtual int subtract(int a, int b) { return a - b; }
	virtual double average(int a[], int size) {
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += a[i];
		}return (double)sum / size; //double�� return��
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
		cout << "���� 2 ���� �Է��ϼ���>> ";
		cin >> a >> b;
	}
protected:
	int a, b;
	virtual int calc(int a, int b) = 0; // �� ������ �� ����
public:
	void run() {
		input();
		cout << "���� ���� " << calc(a, b) << endl;
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

//�����ǽ� 12�� ���ø�

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

//�ǽ� 12-1��
template <class T>
bool checkItem(T item, T minus[], int sizeMinus) {
	for (int i = 0; i < sizeMinus; i++) {
		if (minus[i] == item)
			return true;   //���� ���Ұ� ����.
	}return false; //���� ���Ұ� ����.
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
	// remove() �Լ��� int�� ��üȭ�ϴ� ���
	cout << "���� �迭 {1,2,3,4}���� ���� �迭 {-3,5,10,1,2}�� ���ϴ�" << endl;
	int x[] = { 1,2,3,4 };
	int y[] = { -3,5,10,1,2 };
	int retSize;
	int* p = remove(x, 4, y, 5, retSize);  //x��y�� �������� 1,2 �� �����ؾ���! + int*�� ��ġ

	if (retSize == 0) {
		cout << "��� ���ŵǾ� �����ϴ� �迭�� �����ϴ�." << endl;
		//return 0;
	}
	else {
		for (int i = 0; i < retSize; i++) // �迭�� ��� ���� ���
			cout << p[i] << ' ';
		cout << endl;
		delete[] p; // �Ҵ���� �迭 ��ȯ
	}
	// remove() �Լ��� double�� ��üȭ�ϴ� ���
	// �̰��� �ۼ�
}


