/*

#include <iostream>
using namespace std;

//�����ǽ� 1��
int Sum(int a=-20, int b=-10, int c=10) { //a,b,c ����Ʈ��(�����ʺ��� �ν�)
	return(a + b + c);					  //���� b���� ����Ʈ���� ���ٸ� error �߻�
}

void ex01() {
	int a = 10, b = 20, c = 30;
	int d, e, f,g;
	d = Sum(a, b,c);
	e = Sum(a, b);			//c�� 10���� �ν�
	f = Sum(a);				//b,c�� default������ �ν�
	g = Sum();				//a,b,c�� default������ �ν�
	cout << d << endl;
}

//�����ǽ� 2��
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
	dC = Diff(dA, dB);				//Diff�Լ��� double���� �ν�

	unsigned char k;
	UCHAR Q;			//�� ª�� ����

}

//�ǽ����� 1��
// ���� ����
void f(char c = ' ', int line = 1) {
	for (int k = 0; k < line; k++) {
		for (int i = 1; i < 10; i++) {
			cout << c;
		}cout << '\n';
	}
}
// �Լ� ����
void ex1() {
	f(); // ���ٿ� ��ĭ�� 10�� ����Ѵ�.
	f('%'); // �� �ٿ� '%'�� 10�� ����Ѵ�.
	f('@', 5); // 5 �ٿ� '@' ���ڸ� 10�� ����Ѵ�.
}


//�ǽ�����2��
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
	int x = big(3, 5); // 3�� 5��ū�� 5�� �ִ밪 100���� �����Ƿ�, 5 ����
	int y = big(300, 60); // 300�� 60��ū�� 300�� �ִ밪 100���� ũ�Ƿ�, 100 ����
	int z = big(30, 60, 50); // 30�� 60 ��ū�� 60�� �ִ밪 50���� ũ�Ƿ�, 50 ����
	cout << x << ' ' << y << ' ' << z << endl;
}
*/
