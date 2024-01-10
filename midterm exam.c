#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>

//1����
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

	printf("ù��° ��=");
	scanf("%d", &x);
	printf("�ι�° ��=");
	scanf("%d", &y);
	printf("����° ��=");
	scanf("%d", &z);
	printf("ū ��="); printf("%d\n", (x > y) ? (x > z) ? x : z : (y > z) ? y : z);
	printf("���� ��="); printf("%d\n", (x < y) ? (x < z) ? x : z : (y < z) ? y : z);
}

//2����
#include <stdio.h>

void ex0201() {
	int kor, mat, eng, sum;
	float total;
	char grade;

	printf("���� ���� ���� (0~99)�Է�\n");
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

	printf("���� ���� ���� ���� ��� ����\n");
	printf("%d   %d   %d   %d  %.1f   %c\n", kor, mat, eng, sum, total, grade);
}

void ex0202() {
	int a, b, c;

	printf("�ﰢ���� 3���� �Է��Ͻÿ�:");
	scanf("%d %d %d", &a, &b, &c);

	if (a + b > c) {
		if (b + c > a) {
			if (a + c > b)
				printf("�ùٸ� �ﰢ��");
			else
				printf("�ùٸ��� ���� �ﰢ��");
		}
		else
			printf("�ùٸ��� ���� �ﰢ��");
	}
	else
		printf("�ùٸ��� ���� �ﰢ��");
}

void ex0203() {
	int num, sum = 0;

	do {
		printf("������ �Է��Ͻÿ�.\n");
		scanf("%d", &num);
		sum += num;
	} while (num != 0);

	printf("%d", sum);
}

void ex0204(void) {
	int score[5];
	srand((unsigned int)time(NULL)); //����ؼ� �����Ǵ� ��(�ð��� ����)
	// rand()���� �ð����� �ٲٰ� �ʹ�!
	for (int i = 0; i < 5; i++) {
		score[i] = rand();
		printf("score[%d]=%d\n", i, (int)score[i] % 100);
		//100������ ���� ǥ���ϱ����� 100�� ���� ����Ͽ���.
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
	float grade[3] = { 0,0,0 };  //�л��� ������ ������ �����ϴ� �迭
	float avg[3] = { 0,0,0 };  //�л����� ���������� �����ϴ� �迭
	int arry[3][5] = {
	{1,87,98,80,76},
	{2,99,89,90,90},
	{3,65,68,50,49}
	};

	for(int i = 0; i < 3; i++) {
		grade[i] = arry[i][1] + arry[i][2] + arry[i][3] + arry[i][4];
	}

	for (int i = 0; i < 3; i++) {
		avg[i] += grade[i] / 4.0; //�л��� ���� ����
		avg_fin += avg[i]; //��ü �л��� ������ ��
	}

	for (int i = 0; i < 3; i++) {
		printf("�й� : %d , �������� : %lf\n", arry[i][0], avg[i]);
	}
	printf("�������� = %lf", avg_fin / 3.0);
}


//��������
void ex0207() {
	int index = 0, num = 0, count = 0;
	int array[6] = { 5,3,8,1,2,7 };
	int tmp, i;

	do {
		index = num; //1���� �ݺ����� index�� �ּڰ��� ������ �迭�� ���ҹ�ȣ�� �ӽ÷� �����Ѵ�.
		for (i = num + 1; i < 6; i++) { //�迭�� �ּڰ��� ã�´�.
			if (array[i] < array[index]) {
				index = i; //�ּڰ��� ���� �迭�� ���ҹ�ȣ�� index�� ���
			}
		}
		tmp = array[num];  //array[num]�� array[index]�� ��ȯ�Ѵ�.
		array[num] = array[index];
		array[index] = tmp;

		num++;  //���� array[num]�� ���ϰڴ�.
		count++;
	} while (count < 6);

	for (int i = 0; i < 6; i++) {
		printf("%d ", array[i]);
	}

}

//3����

void ex0301(void) {
	int data = 0x0A0B0C0D;
	char* pc;
	short* ps;
	int* pi;
	pc = (char*)&data;
	ps = (short*)&data;
	pi = (int*)&data;
	for (int i = 0; i < 4; i++) { //1����Ʈ�� �д´�.
		printf("*(pc + %d) = %02X \n", i, *(pc + i));
	}
	for (int i = 0; i < 2; i++) { //2����Ʈ�� �д´�.
		printf("*(ps + %d) = %04X \n", i, *(ps + i));
	}
	for (int i = 0; i < 2; i++) { //4����Ʈ �д´�.
		printf("*(pi + %d) = %04X \n", i, *(pi + i));
	}
}

// ����� y������ ���
int get_line_parameter(int x1, int y1, int x2, int y2, float* slope, float* yintercept)
{
	if (x1 == x2)
		return -1;
	else {
		*slope = (float)(y2 - y1) / (float)(x2 - x1); //���� ���
		*yintercept = y1 - (*slope) * x1;  // y���� ���
		return 0;
	}
}

void ex0302(void)
{
	float s, y;
	if (get_line_parameter(3, 3, 6, 6, &s, &y) == -1) //x1�� x2�� ���ٸ�
		printf("����\n");
	else
		printf("����� %f, y������ %f\n", s, y);
}

void ex0303(void)
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int(*pa)[5];
	int i;
	pa = &a;

	for (i = 0; i < 5; i++)
		printf("%d \n", (*pa)[i]); //�����͹迭 ��½� (*pa)[i]�� ���
}

void ex0303_(int argc, char* argv[])
{
	int i = 0;
	for (i = 0; i < argc; i++)
		printf("��ɾ� ���ο��� %d��° ���ڿ� = %s\n", i, argv[i]);
}


struct student {
	int number;
	char name[10];
	double grade;
};

void ex0304(void)
{
	struct student s;

	printf("�й��� �Է��Ͻÿ�: ");
	scanf("%d", &s.number);
	printf("�̸��� �Է��Ͻÿ�: ");
	scanf("%s", s.name); //���ڿ��� s.name�� 
	printf("������ �Է��Ͻÿ�(�Ǽ�): ");
	scanf("%lf", &s.grade);

	printf("�й�: %d\n", s.number);
	printf("�̸�: %s\n", s.name);
	printf("����: %f\n", s.grade);
}

struct student_ {
	int number;
	char name[20];
	double grade;
};

void ex0305(void)
{
	struct student_ list[100];	// ����ü�� �迭 ����
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 100; i++) {
		list[i].number = i;
		strcpy(list[i].name, "student");
		list[i].grade = rand() % 100;

		printf("�й�: %d\n", list[i].number);
		printf("�̸�: %s\n", list[i].name);
		printf("����: %.1lf\n", list[i].grade);
	}
}

//4����
void ex0401() {
	char dept[20], name[20]; // �������� ����
	int grade, year; // �������� ����
	printf("������ �Է��ϼ���.\n\n"); // �ȳ��� ���
	printf("�а�: "); // �ȳ��� ���
	scanf("%s", dept); // �а� �Է�
	printf("�г�: "); // �ȳ��� ���
	scanf("%d", &grade); // �г� �Է�
	printf("���г⵵: "); // �ȳ��� ���
	scanf("%d", &year); // ���г⵵ �Է�
	printf("�̸�: "); // �ȳ��� ���
	scanf("%s", name); // �̸� �Է�
	// �ڱ�Ұ� ���
	printf("\n���� %s %d�г� %d�й� %s�Դϴ�.\n", dept, grade, year, name);
}

float max_(float a, float b, float c);
float min_(float a, float b, float c);

void ex0402(void) {
	float num1, num2, num3;
	float max, min;
	float diff;

	printf("�� ���� ���� �Է��ϼ���.\n\n"); // ������ �Է�
	printf("ù ��° ��: "); scanf("%f", &num1);
	printf("�� ��° ��: "); scanf("%f", &num2);
	printf("�� ��° ��: "); scanf("%f", &num3);

	max = max_(num1, num2, num3);
	min = min_(num1, num2, num3);


	diff = max - min;
	printf("\n���� ū ���� ���� ���� ����=%f\n", diff);
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
	printf("10���� ���� �Է��Ͻÿ�:\n");
	for (int i = 0; i < 10; i++) {
		printf("%d��° ��: ", i + 1);
		scanf("%d", &score[i]); //���� �Է��ϹǷ� &score[i]
	}
}

float avg_() {
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += score[i];
	}
	return (float)sum / num; //float������ ��ȯ�ؾ� �ϱ� ������ int�� ���� sum�� float������ �ڷ����� ��ȯ�Ѵ�.
}

void ex0403(void) {
	float avg;

	input();
	avg = avg_();
	printf("��� = %f", avg);

	return 0;
}

//5����
unsigned int get_integer() {
	unsigned char* value;
	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &value);
	return value;
}

void ex0501(void) {
	unsigned char x = get_integer();
	unsigned char y = get_integer();
	printf("�μ��� %u %u�Դϴ�. \n", x, y);
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

	printf("������ �ո�: %d \n", heads);
	printf("������ �޸�: %d \n", tails);
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
	printf("���� %lf�Դϴ�.\n", answer);
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
	printf("%d�� ��� : ", num2);
	for (int i = 2; i <= num2; i++) {
		if (num2 % i == 0)
			printf("%d ", i);
	}
}

void ex0504(void)
{
	int number; // ���� ������ ����
	while (1) // ���� �ݺ�
	{
		printf("����� ���� ������ �Է��ϼ���(1 ������ ���� ����): ");
		scanf("%d", &number); // ������ �Է�

		if (number >= 2) { // ����� ���� �� �ִٸ�
			function(number);
		}
		else { // ����� ���� �� ���ٸ�
			printf("%d�� ���� ����� ���� �� �����ϴ�.\n", number);
			printf("���α׷��� �����մϴ�.\n");
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
	int number; // ���� ������ ����
	printf("1000 ���� ������ ��� : \n");
	for (number = 2; number <= 1000; number++) {
		if (number == sum12(number))
			printf("%d\n", number);
	}
}

//6����
#define NMAX 5

void ex0601()
{
	int ip[NMAX], n, xdata = 0, i;
	n = 0;

	for (i = 0; i < NMAX; ++i)
	{
		ip[i] = 0; // �迭 0���� �ʱ�ȭ
	}

	srand((unsigned int)time(NULL));

	printf("1~4�� �� �� �ĺ��� ��ȣ�� �Է��Ͻÿ� :");
	int count = 0;

	while (count < 100) // �Էµ� �����Ͱ� ��ȣ�� ���� (���� �Է� �� �ݺ��� Ż��)
	{
		xdata = rand() % 5;
		printf("%d�� �ĺ��� : %d ����\n", n + 1, xdata);
		n++; // �� ��ǥ Ƚ�� ����
		if (xdata<1 || xdata>NMAX) { // 1~4 �̿��� ���� �Է� ��
			++ip[0]; //��ȿ ǥ �� ����
			count++;
		}
		else { // 1~4 ������ ���̸�
			++ip[xdata]; //�ش� �ĺ���ǥ�� ����
			count++;
		}
	}

	printf("\n��ǥ��\n");
	for (i = 1; i < NMAX; i++) {
		printf("%d�� : %d ǥ", i, ip[i]); // 1~4�� �ĺ� ��ǥ�� ���
		for (int j = 0; j < ip[i]; j++) // ǥ���� * ���)
			printf("*");
		printf("\n");
	}

	printf("��ȿǥ : %dǥ \n", ip[0]); // ��ȿǥ ���
	printf("����ǥ�� : %dǥ \n", n); //�� ��ǥȽ�� ��� ��ϴ��б� ����Ʈ�����к�
}

void ex0602() {
	int count1 = 0; //������ �ո�
	int count2 = 0; //������ �޸�
	int flip[10] = { 0 };

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; i++) {
		flip[i] = rand() % 2;
		if (flip[i] == 1)
			count1++;
		else
			count2++;
	}
	printf("���� �ո� : %d \n���� �޸�: %d", count1, count2);
}

void ex0602()
{
	int number;
	int prime = 1;

	while (1) { // ���� ����
		printf("�Ҽ��� ������ ������ �Է��ϼ���(1 ������ ���̸� ����): ");
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
			printf("%d�� ���� �Ҽ��� ������ �� �����ϴ�.\n", number);
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		if (prime == 1)
			printf("%d�� �Ҽ��Դϴ�.", number);
		else
			printf("%d�� �Ҽ��� �ƴմϴ�.", number);
		printf("\n");
	} // end of while
	return 0;
} // end of mai

void ex0603()
{
	int number, index;
	char* array; // ������ ������

	printf("������ �Է��ϼ���: "); // ���� �Է�
	scanf("%d", &number);

	if (number > 2)
	{
		array = (char*)calloc(number + 1, sizeof(char)); // �迭 ���� �Ҵ�
		if (array != NULL)
		{
			printf("%d���� �迭�� �Ҵ��Ͽ����ϴ�.\n", number + 1); // �����佺�׳׽� ȣ��
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

//7����
int ifactorial(int n);
double dfactorial(double n);

void ex0701()
{
	int n; // 1���� 20���� ���ϴ� ����
	int ifact = 1; // ���� ���丮�� ���� ���� �� �ʱ�ȭ
	double dfact = 1.0; // �Ǽ� ���丮�� ���� ���� �� �ʱ�ȭ

	printf(" n ���� ���丮�� �Ǽ� ���丮��\n"); // ���� �� �μ�
	printf("===============================================\n");
	for (n = 1; n <= 20; n++)
	{
		ifact = ifactorial(n); // ���� ���丮��
		dfact = dfactorial(n); // �Ǽ� ���丮��
		printf("%2d: %20d %20.0lf\n", n, ifact, dfact); // ��� ���
	}
}

int ifactorial(int n)
{
	if (n == 1) // ��ȯ�Լ� Ż�� ����
		return 1;
	else
		return n * ifactorial(n - 1); // ��ȯ ȣ��
}

double dfactorial(double n)
{
	if (n == 1.0) // ��ȯ�Լ� Ż�� ����
		return 1.0;
	else
		return n * dfactorial(n - 1); // ��ȯ ȣ��
}

void ex0702()
{
	int n;
	double nexp, newexp, oldexp, fact;

	nexp = exp(1.0); // �ڿ���� e (���̺귯�� �Լ� ���) 
	printf(" n �ڿ���� ��� ����\n");
	printf("================================================\n");

	n = 1; // ���� �ʱ�ȭ
	newexp = 0; // ���� ����� �ڿ����
	oldexp = -1.0; // ���� �ڿ����. �ʱ⿡ oldexp�� newexp�� �ٸ��� �����Ѵ�. 
	fact = 1.0; // ���丮��

	while (oldexp != newexp) // ���� ���� ���ο� ���� �ٸ��� ��� �ݺ�
	{
		oldexp = newexp; // ���� ������ �����Ѵ�. 
		newexp = newexp + 1.0 / fact; // ���� ����Ѵ�. 
		printf("%2d %20.18lf %20.18lf %20.18lf\n", n, nexp, newexp,
			fabs(nexp - newexp)); // ���
		fact = fact * (double)n; // ������ ���Ͽ� ���丮���� �̸� ����Ѵ�. 
		n = n + 1; // n�� ������Ų��.
	}
}

void ex0703(void) {
	int n, sign = -1;
	double PI, pi1, pi2, pi2sqr;

	PI = 4.0 * atan(1.0); //������ ���
	printf("������=%10.8lf\n", PI);
	printf("==============================================\n");
	printf("���� ��\t����1\t\t����1\t\t����2\t\t����2\n"); // ���� �� ���
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

double trapez(int steps); // �Լ� ����

void ex0704()
{
	double log2, integ;
	int steps;

	log2 = log(2.0); // loge2
	printf(" ���� log2 ��ٸ��� ���� ����\n");
	printf("=======================================\n");

	for (steps = 10; steps <= 10000000; steps *= 10)
	{
		integ = log2; // �ӽ�. �Լ� ȣ��� ��ġ�� �κ�
		integ = trapez(steps); // main()���� ��
		printf("%8d %20.18lf %20.18lf %20.18lf\n", steps, log2, integ, fabs(log2 - integ));
	}
}

double trapez(int steps) // �Լ� ����
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
	for (x = 0; x < 3; x++) // ���带 �ʱ�ȭ�Ѵ�. 
		for (y = 0; y < 3; y++)
			board[x][y] = ' ';

	for (k = 0; k < 9; k++) {// ����ڷκ��� ��ġ�� �޾Ƽ� ���忡 ǥ���Ѵ�. 
		printf("(x, y) ��ǥ: ");
		scanf(" %d %d", &x, &y);
		board[x][y] = (k % 2 == 0) ? 'X' : 'O'; // ������ ���� 'X', 'O����      
		for (i = 0; i < 3; i++) {// ���带 ȭ�鿡 �׸���.   
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

