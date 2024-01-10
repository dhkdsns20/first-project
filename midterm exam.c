#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

//1일차
void ex0101(void) {
	int num1 = 0;
	int num2 = 0;

	printf("num1="); scanf("%d", &num1);
	printf("num2="); scanf("%d", &num2);

	printf("%d + %d = %d\n", num1, num2, num1 + num2);
	printf("%d - %d = %d\n", num1, num2, num1 - num2);
	printf("%d * %d = %d\n", num1, num2, num1 * num2);
	printf("%d / %d = %d\n", num1, num2, num1 / num2);
}

void ex0102(void) {
	int x, y, z;

	printf("첫번째 수=");
	scanf("%d", &x);
	printf("두번째 수=");
	scanf("%d", &y);
	printf("세번째 수=");
	scanf("%d", &z);
	printf("큰 수="); printf("%d\n", (x > y) ? (x > z) ? x : z : (y > z) ? y : z);
	printf("작은 수="); printf("%d\n", (x < y) ? (x < z) ? x : z : (y < z) ? y : z);
}

//2일차
#include <stdio.h>

void ex0201() {
	int kor, mat, eng, sum;
	float total;
	char grade;

	printf("국어 수학 영어 (0~99)입력\n");
	scanf("%d %d %d", &kor, &mat, &eng);

	sum = kor + mat + eng;
	total = sum / 3.0;

	if (total >= 90)
		grade = 'A';
	else if (total >= 80)
		grade = 'B';
	else if (total >= 70)
		grade = 'C';
	else if (total >= 60)
		grade = 'D';
	else
		grade = 'F';

	printf("국어 수학 영어 총합 평균 학점\n");
	printf("%d   %d   %d   %d  %.1f   %c\n", kor, mat, eng, sum, total, grade);
}

void ex0202() {
	int a, b, c;

	printf("삼각형의 3변을 입력하시오:");
	scanf("%d %d %d", &a, &b, &c);

	if (a + b > c) {
		if (b + c > a) {
			if (a + c > b)
				printf("올바른 삼각형");
			else
				printf("올바르지 않은 삼각형");
		}
		else
			printf("올바르지 않은 삼각형");
	}
	else
		printf("올바르지 않은 삼각형");
}

void ex0203() {
	int num, sum = 0;

	do {
		printf("정수를 입력하시오.\n");
		scanf("%d", &num);
		sum += num;
	} while (num != 0);

	printf("%d", sum);
}

void ex0204(void) {
	int score[5];
	srand((unsigned int)time(NULL)); //계속해서 증가되는 값(시간을 센다)
	// rand()값을 시간마다 바꾸고 싶다!
	for (int i = 0; i < 5; i++) {
		score[i] = rand();
		printf("score[%d]=%d\n", i, (int)score[i] % 100);
		//100이하의 값을 표시하기위해 100의 몫을 출력하였다.
	}
}

int max_(int* arry, int size) {
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (max < arry[i])
			max = arry[i];
	}
	return max;
}

int min_(int* arry, int size) {
	int min = 0;
	for (int i = 0; i < 20; i++) {
		if (min > arry[i])
			min = arry[i];
	}
	return min;
}

void ex0205(void) {
	int arry[20];
	int max_ = 0, min_ = 0;

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 20; i++) {
		arry[i] = rand() % 100;
	}

	max_ = max(arry, 20);
	min_ = min(arry, 20);

	printf("max=%d, min=%d", max_, min_);
}

void ex0206(void) {
	float avg_fin = 0;
	float grade[3] = { 0,0,0 };  //학생들 점수의 총합을 저장하는 배열
	float avg[3] = { 0,0,0 };  //학생들의 최종성적을 저장하는 배열
	int arry[3][5] = {
	{1,87,98,80,76},
	{2,99,89,90,90},
	{3,65,68,50,49}
	};

	for(int i = 0; i < 3; i++) {
		grade[i] = arry[i][1] + arry[i][2] + arry[i][3] + arry[i][4];
	}

	for (int i = 0; i < 3; i++) {
		avg[i] += grade[i] / 4.0; //학생들 개인 성적
		avg_fin += avg[i]; //전체 학생의 성적의 합
	}

	for (int i = 0; i < 3; i++) {
		printf("학번 : %d , 최종성적 : %lf\n", arry[i][0], avg[i]);
	}
	printf("최종성적 = %lf", avg_fin / 3.0);
}


//선택정렬
void ex0207() {
	int index = 0, num = 0, count = 0;
	int array[6] = { 5,3,8,1,2,7 };
	int tmp, i;

	do {
		index = num; //1번의 반복에서 index는 최솟값을 가지는 배열의 원소번호를 임시로 저장한다.
		for (i = num + 1; i < 6; i++) { //배열의 최솟값을 찾는다.
			if (array[i] < array[index]) {
				index = i; //최솟값을 갖는 배열의 원소번호를 index에 기록
			}
		}
		tmp = array[num];  //array[num]과 array[index]를 교환한다.
		array[num] = array[index];
		array[index] = tmp;

		num++;  //다음 array[num]을 비교하겠다.
		count++;
	} while (count < 6);

	for (int i = 0; i < 6; i++) {
		printf("%d ", array[i]);
	}

}

//3일차

void ex0301(void) {
	int data = 0x0A0B0C0D;
	char* pc;
	short* ps;
	int* pi;
	pc = (char*)&data;
	ps = (short*)&data;
	pi = (int*)&data;
	for (int i = 0; i < 4; i++) { //1바이트씩 읽는다.
		printf("*(pc + %d) = %02X \n", i, *(pc + i));
	}
	for (int i = 0; i < 2; i++) { //2바이트씩 읽는다.
		printf("*(ps + %d) = %04X \n", i, *(ps + i));
	}
	for (int i = 0; i < 2; i++) { //4바이트 읽는다.
		printf("*(pi + %d) = %04X \n", i, *(pi + i));
	}
}

// 기울기와 y절편을 계산
int get_line_parameter(int x1, int y1, int x2, int y2, float* slope, float* yintercept)
{
	if (x1 == x2)
		return -1;
	else {
		*slope = (float)(y2 - y1) / (float)(x2 - x1); //기울기 계산
		*yintercept = y1 - (*slope) * x1;  // y절편 계산
		return 0;
	}
}

void ex0302(void)
{
	float s, y;
	if (get_line_parameter(3, 3, 6, 6, &s, &y) == -1) //x1과 x2가 같다면
		printf("에러\n");
	else
		printf("기울기는 %f, y절편은 %f\n", s, y);
}

void ex0303(void)
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int(*pa)[5];
	int i;
	pa = &a;

	for (i = 0; i < 5; i++)
		printf("%d \n", (*pa)[i]); //포인터배열 출력시 (*pa)[i]로 출력
}

void ex0303_(int argc, char* argv[])
{
	int i = 0;
	for (i = 0; i < argc; i++)
		printf("명령어 라인에서 %d번째 문자열 = %s\n", i, argv[i]);
}


struct student {
	int number;
	char name[10];
	double grade;
};

void ex0304(void)
{
	struct student s;

	printf("학번을 입력하시오: ");
	scanf("%d", &s.number);
	printf("이름을 입력하시오: ");
	scanf("%s", s.name); //문자열은 s.name로 
	printf("학점을 입력하시오(실수): ");
	scanf("%lf", &s.grade);

	printf("학번: %d\n", s.number);
	printf("이름: %s\n", s.name);
	printf("학점: %f\n", s.grade);
}

struct student_ {
	int number;
	char name[20];
	double grade;
};

void ex0305(void)
{
	struct student_ list[100];	// 구조체의 배열 선언
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 100; i++) {
		list[i].number = i;
		strcpy(list[i].name, "student");
		list[i].grade = rand() % 100;

		printf("학번: %d\n", list[i].number);
		printf("이름: %s\n", list[i].name);
		printf("학점: %.1lf\n", list[i].grade);
	}
}

//4일차
void ex0401() {
	char dept[20], name[20]; // 지역변수 선언
	int grade, year; // 지역변수 선언
	printf("정보를 입력하세요.\n\n"); // 안내문 출력
	printf("학과: "); // 안내문 출력
	scanf("%s", dept); // 학과 입력
	printf("학년: "); // 안내문 출력
	scanf("%d", &grade); // 학년 입력
	printf("입학년도: "); // 안내문 출력
	scanf("%d", &year); // 입학년도 입력
	printf("이름: "); // 안내문 출력
	scanf("%s", name); // 이름 입력
	// 자기소개 출력
	printf("\n나는 %s %d학년 %d학번 %s입니다.\n", dept, grade, year, name);
}

float max_(float a, float b, float c);
float min_(float a, float b, float c);

void ex0402(void) {
	float num1, num2, num3;
	float max, min;
	float diff;

	printf("세 개의 수를 입력하세요.\n\n"); // 데이터 입력
	printf("첫 번째 수: "); scanf("%f", &num1);
	printf("두 번째 수: "); scanf("%f", &num2);
	printf("세 번째 수: "); scanf("%f", &num3);

	max = max_(num1, num2, num3);
	min = min_(num1, num2, num3);


	diff = max - min;
	printf("\n가장 큰 수와 작은 수의 차이=%f\n", diff);
}

float max_(float a, float b, float c) {
	float max;

	if (a > b)
		max = a;
	else
		max = b;
	max = (c > max) ? c : max;

	return max;
}

float min_(float a, float b, float c) {
	float min = a;

	if (min > b)
		min = b;
	if (min > c)
		min = c;

	return min;
}

#define num 10
int score[10];

void input() {
	printf("10개의 수를 입력하시오:\n");
	for (int i = 0; i < 10; i++) {
		printf("%d번째 수: ", i + 1);
		scanf("%d", &score[i]); //값을 입력하므로 &score[i]
	}
}

float avg_() {
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += score[i];
	}
	return (float)sum / num; //float형으로 반환해야 하기 때문에 int형 변수 sum을 float형으로 자료형을 변환한다.
}

void ex0403(void) {
	float avg;

	input();
	avg = avg_();
	printf("평균 = %f", avg);

	return 0;
}

//5일차
unsigned int get_integer() {
	unsigned char* value;
	printf("정수를 입력하시오: ");
	scanf("%d", &value);
	return value;
}

void ex0501(void) {
	unsigned char x = get_integer();
	unsigned char y = get_integer();
	printf("두수는 %u %u입니다. \n", x, y);
	return 0;
}

int coin_toss(void);

void ex0502(void)
{
	int toss;
	int heads = 0;
	int tails = 0;
	srand((unsigned)time(NULL));

	for (toss = 0; toss < 100; toss++) {
		if (coin_toss() == 1)
			heads++;
		else
			tails++;
	}

	printf("동전의 앞면: %d \n", heads);
	printf("동전의 뒷면: %d \n", tails);
	return 0;
}

int coin_toss(void)
{
	int i = rand() % 2;
	if (i == 0)
		return 0;
	else
		return 1;
}

double sum_(double, ...);

void ex0503(void)
{
	double answer = sum(4.0, 4.0, 3.0, 2.0, 1.0);
	printf("합은 %lf입니다.\n", answer);
	return 0;
}

double sum_(double num1, ...)
{
	float answer = 0;
	va_list argptr;
	va_start(argptr, num1);

	for (; num1 > 0; num1--) answer += va_arg(argptr,double);
	va_end(argptr);
	return answer;
}

void function_(int num2) {
	printf("%d의 약수 : ", num2);
	for (int i = 2; i <= num2; i++) {
		if (num2 % i == 0)
			printf("%d ", i);
	}
}

void ex0504(void)
{
	int number; // 지역 변수로 선언
	while (1) // 무한 반복
	{
		printf("약수를 구할 정수를 입력하세요(1 이하의 수면 종료): ");
		scanf("%d", &number); // 데이터 입력

		if (number >= 2) { // 약수를 구할 수 있다면
			function(number);
		}
		else { // 약수를 구할 수 없다면
			printf("%d에 대한 약수를 구할 수 없습니다.\n", number);
			printf("프로그램을 종료합니다.\n");
			break;
		}
		printf("\n");
	}
}

int sum12(int num3) {
	int sum = 0;
	for (int i = 1; i < num3; i++) {
		if (num3 % i == 0)
			sum += i;
	}return sum;
}

void ex0505(void)
{
	int number; // 지역 변수로 선언
	printf("1000 이하 완전수 출력 : \n");
	for (number = 2; number <= 1000; number++) {
		if (number == sum12(number))
			printf("%d\n", number);
	}
}

//6일차
#define NMAX 5

void ex0601()
{
	int ip[NMAX], n, xdata = 0, i;
	n = 0;

	for (i = 0; i < NMAX; ++i)
	{
		ip[i] = 0; // 배열 0으로 초기화
	}

	srand((unsigned int)time(NULL));

	printf("1~4번 중 한 후보의 번호를 입력하시오 :");
	int count = 0;

	while (count < 100) // 입력된 데이터가 번호인 동안 (문자 입력 시 반복문 탈출)
	{
		xdata = rand() % 5;
		printf("%d번 후보자 : %d 선택\n", n + 1, xdata);
		n++; // 총 투표 횟수 증가
		if (xdata<1 || xdata>NMAX) { // 1~4 이외의 숫자 입력 시
			++ip[0]; //무효 표 수 증가
			count++;
		}
		else { // 1~4 사이의 값이면
			++ip[xdata]; //해당 후보투표수 증가
			count++;
		}
	}

	printf("\n득표수\n");
	for (i = 1; i < NMAX; i++) {
		printf("%d번 : %d 표", i, ip[i]); // 1~4번 후보 투표수 출력
		for (int j = 0; j < ip[i]; j++) // 표수만 * 출력)
			printf("*");
		printf("\n");
	}

	printf("무효표 : %d표 \n", ip[0]); // 무효표 출력
	printf("총투표수 : %d표 \n", n); //총 투표횟수 출력 충북대학교 소프트웨어학부
}

void ex0602() {
	int count1 = 0; //동전의 앞면
	int count2 = 0; //동전의 뒷면
	int flip[10] = { 0 };

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; i++) {
		flip[i] = rand() % 2;
		if (flip[i] == 1)
			count1++;
		else
			count2++;
	}
	printf("동전 앞면 : %d \n동전 뒷면: %d", count1, count2);
}

void ex0602()
{
	int number;
	int prime = 1;

	while (1) { // 무한 루프
		printf("소수를 판정할 정수를 입력하세요(1 이하의 수이면 종료): ");
		scanf("%d", &number);

		if (number >= 2) {
			for (int i = 2; i < number; i++) {
				if (number % i == 0) {
					prime = 0;
					break;
				}
			}
		}
		else {
			printf("%d에 대한 소수를 판정할 수 없습니다.\n", number);
			printf("프로그램을 종료합니다.\n");
			break;
		}
		if (prime == 1)
			printf("%d는 소수입니다.", number);
		else
			printf("%d는 소수가 아닙니다.", number);
		printf("\n");
	} // end of while
	return 0;
} // end of mai

void ex0603()
{
	int number, index;
	char* array; // 문자형 포인터

	printf("정수를 입력하세요: "); // 정수 입력
	scanf("%d", &number);

	if (number > 2)
	{
		array = (char*)calloc(number + 1, sizeof(char)); // 배열 동적 할당
		if (array != NULL)
		{
			printf("%d개의 배열을 할당하였습니다.\n", number + 1); // 에라토스테네스 호출
			double to = sqrt(number);

			for (int n = 2; n < to; n++) {
				double last = number / n;
				for (int m = 2; m < last; m++) {
					index = n * m;
					if (index <= number)
						array[index] = 1;
				}
			}
			for (int j = 2; j < number; j++) {
				if (array[j] == 0)
					printf("%d ", j);
			}
			free(array);
		}
	}
}

//7일차
int ifactorial(int n);
double dfactorial(double n);

void ex0701()
{
	int n; // 1부터 20까지 변하는 변수
	int ifact = 1; // 정수 팩토리얼 변수 선언 및 초기화
	double dfact = 1.0; // 실수 팩토리얼 변수 선언 및 초기화

	printf(" n 정수 팩토리얼 실수 팩토리얼\n"); // 제목 줄 인쇄
	printf("===============================================\n");
	for (n = 1; n <= 20; n++)
	{
		ifact = ifactorial(n); // 정수 팩토리얼
		dfact = dfactorial(n); // 실수 팩토리얼
		printf("%2d: %20d %20.0lf\n", n, ifact, dfact); // 결과 출력
	}
}

int ifactorial(int n)
{
	if (n == 1) // 순환함수 탈출 조건
		return 1;
	else
		return n * ifactorial(n - 1); // 순환 호출
}

double dfactorial(double n)
{
	if (n == 1.0) // 순환함수 탈출 조건
		return 1.0;
	else
		return n * dfactorial(n - 1); // 순환 호출
}

void ex0702()
{
	int n;
	double nexp, newexp, oldexp, fact;

	nexp = exp(1.0); // 자연대수 e (라이브러리 함수 사용) 
	printf(" n 자연대수 계산 오차\n");
	printf("================================================\n");

	n = 1; // 변수 초기화
	newexp = 0; // 새로 계산할 자연대수
	oldexp = -1.0; // 이전 자연대수. 초기에 oldexp와 newexp를 다르게 설정한다. 
	fact = 1.0; // 팩토리얼

	while (oldexp != newexp) // 이전 값과 새로운 값이 다르면 계속 반복
	{
		oldexp = newexp; // 이전 값으로 저장한다. 
		newexp = newexp + 1.0 / fact; // 새로 계산한다. 
		printf("%2d %20.18lf %20.18lf %20.18lf\n", n, nexp, newexp,
			fabs(nexp - newexp)); // 출력
		fact = fact * (double)n; // 다음을 위하여 팩토리얼을 미리 계산한다. 
		n = n + 1; // n을 증가시킨다.
	}
}

void ex0703(void) {
	int n, sign = -1;
	double PI, pi1, pi2, pi2sqr;

	PI = 4.0 * atan(1.0); //원주율 계싼
	printf("원주율=%10.8lf\n", PI);
	printf("==============================================\n");
	printf("항의 수\t공식1\t\t오차1\t\t공식2\t\t오차2\n"); // 제목 줄 출력
	printf("================================================\n");

	pi1 = 0.0;
	pi2sqr = 0.0;
	sign = -1;
	for (n = 1; n <= 10000; n++) {
		sign *= -1;
		pi1 += (double)sign * 4.0 / (2.0 * (double)n - 1.0);
		pi2sqr += 6.0 / ((double)n * (double)n);
		pi2 = sqrt(pi2sqr);
		if ((n % 1000 == 0))
			printf("%6d\t%10.8lf\t%10.8lf\t%10.8lf\t%10.8lf\n", n, pi1, fabs(PI - pi1), pi2, fabs(PI - pi2));
	}
}

#define YN(x) (1.0/(1.0 + (x))) 

double trapez(int steps); // 함수 선언

void ex0704()
{
	double log2, integ;
	int steps;

	log2 = log(2.0); // loge2
	printf(" 구간 log2 사다리꼴 적분 오차\n");
	printf("=======================================\n");

	for (steps = 10; steps <= 10000000; steps *= 10)
	{
		integ = log2; // 임시. 함수 호출로 대치할 부분
		integ = trapez(steps); // main()에서 함
		printf("%8d %20.18lf %20.18lf %20.18lf\n", steps, log2, integ, fabs(log2 - integ));
	}
}

double trapez(int steps) // 함수 구현
{
	double integral, h, x;
	int k;

	integral = 0.0;
	h = 1.0 / (double)steps;
	for (k = 0; k <= steps; k++) {
		x = h * (double)k;
		if ((k == 0) || (k == steps))
			integral += YN(x);
		else
			integral += 2.0 * YN(x);
	}
	integral = h * integral / 2.0;
	return integral;
}


void ex0706(void) {
	char board[3][3];
	int x, y, k, i;
	for (x = 0; x < 3; x++) // 보드를 초기화한다. 
		for (y = 0; y < 3; y++)
			board[x][y] = ' ';

	for (k = 0; k < 9; k++) {// 사용자로부터 위치를 받아서 보드에 표시한다. 
		printf("(x, y) 좌표: ");
		scanf(" %d %d", &x, &y);
		board[x][y] = (k % 2 == 0) ? 'X' : 'O'; // 순번에 따라 'X', 'O’중      
		for (i = 0; i < 3; i++) {// 보드를 화면에 그린다.   
			printf("---|---|---\n");
			printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		}
		printf("---|---|---\n");
	}
}


char board[3][3]; // Tic-Tac-Toe board
void init_board() {
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			board[i][j] = ' ';
		}
	}
}
int is_valid_move(int row, int col) {
	if (row < 0 || row >= 3 || col < 0 || col >= 3)
	{
		return 0;
	}
	if (board[row][col] != ' ') { return 0; }
	return 1;
}

int check_win(char symbol) {
	int i;
	// Check rows    
	for (i = 0; i < 3; i++) {
		if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) { return 1; }
	}
	// Check columns    
	for (i = 0; i < 3; i++) {
		if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) { return 1; }
	}
	// Check diagonals    
	if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) { return 1; }
	if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) { return 1; }
	return 0;
}
void computer_move() {
	int row, col;
	// Randomly select a valid move   
	do {
		row = rand() % 3;
		col = rand() % 3;
	} while (!is_valid_move(row, col));      board[row][col] = 'O';
}
int is_draw() {
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (board[i][j] == ' ') { return 0; }
		}
	}
	return 1;
}
void print_board() {
	int i, j;
	printf("\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			printf(" %c ", board[i][j]);
			if (j != 2) {
				printf("|");
			}
		}
		printf("\n");
		if (i != 2) {
			printf("---+---+---\n");
		}
	}
	printf("\n");
}
void ex0707(void) {
	srand(time(0));
	int row, col;
	int game_finished = 0;
	init_board();
	printf("Tic-Tac-Toe Game against Computer\n");
	while (!game_finished) {
		print_board();
		printf("Player, enter the row and column (e.g., 1 1): ");
		scanf("%d %d", &row, &col);
		if (!is_valid_move(row - 1, col - 1)) {
			printf("Invalid move! Try again.\n");
			continue;
		}
		board[row - 1][col - 1] = 'X';
		if (check_win('X')) {
			print_board();
			printf("Player wins!\n");
			game_finished = 1;
		}
		else if (is_draw()) {
			print_board();
			printf("It's a draw!\n");
			game_finished = 1;
		}
		else {
			// Computer's move
			computer_move();
			if (check_win('O')) {
				print_board();
				printf("Computer wins!\n");
				game_finished = 1;
			}
			else if (is_draw()) {
				print_board();
				printf("It's a draw!\n");
				game_finished = 1;
			}
		}
	}
}

