#include<iostream>
using namespace std;
/*
* //수업 실습
* class Circle {
	int radius;
public:
	Circle() { radius = 1; }		//생성자는 반환형 x	
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	float getArea();
};

float Circle::getArea() {
	return 3.14 * radius * radius;
}


int main() {
	Circle circleArray[3]; // Circle 객체 배열 생성

	//배열의 각 원소 객체의 맴버 접근
	circleArray[0].setRadius(10);
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30);

	for (int i = 0; i < 3; i++) //배열의 각 원소 객체의 맴버 접근
		cout << "Circle" << i << "의 면적은" << circleArray[i].getArea() << endl;

	Circle* p;
	p = circleArray;
	p->setRadius(5); // p가 가리키는 circleArray[0]의 radius를 5로 만듬
	(*p).setRadius(5); // 윗줄과 동일
	for (int i = 0; i < 3; i++) {
		cout << "Circle" << i << "의 면적은" << p->getArea() << endl;
		p++;
	}
}
*/

//실습 7-2

class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
};

int main() {
	Color screenColor(255, 0, 0);  // 빨간색의 screenColor 객체 생성
	Color* p;					   
	p = &screenColor;			   // p가 screenColor의 주소를 가짐
	p->show();					   // p와 show()를 이용해 screenColor의 색 출력
	Color colors[3];			   // Color의 일차원 배열 colors 선언. 원소는 3개
	p = colors;					   // p가 colors 배열을 가리키도록 코드 작성

// p와 setColor()를 이용하여 colors[0], colors[1], colors[2]가
// 각각 빨강, 초록, 파랑색을 가지도록 코드 작성
	p->setColor(255, 0, 0);
	(p + 1)->setColor(0, 255, 0);
	(p + 2)->setColor(0, 0, 255);

// p와 show()를 이용하여 colors 배열의 모든 객체의 색 출력. for 문 이용
	p->show(); //p[i].show() , (*p).show() 는 동일
	(p + 1)->show();
	(p + 2)->show();
}

