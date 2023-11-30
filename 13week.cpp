#include <iostream>
using namespace std;

//�ǽ� 10-2
class Circle {    //�θ�Ŭ����
private:
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
	void setRadius(int r) {   //radius�� private�̹Ƿ� 
		radius = r;
	}
	int getRadius() {
		return radius;
	}
};

class NamedCircle : public Circle {   //Circle�� �ڽ�Ŭ���� NamedCircle
	string name;
public:
	NamedCircle() {
		this->setRadius(0); //public�̹Ƿ� ���ٰ���
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
	

	cout << "5���� ���� �������� ���� �̸��� �Է��ϼ���." << endl;
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

	cout << "���� ������ ū ���ڴ� " << pizza[saved_index].getName()<< "�Դϴ�." << endl;
}

//�ǽ� 10-3
class BaseArray {
private:
	int capacity; // ���� �Ҵ�� �޸� �뷮
	int* mem; // ���� �迭�� ����� ���� �޸� ������
public:
	BaseArray(int capacity = 100) {
		this->capacity = capacity;
		mem = new int[capacity]; //int mem[100]; 100���� ���� but capacity�� �迭 ���氡��
	}
	~BaseArray() { delete[] mem; } //memory �Ҵ� ����
	void put(int index, int val) { mem[index] = val; } //mem�� index��°�� val�̶�� ���� �־��ش�.
	int get(int index) { return mem[index]; } //mem�� index��ġ�� ���� �����Ѵ�.
	int getCapacity() { return capacity; }
};

//�ٽ� �ڵ� Ȯ��
class MyQueue : public BaseArray {
	int size;
	int* mem;
public:
	MyQueue(int capacity) : BaseArray(capacity) { size = 0; };

	void enqueue(int input) {
		put(size, input);
		size++;
	}
	int capacity() {return getCapacity();} //capacity�� �����ϰ� ������ private�̹Ƿ� �Լ��� �����´�.
	int length() {return size;}
	
	int dequeue() {  
		int tmp = get(0);
		//������ ���� ���ذ� �ʿ��� �κ�
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
	cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mQ.enqueue(n); // ť�� ����
	}
	cout << "ť�� �뷮 : " << mQ.capacity() << ", ť�� ũ�� : " << mQ.length() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mQ.length() != 0) {
		cout << mQ.dequeue() << ' '; // ť���� �����Ͽ� ���
	}
	cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
}

//ť ��� ���� �����

class MyStack : public BaseArray {
	int size;
	int* mem;
public:
	MyStack(int capacity) : BaseArray(capacity) { size = 0; };

	void push(int input) {
		put(size, input);
		size++;
	}
	int capacity() { return getCapacity(); } //capacity�� �����ϰ� ������ private�̹Ƿ� �Լ��� �����´�.
	int length() { return size; }

	int pop() {
		size--;
		return get(size);
	}
};

int main() {
	MyStack mStack(100);
	int n;
	cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n); // ť�� ����
	}
	cout << "������ �뷮 : " << mStack.capacity() << ", ������ ũ�� : " << mStack.length() << endl;
	cout << "������ ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mStack.length() != 0) {
		cout << mStack.pop() << ' '; // ���ÿ��� �����Ͽ� ���
	}
	cout << endl << "ť�� ���� ũ�� : " << mStack.length() << endl;
}