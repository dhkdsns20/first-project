#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Test {
public:
	int* data;
	int size; //(깊은복사)
	Test() { data = NULL; size = 0; }

	void MemAlloc(int size) { data = new int[size]; this->size = size; }  
	//SIZE만큼 메모리를 할당해서 주소를 data에 넣어준다.
	
	Test(Test& rightobj) {							//복사 생성자(깊은복사를 위함)
		this->data = new int[rightobj.size];			//메모리 할당
		for (int i = 0; i < rightobj.size; i++) {		//할당된 메모리에 데이터복사
			this->data[i] = rightobj.data[i];			//복사생성자도 생성자이므로, 객체를 선언할 때 자동 실행됨
		}
	}

	~Test() {
		delete[] data;						//B가 먼저 해제됨 하지만 A도 같이 해제 된다. 따라서 B해제 후 A해제 시 이미 해제 되었으므로 오류가 발생한다.
	}
};

void ex01() {
	Test A;  //깊은복사
	// Test A,B; (얕은복사)

	A.MemAlloc(5);						//A의 메모리 할당
	for (int i = 0; i < 5; i++) {
		A.data[i] = 100 * i;
	}

	Test B=A;								//깊은복사
	//B=A; (얕은 복사) A의 주소를 B에 공유

}

class Book {
	char* title; // 제목 문자열
	int price; // 가격

public:
	Book(const char* title, int price);
	Book(const Book& other); // 깊은 복사 생성자
	~Book();
	void set(const char* title, int price);
	void show() { std::cout << title << ' ' << price << "원" << std::endl; }
};

Book::Book(const char* title, int price) {
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
	this->price = price;
}

Book::Book(const Book& other) {
	this->title = new char[strlen(other.title) + 1];
	strcpy(this->title, other.title);
	this->price = other.price;
}

Book::~Book() {
	delete[] title;
}

void Book::set(const char* title, int price) {
	delete[] this->title; // 기존 문자열 메모리 해제
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
	this->price = price;
}

int main() {
	Book cpp("명품C++", 10000);
	Book java = cpp; // 깊은 복사가 이루어짐
	java.set("명품자바", 12000);
	cpp.show();
	java.show();

	return 0;
}