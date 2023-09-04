#include <iostream>
#include <cstring>
using namespace std;

//실습1번
void ex01() {
	int n = 0;
	int sum(int, int);
	std::cout << "끝 수를 입력하세요>>";
	cin >> n;

	if (n <= 0) {
		std::cout << "양수를 입력하세요!\n";
	}
	std::cout << "1에서 " << n << "까지의 합은 " << sum(1, n) << "입니다.\n";
}

int sum(int a, int b) {  //a~b까지의 합을 계산한다.
	int res = 0;
	int k;
	for (k = a; k <= b; k++) {
		res += k;
	}

	return res;
}



//실습2번
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

//실습3번
double biggest(double x[], double n) { //최댓값을 구하는 함수
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
	cout << "5 개의 실수를 입력하라>>";

	for (int i = 0; i < 5; i++) {
		cin>> a[i];
	}
	
	cout << "제일 큰 수=" << biggest(a, 5) << endl;
}


//실습4번
void ex04(){
	char c[100]; //한 라인에 100개의 문자면 충분하다.
	int count = 0;
	cout << "문자들을 입력하라(100개 미만)." << endl;
	cin.ignore();	
	cin.getline(c, 100, '\n'); 

	for (int i = 0; i < 100; i++) {
		if (c[i] == 'x')
			count++;
	}
	cout << 'x' << "의 개수는" << count << endl;
}

//실습5번
void ex05() {
	char password1[100], password2[100];
	cout << "새 암호를 입력하세요>>";
	cin.getline(password1, 100, '\n');
	cout << "새 암호를 다시 한번 입력하세요>>";
	cin.getline(password2, 100, '\n');
	
	int result = strcmp(password1, password2);

	if (result == 0)
		cout << "같습니다.\n";
	else
		cout << "같지 않습니다.\n";
}

//실습6번
void ex06() {
	char name[100];
	char addresss[100];
	int age;
	
	cout << "이름은?";
	cin.getline(name, 100, '\n');
	cout << "주소은?";
	cin.getline(addresss, 100, '\n');
	cout << "나이은?";
	cin >> age;
	cout << "---------------------------------\n";
	cout << name << "." << addresss << " " << age << "세";
}


//전체코드 실행
int main() {
	ex01();
	ex02();
	ex03();
	ex04();
	ex05();
	ex06();

}





