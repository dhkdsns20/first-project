#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//stage 3
void ex01(void) {
    int n, m;
    scanf("%d", &n);

    for (m = 1; m < 10; m++) {
        printf("%d * %d = %d\n", n, m, n * m);
    }
}

void ex02() {
    int n;
    int A, B;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &A, &B);
        printf("%d\n", A + B);
    }
}

void ex03() {
    int n, sum = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    printf("%d", sum);
}

void ex04() {
    double total, price, sum;
    int n, index;

    scanf("%lf", &total);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf %d", &price, &index);
        sum += price * index;
    }

    if (total == sum)
        printf("Yes");
    else
        printf("No");
}

void ex05() {
    int n, longs;
    scanf("%d", &n);
    longs = n / 4;
    for (int i = 0; i < longs; i++) {
        printf("long ");
    }printf("int");
}

void ex06() {
    int n;
    int A, B;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &A, &B);
        printf("%d\n", A + B);
    }
}

void ex07() {
    int n;
    int A, B;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d\n", i + 1, A + B);
    }
}

void ex08() {
    int n;
    int A, B;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d + %d = %d\n", i + 1, A, B, A + B);
    }
}

void ex09() {
    int n;
    scanf("%d", &n);

    for (int j = 0; j < n; j++) {
        for (int i = 0; i <= j; i++) {
            printf("*");
        }printf("\n");
    }
}

void ex10() {
    int n;
    scanf("%d", &n);

    for (int j = 0; j < n; j++) {
        for (int m = n - 1; m > j; m--) {
            printf(" ");
        }
        for (int i = 0; i <= j; i++) {
            printf("*");
        }printf("\n");
    }
}

void ex11() {
    int A, B;

    while (1) {
        scanf("%d %d", &A, &B);
        if (A == 0 && B == 0)
            break;
        else
            printf("%d\n", A + B);

    }
}
//EOF(end of file) ������ ���� ������ ����
void ex12() {
    int A, B;

    while (scanf("%d %d", &A, &B) != EOF) {
        printf("%d\n", A + B);
    }
}


//stage 4
void ex0401() {
    int n, input, count = 0;
    int arr[100] = { 0 };
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d ", &arr[i]);
    }
    scanf("%d", &input);
    for (int i = 0; i < n; i++) {
        if (arr[i] == input)
            count++;
    }
    printf("%d", count);
}

void ex0402() {
    int n, x, count = 0;
    int arr[10000] = { 0 };
    scanf("%d %d\n", &n, &x);

    for (int i = 0; i < n; i++) {
        scanf("%d ", &arr[i]);
        if (arr[i] < x)
            printf("%d ", arr[i]);
    }
}


void ex0403() {
    int n, max, min;

    scanf("%d", &n);
    int arr[1000000] = { 0 };
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max = min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];

        if (arr[i] < min)
            min = arr[i];
    }
    printf("%d %d", min, max);
}

void ex0404() {
    int n, index = 0, max = 0;
    int arr[9] = { 0 };
    for (int i = 0; i < 9; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < 9; i++) {
        if (arr[i] > max) {
            index = i;
            max = arr[i];
        }
    }printf("%d\n%d", max, index + 1);
}

void ex0405() {
    int i, j, k;
    int n, m;
    int arr[100] = { 0 };
    scanf("%d %d", &n, &m);
    for (int a = 0; a < m; a++) {
        scanf("%d %d %d", &i, &j, &k);
        for (int b = i - 1; b < j; b++) {
            arr[b] = k;
        }
    }
    for (int c = 0; c < n; c++) {
        printf("%d ", arr[c]);
    }
}


void swap(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
void ex0406() {
    int i, j;
    int n, m;
    int arr[100] = { 0 };
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) { //�ʱ�ȭ ��Ų��.
        arr[i] = i;
    }

    for (int a = 0; a < m; a++) {
        scanf("%d %d", &i, &j);
        swap(&arr[i], &arr[j]);
    }

    for (int b = 1; b <= n; b++) {
        printf("%d ", arr[b]);
    }
}

void ex0407() {
    int num[30] = { 0 };
    int n, m;
    int index;
    //index���� �迭�� �����ع����� �Էµ� ���� ���׹����϶� i�� �Էµ� ���� ��ġ���� �ʴ´�.
    for (int i = 0; i < 28; i++) {
        scanf("%d", &index);
        num[index - 1] += 1;
    }
    for (int i = 0; i < 30; i++) {
        if (num[i] == 0)
            printf("%d\n", i + 1);
    }
}

void ex0408() {
    int n, count = 0;
    int other[10] = { 0 };

    for (int i = 0; i < 10; i++) {
        scanf("%d", &n);
        other[i] = n % 42;
    }
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (other[i] == other[j])
                other[i] = -1;
        }
    }
    for (int i = 0; i < 10; i++) {
        if (other[i] != -1)
            count++;
    }
    printf("%d", count);
}


void ex0409() {
    int i, j;
    int n, m;
    int arr[100] = { 0 };
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) { //�ʱ�ȭ ��Ų��.
        arr[i] = i;
    }

    for (int a = 0; a < m; a++) {
        scanf("%d %d", &i, &j);
        for (int b = i; b <= j; b++) {
            swap(&arr[b], &arr[j]);
            j--;
        }
    }

    for (int b = 1; b <= n; b++) {
        printf("%d ", arr[b]);
    }
}

void ex0410() {
    int n;
    scanf("%d", &n);
    double arr[n], sum;
    double max = arr[0];


    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
    }
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] / max * 100;
        sum += arr[i];
    }printf("%lf", sum / n);
}

//stage 5
void ex0501() {
    char words[1000];
    int count;

    scanf("%s", words);
    scanf("%d", &count);
    printf("%c", words[count - 1]);
}

void ex0502() {
    char s[100];
    int count = 0;
    scanf("%s", s);
    for (int i = 0; i < 100; i++) {
        if (s[i] == '\0')
            break;
        count++;
    }
    printf("%d", count);
}

void ex0503() {
    int n;
    char a[100];

    scanf("%d", &n);

    while (n--) {
        scanf("%s", a);
        printf("%c%c \n", a[0], a[strlen(a) - 1]);
    }
}

void ex0504() {
    char n;
    scanf("%s", &n);
    printf("%d", n);
}

//���� ���� ���� ���ϱ�
void ex11720() {
    int n, sum = 0;
    char arr[100];

    scanf("%d", &n);
    scanf("%s", arr);
    for (int i = 0; i < n; i++) {
        sum += arr[i] - '0';
    }printf("%d", sum);
}

//���ĺ� ã��
void ex10809() {
    char arr[100];
    int index[26] = { 0 };
    scanf("%s", arr);

    for (int i = 0; i < strlen(arr); i++) {
        if (index[arr[i] - 'a'] == 0) index[arr[i] - 'a'] = i + 1;
    }
    for (int k = 0; k < 26; k++) {
        if (index[k] == 0) printf("-1 ");
        else printf("%d ", index[k] - 1); //��� 
    }
}

//�״�� ����ϱ�
void ex11718() {
    char a;
    while (scanf("%c", &a) == 1) {
        printf("%c", a);
    }
}

//���ڿ� �ݺ�
void ex2675() {
    int n, cnt = 0;
    char arr[20];
    scanf("%d", &n);

    for (int k = 0; k < n; k++) {
        scanf("%d %s", &cnt, arr);

        for (int i = 0; i < strlen(arr); i++) {
            for (int j = 0; j < cnt; j++) {
                printf("%c", arr[i]);
            }
        }printf("\n");
    }
}

//�ܾ��� ����
void ex1152() {
    char word[1000000];
    int count = 0, len;

    scanf("%[^\n]s", word);
    len = strlen(word);

    if (len == 1 && word[0] == ' ') {
        printf("%d", count);
        //return 0;
    }
    for (int i = 0; i < len; i++) {
        if (word[i] == ' ') {
            count++;
        }
    }
    printf("%d", count + 1);
}

//��� 2908��

void ex2908() {
    char a[5], b[5];
    int num1, num2;
    scanf("%s %s", a, b);
    char temp;
    temp = a[0]; a[0] = a[2]; a[2] = temp;
    temp = b[0]; b[0] = b[2]; b[2] = temp;

    if (atoi(a) > atoi(b))     //#include <stdlib.h> 
        printf("%c%c%c", a[0], a[1], a[2]);
    else if (atoi(a) == atoi(b))
        printf("same");
    else
        printf("%c%c%c", b[0], b[1], b[2]);
}

//���̾�
void ex5622() {
    char arr[15];
    int count = 0;
    scanf("%s", arr);

    for (int i = 0; i < strlen(arr); i++) { //�ƽ�Ű�ڵ带 Ȱ���� �ڵ� ����ȭ
        if (arr[i] >= 65 && arr[i] <= 67) { count += 3; }
        if (arr[i] >= 68 && arr[i] <= 70) { count += 4; }
        if (arr[i] >= 71 && arr[i] <= 73) { count += 5; }
        if (arr[i] >= 74 && arr[i] <= 76) { count += 6; }
        if (arr[i] >= 77 && arr[i] <= 79) { count += 7; }
        if (arr[i] >= 80 && arr[i] <= 83) { count += 8; }
        if (arr[i] >= 84 && arr[i] <= 86) { count += 9; }
        if (arr[i] >= 87 && arr[i] <= 90) { count += 10; }
    }
    printf("%d", count);
}

//stage6 ��ȭ1

//����
void ex25083(void) {
    printf("         ,r'\"7\n"); // ���� ����ǥ, ū ����ǥ ����� ���ؼ��� �տ� '\'�� �߰� 
    printf("r`-_   ,\'  ,/\n");
    printf(" \\. \". L_r\'\n"); // '\' ����� ���ؼ��� '\\' �Է�
    printf("   `~\\/\n");
    printf("      |\n");
    printf("      |\n");
}

//ü��
void ex3003() {
    int arr1[6] = { 1,1,2,2,2,8 };
    int arr2[6] = { 0 };
    for (int i = 0; i < 6; i++) {
        scanf("%d", &arr2[i]);
        arr1[i] -= arr2[i];
    }
    for (int i = 0; i < 6; i++) {
        printf("%d ", arr1[i]);
    }
}

//�����-7
void ex2444() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = n - i; j > 0; j--)printf(" ");
        for (int k = 2 * i - 1; k > 0; k--)printf("*");
        printf("\n");
    }
    for (int i = n - 1; i > 0; i--) {
        for (int j = n - i; j > 0; j--)printf(" ");
        for (int k = 2 * i - 1; k > 0; k--)printf("*");
        printf("\n");
    }
    return 0;
}

//�Ӹ�������� Ȯ���ϱ�
void ex10988() {
    char arr[100];
    int num = 0;
    scanf("%s", &arr);
    for (int i = 0; i < strlen(arr) / 2; i++) {
        if (arr[i] != arr[strlen(arr) - 1 - i])
            num = 1;
    }
    if (num == 1)
        printf("0");
    else
        printf("1");
}

//�ܾ����
char a[1000005];
int arr[26];

void ex1157() {
    int max = 0;
    char ans;

    scanf("%s", a); //���ڿ��� �Է¹޴´�.

    for (int i = 0; i < strlen(a); i++) //���ڿ� ũ�⸸ŭ �ݺ�
        if (a[i] >= 'a') arr[a[i] - 'a']++; //�ҹ��� ��
        else arr[a[i] - 'A']++; //�빮�� ����

    for (int i = 0; i < 26; i++) //
        if (arr[i] == max) {
            ans = '?';
        }
        else if (arr[i] > max) {
            max = arr[i]; //max���� �󵵰� ���� �ܾ max�� ����
            ans = 'A' + i; //'A'(=65)�� ���� �빮�ڷ� ���
        } printf("%c", ans);
}

//ũ�ξ�Ƽ�� ���ĺ���
void ex2941() {
    char s[100];
    scanf("%s", &s);
    int cnt = 0, i = 0;

    while (i < strlen(s)) {
        if (s[i] == 'c') {
            if (s[i + 1] == '=')
                i++;
            else if (s[i + 1] == '-')
                i++;
        }
        else if (s[i] == 'd') {
            if (s[i + 1] == '-')
                i++;
            else if (s[i + 1] == 'z' && s[i + 2] == '=')
                i += 2;
        }
        else if (s[i] == 'l') {
            if (s[i + 1] == 'j')
                i++;
        }
        else if (s[i] == 'n') {
            if (s[i + 1] == 'j')
                i++;
        }
        else if (s[i] == 's') {
            if (s[i + 1] == '=')
                i++;
        }
        else if (s[i] == 'z') {
            if (s[i + 1] == '=')
                i++;
        }

        cnt++;
        i++;
    }

    printf("%d", cnt);
}

//�׷� �ܾ� üĿ
void ex1316()
{

    char input_words[101]; //���ڿ� �迭
    int N; //input �� N
    scanf("%d", &N);


    int count = N;

    for (int i = 0; i < N; i++)
    {
        char first = '0';
        int Alphabet[26] = { 0, };
        scanf("%s", input_words);
        for (int j = 0; input_words[j] != '\0'; j++)
        {
            if (first != input_words[j]) //���ӵ� ��� ���
            {
                first = input_words[j];
                Alphabet[input_words[j] - 'a'] += 1;
            }
            if (Alphabet[input_words[j] - 'a'] == 2)
            {
                count -= 1;
                break;
            }
        }
    }
    printf("%d", count);
}

//���� ������
void ex25206(void)
{
    double score;
    char subject[50];
    char major[2];
    double sum, sumScore, majorScore = 0.0;
    for (int i = 0; i < 20; i++) {
        scanf("%s %lf %s", subject, &score, major);
        if (major[0] == 'P') {
            continue;
        }
        sumScore += score; //sumScore�� ��ü����
        if (major[0] == 'F') {
            continue;
        }
        else if (major[0] == 'A') {
            majorScore = 4;
        }
        else if (major[0] == 'B') {
            majorScore = 3;
        }
        else if (major[0] == 'C') {
            majorScore = 2;
        }
        else {
            majorScore = 1;
        }
        if (major[1] == '+') { //+�� ������ 0.5���� ���Ѵ�.
            majorScore += 0.5;
        }
        sum += score * majorScore; //����*����
    }
    printf("%lf", sum / sumScore);
}





//stage7 2���� �迭

//��� ����
void ex2738() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr1[n][m], arr2[n][m], sum[n][m];


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", sum[i][j]);
        }printf("\n");
    }
}

//�ִ� 
void ex2566() {
    int arr[9][9];
    int max = -1, x = 0, y = 0;
    //����� ���� ��� 0�϶� x,y�� �����Ⱚ�� �� �ִ�.

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
                x = i; y = j;
            }
        }
    }printf("%d\n%d %d", max, x + 1, y + 1);
}

//�����б�
void ex10798() {
    char arr[5][15] = { 0 }; //0���� �ʱ�ȭ!
    for (int i = 0; i < 5; i++) {
        scanf("%s", &arr[i]);
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[j][i] == '\0')
                continue;
            else
                printf("%c", arr[j][i]);
        }
    }
}

//������
void ex2563() {
    int sum = 0, cnt = 0, x = 0, y = 0;
    int arr[100][100] = { 0 };

    scanf("%d", &cnt); //�������� ��

    for (int i = 0; i < cnt; i++) {
        scanf("%d %d", &x, &y);

        for (int j = x; j < x + 10; j++) {
            for (int k = y; k < y + 10; k++) {
                arr[j][k] = 1;        // �迭�� 1������
            }
        }
    }

    for (int j = 0; j < 100; j++) {
        for (int k = 0; k < 100; k++) {
            if (arr[j][k] == 1)
                sum++;        // �迭�� 1�� ������ ���Ѵ�.
        }
    }printf("%d", sum);
}
//stage 8 �Ϲ� ���� 1

//���� ��ȯ
void ex2745() {
    char input[10000];
    int B;
    int result = 0;

    scanf("%s %d", input, &B);      //���ڿ� ������ �Է¹���

    int len = strlen(input);        //���ڿ� ���� ���ϱ�

    for (int i = 0; i < len; i++) {

        if (input[i] >= '0' && input[i] <= '9') {
            input[i] = input[i] - '0';
        }
        else if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = input[i] - 'A' + 10;
        }
        result += input[i] * pow(B, len - 1 - i);      //���� ��ȯ ��
    }
    printf("%d", result);
}

//���� ��ȯ 2
void convert(int N, int B)
{
    if (N != 0) {
        convert(N / B, B);
        if (N % B > 9 && B > 10)
            printf("%c", 'A' + N % B - 10);
        else
            printf("%d", N % B);
    }
}

void ex11005() {
    int N;
    int B;
    scanf("%d", &N);
    scanf("%d", &B);

    convert(N, B);
    return 0;
}



//��Ź�� ���� ����
void ex2720() {
    int a; //�׽�Ʈ���̽�
    int q, d, n, p; //������� ����(0.25),����(0.20),����(0.05),���(0.01)
    int num;
    scanf("%d", &a);
    for (int i = 0; i < a; i++) {
        scanf("%d", &num);
        q = num / 25; num = num % 25;
        d = num / 10; num = num % 10;
        n = num / 5;  num = num % 5;
        p = num / 1;
        printf("%d %d %d %d\n", q, d, n, p);
    }
}

//�߾� �̵� �˰���
void ex2903() {
    int n; //���簢���� ��
    int num; //���ο� ������ �ִ� ���� ����
    scanf("%d", &n);
    num = pow(2, n - 1);
    num = 2 * num + 1;

    printf("%d", num * num);
}

//����
void ex2292() {
    int start = 1, n = 1;
    int num, end, index;

    scanf("%d", &num);

    if (num == 1)
        index = 1;
    else {
        start = 2;
        while (1) {
            end = start + 6 * n - 1; //������ Ȯ��
            if (start <= num && num <= end) { //���� ���� �ִٸ�
                index = n + 1; //�ε����� n����
                break;
            }
            else { //n����
                n++;
                start += 6 * n - 6;
            }
        }
    }
    printf("%d", index);
}

//�м�ã��
void ex1193() {
    int num, i = 0, j = 0, count = 1, n = 1, end = 0, index = 0, start = 0;
    scanf("%d", &num);

    //num�� ���° �밢������ �Ǵ�
    if (num == 1)
        index = 0;
    else {
        start = 2;
        end = start + 1;
        while (1) {
            if (start <= num && num <= end) { //���� ���� �ִٸ�
                index = n; //�ε����� n����
                break;
            }
            else { //n����
                start = end + 1; //������ ���� 
                n++;
                end = start + n;
            }
        }
    }

    if (index == 0)
        printf("1/1");
    else {
        if (index % 2 == 0) { //¦�� count
            printf("%d/%d", index + 1 - num % start, 1 + num % start);
        }
        else { //Ȧ�� count
            printf("%d/%d", 1 + num % start, index + 1 - num % start);
        }
    }

}

//�����̴� �ö󰡰� �ʹ�.
int main() {
    int a, b, v;
    int day = 1;
    scanf("%d %d %d", &a, &b, &v);
    day = (v - b - 1) / (a - b) + 1;
    printf("%d", day);

}




//stage 9 ���,����� �Ҽ�

//����� ���
void ex5086() {
    int a, b;
    while (1) {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0)
            break;
        if (a > b) { //���
            if (a % b == 0)
                printf("multiple\n");
            else
                printf("neither\n");
        }
        else if (a < b) {// ���
            if (b % a == 0)
                printf("factor\n");
            else
                printf("neither\n");
        }
    }
}

//��� ���ϱ�
void ex2501() {
    int index = 1, n, k;
    int s[10000];
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) { //��� ã��
        if (n % i == 0) {
            s[index++] = i;
        }
    }
    if (index < k)
        printf("0");
    else
        printf("%d", s[k]);
}


//������� ��
void ex9506() {
    int n, k = 0, sum = 0;
    int s[1000];

    while (1) {
        scanf("%d", &n);
        if (n == -1)
            break;
        sum = 0; k = 0;//�� �� �ʱ�ȭ
        for (int a = 0; a < 1000; a++) { //��� ����迭 �ʱ�ȭ
            s[a] = 0;
        }
        for (int i = 1; i < n; i++) { //��� ã��
            if (n % i == 0) {
                s[k++] += i;
                sum += i;
            }
        }
        if (sum == n) { //���������
            printf("%d = ", n);
            for (int j = 0; j < k; j++)
                if (j != k - 1)
                    printf("%d + ", s[j]);
                else
                    printf("%d\n", s[j]);
        }
        else { //�������� �ƴϸ�
            printf("%d is NOT perfect.\n", n);
        }
    }
}

//�Ҽ� ã��
void ex1978() {
    int n;
    scanf("%d", &n);
    int s[n];
    int index = 0, sum = 0;

    for (int i = 0; i < n; i++) {
        sum = 0;
        scanf("%d", &s[i]); //���� �Է¹޴´�.
        for (int j = 2; j <= s[i]; j++) { //�Ҽ� ����
            if (s[i] % j == 0) //���(�ڱ��ڽ�����)
                sum += j;
        }
        if (sum != 1 && sum == s[i])
            index++;
    }printf("%d", index);
}

//�Ҽ�
void ex2581() {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    int min = 0, sum = 0, total = 0;

    for (int i = n; i <= m; i++) {
        sum = 0;
        if (i <= 1) //n�� 1�� ��� 1�� ��µ�.
            continue;

        for (int j = 2; j < i; j++) { //�Ҽ� ����
            if (i % j == 0) { //2�̻��� ��� �˻�
                sum = 1;
                break;  //������� ���Ѵ�.
            }
        }
        if (sum == 0) { //�Ҽ����(2�̻��� ��� x)
            total += i;
            if (min == 0)
                min = i;
        }
    }
    if (total != 0)
        printf("%d\n%d", total, min); //�Ҽ��� �ִٸ�  
    else
        printf("-1"); //�Ҽ��� ���ٸ�
}

//���μ�����
void ex11653() {
    int n, tmp = 0, i = 2, k = 0, cnt = 0;
    int s[10000];
    scanf("%d", &n);
    tmp = n;

    while (1) {
        if (tmp % i == 0) {
            tmp = tmp / i; //��
            s[k++] = i; //������ �� ����
        }
        else
            i++; //������ �� ����
        if (tmp <= 1) //��� ������ ��������
            break;
        cnt++;
    }
    for (int j = 0; s[j] != '\0'; j++)
        printf("%d\n", s[j]);
}



//stage 10 ����: ���簢���� �ﰢ��

//���簢��
void ex27323() {
    int a, b;
    scanf("%d\n%d", &a, &b);
    printf("%d", a * b);
}

//���簢������ Ż��
void ex1085() {
    int x, y, w, h, min = 0;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    min = x;
    if (w - x < min) min = w - x;
    if (y < min) min = y;
    if (h - y < min) min = h - y;
    printf("%d", min);
}

//�� ��° ��
void ex3009(void)
{
    int x[4], y[4], i;

    for (i = 0; i < 3; i++) scanf("%d %d", &x[i], &y[i]);
    /*x�� ���� ���Ͽ� ��ġ�� ���� x���� x[3]�� ����*/
    if (x[0] == x[1]) x[3] = x[2];
    else if (x[0] == x[2]) x[3] = x[1];
    else x[3] = x[0];

    /*y�� ���� ���Ͽ� ��ġ�� ���� y���� y[3]�� ����*/
    if (y[0] == y[1]) y[3] = y[2];
    else if (y[0] == y[2]) y[3] = y[1];
    else y[3] = y[0];

    printf("%d %d\n", x[3], y[3]);
    return 0;
}
//������ ü������ �Դϴ�.
void ex15894(void) {
    long long n;  //n�� ���� �� 
    scanf("%lld", &n);
    printf("%lld", n * 4);
}

//����
void ex9063() {
    int n, size = 0;
    int x[100000], y[100000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    int max1 = x[0], max2 = y[0], min1 = x[0], min2 = y[0];
    for (int i = 1; i < n; i++) {
        if (max1 < x[i]) max1 = x[i];
        if (min1 > x[i]) min1 = x[i];
        if (max2 < y[i]) max2 = y[i];
        if (min2 > y[i]) min2 = y[i];
    }
    size = (max1 - min1) * (max2 - min2);
    printf("%d", size);
}

//�ﰢ�� �ܿ��
void ex10101() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a + b + c == 180) {
        if (a == b && b == c)
            printf("Equilateral");
        else if (a == b || b == c || c == a)
            printf("Isosceles");
        else
            printf("Scalene");
    }
    else
        printf("Error");
}
//�ﰢ���� �� ��

void ex5073() {
    int x, y, z, max;

    while (1) {
        scanf("%d %d %d", &x, &y, &z);
        if (x == y && y == z && z == 0)
            break;
        max = x; // x is initially assumed to be the largest
        if (max < y) {
            max = y;
        }
        if (max < z) { // z is the largest
            max = z;
        }

        if (max >= x + y || max >= x + z || max >= y + z) {
            printf("Invalid\n");
            continue;
        }

        if (x == y && y == z) {
            printf("Equilateral\n");
        }
        else if (x == y || y == z || x == z) {
            printf("Isosceles\n");
        }
        else {
            printf("Scalene\n");
        }
    }
}

//�� ����
void swap(int arr[], int size) {
    int temp;
    for (int a = 0; a < size - 1; a++) {
        for (int b = 0; b < size - a - 1; b++) {
            if (arr[b] > arr[b + 1]) {
                temp = arr[b + 1];
                arr[b + 1] = arr[b];
                arr[b] = temp;
            }
        }
    }
}
void ex14215() {
    int i[3];

    scanf("%d %d %d", &i[0], &i[1], &i[2]);
    swap(i, 3);
    int sum;
    sum = i[0] + i[1];

    while (1) {
        if (i[2] < sum) {
            sum += i[2];
            break;
        }
        else
            i[2] -= 1;
    }
    printf("%d", sum);
}