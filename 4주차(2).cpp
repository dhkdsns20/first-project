#include <string>
#include <iostream>
#include <vector>
using namespace std;

//수업실습 1번
void ex01() {
	char cname[] = "hong";
	string sname(cname);
	sname[0] = 'T';
	cout << sname[0] << endl;

	string name("hong sang woo");
	string address("chungju");
	
	string str = name + address;
	cout << name << endl;

	string str_copy = str;
	cout << str_copy << endl;

	cout << str.size() << endl; //str의 길이를 측정

	int pos =str.find("woo"); // 'woo'가 발견된 위치(hong sang woo에서 w=10) 10출력


	cout << pos << endl;
}

//수업실습 2번

void ex02() {
	vector<int> A;

	cout << A.size() << endl;
	
	A.push_back(10);
	A.push_back(20);
	A.push_back(30);
	A.push_back(40);
	
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << endl;
	}
	A.clear();

}

//수업실습 3번
class Circle {
public:
	int radius;

	double getArea() {
		return(3.14 * radius * radius);
	}
	void setRadius(int r) {
		radius = r;

	}
};
/*
double Circle::getArea() {
	return 3.14 * radius * radius;
}
void Circle::setRadius(int r) {
	radius = r;

}*/ 
// 분리해서도 선언가능


void ex03() {
	Circle B;

	//B.radius = 10;
	B.setRadius(10);
	double area=B.getArea();

}

//수업실습 4번
void ex04() {
	Circle donut;
	donut.radius = 1; // donut 객체의 반지름을 1로 설정
	double area = donut.getArea(); // donut 객체의 면적 알아내기
	cout << "donut 면적은 " << area << endl;

	Circle pizza;
	pizza.radius = 30; // pizza 객체의 반지름을 30으로 설정
	area = pizza.getArea(); // pizza 객체의 면적 알아내기
	cout << "pizza 면적은 " << area << endl;

	Circle* ptr = &pizza; //pizza클래스의 주소를 ptr에 저장

	cout <<ptr->radius << endl; // (*ptr).radius ptr이 가리키는 주소에 radius의 값


}

//실습 3번
class Rectangle {
public:
	int width;
	int height;

	int getArea() {
		return width * height;
	}
};

int main() {
	Rectangle rect;
	rect.width = 3;
	rect.height = 5;
	cout << "사각형의 면적은 " << rect.getArea() << endl;
}