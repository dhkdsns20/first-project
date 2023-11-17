#include <iostream>
#include <vector>
using namespace std;


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
	/*
	* �ɹ��Լ��� ������
	void operator +=(int increment) {
		this->price += increment;
	}
	void operator -=(int decrement) {
		this->price += decrement;
	}
	*/
	void operator +=(int increment);
	void operator -=(int decrement);
	bool operator == (int price) {
		if(this->price == price)
			return true;
		else
			return false;
	}
	bool operator == (string title) {
		if (this->title == title)
			return true;
		else
			return false;
	}
	bool operator == (Book book) {
		if (this->pages == book.pages&& this->title == book.title)
			return true;
		else
			return false;
	}
	bool operator!() {
		if (this->price==0)
			return true;
		else
			return false;
	}
};

void Book::operator +=(int increment) {
	this->price += increment;
}

void Book::operator -=(int decrement) {
	this->price += decrement;
}

//�ǽ� 9-1/9-2
void ex09010902() {
	Book A, B;

	Book a("û��", 20000, 300), b("�̷�", 30000, 500);
	a += 500; // a.operator+=(500) å a�� ���� 500�� ����
	b -= 500; // å b�� ���� 500�� ����
	a.show();
	b.show();

}

//�ǽ� 9-3/9-4
void ex09030904() {
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

void Vec1DTest() {
	int size = 5;

	vector<int> vec1d(size, 0);

	for (int i = 0; i < vec1d.size(); i++) {
		vec1d[i] = 100;
	}
}

void Vec2DTest() {
	int m = 2, n = 3;

	vector<vector<int>>  vec(m, vector<int>(n, 0));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			vec[i][j] = 100;
	}
}

void ex() {
	Vec1DTest();
	Vec2DTest();

	int m = 2, n = 3;
	vector<vector<int>>  A(m, vector<int>(n, 1));  //vector �����ϴ� ����� �ϱ�
		
	int y = 3, x = 2;
	vector<vector<int>>  B(y, vector<int>(x, 2));

	//c[i][j] =A[i][0]*B[0][j]+A[i][1]*B[1][j]+A[i][2]*B[2][j]
	vector<vector<int>>  C(m, vector<int>(x, 2));


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < x; j++) {
			C[i][j] = 0;
			for (int k = 0; k < n; k++) {
				C[i][j] = A[i][k] * B[k][j];
			}
		}
	}
	

}

// 11/17 ����

class Matrix2D {

};

//int main() {
//
//	int m = 2, n = 3;
//	vector<vector<int>> A;
//	A.reserve(m);					// m���� �޸� �Ҵ�
//	for (int i = 0; i < A.size(); i++) {
//		A[i].reserve(n);
//	}
//	for (int i = 0; i < m; i++) for (int j = 0; j < n;j++) {
//		A[i][j] = 100;
//	}
//}

//���� �ǽ� 1��
// 2���� ��鿡�� �� ���� ǥ���ϴ� Ŭ���� Point ����
class Point {			//�θ� Ŭ����
	int x, y; //�� �� (x,y) ��ǥ��
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : public Point {  //��� Ŭ����
	// 2���� ��鿡�� �÷� ���� ǥ���ϴ� Ŭ���� ColorPoint.Point�� ��ӹ���
		string color;// ���� �� ǥ��
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};
void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint(); // Point�� showPoint() ȣ��
}
void ex1() {
	Point p; // �⺻ Ŭ������ ��ü ����
	ColorPoint cp; // �Ļ� Ŭ������ ��ü ����
	cp.set(3, 4); // �⺻ Ŭ������ ��� ȣ��
	cp.setColor("Red"); // �Ļ� Ŭ������ ��� ȣ��
	cp.showColorPoint(); // �Ļ� Ŭ������ ��� ȣ��
}

class A {
	int y;
public:
	A() { cout << "������ A" << endl; }
	A(int y) {
		this->y = y;
		cout << "������ A******" << endl; 
	}
	~A() { cout << "�Ҹ��� A" << endl; }
};

class B : public A {
	int x;
public:
	B() { cout << "������ B" << endl; }
	B(int x,int y) : A(x) {
		this->x = x;
		cout << "������ B******" << endl;
	}
	~B() { cout << "�Ҹ��� B" << endl; }
};

class C : public B {
public:
	C() { cout << "������ C" << endl; }
	~C() { cout << "�Ҹ��� C" << endl; }
};

void ex2() {
	B father(100, 200);
}

//�ǽ�10-1��
class Circle {
private:
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
	void setRadius(int r) {   //radius�� private�̹Ƿ� 
		radius = r;
	}
	int getRadius() {
		return radius;
	}
};

class NamedCircle : public Circle{
	int x;
	string y;
public:
	NamedCircle();
	NamedCircle(int x, string y) {
		setRadius(x);
		this->y = y;
	}
	void show() { cout << "�������� " << getRadius() << "��" << y << endl; }

};

int main() {
	NamedCircle waffle(3, "waffle"); // �������� 3�̰� �̸��� waffle�� ��
	waffle.show();
}