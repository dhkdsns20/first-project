//실습 2번
#include<iostream>
using namespace std;

class Oval {

	int Width, Height;

public:
	Oval();
	Oval(int w, int h);
	~Oval();
	int getwidth();
	int getheight();
	void set(int w, int h);
	void show();
};

//생성자 2개 생성
Oval::Oval() {
	Width = 1;
	Height = 1;
}
Oval::Oval(int w, int h) {
	Width = w;
	Height = h;

}

Oval::~Oval() {
	cout << "Oval 소멸 : Width = " << Width << " Height =" << Height << endl;
}
void Oval::set(int w, int h) {
	Width = w;
	Height = h;
}
void Oval::show() {
	cout << "width = " << Width << ", height =" << Height << endl;
}
int Oval::getwidth() {
	return Width;
}
int Oval::getheight() {
	return Height;
}

int main() {
	Oval a, b(3, 4);
	a.set(10, 20);
	a.show();
	cout << b.getwidth() << ", " << b.getheight() << endl;
}

