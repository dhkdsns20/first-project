#include <iostream>
using namespace std;

//�����ǽ� 1��
void ex1() {
	int n = 10, m;
	char c = 'A';
	double d;
	int* p = &n; // p�� n�� �ּҰ��� ����
	char* q = &c; // q�� c�� �ּҰ��� ����
	double* r = &d; // r�� d�� �ּҰ��� ����
	*p = 25; // n�� 25�� �����
	*q = 'A'; // c�� ���� 'A'�� �����
	*r = 3.14; // d�� 3.14�� �����
	m = *p + 10; // p�� ����Ű�� ��(n ������)+10�� m�� ����
	cout << n << ' ' << *p << "\n"; // �� �� 25�� ��µ�
	cout << c << ' ' << *q << "\n"; // �� �� 'A'�� ��µ�
	cout << d << ' ' << *r << "\n"; // �� �� 3.14�� ��µ�
	cout << m << "\n"; // m �� 35 ���
}

//�����ǽ� 2��
void func(int* pointer) {
	cout << pointer << endl; //pointer�� �ּ� ���
	cout << *pointer << endl; //pointer�� ����Ű�� �� ���
	return;
}
void ex2() {
	int arr[6] = { 10,20,30,40,50,60 };
	int* ptr = arr;

	ptr++;

	func(&ptr[2]); 
	//ptr++�̹Ƿ� ptr[3]�� ���� �ּҿ� ����Ű�� ���� ���.

}

//�����ǽ� 3��
void ex3() {
	int a = 10, b = 20, c = 30, d = 40, e = 50;

	int* ptr[3];
	ptr[0] = &a;
	ptr[1] = &b;
	ptr[2] = &c;

	
	for (int i = 0; i < 3; i++) {
		cout << *ptr[i] << endl;
	}
}

//�����ǽ� 4��
void ex4() {
	int arr_0[3] = { 1,2,3 };
	int arr_1[4] = { 11,12,13,14 };
	int arr_2[5] = { 21,22,23,24,25 };

	int* ptr[3];
	ptr[0] = arr_0; //ptr[0] �ϳ��� ����
	ptr[1] = arr_1;
	ptr[2] = arr_2;

	int** ptr2 = ptr; //ptr�� �ּҸ� ptr2�� ����

	cout << *(ptr[0]+1) << endl; //ptr[0][1] �� arr_0[1]�� ���� ���
}

//�����ǽ� 9/15 
void Func(int b) {
	cout << "FUNC" << b << endl;
	cout << "FUNC &" << &b << endl; //b�� �ּҸ� ���
}
void FuncPrt(int* a) {
	*a = 200;
	cout << "FUNC" << a << endl;
	cout << "FUNC &" << a << endl; //a�� �ּҸ� ���
}
void Ex01_1()
{
	int a = 100;
	cout << a << endl;
	cout << a << endl;

	//Func(a);
	FuncPrt(&a);

	int* p;
	p = &a;
	cout << p << endl;
	cout << *p << endl;

}
void FuncArray(int* ptr) {
	cout << "Func" << ptr << endl;
	cout << "Func" << *ptr << endl;
	cout << "Func" << ptr[0] << endl;

	for (int i = 0; i < 5; i++) {
		ptr[i] = ptr[i] + 5;
	}
}
void Ex02_2() {
	int c[5] = { 10,20,30,40,50 };

	cout << c << endl;
	cout << *c << endl;
	cout << c + 1 << endl;
	cout << *(c + 1) << endl;

	FuncArray(c);
	int* p;
	p = c;

	cout << p << endl;
	cout << *p << endl;

}
void FuncRef(int& ttt)
{
	cout << "REF" << ttt << endl;
}
int Ex03_2() {
	int target = 20;
	int& nickname = target;


	nickname = -10;
	cout << target << endl;

	FuncRef(target);
	cout << target << endl;

	return 0;
}
void swap(int& a, int& b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
void Adder(int a, int b, int* c) {
	*c = a + b;
	cout << "PTR function" << endl;
}

void AddSub(int a, int b, int& sum, int& diff) {
	sum = a = b;
	diff = a - b;
	cout << "AddSub function" << endl;
}

void ex04_2() {
	int a = 10 , b = 20;
	swap(a, b);
	cout << "a=" << a << " b=" << b << endl;
	int c = 0;
	Adder(a, b, &c);
	cout << "c=" << c << endl;
	int d = 0;
	AddSub(a, b, c, d);
	cout << "sum=" << c << "  diff" << d << endl;
}

//�ǽ�1�� (�������� ����)
/*
* void ex01() {
	int M[3][3] = { {1,2,3},{4,5,6}, {7,8,9} };
	int(*ptr)[3]; int* p; int** pt;

	ptr = M;
	cout << ptr << M << "\n";
	cout << ptr + 1 << M + 1 << "\n";
	cout << *(ptr + 1) << ptr[1] << *(M + 1) << M[1] << "\n";
	cout << **(ptr + 1) << **(M + 1) << *M[1] << M[1][0] << "\n";
	p = M[0];
	cout << p << M[0] << *M << "\n";
	cout << p + 1 << M[0] + 1 << *M + 1 << "\n";
	cout << *(p + 1) << *(M[0] + 1) << *(*M + 1) << "\n";
	pt = &p; // pt = M; (X)
	cout << *pt << p << "\n";
	cout << **pt << *p << "\n";

}
*/


//�ǽ�2��
bool average(int a[], int size, int& avg) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += a[i];
	}
	avg = sum / size;
	return avg;
}

void ex02() {
	int x[] = { 0,1,2,3,4,5 };
	int avg;
	int size = 6;
	if (average(x, size, avg)) cout << "����� " << avg << endl;
	else cout << "�Ű� ���� ����" << endl;
	if (average(x, size, avg)) cout << "����� " << avg << endl;
	else cout << "�Ű� ���� ���� " << endl;
}

//�ǽ�3��

bool bigger(int a, int b, int& big) {
	if (a > b)
		big = a;
	else if (a < b)
		big = b;
	else
		return true;
	return false;
}

void ex03() {
	int x, y, big;
	bool b;
	cout << "�� ������ �Է��ϼ���>> ";
	cin >> x >> y;
	b = bigger(x, y, big);
	if (b) {
		cout << "same" << endl;
	}
	else {
		cout << "ū ���� " << big << endl;
	}
}



//�ǽ�4��
char& find(char a[], char c, bool& success) {
	for (int i = 0; a[i] != '\n'; i++) {
		if (a[i] == 'M')
			success = true;
		else
			success = false;
		return a[i];
	}
}
void ex04() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M�� �߰��� �� ����" << endl;
	}
	loc = 'm'; // 'M' ��ġ�� 'm' ���
	cout << s << endl; // "mike"�� ��µ�
}


int main() {
	ex02();
	ex03();
	ex04();
}












