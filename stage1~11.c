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
//EOF(end of file) 파일의 끝을 만나면 종료
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

    for (int i = 1; i <= n; i++) { //초기화 시킨다.
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
    //index없이 배열에 저장해버리면 입력된 수가 뒤죽박죽일때 i와 입력된 수가 일치하지 않는다.
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

    for (int i = 1; i <= n; i++) { //초기화 시킨다.
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

//공백 없는 숫자 더하기
void ex11720() {
    int n, sum = 0;
    char arr[100];

    scanf("%d", &n);
    scanf("%s", arr);
    for (int i = 0; i < n; i++) {
        sum += arr[i] - '0';
    }printf("%d", sum);
}

//알파벳 찾기
void ex10809() {
    char arr[100];
    int index[26] = { 0 };
    scanf("%s", arr);

    for (int i = 0; i < strlen(arr); i++) {
        if (index[arr[i] - 'a'] == 0) index[arr[i] - 'a'] = i + 1;
    }
    for (int k = 0; k < 26; k++) {
        if (index[k] == 0) printf("-1 ");
        else printf("%d ", index[k] - 1); //출력 
    }
}

//그대로 출력하기
void ex11718() {
    char a;
    while (scanf("%c", &a) == 1) {
        printf("%c", a);
    }
}

//문자열 반복
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

//단어의 개수
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

//상수 2908번

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

//다이얼
void ex5622() {
    char arr[15];
    int count = 0;
    scanf("%s", arr);

    for (int i = 0; i < strlen(arr); i++) { //아스키코드를 활용해 코드 간략화
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
