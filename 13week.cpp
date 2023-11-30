#include <iostream>
using namespace std;

//실습 10-2
class Circle {    //부모클래스
private:
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
	void setRadius(int r) {   //radius가 private이므로 
		radius = r;
	}
	int getRadius() {
		return radius;
	}
};

class NamedCircle : public Circle {   //Circle의 자식클래스 NamedCircle
	string name;
public:
	NamedCircle() {
		this->setRadius(0); //public이므로 접근가능
		//this->radius = 0; (X)
		this->name = "";
	}
	NamedCircle(int r, string name) {
		setRadius(r);
		this->name = name;
	}
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}

};

void ex1002() {
	NamedCircle pizza[5];
	

	cout << "5개의 정수 반지름과 원의 이름을 입력하세요." << endl;
	for (int i = 0; i < 5; i++) {
		cout << i+1 << ">>";
		//cin >> pizza[i].radius >> pizza[i].name;
		int r;
		string name;
		cin >> r >> name;
		pizza[i].setRadius(r);
		pizza[i].setName(name);
	}
	
	int saved_index= 0;
	int r_max = pizza[0].getRadius();

	for (int i = 0; i < 5; i++) {
		if (pizza[0].getRadius() < pizza[i].getRadius()) {
			saved_index = i;
		}
		r_max = pizza[saved_index].getRadius();

	}

	cout << "가장 면적이 큰 피자는 " << pizza[saved_index].getName()<< "입니다." << endl;
}

//실습 10-3
class BaseArray {
private:
	int capacity; // 동적 할당된 메모리 용량
	int* mem; // 정수 배열을 만들기 위한 메모리 포인터
public:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity]; //int mem[100]; 100개로 고정 but capacity는 배열 변경가능
	}
	~BaseArray() { delete[] mem; } //memory 할당 해제
	void put(int index, int val) { mem[index] = val; } //mem의 index번째에 val이라는 값을 넣어준다.
	int get(int index) { return mem[index]; } //mem의 index위치의 값을 리턴한다.
	int getCapacity() { return capacity; }
};

//다시 코드 확인
class MyQueue : public BaseArray {
	int size;
	int* mem;
public:
	MyQueue(int capacity) : BaseArray(capacity) { size = 0; };

	void enqueue(int input) {
		put(size, input);
		size++;
	}
	int capacity() {return getCapacity();} //capacity를 리턴하고 싶으나 private이므로 함수를 가져온다.
	int length() {return size;}
	
	int dequeue() {  
		int tmp = get(0);
		//구조에 대한 이해가 필요한 부분
		for (int index = 0; index < size - 1; index++) {
			//mem[index] = mem[index + 1]; size--;			
			put(index, get(index + 1));
		}
		return get(0);
	}
};

void ex1003() {
	MyQueue mQ(100);
	int n;
	cout << "큐에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n); // 큐에 삽입
	}
	cout << "큐의 용량 : " << mQ.capacity() << ", 큐의 크기 : " << mQ.length() << endl;
	cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' '; // 큐에서 제거하여 출력
	}
	cout << endl << "큐의 현재 크기 : " << mQ.length() << endl;
}

//큐 대신 스택 만들기

class MyStack : public BaseArray {
	int size;
	int* mem;
public:
	MyStack(int capacity) : BaseArray(capacity) { size = 0; };

	void push(int input) {
		put(size, input);
		size++;
	}
	int capacity() { return getCapacity(); } //capacity를 리턴하고 싶으나 private이므로 함수를 가져온다.
	int length() { return size; }

	int pop() {
		size--;
		return get(size);
	}
};

int main() {
	MyStack mStack(100);
	int n;
	cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n); // 큐에 삽입
	}
	cout << "스택의 용량 : " << mStack.capacity() << ", 스택의 크기 : " << mStack.length() << endl;
	cout << "스택의 원소를 순서대로 제거하여 출력한다>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' '; // 스택에서 제거하여 출력
	}
	cout << endl << "큐의 현재 크기 : " << mStack.length() << endl;
}