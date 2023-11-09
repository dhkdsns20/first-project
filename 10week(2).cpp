#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Test {
public:
	int* data;
	int size; //(��������)
	Test() { data = NULL; size = 0; }

	void MemAlloc(int size) { data = new int[size]; this->size = size; }  
	//SIZE��ŭ �޸𸮸� �Ҵ��ؼ� �ּҸ� data�� �־��ش�.
	
	Test(Test& rightobj) {							//���� ������(�������縦 ����)
		this->data = new int[rightobj.size];			//�޸� �Ҵ�
		for (int i = 0; i < rightobj.size; i++) {		//�Ҵ�� �޸𸮿� �����ͺ���
			this->data[i] = rightobj.data[i];			//��������ڵ� �������̹Ƿ�, ��ü�� ������ �� �ڵ� �����
		}
	}

	~Test() {
		delete[] data;						//B�� ���� ������ ������ A�� ���� ���� �ȴ�. ���� B���� �� A���� �� �̹� ���� �Ǿ����Ƿ� ������ �߻��Ѵ�.
	}
};

void ex01() {
	Test A;  //��������
	// Test A,B; (��������)

	A.MemAlloc(5);						//A�� �޸� �Ҵ�
	for (int i = 0; i < 5; i++) {
		A.data[i] = 100 * i;
	}

	Test B=A;								//��������
	//B=A; (���� ����) A�� �ּҸ� B�� ����

}

class Book {
	char* title; // ���� ���ڿ�
	int price; // ����

public:
	Book(const char* title, int price);
	Book(const Book& other); // ���� ���� ������
	~Book();
	void set(const char* title, int price);
	void show() { std::cout << title << ' ' << price << "��" << std::endl; }
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
	delete[] this->title; // ���� ���ڿ� �޸� ����
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
	this->price = price;
}

int main() {
	Book cpp("��ǰC++", 10000);
	Book java = cpp; // ���� ���簡 �̷����
	java.set("��ǰ�ڹ�", 12000);
	cpp.show();
	java.show();

	return 0;
}