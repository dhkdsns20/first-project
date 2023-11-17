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
		cout << title << ' ' << price << "원 " << pages << " 페이지" << endl;
	}
	string getTitle() {
		return title;
	}
	/*
	* 맴버함수로 구현시
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

//실습 9-1/9-2
void ex09010902() {
	Book A, B;

	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500; // a.operator+=(500) 책 a의 가격 500원 증가
	b -= 500; // 책 b의 가격 500원 감소
	a.show();
	b.show();

}

//실습 9-3/9-4
void ex09030904() {
	Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
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
	vector<vector<int>>  A(m, vector<int>(n, 1));  //vector 선언하는 방법은 암기
		
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

// 11/17 수업

class Matrix2D {

};

//int main() {
//
//	int m = 2, n = 3;
//	vector<vector<int>> A;
//	A.reserve(m);					// m개의 메모리 할당
//	for (int i = 0; i < A.size(); i++) {
//		A[i].reserve(n);
//	}
//	for (int i = 0; i < m; i++) for (int j = 0; j < n;j++) {
//		A[i][j] = 100;
//	}
//}

//수업 실습 1번
// 2차원 평면에서 한 점을 표현하는 클래스 Point 선언
class Point {			//부모 클래스
	int x, y; //한 점 (x,y) 좌표값
public:
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : public Point {  //상속 클래스
	// 2차원 평면에서 컬러 점을 표현하는 클래스 ColorPoint.Point를 상속받음
		string color;// 점의 색 표현
public:
	void setColor(string color) { this->color = color; }
	void showColorPoint();
};
void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint(); // Point의 showPoint() 호출
}
void ex1() {
	Point p; // 기본 클래스의 객체 생성
	ColorPoint cp; // 파생 클래스의 객체 생성
	cp.set(3, 4); // 기본 클래스의 멤버 호출
	cp.setColor("Red"); // 파생 클래스의 멤버 호출
	cp.showColorPoint(); // 파생 클래스의 멤버 호출
}

class A {
	int y;
public:
	A() { cout << "생성자 A" << endl; }
	A(int y) {
		this->y = y;
		cout << "생성자 A******" << endl; 
	}
	~A() { cout << "소멸자 A" << endl; }
};

class B : public A {
	int x;
public:
	B() { cout << "생성자 B" << endl; }
	B(int x,int y) : A(x) {
		this->x = x;
		cout << "생성자 B******" << endl;
	}
	~B() { cout << "소멸자 B" << endl; }
};

class C : public B {
public:
	C() { cout << "생성자 C" << endl; }
	~C() { cout << "소멸자 C" << endl; }
};

void ex2() {
	B father(100, 200);
}

//실습10-1번
class Circle {
private:
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
	void setRadius(int r) {   //radius가 private이므로 
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
	void show() { cout << "반지름이 " << getRadius() << "인" << y << endl; }

};

int main() {
	NamedCircle waffle(3, "waffle"); // 반지름이 3이고 이름이 waffle인 원
	waffle.show();
}