#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define	SIZE	10	// �迭�� ũ�⸦ �����Ѵ�.
void print_array(int array[]);	// �迭 �����͸� ����ϴ� �Լ�
int find_max(int array[]);		// �迭���� ���� ���� ū ������ �ε����� ����

void ex0901(void)
{
    int data[SIZE] = { 3, 2, 9, 7, 1, 4, 8, 0, 6, 5 };
    int maxindex;

    print_array(data);		// �迭�� ���� ����Ѵ�.
    maxindex = find_max(data);	// �ִ� ���� ����Ǿ� �ִ� �迭�� �ε����� ���Ѵ�.
    printf("�ִ밪: data[%d] = %d\n", maxindex, data[maxindex]);	// ���
}

void print_array(int array[]) {
    int n;
    printf("�迭�� ��\n");
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
    printf("1~45 ������ ��ȣ�� 6�� �����ϼ��� : ");
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

    printf("\n�Է� ��ȣ:  ");
    for (i = 0; i < 6; i++) {
        printf("%3d ", arr_user[i]);
    }

    printf("\n��÷ ��ȣ: ");
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

    printf("\n��÷ ��ȣ�� %d���Դϴ�.\n", win);

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

    initialize(); // ������ �ʱ�ȭ
    do { //�ݺ�
        printf("�����\n"); print_bingo(ubingo); //������� �������� ����Ѵ�. 
        number = get_number(0); //����ڰ� ��ȣ�� �����Ѵ�. 
        erase_bingo(ubingo, number); //����ڿ� ��ǻ�Ͱ� �ش� ��ȣ�� �����ǿ��� �����. 
        erase_bingo(cbingo, number);

        number = get_number(1); //��ǻ�Ͱ� ��ȣ�� �����Ѵ�. 
        erase_bingo(ubingo, number); //����ڿ� ��ǻ�Ͱ� �ش� ��ȣ�� �����ǿ��� �����. 
        erase_bingo(cbingo, number);

        uwin = check_bingo(ubingo); //����ڰ� ���� �ϼ��ߴ��� �˻��Ѵ�. 
        cwin = check_bingo(cbingo); //����ڰ� ���� �ϼ��ߴ��� �˻��Ѵ�. 
    } while ((uwin == 0) && (cwin == 0)); //�ϼ����� �ʾҴٸ�, �ݺ�. 

    printf("�����\n"); print_bingo(ubingo); //����ڿ� ��ǻ���� �������� ����Ѵ�. 
    printf("��ǻ��\n"); print_bingo(cbingo);
    print_winner(cwin * 2 + uwin); //���ڸ� ǥ���Ѵ�. 
}

void initialize() { // ������ �ʱ�ȭ
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

void erase_bingo(int arr[][5], int number) { //����ڿ� ��ǻ�Ͱ� �ش� ��ȣ�� �����ǿ��� �����.
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[i][j] == number) {
                arr[i][j] = 0;
            }
        }
    }
}
void print_bingo(int arr[][5]) { //������� �������� ����Ѵ�.
    for (int i = 0; i < 5; i++) {
        printf("[");
        for (int j = 0; j < 5; j++) {
            printf("%2d ", arr[i][j]);
        }printf("]\n");
    }
}
void print_winner(int winner) { //���ڸ� ǥ���Ѵ�.

}

int get_number(int from) { //��ȣ�� �����Ѵ�.
    int number;
    if (from == 0) {
        printf("1~25 ������ ��ȣ�� �Է��Ͻÿ�:");
        scanf("%d ", &number);
        return number;
    }
    else {
        srand((unsigned int)time(NULL));
        number = rand() % 25 + 1;
        return number;
    }
}

int check_bingo(int arr[][5]) { //����ڰ� ���� �ϼ��ߴ��� �˻��Ѵ�.
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

    initialize(); // ������ �ʱ�ȭ

    do
    { //�ݺ�
        printf("�����\n");
        print_bingo(ubingo); //������� �������� ����Ѵ�.

        number = get_number(0); //����ڰ� ��ȣ�� �����Ѵ�.
        erase_bingo(ubingo, number); //����ڿ� ��ǻ�Ͱ� �ش� ��ȣ�� �����ǿ��� �����.
        erase_bingo(cbingo, number);

        //��ǻ�Ͱ� ��ȣ�� ������ �߻��Ͽ� ����
        number = get_number(1); //��ǻ�Ͱ� ��ȣ�� �����Ѵ�.
        erase_bingo(ubingo, number); //����ڿ� ��ǻ�Ͱ� �ش� ��ȣ�� �����ǿ��� �����.
        erase_bingo(cbingo, number);

        uwin = check_bingo(ubingo); //����ڰ� ���� �ϼ��ߴ��� �˻��Ѵ�.
        cwin = check_bingo(cbingo); //����ڰ� ���� �ϼ��ߴ��� �˻��Ѵ�.
    } while ((uwin == 0) && (cwin == 0)); //�ϼ����� �ʾҴٸ�, �ݺ�.

    printf("�����\n"); print_bingo(ubingo); //����ڿ� ��ǻ���� �������� ����Ѵ�.
    printf("��ǻ��\n"); print_bingo(cbingo);
    print_winner(cwin * 2 + uwin); //���ڸ� ǥ���Ѵ�.

    return 0;
}// �����Լ� ��

//�ʱ�ȭ - �����, ��ǻ�� ���, ������ �߻����Ѽ� 
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
    case 1: printf("����ڰ� �̰���ϴ�.\n"); break;
    case 2: printf("��ǻ�Ͱ� �̰���ϴ�.\n"); break;
    case 3: printf("�����ϴ�.\n"); break;
    default: printf("���� �̻��մϴ�.\n"); break;
    }
}

int get_number(int from)
{
    int number;
    int x, retry;

    do {
        retry = 0;
        if (from == 0) {
            printf("1~25 ������ ���ڸ� �Է��ϼ���:");
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
        printf("����ڰ� %d�� �����߽��ϴ�.\n", number);
    else
        printf("��ǻ�Ͱ� %d�� �����߽��ϴ�.\n", number);
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
    int data[SIZE10], n; // �����͸� ������ �迭
    for (n = 0; n < 3; n++) // ��� 3 ȸ ����
    {
        srand((unsigned int)time(NULL));
        generate_random(data); // ���� ����
        print_array("����: ", data); // ���� ���
        selection_sort(data); // �������� ����
        print_array("����: ", data); // ���� ���
        printf("\n"); // �� �ٲ� ���
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

void generate_random(int array[], int size); // ���� ���� �Լ� ����
void print_array(char* str, int array[], int size); // �迭 ��� ���� ����
void bubble(int array[], int last);
void swap(int* a, int* b);

void ex1002(void) {
    int* data, size;
    srand(time(NULL)); // ���� �ʱ�ȭ
    printf("�迭�� ũ�⸦ �Է��ϼ���: "); // �迭�� ũ�� �Է�
    scanf("%d", &size);

    data = (int*)malloc(sizeof(int) * size); // �迭 ���� �Ҵ�
    generate_random(data, size); // ���� ����

    print_array("����: ", data, size); // ���� ������ ���

    printf("\n");

    bubble(data, size); // ��������
    print_array("����: ", data, size); // ���� ������ ���
    // ���Ͽ� ����

    free(data); // �����ġ ����
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
    for (int n = 0; n < last - 1; n++) { //last�������� ��ȯ�� �ݺ�
        for (int m = 0; m < last - n - 1; m++) { //ū ���� ������ ������ �迭������ ����
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
int sorted[MAX_SIZE]; // �߰����� ������ �ʿ�

// i: ���ĵ� ���� ����Ʈ�� ���� �ε���
// j: ���ĵ� ������ ����Ʈ�� ���� �ε���
// k: ���ĵ� ����Ʈ�� ���� �ε���
//* 2���� ������ �迭 list[left...mid]�� list[mid+1...right]�� �պ� ���� */
//* (������ ���ڵ��� ���ĵǴ� ����) */

void merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;
    /* �������ĵ� list�� �պ� */
    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
            sorted[k++] = list[i++];
        else
            sorted[k++] = list[j++];
    }

    // ���� �ִ� ������ �ϰ� ����
    if (i > mid) {
        for (l = j; l <= right; l++)
            sorted[k++] = list[l];
    }
    // ���� �ִ� ������ �ϰ� ���� 
    else {
        for (l = i; l <= mid; l++)
            sorted[k++] = list[l];
    }
    // �迭 sorted[](�ӽ� �迭)�� ����Ʈ�� �迭 list[]�� �纹��
    for (l = left; l <= right; l++) {
        list[l] = sorted[l];
    }
}
// �պ� ����
void merge_sort(int list[], int left, int right) {
    int mid;
    if (left < right) {
        // �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ���� -����(Divide)
        mid = (left + right) / 2;
        merge_sort(list, left, mid); // ���� �κ� ����Ʈ ���� -����(Conquer) 
        merge_sort(list, mid + 1, right); // ���� �κ� ����Ʈ ���� -����(Conquer)
        // ���ĵ� 2���� �κ� �迭�� �պ��ϴ� ���� -����(Combine) 
        merge(list, left, mid, right);
    }
}

int main() {
    int i;
    int n = MAX_SIZE;
    int list[8] = { 21, 10, 12, 20, 25, 13, 15, 22 };
    // �պ� ���� ����(left: �迭�� ���� = 0, right: �迭�� �� = 7)
    merge_sort(list, 0, n - 1);
    // ���� ��� ���
    for (i = 0; i < n; i++) {
        printf("%d\n", list[i]);
    }
}