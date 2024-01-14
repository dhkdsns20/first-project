#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define	SIZE	10	// 배열의 크기를 선언한다.
void print_array(int array[]);	// 배열 데이터를 출력하는 함수
int find_max(int array[]);		// 배열에서 값이 가장 큰 원소의 인덱스를 리턴

void ex0901(void)
{
    int data[SIZE] = { 3, 2, 9, 7, 1, 4, 8, 0, 6, 5 };
    int maxindex;

    print_array(data);		// 배열의 값을 출력한다.
    maxindex = find_max(data);	// 최대 값이 저장되어 있는 배열의 인덱스를 구한다.
    printf("최대값: data[%d] = %d\n", maxindex, data[maxindex]);	// 출력
}

void print_array(int array[]) {
    int n;
    printf("배열의 값\n");
    for (n = 0; n < SIZE; n++) {
        printf("data[%d]=%d ", n, array[n]);
        if ((n + 1) % 5 == 0)
            printf("\n");
    }
}

int find_max(int array[]) {
    int n, max = 0;
    for (n = 0; n < SIZE; n++) {
        if (array[max] < array[n])
            max = n;
    }return max;
}




void generate_lotto(int arr_lotto[]) {
    int cnt = 0, dup = 0;

    do {
        dup = 0;
        arr_lotto[cnt] = rand() % 45 + 1;

        if (cnt > 0) {
            for (int j = 0; j < cnt; j++) {
                if (arr_lotto[cnt] == arr_lotto[j]) {
                    dup++;
                }
            }
        }

        if (dup == 0) {
            cnt++;
        }

    } while (cnt < 6);
}

void user_check(int arr_user[]) {
    printf("1~45 사이의 번호를 6개 선택하세요 : ");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &arr_user[i]);
    }
}

void ex0902(void) {
    int arr_lotto[6];
    int arr_user[6];
    int i, win = 0;
    srand((unsigned)time(NULL));

    user_check(arr_user);
    generate_lotto(arr_lotto);

    printf("\n입력 번호:  ");
    for (i = 0; i < 6; i++) {
        printf("%3d ", arr_user[i]);
    }

    printf("\n당첨 번호: ");
    for (i = 0; i < 6; i++) {
        printf("%3d ", arr_lotto[i]);
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (arr_lotto[i] == arr_user[j]) {
                win++;
            }
        }
    }

    printf("\n당첨 번호는 %d개입니다.\n", win);

}

void initialize();
void erase_bingo(int arr[][5], int number);
void print_bingo(int arr[][5]);
void print_winner(int winner);
int get_number(int from); // 0: user, 1: computer 
int check_bingo();

int ubingo[5][5];
int cbingo[5][5];

void ex0903()
{
    int number, uwin, cwin;

    initialize(); // 빙고판 초기화
    do { //반복
        printf("사용자\n"); print_bingo(ubingo); //사용자의 빙고판을 출력한다. 
        number = get_number(0); //사용자가 번호를 선택한다. 
        erase_bingo(ubingo, number); //사용자와 컴퓨터가 해당 번호를 빙고판에서 지운다. 
        erase_bingo(cbingo, number);

        number = get_number(1); //컴퓨터가 번호를 선택한다. 
        erase_bingo(ubingo, number); //사용자와 컴퓨터가 해당 번호를 빙고판에서 지운다. 
        erase_bingo(cbingo, number);

        uwin = check_bingo(ubingo); //사용자가 빙고를 완성했는지 검사한다. 
        cwin = check_bingo(cbingo); //사용자가 빙고를 완성했는지 검사한다. 
    } while ((uwin == 0) && (cwin == 0)); //완성하지 않았다면, 반복. 

    printf("사용자\n"); print_bingo(ubingo); //사용자와 컴퓨터의 빙고판을 출력한다. 
    printf("컴퓨터\n"); print_bingo(cbingo);
    print_winner(cwin * 2 + uwin); //승자를 표시한다. 
}

void initialize() { // 빙고판 초기화
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            ubingo[i][j] = rand() % 25 + 1;
        }
    }
    int index1[5] = { 0 };
    int index2[5] = { 0 };

    for (int i = 0; i < 5; i++) {
        index1[i] = rand() % 5;
        int x = index1[i];

        if (index1[i] != 0) {
            for (int j = 0; j < 5; j++) {
                index2[j] = rand() % 5;
                int y = index2[j];

                if (index2[j] != 0)
                    cbingo[i][j] = ubingo[x][y];
            }
        }
    }
}

void erase_bingo(int arr[][5], int number) { //사용자와 컴퓨터가 해당 번호를 빙고판에서 지운다.
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[i][j] == number) {
                arr[i][j] = 0;
            }
        }
    }
}
void print_bingo(int arr[][5]) { //사용자의 빙고판을 출력한다.
    for (int i = 0; i < 5; i++) {
        printf("[");
        for (int j = 0; j < 5; j++) {
            printf("%2d ", arr[i][j]);
        }printf("]\n");
    }
}
void print_winner(int winner) { //승자를 표시한다.

}

int get_number(int from) { //번호를 선택한다.
    int number;
    if (from == 0) {
        printf("1~25 까지의 번호를 입력하시오:");
        scanf("%d ", &number);
        return number;
    }
    else {
        srand((unsigned int)time(NULL));
        number = rand() % 25 + 1;
        return number;
    }
}

int check_bingo(int arr[][5]) { //사용자가 빙고를 완성했는지 검사한다.
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[i][j] == 0) {
                return 0;
            }
        }
    }
}


#define SIZE 5
#define SIZE2 25

void initialize();
void set_rand(int* array);
void swap(int* x, int* y);
void erase_bingo(int arr[][5], int number);
void print_bingo(int arr[][5]);
void print_winner(int winner);
int get_number(int from); // 0: user, 1: computer
int check_bingo(int arr[][5]);

int ubingo[5][5];
int cbingo[5][5];
int checked[25];
int count = 0;

void ex0904() {
    int number, uwin, cwin;

    initialize(); // 빙고판 초기화

    do
    { //반복
        printf("사용자\n");
        print_bingo(ubingo); //사용자의 빙고판을 출력한다.

        number = get_number(0); //사용자가 번호를 선택한다.
        erase_bingo(ubingo, number); //사용자와 컴퓨터가 해당 번호를 빙고판에서 지운다.
        erase_bingo(cbingo, number);

        //컴퓨터가 번호를 난수를 발생하여 선택
        number = get_number(1); //컴퓨터가 번호를 선택한다.
        erase_bingo(ubingo, number); //사용자와 컴퓨터가 해당 번호를 빙고판에서 지운다.
        erase_bingo(cbingo, number);

        uwin = check_bingo(ubingo); //사용자가 빙고를 완성했는지 검사한다.
        cwin = check_bingo(cbingo); //사용자가 빙고를 완성했는지 검사한다.
    } while ((uwin == 0) && (cwin == 0)); //완성하지 않았다면, 반복.

    printf("사용자\n"); print_bingo(ubingo); //사용자와 컴퓨터의 빙고판을 출력한다.
    printf("컴퓨터\n"); print_bingo(cbingo);
    print_winner(cwin * 2 + uwin); //승자를 표시한다.

    return 0;
}// 메인함수 끝

//초기화 - 사용자, 컴퓨터 모두, 난수를 발생시켜서 
void initialize() {
    srand((unsigned int)time(NULL));
    set_rand((int*)ubingo);
    set_rand((int*)cbingo);
}

void set_rand(int* array) {
    int i;

    for (i = 0; i < SIZE2; i++)
        array[i] = i + 1;
    for (i = 0; i < SIZE2; i++)
        swap(&array[i], &array[rand() % 25]);
}

void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void erase_bingo(int arr[][5], int number)
{
    int x, y;

    for (y = 0; y < SIZE; y++)
        for (x = 0; x < SIZE; x++)
            if (arr[y][x] == number)
                arr[y][x] = 0;
}

void print_bingo(int arr[][5])
{
    int x, y;
    for (y = 0; y < SIZE; y++) {
        for (x = 0; x < SIZE; x++) {
            if (arr[y][x] != -1)
                printf("%5d", arr[y][x]);
            else
                printf(" XX");
        }
        printf("\n");
    }
}

void print_winner(int winner)
{
    switch (winner) {
    case 1: printf("사용자가 이겼습니다.\n"); break;
    case 2: printf("컴퓨터가 이겼습니다.\n"); break;
    case 3: printf("비겼습니다.\n"); break;
    default: printf("뭔가 이상합니다.\n"); break;
    }
}

int get_number(int from)
{
    int number;
    int x, retry;

    do {
        retry = 0;
        if (from == 0) {
            printf("1~25 사이의 숫자를 입력하세요:");
            scanf("%d", &number);
            if (number < 1 || number > 25)
                retry = 1;
        }
        else
            number = rand() % 25 + 1;

        if (retry == 0) {
            for (x = 0; x < count; x++) {
                if (checked[x] == number) {
                    retry = 1;
                    break;
                }
            }
        }
    } while (retry == 1);

    checked[count++] = number;

    if (from == 0)
        printf("사용자가 %d를 선택했습니다.\n", number);
    else
        printf("컴퓨터가 %d를 선택했습니다.\n", number);
    return number;
}

int check_bingo(int arr[][5])
{
    int x, y, sum;

    for (y = 0; y < SIZE; y++) { // check x-axis
        sum = 0;
        for (x = 0; x < SIZE; x++) {
            sum += arr[y][x];
        }
        if (sum == 0) return 1;
    }

    for (x = 0; x < SIZE; x++) { // // check y-axis
        sum = 0;
        for (y = 0; y < SIZE; y++) {
            sum += arr[y][x];
        }
        if (sum == 0) return 1;
    }

    sum = 0; // check cross 1
    for (x = 0; x < SIZE; x++) {
        sum += arr[x][x];
    }
    if (sum == 0) return 1;

    sum = 0; // check cross 2
    for (x = 0; x < SIZE; x++) {
        sum += arr[x][SIZE - x - 1];
    }

    if (sum == 0) return 1;
    return 0;
}


#define SIZE10 10
void generate_random(int array[]);
void print_array(char* str, int array[]);
void selection_sort(int array[]);
void swap(int* a, int* b);

void ex1001(void)
{
    int data[SIZE10], n; // 데이터를 저장할 배열
    for (n = 0; n < 3; n++) // 모두 3 회 수행
    {
        srand((unsigned int)time(NULL));
        generate_random(data); // 난수 생성
        print_array("원본: ", data); // 원본 출력
        selection_sort(data); // 오름차순 정렬
        print_array("정렬: ", data); // 정렬 출력
        printf("\n"); // 줄 바꿈 출력
    }
}

void generate_random(int array[]) {

    for (int i = 0; i < SIZE10; i++) {
        array[i] = rand() % 10;
        for (int j = 0; j < i; j++) {
            if (array[i] == array[j])
                i--;
        }
    }
}
void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void selection_sort(int array[]) {
    int n, m, minindex;
    for (n = 0; n < SIZE - 1; n++) {
        minindex = n;
        for (m = n + 1; m < SIZE; m++)
            if (array[minindex] > array[m])
                minindex = m;
        swap(&array[minindex], &array[n]);
    }
}
void print_array(char* str, int array[]) {
    printf("%s", str);
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
}

void generate_random(int array[], int size); // 난수 생성 함수 선언
void print_array(char* str, int array[], int size); // 배열 출력 힘수 선언
void bubble(int array[], int last);
void swap(int* a, int* b);

void ex1002(void) {
    int* data, size;
    srand(time(NULL)); // 난수 초기화
    printf("배열의 크기를 입력하세요: "); // 배열의 크기 입력
    scanf("%d", &size);

    data = (int*)malloc(sizeof(int) * size); // 배열 동적 할당
    generate_random(data, size); // 난수 생성

    print_array("원본: ", data, size); // 원본 데이터 출력

    printf("\n");

    bubble(data, size); // 버블정렬
    print_array("정렬: ", data, size); // 정렬 데이터 출력
    // 파일에 저장

    free(data); // 기억장치 해제
}

void generate_random(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 1000;

        for (int j = 0; j < i; j++) {
            if (array[i] == array[j])
                i--;
        }
    }
}

void print_array(char* str, int array[], int size) {
    printf("%s %d\n", str, size);
    for (int i = 0; i < size; i++) {

        printf("%d ", array[i]);

        if ((i + 1) % 10 == 0)
            printf("\n");
    }
}

void bubble(int array[], int last) {
    for (int n = 0; n < last - 1; n++) { //last직전까지 교환을 반복
        for (int m = 0; m < last - n - 1; m++) { //큰 값을 제외한 나머지 배열에서의 정렬
            if (array[m] > array[m + 1])
                swap(&array[m], &array[m + 1]);
        }
    }
}

void swap(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}


#define MAX_SIZE 8
int sorted[MAX_SIZE]; // 추가적인 공간이 필요

// i: 정렬된 왼쪽 리스트에 대한 인덱스
// j: 정렬된 오른쪽 리스트에 대한 인덱스
// k: 정렬될 리스트에 대한 인덱스
//* 2개의 인접한 배열 list[left...mid]와 list[mid+1...right]의 합병 과정 */
//* (실제로 숫자들이 정렬되는 과정) */

void merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;
    /* 분할정렬된 list의 합병 */
    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    // 남아 있는 값들을 일괄 복사
    if (i > mid) {
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    }
    // 남아 있는 값들을 일괄 복사 
    else {
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
    }
    // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
    for (l = left; l <= right; l++) {
        list[l] = sorted[l];
    }
}
// 합병 정렬
void merge_sort(int list[], int left, int right) {
    int mid;
    if (left < right) {
        // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
        mid = (left + right) / 2;
        merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer) 
        merge_sort(list, mid + 1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
        // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine) 
        merge(list, left, mid, right);
    }
}

void ex1003() {
    int i;
    int n = MAX_SIZE;
    int list[8] = { 21, 10, 12, 20, 25, 13, 15, 22 };
    // 합병 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 7)
    merge_sort(list, 0, n - 1);
    // 정렬 결과 출력
    for (i = 0; i < n; i++) {
        printf("%d\n", list[i]);
    }
}

void ex1101(void)
{
    FILE* fp = NULL;
    int c;
    fp = fopen("sample.txt", "r");
    if (fp == NULL)
        printf("파일 열기 실패\n");
    else
        printf("파일 열기 성공\n");

    while ((c = fgetc(fp)) != EOF)
        putchar(c);
    fclose(fp);
}

void ex1102(void)
{
    int i;
    int buffer[SIZE] = { 10, 20, 30, 40, 50 };
    FILE* fp = NULL;

    fp = fopen("binary.bin", "wb"); // ①
    if (fp == NULL)
    {
        fprintf(stderr, "binary.bin 파일을열수없습니다.");
        return 1;
    }

    fwrite(buffer, sizeof(int), SIZE, fp); // ②

    for (i = 0; i < SIZE; i++)
        printf("%d ", buffer[i]);

    fclose(fp);
}

void generate_random(int* array, int size)	// 난수 생성 함수 선언
{
    int n;
    for (n = 0; n < size; n++)
        array[n] = (rand() % 1000) + 1;
}
void print_array(FILE* fp, char* str, int* array, int size)// 배열 출력 힘수 선언
{
    int n;
    fprintf(fp, "%s %d\n", str, size);
    for (n = 0; n < size; n++) {
        fprintf(fp, "%5d", array[n]);
        if ((n + 1) % 10 == 0)
            fprintf(fp, "\n");
    }
    fprintf(fp, "\n");
}

void save_data(int array[], int size) {
    FILE* fp;
    fp = fopen("sorted.txt", "w");
    if (fp != NULL) {
        print_array(fp, "정렬:", array, size);
        fclose(fp);
    }
}

void swap(int* x, int* y)	// 두 수를 바꾸는 함수 선언
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void bubble(int array[], int last) {
    for (int n = 0; n < last - 1; n++) { //last직전까지 교환을 반복
        for (int m = 0; m < last - n - 1; m++) { //큰 값을 제외한 나머지 배열에서의 정렬
            if (array[m] > array[m + 1])
                swap(&array[m], &array[m + 1]);
        }
    }
}

void ex1103() {
    int* data = NULL, size = 0;  // 변수 
    int index, key = 1;
    char temp[20];               // 파일 읽기에 필요한 변수
    int n;
    char* fpath = "sorted.txt";
    FILE* fp = fopen(fpath, "r"); // 파일 포인터 선언 및 파일 열기

    if (fp != NULL) {    // 파일을 성공적으로 열었다면
        fscanf(fp, "%s %d", temp, &size); // “원본:”과 데이터 크기를 읽는다
        if (size != 0) {
            data = (int*)malloc(sizeof(int) * size); // 배열을 동적으로 할당한다
            for (n = 0; n < size; n++) // 데이터를 읽는다
                fscanf(fp, "%d", &data[n]);
        }
        fclose(fp); // 파일을 닫는다
    }
    else
        printf("파일이 존재하지 않습니다.");

    print_array(stdout, "원본: ", data, size);
    while (key > 0) {
        printf("검색할 수를 입력하세요: "); // 사용자의 입력을 받는다. 
        scanf("%d", &key);
        if (key > 0) {  // key를 탐색하고 결과를 출력한다. // 추후 구현
            printf("%d를 탐색합니다.\n", key);
        }
    } printf("프로그램을 종료합니다.\n\n");
}

void ex1201(void) {
    char str[80];
    float f;
    FILE* pFile;

    pFile = fopen("myfile.txt", "r"); // myfile.txt를 읽기 모드로 열기
    fscanf(pFile, "%f", &f); // 파일에서 실수를 읽는다. 
    fscanf(pFile, "%s", str); // 파일에서 문자열을 
    fclose(pFile); // 파일을 닫는다.
    printf("I have read: %f and %s\n", f, str); // 읽은 데이터를 출력한
}

void generate_random(int* array, int size)	// 난수 생성 함수 선언
{
    int n;
    for (n = 0; n < size; n++)
        array[n] = (rand() % 1000) + 1;
}
void print_array(char* str, int* array, int size)	// 배열 출력 힘수 선언
{
    int n;
    printf("%s %d\n", str, size);
    for (n = 0; n < size; n++)
        printf("%5d", array[n]);
    printf("\n");
}

void swap(int* x, int* y)	// 두 수를 바꾸는 함수 선언
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void bubble(int array[], int last)
{
    int m;
    for (m = 0; m < last; m++)
        if (array[m] > array[m + 1])
            swap(&array[m], &array[m + 1]);
}
void bubble_sort(int array[], int size)	// 함수 구현
{
    int n;
    for (n = 0; n < size - 1; n++)		// array[0] ~ array[size–n–1] 중에서
        bubble(array, size - n - 1);	// 가장 큰 값을 array[size-n-1]으로 보낸다.
}
void print_array1(FILE* fp, char* str, int array[], int size)	// 파라미터 FILE * 추가
{
    int n;
    fprintf(fp, "%s %d\n", str, size);		// printf(…)를 fprintf(fp, …)로 수정한다.
    for (n = 0; n < size; n++)
    {
        fprintf(fp, "%5d", array[n]);		// printf(…)를 fprintf(fp, …)로 수정한다.
        if ((n + 1) % 10 == 0)
            fprintf(fp, "\n");		// printf(…)를 fprintf(fp, …)로 수정한다.
    }
    fprintf(fp, "\n");			// printf(…)를 fprintf(fp, …)로 수정한다.
}
void save_data(int array[], int size)
{
    FILE* fp;			// 파일 포인터를 선언한다.
    fp = fopen("sorted.txt", "w");	// 텍스트 파일을 쓰기 모드로 연다.
    if (fp != NULL)		// 파일 열기에 성공하였다면,
    {
        print_array1(fp, "정렬: ", array, size);	// 파일을 사용하고
        fclose(fp);			// 파일을 닫는다.
    }
}

int linear_search(int array[], int size, int key) {
    int n;
    for (n = 0; n < size; n++) {
        if (key == array[n]) //배열의 인덱스를 리턴
            return n;
        if (key < array[n]) //배열의 원소가 키 보다 크면
            break;
    }return -1; //찾지 못했으면
}

int binary_search(int array[], int size, int key) {
    int low, high, center;
    low = 0;
    high = size - 1;

    while (low <= high) {
        center = (low + high) / 2;
        if (key == array[center])
            return center;
        else if (key > array[center])
            low = center + 1;
        else
            high = center - 1;
    }return -1;
}
int* read_data1(int* arrsize) {
    int* array = NULL, size = 0;
    array = malloc(size);
    *arrsize = size;
    return array;
}

void ex1202(void)
{
    int* data = NULL, size = 0; // 변수 수정 및 초기화
    int index, key = 1;
    char temp[20]; // 파일 읽기에 필요한 변수

    int n;
    char* fpath = "sorted.txt";
    FILE* fp = fopen(fpath, "r"); // 파일 포인터 선언 및 파일 열기
    if (fp != NULL) // 파일을 성공적으로 열었다면
    {
        fscanf(fp, "%s %d", temp, &size); // “원본:”과 데이터 크기를 읽는다.
        if (size != 0)
        {
            data = (int*)malloc(sizeof(int) * size); // 배열을 동적으로 할당한다.
            for (n = 0; n < size; n++) // 데이터를 읽는다.
                fscanf(fp, "%d", &data[n]);
            print_array1(stdout, "정렬", data, size);
        }

    }
    else
        printf("파일이 존재하지 않습니다.");

    printf("검색할 수를 입력하세요:");
    scanf("%d", &key);

    if (key > 0) {
        //index = linear_search(data, size, key); // 선형탐색
        index = binary_search(data, size, key); //이진탐색
        if (index != -1) //발견
            printf("데이터가 %d 번째에 있습니다.\n", index + 1);
        else //발견X
            printf("데이터가 파일에 없습니다.\n");
    }
    else
        fclose(fp); // 파일을 닫는다.

    if (data != NULL) // 기억장소를 동적으로 할당하므로
        free(data); // 해제한다. 
}


#define MAXLENGTH 100 // 단어 최대 길이
#define MAXWORD 100 //단어 최대 수
void get_words();
void sort_string();
void print_words();
void deallocate();

char* pstrarray[MAXWORD]; //단어를 저장할 문자 포인터 배열
int nword; //단어 

void ex1204() {
    get_words(); //사용자에게 단어를 입력 받아 저장한다.
    sort_string(); //단어를 오름차순으로 정렬한다.
    print_words(); //정렬된 단어를 출력한다.
    deallocate(); //할당받은 공간을 해제한다.
}

void get_words() {
    char buffer[100], * temp;// 사용자가 입력한 문자열 저장, 기억 공간 할당용
    int size; // 받은 문자열의 길이

    nword = 0; // 전역 변수 초기
    printf("단어를 입력하세요. 최대 단어 수는 100 개 입니다.\n"); // 안내문 출력
    printf("입력을 중지하려면 엔터를 입력하세요.\n\n");
    while (nword < MAXWORD) {
        printf("%d. 단어 입력: ", nword + 1); // 안내문 출력
        gets(buffer); // 문자열 입력
        if (strcmp(buffer, "") == 0) // 엔터키를 입력하였다면
            break; // 반복문을 벗어나서, 함수 종료
        else // 단어를 입력하였다면
        {
            size = strlen(buffer) + 1; // 단어의 크기를 구하고
            temp = (char*)malloc(size); // 기억 공간을 할당하고
            strcpy(temp, buffer); // 단어를 복사하여
            pstrarray[nword++] = temp; // 포인터 배열에 연결한다. 
        }
    }
}

void deallocate() {
    int n;
    for (n = 0; n < nword; n++) //nword까지
        if (pstrarray[n] != NULL) //문자열이 연결되어 있다면
            free(pstrarray[n]); //기억 공간을 해제한다.
}

void print_words() {
    int n;
    printf("\n정렬 후 출력: 단어 수=%d\n", nword);
    for (n = 0; n < nword; n++)
        puts(pstrarray[n]);
}

void sort_string() { // selection_sort(int array[]) 복사하여 수정한다
    int n, m, minindex;
    char* temp; // 문자열을 교체하기 위하여 임시 변수를 추가한다.
    for (n = 0; n < nword - 1; n++) {
        minindex = n;
        for (m = n; m < nword; m++)
            if (strcmp(pstrarray[minindex], pstrarray[m]) > 0)
                minindex = m;
        temp = pstrarray[minindex];
        pstrarray[minindex] = pstrarray[n];
        pstrarray[n] = temp;
    }
}

//#include <stdlib.h> // malloc(),free()
//#include <string.h> // memset()
//#include <ctype.h> // tolower()
#define MAXWORD 1000 //파일에 들어 있는 단어의 최대 수

void intialize();
void read_file();
void print_words();
void deallocate();

void convert_lower(char* str);
int linear_search(int* key, int* found);
void move_downward(int index);
void insert_data(int index, char* str);

struct WORDCOUNT {     //단어를 저장할 구조체 선언
    char* str;          //단어를 저장할 문자형 포인터
    int count;          //단어가 나타난 횟수
};

struct WORDCOUNT* words; //단어를 저장할 배열(포인터)
int nwords;              //배열에 저장되어 있는 단어 수

void ex1301(void) {
    intialize();   // 구조제 배열을 할당하고 초기화 한다
    read_file();   // 파일에서 단어를 추출하여 words[]에 저장한
    print_words();  // words[]에 저장되어 있는 단어와 횟수
    deallocate();  // 동적으로 할당 받은 기억장소를 해제한
}

void intialize() {
    words = (struct WORDCOUNT*)malloc(sizeof(struct WORDCOUNT) * MAXWORD); //구조체 배열
    memset(words, 0, sizeof(struct WORDCOUNT) * MAXWORD); //메모리에 특정값 세팅
    nwords = 0;  //저장된 단어 수 = 0
}

void read_file() {
    char buffer[256];  //한개의 라인을 읽는 저장소
    FILE* fp = fopen("programming.txt", "r");  //읽기모드로 파일열기
    char* token;
    int found, index; //탐색을 위한 변수

    while (fgets(buffer, 256, fp) != NULL) { //한줄을 읽었으면
        token = strtok(buffer, " ,.!?\t\n"); //첫번째 토큰 분리
        while (token != NULL) {
            convert_lower(token); //단어->소문자 변환
            index = linear_search(token, &found); //단어 존재 검사
            if (found == 1)
                words[index].count += 1;
            else {
                move_downward(index);    //단어를 한 칸씩 아래로 욺기고
                insert_data(index, token); //해당 위치에 단어를 추가한다.
            }
            printf("%s\n", token); //추출된 단어 출력
            token = strtok(NULL, " ,.?!\t\n"); //다음 토큰을 추출
        }

    }
    fclose(fp); //파일을 닫는다.
}

void print_words() {
    int n;
    for (n = 0; n < nwords; n++) {
        printf("%3d.%-18s:%d\n", n + 1, words[n].str, words[n].count);
    }
}

void deallocate() {
    for (int n = 0; n < nwords; n++) //저장되어 있는 단어에 대해서
        if (words[n].str != NULL) //기억장소가 할당되었다면
            free(words[n].str);  //구조체 배열을 해제
}

void convert_lower(char* str) {
    while (*str != NULL) {
        *str = tolower(*str); //소문자로 변환
        str++;
    }
}

int linear_search(int* key, int* found) {
    int n, compare;
    *found = 0;  //찾지 못했다고 가정.
    for (n = 0; n < nwords; n++) {
        compare = strcmp(key, words[n].str); //문자열비교
        if (compare == 0) { //찾았다면
            *found = 1; //찾았다고 표시
            break;
        }
        if (compare < 0)  //배열의 단어가 키 보다 크면
            break;
    }return n; //배열의 인덱스를 리턴.
}

void move_downward(int index) {
    int n;
    if (nwords < MAXWORD - 1) { //단어수가 배열의 최대 수를 초과하지 않으면
        for (n = nwords; n >= index; n--) {  //마지막 단어부터
            words[n + 1].str = words[n].str; //단어를 욺긴다.
            words[n + 1].count = words[n].count;  //단어 수를 욺긴다.
            // words[n+1] = words[n]; // 구조체 멤버를 한 번에 욺긴다.
        }
    }
}


void insert_data(int index, char* str) {
    int size; //단어의 문자 수
    if (nwords < MAXWORD - 1) {
        size = strlen(str) + 1;
        words[index].str = (char*)malloc(size);
        strcpy(words[index].str, str);
        words[index].count = 1;
        nwords++;
    }
}



typedef struct STUDENT_INFO SINFO;
void insert_node(SINFO* student);


void get_strudentinfo();
void print_list();
void delete_list();

struct STUDENT_INFO {
    char id[16];
    char name[16];
    int score;
    struct STUDENT_INFO* next;
};

SINFO* listhead = NULL;

int main() {
    get_strudentinfo();
    print_list();
}

void get_strudentinfo() {
    SINFO student;
    printf("학생 정보를 입력하세요.\n");
    printf("입력을 마치려면 학번에 -1을 넣으세요.\n\n");
    while (1) {
        printf("학번: ");
        scanf("%s", student.id);
        if (strcmp(student.id, "-1") != 0) {
            printf("이름: ");
            scanf("%s", student.name);
            printf("성적: ");
            scanf("%d", &student.score);
            insert_node(&student);
            printf("\n");
        }
        else
            break;
    }
    delete_list();
}

void insert_node(SINFO* student) {
    SINFO* temp = (SINFO*)malloc(sizeof(SINFO)); //동적으로 노드생성
    strcpy(temp->id, student->id);  //학생 데이터를 복사
    strcpy(temp->name, student->name);
    temp->score = student->score;

    temp->next = listhead;  //리스트의 앞에 삽입.
    listhead = temp;
}

void print_list() {
    SINFO* search; //연결리스트를 추적하기 위한 포인터
    search = listhead; //포인터 초기화
    printf("\n%16s%16s%6s\n", "학번", "이름", "성적");
    printf("======================================\n");
    while (search != NULL) {
        printf("%16s", search->id); // 데이터를 출력하고
        printf("%16s", search->name);
        printf("%6d\n", search->score);
        search = search->next; // 다음 노드로 이동한다
    }
}


void delete_list() {
    SINFO* temp = listhead; //temp를 초기화
    while (listhead != NULL) {  //연결리스트의 끝에 도달할 때까지
        listhead = listhead->next; //리스트 헤드를 다음 노드로 욺기고
        free(temp); //temp가 가리키는 노드를 해제한다.
        temp = listhead; //temp를 수정한다.
    }
}