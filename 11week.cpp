#include <iostream>
using namespace std;


//수업실습1번
class Rect { // Rect 클래스 선언
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend bool equals(Rect r, Rect s);
};

bool equals(Rect r, Rect s) { // 외부 함수
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

void ex01() {
	Rect a(3, 4), b(4, 5);
	if (equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
}

class Power {
	int kick;
	int punch;
public:
	Power() {kick = punch = 0;}
	Power(int kick_in, int punch_in) {
		this->kick=kick_in;
		this->punch=punch_in;
	}
	friend Power AddPower(Power A, Power B); //kick punch를 public으로 선언하거나 friend를 사용해 외부함수를 access허용한다.
};

Power AddPower(Power A,Power B) {					//반환형을 Power로 설정
	Power tmp;
	tmp.kick=A.kick + B.kick;
	tmp.punch = A.punch + B.punch;

	return tmp;
}

void ex02() {
	Power A(20, 10), B(30, 20);
	
	Power C = AddPower(A, B);

}

//수업실습 3번
class _Power_ {
	int kick;
	int punch;
public:
	_Power_() { kick = punch = 0; }
	_Power_(int kick_in, int punch_in) {
		this->kick = kick_in;
		this->punch = punch_in;
	}
	_Power_ operator+(_Power_ B) {
		_Power_ tmp;
		tmp.kick = this->kick + B.kick;
		tmp.punch = this->punch + B.punch;
		return tmp;
	}
	_Power_ operator-(_Power_ B) {
		_Power_ tmp;
		tmp.kick = this->kick - B.kick;
		tmp.punch = this->punch - B.punch;
		return tmp;
	}
};

class Point2D {
public: 
	int x, y;
	Point2D() { x = y = 0; } //디폴트 생성자도 정의해야함.
	Point2D(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Point2D operator+(Point2D Q) {
		Point2D tmp;

		tmp.x = this->x + Q.x;
		tmp.y = this->y + Q.y;

		return tmp;
	}

};

void ex03() {
	_Power_ A(20, 10), B(30, 20);
	_Power_ C = A + B;//A.operator+(B)
	_Power_ D = A - B;

	Point2D P(4, 5), Q(7, 8);
	Point2D R = P + Q;
	
}

//실습1번
class Cpx {
	float re, im;
public:
	Cpx() { re = im = 0; }
	Cpx(float im, float re) { this->re = re; this->im = im; }
	
	Cpx operator+(Cpx in) {
		Cpx tmp;
		tmp.re = this->re + in.re;
		tmp.im = this->im + in.im;
		return tmp;
	}
	Cpx operator-(Cpx in) {
		Cpx tmp;
		tmp.re = this->re - in.re;
		tmp.im = this->im - in.im;
		return tmp;
	}
	Cpx operator*(Cpx in) {
		Cpx tmp;
		//float a,b,c,d로 각각을 지정하고 하면 더 잘보임.
		tmp.re = this->re * in.re- this->im * in.im;
		tmp.im = this->re * in.im+ this->im * in.re;
		return tmp;
	}
	Cpx operator/(Cpx in) {
		Cpx tmp;
		tmp.re = ((this->re * in.re) + (this->im * in.im)) / ((in.im * in.im) + (in.re * in.re));
	;
		tmp.im = ((this->im * in.re) - (this->re * in.im)) / ((in.im * in.im) + (in.re * in.re));;
		return tmp;
	}
	void show()
	{
		cout.precision(5);
		if (im >= 0)
			cout << re << " + j" << im << endl;
		else
			cout << re << " - j" << -im << endl;
	}
	friend Cpx AddCpx(Cpx A, Cpx B);
};

///Cpx operator+(Cpx in) {
Cpx AddCpx(Cpx A,Cpx B){
	Cpx tmp;
	tmp.re = A.re + B.re;
	tmp.im = A.im + B.im;
	return tmp;
}


void ex1() {
	Cpx X(1, 2), Y(3, 4), Z;
	Z = X + Y;
	Z.show();
	Z = X - Y;
	Z.show();
	Z = X * Y;
	Z.show();
	Z = X / Y;
	Z.show();
}

int main() {
	Cpx X(1, 2), Y(3, 4) , Z;

	Z = AddCpx(X, Y);

	return 0;
}