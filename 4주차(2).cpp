#include <string>
#include <iostream>
#include <vector>
using namespace std;

//�����ǽ� 1��
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

	cout << str.size() << endl; //str�� ���̸� ����

	int pos =str.find("woo"); // 'woo'�� �߰ߵ� ��ġ(hong sang woo���� w=10) 10���


	cout << pos << endl;
}

//�����ǽ� 2��

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

//�����ǽ� 3��
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
// �и��ؼ��� ���𰡴�


void ex03() {
	Circle B;

	//B.radius = 10;
	B.setRadius(10);
	double area=B.getArea();

}

//�����ǽ� 4��
void ex04() {
	Circle donut;
	donut.radius = 1; // donut ��ü�� �������� 1�� ����
	double area = donut.getArea(); // donut ��ü�� ���� �˾Ƴ���
	cout << "donut ������ " << area << endl;

	Circle pizza;
	pizza.radius = 30; // pizza ��ü�� �������� 30���� ����
	area = pizza.getArea(); // pizza ��ü�� ���� �˾Ƴ���
	cout << "pizza ������ " << area << endl;

	Circle* ptr = &pizza; //pizzaŬ������ �ּҸ� ptr�� ����

	cout <<ptr->radius << endl; // (*ptr).radius ptr�� ����Ű�� �ּҿ� radius�� ��


}

//�ǽ� 3��
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
	cout << "�簢���� ������ " << rect.getArea() << endl;
}