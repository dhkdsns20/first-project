/*

#include <iostream>
using namespace std;

//수업실습 1번
int Sum(int a=-20, int b=-10, int c=10) { //a,b,c 디폴트값(오른쪽부터 인식)
	return(a + b + c);					  //만약 b값만 디폴트값이 없다면 error 발생
}

void ex01() {
	int a = 10, b = 20, c = 30;
	int d, e, f,g;
	d = Sum(a, b,c);
	e = Sum(a, b);			//c를 10으로 인식
	f = Sum(a);				//b,c를 default값으로 인식
	g = Sum();				//a,b,c를 default값으로 인식
	cout << d << endl;
}

//수업실습 2번
int Diff(int a, int b) {   //int Diff
	return a - b;
}

double Diff(double a, double b) {  //double Diff
	return a - b;
}

typedef unsigned char UCHAR; // unsigned char = UCHAR

void ex02() {
	int A = 10, B = 20, C;
	C = Diff(A, B);

	double dA = 1.0, dB = 2.0, dC;
	dC = Diff(dA, dB);				//Diff함수중 double형을 인식

	unsigned char k;
	UCHAR Q;			//더 짧게 정의

}

//실습과제 1번
// 원형 선언
void f(char c = ' ', int line = 1) {
	for (int k = 0; k < line; k++) {
		for (int i = 1; i < 10; i++) {
			cout << c;
		}cout << '\n';
	}
}
// 함수 구현
void ex1() {
	f(); // 한줄에 빈칸을 10개 출력한다.
	f('%'); // 한 줄에 '%'를 10개 출력한다.
	f('@', 5); // 5 줄에 '@' 문자를 10개 출력한다.
}


//실습과제2번
int max(int a, int b, int c) {
	int max = 0;
	if (a > b)
		max = a;
	else if (b > a)
		max = b;
	if (max > c)
		max = c;
	return max;
}

int big(int a, int b, int c = 100) {
	int big = 0;
	big = max(a, b, c);
	return big;
}
/*
* int main() {
	int x = big(3, 5); // 3과 5중큰값 5는 최대값 100보다 작으므로, 5 리턴
	int y = big(300, 60); // 300과 60중큰값 300이 최대값 100보다 크므로, 100 리턴
	int z = big(30, 60, 50); // 30과 60 중큰값 60이 최대값 50보다 크므로, 50 리턴
	cout << x << ' ' << y << ' ' << z << endl;
}
*/
