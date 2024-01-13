#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main() {
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