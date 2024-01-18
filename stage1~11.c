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

//stage6 심화1

//새싹
void ex25083(void) {
    printf("         ,r'\"7\n"); // 작은 따옴표, 큰 따옴표 출력을 위해서는 앞에 '\'를 추가 
    printf("r`-_   ,\'  ,/\n");
    printf(" \\. \". L_r\'\n"); // '\' 출력을 위해서는 '\\' 입력
    printf("   `~\\/\n");
    printf("      |\n");
    printf("      |\n");
}

//체스
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

//별찍기-7
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

//팰린드롬인지 확인하기
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

//단어공부
char a[1000005];
int arr[26];

void ex1157() {
    int max = 0;
    char ans;

    scanf("%s", a); //문자열을 입력받는다.

    for (int i = 0; i < strlen(a); i++) //문자열 크기만큼 반복
        if (a[i] >= 'a') arr[a[i] - 'a']++; //소문자 저
        else arr[a[i] - 'A']++; //대문자 저장

    for (int i = 0; i < 26; i++) //
        if (arr[i] == max) {
            ans = '?';
        }
        else if (arr[i] > max) {
            max = arr[i]; //max보다 빈도가 많은 단어를 max에 저장
            ans = 'A' + i; //'A'(=65)를 더해 대문자로 출력
        } printf("%c", ans);
}

//크로아티아 알파벳벳
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

//그룹 단어 체커
void ex1316()
{

    char input_words[101]; //문자열 배열
    int N; //input 값 N
    scanf("%d", &N);


    int count = N;

    for (int i = 0; i < N; i++)
    {
        char first = '0';
        int Alphabet[26] = { 0, };
        scanf("%s", input_words);
        for (int j = 0; input_words[j] != '\0'; j++)
        {
            if (first != input_words[j]) //연속된 경우 통과
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

//너의 평점은
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
        sumScore += score; //sumScore는 전체학점
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
        if (major[1] == '+') { //+가 붙으면 0.5점을 더한다.
            majorScore += 0.5;
        }
        sum += score * majorScore; //학점*점수
    }
    printf("%lf", sum / sumScore);
}





//stage7 2차원 배열

//행렬 덧셈
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

//최댓값 
void ex2566() {
    int arr[9][9];
    int max = -1, x = 0, y = 0;
    //행렬의 값이 모두 0일때 x,y에 쓰레기값이 들어가 있다.

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

//세로읽기
void ex10798() {
    char arr[5][15] = { 0 }; //0으로 초기화!
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

//색종이
void ex2563() {
    int sum = 0, cnt = 0, x = 0, y = 0;
    int arr[100][100] = { 0 };

    scanf("%d", &cnt); //색종이의 수

    for (int i = 0; i < cnt; i++) {
        scanf("%d %d", &x, &y);

        for (int j = x; j < x + 10; j++) {
            for (int k = y; k < y + 10; k++) {
                arr[j][k] = 1;        // 배열에 1을대입
            }
        }
    }

    for (int j = 0; j < 100; j++) {
        for (int k = 0; k < 100; k++) {
            if (arr[j][k] == 1)
                sum++;        // 배열에 1이 있으면 더한다.
        }
    }printf("%d", sum);
}
//stage 8 일반 수학 1

//진법 변환

//진법 변환 2

//세탁소 시장 독혁

//중앙 이동 알고리즘

//벌집

//분수찾기

//달팽이는 올라가고 싶다.




//stage 9 약수,배수와 소수

//배수와 약수

//약수 구하기

//약수들의 합

//소수 찾기

//소인수분해




//stage 10 기하: 직사각형과 삼각형

//직사각형
void ex27323() {
    int a, b;
    scanf("%d\n%d", &a, &b);
    printf("%d", a * b);
}

//직사각형에서 탈출
void ex1085() {
    int x, y, w, h, min = 0;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    min = x;
    if (w - x < min) min = w - x;
    if (y < min) min = y;
    if (h - y < min) min = h - y;
    printf("%d", min);
}

//네 번째 점
void ex3009(void)
{
    int x[4], y[4], i;

    for (i = 0; i < 3; i++) scanf("%d %d", &x[i], &y[i]);
    /*x값 서로 비교하여 겹치지 않은 x값을 x[3]에 대입*/
    if (x[0] == x[1]) x[3] = x[2];
    else if (x[0] == x[2]) x[3] = x[1];
    else x[3] = x[0];

    /*y값 서로 비교하여 겹치지 않은 y값을 y[3]에 대입*/
    if (y[0] == y[1]) y[3] = y[2];
    else if (y[0] == y[2]) y[3] = y[1];
    else y[3] = y[0];

    printf("%d %d\n", x[3], y[3]);
    return 0;
}
//수학은 체육과목 입니다.
void ex15894(void) {
    long long n;  //n의 범위 때 
    scanf("%lld", &n);
    printf("%lld", n * 4);
}

//대지
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

//삼각형 외우기
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
//삼각형과 세 변

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

//세 막대
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