
/*
/수업실습 1번
class Person {
public:
	double money; // 개인 소유의 돈
	void addMoney(int money_in) {
		money += money_in;
	}
	static int sharedMoney; // 공금
	static void addShared(int n) { 
		sharedMoney += n;
	}
};
int Person::sharedMoney = 10; // sharedMoney를 10으로 초기화

void ex01() {
	Person A, B;

	A.sharedMoney = 100; //A,B의 sharedMoney가 공유된다.
	B.sharedMoney = 200;

	//cout << A.addShared << endl;
	cout << Person::sharedMoney << endl;
}

//예제 2번
class Math {
public:			//static 맴버 변수 생성
	static	int sw_abs(int a) { return a > 0 ? a : -a; }
	static	int sw_max(int a, int b) { return (a > b) ? a : b; }
	static	int sw_min(int a, int b) { return (a > b) ? b : a; }
};

void ex2() {	//클래스 이름과 범위지정자(::)로 접근
	cout << Math::sw_abs(-5) << endl;
	cout << Math::sw_max(10, 8) << endl;
	cout << Math::sw_min(-3, -8) << endl;
}
*/

//예제 3번
#include <iostream>
using namespace std;

class Person {
public:
	double money; 
	string name;
	static int sharedMoney;
	void addMoney(int money_in) {money += money_in;}
	static void  addShared(int n) {
		sharedMoney = 0;
		sharedMoney += n;}
	Person() {money = 0;}
	Person(string name_in) {
		money = 0;
		name = name_in;
	}
	~Person() {
		cout << name << "'S money = " << money << endl;
	}
	
};


int main() {
	Person A("KANG"), B("KIM");
	// 3월
	A.addMoney(100);
	A.addShared(5);
	B.addMoney(200);
	B.addShared(5);

	// 4월
	A.addMoney(100);
	A.addShared(5);
	B.addMoney(200);
	B.addShared(5);
	cout << "공금 = " << Person::sharedMoney << endl;
	Person::addShared(100);
	cout << "공금 = " << Person::sharedMoney << endl;
}