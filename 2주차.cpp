#include <iostream>
#include <cstring>
using namespace std;

//�ǽ�1��
void ex01() {
	int n = 0;
	int sum(int, int);
	std::cout << "�� ���� �Է��ϼ���>>";
	cin >> n;

	if (n <= 0) {
		std::cout << "����� �Է��ϼ���!\n";
	}
	std::cout << "1���� " << n << "������ ���� " << sum(1, n) << "�Դϴ�.\n";
}

int sum(int a, int b) {  //a~b������ ���� ����Ѵ�.
	int res = 0;
	int k;
	for (k = a; k <= b; k++) {
		res += k;
	}

	return res;
}



//�ǽ�2��
void ex02() {
	

	int sum(int, int);

	int tot;

	for (int i = 1; i < 10; i++) {			
		for (int j = 1; j < 10; j++) {
			tot = i * j;
			std::cout << i << "X" << j << "=" << tot;
			std::cout << " ";
		}std::cout << "\n";
	}
};

//�ǽ�3��
double biggest(double x[], double n) { //�ִ��� ���ϴ� �Լ�
	double big = x[0];
	for (int i = 1; i < n; i++) {
		if (big < x[i]) {
			big = x[i];
		}
		else
			big = big;
	}
	return big;
}

void ex03() {
	double a[5];
	cout << "5 ���� �Ǽ��� �Է��϶�>>";

	for (int i = 0; i < 5; i++) {
		cin>> a[i];
	}
	
	cout << "���� ū ��=" << biggest(a, 5) << endl;
}


//�ǽ�4��
void ex04(){
	char c[100]; //�� ���ο� 100���� ���ڸ� ����ϴ�.
	int count = 0;
	cout << "���ڵ��� �Է��϶�(100�� �̸�)." << endl;
	cin.ignore();	
	cin.getline(c, 100, '\n'); 

	for (int i = 0; i < 100; i++) {
		if (c[i] == 'x')
			count++;
	}
	cout << 'x' << "�� ������" << count << endl;
}

//�ǽ�5��
void ex05() {
	char password1[100], password2[100];
	cout << "�� ��ȣ�� �Է��ϼ���>>";
	cin.getline(password1, 100, '\n');
	cout << "�� ��ȣ�� �ٽ� �ѹ� �Է��ϼ���>>";
	cin.getline(password2, 100, '\n');
	
	int result = strcmp(password1, password2);

	if (result == 0)
		cout << "�����ϴ�.\n";
	else
		cout << "���� �ʽ��ϴ�.\n";
}

//�ǽ�6��
void ex06() {
	char name[100];
	char addresss[100];
	int age;
	
	cout << "�̸���?";
	cin.getline(name, 100, '\n');
	cout << "�ּ���?";
	cin.getline(addresss, 100, '\n');
	cout << "������?";
	cin >> age;
	cout << "---------------------------------\n";
	cout << name << "." << addresss << " " << age << "��";
}


//��ü�ڵ� ����
int main() {
	ex01();
	ex02();
	ex03();
	ex04();
	ex05();
	ex06();

}





