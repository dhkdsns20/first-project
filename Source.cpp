#include <iostream>
using namespace std;

//수업실습 1번
void ex1() {
	int n = 10, m;
	char c = 'A';
	double d;
	int* p = &n; // p는 n의 주소값을 가짐
	char* q = &c; // q는 c의 주소값을 가짐
	double* r = &d; // r은 d의 주소값을 가짐
	*p = 25; // n에 25가 저장됨
	*q = 'A'; // c에 문자 'A'가 저장됨
	*r = 3.14; // d에 3.14가 저장됨
	m = *p + 10; // p가 가리키는 값(n 변수값)+10을 m에 저장
	cout << n << ' ' << *p << "\n"; // 둘 다 25가 출력됨
	cout << c << ' ' << *q << "\n"; // 둘 다 'A'가 출력됨
	cout << d << ' ' << *r << "\n"; // 둘 다 3.14가 출력됨
	cout << m << "\n"; // m 값 35 출력
}

//수업실습 2번
void func(int* pointer) {
	cout << pointer << endl; //pointer의 주소 출력
	cout << *pointer << endl; //pointer가 가리키는 값 출력
	return;
}
void ex2() {
	int arr[6] = { 10,20,30,40,50,60 };
	int* ptr = arr;

	ptr++;

	func(&ptr[2]); 
	//ptr++이므로 ptr[3]의 값의 주소와 가리키는 값이 출력.

}

//수업실습 3번
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

//수업실습 4번
void ex4() {
	int arr_0[3] = { 1,2,3 };
	int arr_1[4] = { 11,12,13,14 };
	int arr_2[5] = { 21,22,23,24,25 };

	int* ptr[3];
	ptr[0] = arr_0; //ptr[0] 하나가 변수
	ptr[1] = arr_1;
	ptr[2] = arr_2;

	int** ptr2 = ptr; //ptr의 주소를 ptr2로 받음

	cout << *(ptr[0]+1) << endl; //ptr[0][1] 즉 arr_0[1]의 값이 출력
}

//수업실습 9/15 
void Func(int b) {
	cout << "FUNC" << b << endl;
	cout << "FUNC &" << &b << endl; //b의 주소를 출력
}
void FuncPrt(int* a) {
	*a = 200;
	cout << "FUNC" << a << endl;
	cout << "FUNC &" << a << endl; //a의 주소를 출력
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

//실습1번 (과제에서 생략)
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


//실습2번
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
	if (average(x, size, avg)) cout << "평균은 " << avg << endl;
	else cout << "매개 변수 오류" << endl;
	if (average(x, size, avg)) cout << "평균은 " << avg << endl;
	else cout << "매개 변수 오류 " << endl;
}

//실습3번

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
	cout << "두 정수를 입력하세요>> ";
	cin >> x >> y;
	b = bigger(x, y, big);
	if (b) {
		cout << "same" << endl;
	}
	else {
		cout << "큰 수는 " << big << endl;
	}
}



//실습4번
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
		cout << "M을 발견할 수 없다" << endl;
	}
	loc = 'm'; // 'M' 위치에 'm' 기록
	cout << s << endl; // "mike"가 출력됨
}


int main() {
	ex02();
	ex03();
	ex04();
}












