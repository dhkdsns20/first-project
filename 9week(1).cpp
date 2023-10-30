#include <iostream>
using namespace std;
class allocTEST {
public:
	int* data;
	int size;
	allocTEST() {
		data = NULL;
	}
	allocTEST(int size_in) {
		data = new int[size_in];
		size = size_in;
	}
};
void ex01() {
	allocTEST E(100);
	for (int i = 0; i < E.size; i++) {
		E.data[i] = i;
	}


	int A[3];
	A[0] = 100;	A[1] = 200;	A[2] = 300;
	printf("ld", A);
	//A=100; 불가

	// malloc - free 
	int* B;
	B = (int*)malloc(3 * sizeof(int));		 //B의 메모리 할당 
	B[0] = 100; B[1] = 200; B[2] = 300;
	free(B);								//메모리 할당 해제

	// new - delete
	int* C=new int[3];
	C[0] = 100; C[1] = 200; C[2] = 300;
	delete[] C;
	
}

//실습 7-3
class Person {
	string name;
public:
	Person() { name = ""; }
	Person(string name_in) { this->name = name_in; }
	string getName() { return name; }
	void setName(string name_in) { this->name = name_in; }
};

class Family {
	string family_name;
	Person* p; // Person 배열 포인터
	int size; // Person 배열의 크기. 가족 구성원 수

public:
	Family() {};
	Family(string family_name_in, int size_in) {
		family_name = family_name_in;
		size = size_in;
		p = new Person[size_in];
		if (p == NULL) {
			cout << "메모리 할당 실패" << endl;
		}
	}// size 개수만큼 Person 배열 동적 생성

	void setName(int index, string name_in) {
		if (index >= 0 && index < size) {
			p[index].setName(name_in);
		}
		else {
			cout << "Invalid index" << endl;
		}
		p[index].setName(name_in);
	}
	void show() {
		cout << family_name << " 가족은 다음과 같이 3명입니다." << endl;

		for (int i = 0; i < size; i++) {
			cout << p[i].getName() << endl;
		}
	}// 모든 가족 구성원 출력

	~Family() {
		delete[] p; //해제
	}
};

int main() {
	Family simpson("Simpson", 3); // 3명으로 구성된 Simpson 가족
	simpson.setName(0, "Mr. Simpson");
	simpson.setName(1, "Mrs. Simpson");
	simpson.setName(2, "Bart Simpson");
	simpson.show();

	Family* hong= new Family("hong",4);
	hong->setName(0, "MR.HONG0");
	hong->setName(1, "MR.HONG1");
	hong->setName(2, "MR.HONG2");
	hong->setName(3, "MR.HONG3");
	hong->show();
}