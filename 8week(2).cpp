#include<iostream>
using namespace std;
/*
* //���� �ǽ�
* class Circle {
	int radius;
public:
	Circle() { radius = 1; }		//�����ڴ� ��ȯ�� x	
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	float getArea();
};

float Circle::getArea() {
	return 3.14 * radius * radius;
}


int main() {
	Circle circleArray[3]; // Circle ��ü �迭 ����

	//�迭�� �� ���� ��ü�� �ɹ� ����
	circleArray[0].setRadius(10);
	circleArray[1].setRadius(20);
	circleArray[2].setRadius(30);

	for (int i = 0; i < 3; i++) //�迭�� �� ���� ��ü�� �ɹ� ����
		cout << "Circle" << i << "�� ������" << circleArray[i].getArea() << endl;

	Circle* p;
	p = circleArray;
	p->setRadius(5); // p�� ����Ű�� circleArray[0]�� radius�� 5�� ����
	(*p).setRadius(5); // ���ٰ� ����
	for (int i = 0; i < 3; i++) {
		cout << "Circle" << i << "�� ������" << p->getArea() << endl;
		p++;
	}
}
*/

//�ǽ� 7-2

class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
};

int main() {
	Color screenColor(255, 0, 0);  // �������� screenColor ��ü ����
	Color* p;					   
	p = &screenColor;			   // p�� screenColor�� �ּҸ� ����
	p->show();					   // p�� show()�� �̿��� screenColor�� �� ���
	Color colors[3];			   // Color�� ������ �迭 colors ����. ���Ҵ� 3��
	p = colors;					   // p�� colors �迭�� ����Ű���� �ڵ� �ۼ�

// p�� setColor()�� �̿��Ͽ� colors[0], colors[1], colors[2]��
// ���� ����, �ʷ�, �Ķ����� �������� �ڵ� �ۼ�
	p->setColor(255, 0, 0);
	(p + 1)->setColor(0, 255, 0);
	(p + 2)->setColor(0, 0, 255);

// p�� show()�� �̿��Ͽ� colors �迭�� ��� ��ü�� �� ���. for �� �̿�
	p->show(); //p[i].show() , (*p).show() �� ����
	(p + 1)->show();
	(p + 2)->show();
}

