
/*
/�����ǽ� 1��
class Person {
public:
	double money; // ���� ������ ��
	void addMoney(int money_in) {
		money += money_in;
	}
	static int sharedMoney; // ����
	static void addShared(int n) { 
		sharedMoney += n;
	}
};
int Person::sharedMoney = 10; // sharedMoney�� 10���� �ʱ�ȭ

void ex01() {
	Person A, B;

	A.sharedMoney = 100; //A,B�� sharedMoney�� �����ȴ�.
	B.sharedMoney = 200;

	//cout << A.addShared << endl;
	cout << Person::sharedMoney << endl;
}

//���� 2��
class Math {
public:			//static �ɹ� ���� ����
	static	int sw_abs(int a) { return a > 0 ? a : -a; }
	static	int sw_max(int a, int b) { return (a > b) ? a : b; }
	static	int sw_min(int a, int b) { return (a > b) ? b : a; }
};

void ex2() {	//Ŭ���� �̸��� ����������(::)�� ����
	cout << Math::sw_abs(-5) << endl;
	cout << Math::sw_max(10, 8) << endl;
	cout << Math::sw_min(-3, -8) << endl;
}
*/

//���� 3��
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
	// 3��
	A.addMoney(100);
	A.addShared(5);
	B.addMoney(200);
	B.addShared(5);

	// 4��
	A.addMoney(100);
	A.addShared(5);
	B.addMoney(200);
	B.addShared(5);
	cout << "���� = " << Person::sharedMoney << endl;
	Person::addShared(100);
	cout << "���� = " << Person::sharedMoney << endl;
}