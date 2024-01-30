// ����3-1������ �˻�(���ʹ�: for ��)
#include <stdio.h>
#include <stdlib.h>

/*--- ����� ������ n�� �迭 a���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻�(���ʹ�) ---*/
int search(int a[], int n, int key)
{
    int i, count = 0;

    a[n] = key;         // ���ʸ� �߰�
    printf("   | 0 1 2 3 4 5 6\n"); //�迭 �ε�
    printf("---+------------------\n");

    for (i = 0; i < n; i++) {
        printf("   |");
        for (int j = 0; j < i; j++) {
            printf("  ");
        }printf(" *\n");
        printf("  %d| ", count);
        for (int b = 0; b < n; b++) {
            printf("%d ", a[b]);
        }printf("\n");
        if (a[i] == a[n])
            break;
        count++;
    }
    return i == n ? -1 : i;
}

void linear_search() {
    int nx, ky;
    puts("���� �˻�(���ʹ�)");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx + 1, sizeof(int));   // ����� ������ (nx + 1)�� int�� �迭 x�� ����

    for (int i = 0; i < nx; i++) {          // ����: ���� ���� ���� nx��
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("�˻���: ");
    scanf("%d", &ky);

    int idx = search(x, nx, ky);            // �迭 x���� ���� ky�� ��Ҹ� ���� �˻�

    if (idx == -1)
        puts("�˻��� �����߽��ϴ�.");
    else
        printf("%d(��)�� x[%d]�� �ֽ��ϴ�.\n", ky, idx);

    free(x);                                // �迭 x�� ����
}

int search_idx(const int a[], int n, int key, int idx[]) {
    int i = 0;
    for (int j = 0; j < n; j++) {
        if (a[j] == key)
            idx[i++] = j;
    }return i;
}


// ����3-4������ �˻�(�˻� ������ ���)

/*--- ����� ������ n�� �迭 a���� key�� ��ġ�ϴ� ��Ҹ� ���� �˻� ---*/
int bin_search(const int a[], int n, int key)
{
    int pl = 0;                     // �˻� ���� �� ���� �ε���
    int pr = n - 1;                 // �˻� ���� �� ���� �ε���

    printf("   |");
    for (int i = 0; i < n; i++) printf("%4d", i);
    printf("\n---+");
    for (int i = 0; i < n; i++) printf("----", i);
    printf("--\n");

    do {
        int pc = (pl + pr) / 2;     // �˻� ���� �Ѱ���� �ε���

        printf("   |");
        for (int i = 0; i < 4 * pl; i++) printf(" ");
        printf(" <-");
        for (int i = 0; i < 4 * (pc - pl); i++) printf(" ");
        printf("+");
        for (int i = 0; i < 4 * (pr - pc) - 2; i++) printf(" ");
        printf("->\n");

        printf("%3d|", pc);
        for (int i = 0; i < n; i++)
            printf("%4d", a[i]);
        putchar('\n');

        if (a[pc] == key)           // �˻� ����
            return pc;
        else if (a[pc] < key)
            pl = pc + 1;            // �˻� ������ ���� �������� ����
        else
            pr = pc - 1;            // �˻� ������ ���� �������� ����

        printf("   |\n");

    } while (pl <= pr);

    return -1;                      // �˻� ����
}

int bin_search2(const int a[], int n, int key)
{
    int pl = 0;                     // �˻� ���� �� ���� �ε���
    int pr = n - 1;                 // �˻� ���� �� ���� �ε���

    do {
        int pc = (pl + pr) / 2;     // �˻� ���� �Ѱ���� �ε���
        if (a[pc] == key) {         // �˻� ����
            while (pc > pl && a[pc - 1] == key) //pc���� ���� index�� key�� ������!
                pc--;               //pc�� ���ҽ�Ų��.
            return pc;
        }
        else if (a[pc] < key)
            pl = pc + 1;            // �˻� ������ ���� �������� ����
        else
            pr = pc - 1;            // �˻� ������ ���� �������� ����
    } while (pl <= pr);

    return -1;                      // �˻� ����
}

return min;
}
void binary_search(void)
{
    int nx, ky;

    puts("���� �˻�");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ��� ������ nx�� int�� �迭 x�� ����

    printf("������������ �Է��ϼ���.\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);

    for (int i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i - 1]);      // �ٷ� ���� ������ ������ �ٽ� �Է�
    }
    printf("�˻���: ");
    scanf("%d", &ky);

    int idx = bin_search2(x, nx, ky);    // �迭 x���� ���� ky�� ��Ҹ� ���� �˻�

    if (idx == -1)
        puts("�˻��� �����߽��ϴ�.");
    else
        printf("%d��(��) x[%d]�� �ֽ��ϴ�.\n", ky, idx);

    free(x);                            // �迭 x�� ����
}

// ����3-6��bsearch �Լ��� ����Ͽ� ������������ ������ long�� �迭���� �˻�

/*--- ������ ���ϴ� �Լ�(long�� ��������) ---*/
int long_cmpr(const long* a, const long* b)
{
    if (*a < *b)
        return 1;
    else if (*a > *b)
        return -1;
    else
        return 0;
}

void bsearch_1(void)
{
    int nx;
    long ky;

    puts("bsearch �Լ��� ����Ͽ� �˻�");
    printf("��� ����: ");
    scanf("%d", &nx);
    long* x = calloc(nx, sizeof(long)); // ����� ������ nx�� long�� �迭 x�� ����

    printf("������������ �Է��ϼ���.\n");

    printf("x[0] : ");
    scanf("%ld", &x[0]);

    for (int i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%ld", &x[i]);
        } while (x[i] > x[i - 1]);      // �ٷ� ���� ������ ũ�� �ٽ� �Է�
    }

    printf("�˻���: ");
    scanf("%d", &ky);

    long* p = bsearch(
        &ky,                            // �˻����� ���� ������
        x,                              // �迭
        nx,                             // ����� ����
        sizeof(int),                    // ����� ũ��
        (int (*)(const void*, const void*))long_cmpr  // �� �Լ�
    );

    if (p == NULL)
        puts("�˻��� �����߽��ϴ�.");
    else
        printf("%d��(��) x[%d]�� �ֽ��ϴ�.\n", ky, (int)(p - x));

    free(x);                            // �迭 x�� ����
}


// ����3-7��bsearch �Լ��� ���� ������ ���� Ž�� �Լ�

/*--- base�� ����Ű�� ����� ũ�Ⱑ size�̰� ����� ������ nmemb�� �迭���� key�� ��ġ�ϴ� ��Ҹ�
      �� �Լ� compar�� ����ؼ� ���� �˻� ---*/
void* seqsearch(const void* key, const void* base, size_t nmemb, size_t size,
    int (*compar)(const void*, const void*))
{
    char* x = (char*)base;

    for (size_t i = 0; i < nmemb; i++)
        if (!compar((const void*)&x[i * size], key))
            return (&x[i * size]);
    return NULL;                            // �˻� ����
}

/*--- ������ ���ϴ� �Լ� ---*/
int int_cmp(const int* a, const int* b)
{
    if (*a < *b)
        return -1;
    else if (*a > *b)
        return 1;
    else
        return 0;
}

int main(void)
{
    int nx, ky;

    puts("seqsearch �Լ��� �˻�");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ��� ������ nx�� int�� �迭 x�� ����

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    printf("�˻���: ");
    scanf("%d", &ky);

    int* p = seqsearch(
        &ky,                            // �˻����� ���� ������
        x,                              // �迭
        nx,                             // ����� ����
        sizeof(int),                    // ����� ũ��
        (int (*)(const void*, const void*))int_cmp    // �� �Լ�
    );

    if (p == NULL)
        puts("�˻��� �����߽��ϴ�.");
    else
        printf("%d��(��) x[%d]�� �ֽ��ϴ�.\n", ky, (int)(p - x));

    free(x);                            // �迭 x�� ����
}

// ����3-9��bsearch �Լ��� Ȯ���� �Լ�(�� �տ� �ִ� ��Ҹ� �˻�)
#include <stdio.h>
#include <stdlib.h>

/*--- base�� ����Ű�� ����� ũ�Ⱑ size�̰� ����� ������ nmemb�� �迭���� key�� ��ġ�ϴ� ��Ҹ�
      �� �Լ� compar�� �̿��ؼ� ���� �˻�
      �� key�� ���� ��Ұ� ���� �� ������ �� ���� ��Ҹ� �˻� ---*/
void* bsearchx(const void* key, const void* base, size_t nmemb, size_t size,
    int (*compar)(const void*, const void*))
{
    char* x = (char*)base;
    size_t pl = 0;                          // �˻� ���� �� ���� �ε���
    size_t pr = nmemb - 1;                  // �˻� ���� �� ���� �ε���

    if (nmemb > 0) {
        while (1) {
            size_t pc = (pl + pr) / 2;      // �˻� ���� �Ѱ���� �ε���
            int comp = compar((const void*)&x[pc * size], key);

            if (comp == 0) {                // �˻� ����
                for (; pc > pl; pc--)      // key�� ���� ���� ��Ҹ� �˻�
                    if (compar((const void*)&x[(pc - 1) * size], key))
                        break;
                return &x[pc * size];
            }
            else if (pl == pr)
                break;
            else if (comp < 0)
                pl = pc + 1;                // �˻� ������ ���� �������� ����
            else
                pr = pc - 1;                // �˻� ������ ���� �������� ����
        }
    }

    return NULL;                            // �˻� ����
}

/*--- ������ ���ϴ� �Լ� ---*/
int int_cmp(const int* a, const int* b)
{
    if (*a < *b)
        return -1;
    else if (*a > *b)
        return 1;
    else
        return 0;
}

void bsearchxx(void)
{
    int nx, ky;

    puts("bsearchx �Լ��� �˻�");
    printf("��� ����: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // ��� ������ nx�� int�� �迭 x�� ����

    printf("������������ �Է��ϼ���.\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);

    for (int i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i - 1]);      // �ٷ� ���� ������ ������ �ٽ� �Է�
    }

    printf("�˻���: ");
    scanf("%d", &ky);

    int* p = bsearchx(
        &ky,                            // �˻����� ���� ������
        x,                              // �迭
        nx,                             // ����� ����
        sizeof(int),                    // ����� ũ��
        (int (*)(const void*, const void*))int_cmp    // �� �Լ�
    );

    if (p == NULL)
        puts("�˻��� �����߽��ϴ�.");
    else
        printf("%d��(��) x[%d]�� �ֽ��ϴ�.\n", ky, (int)(p - x));

    free(x);                            // �迭 x�� ����

}


// int�� ���� IntStack(���)
#ifndef ___IntStack
#define ___IntStack

/*--- ������ �����ϴ� ����ü ---*/
typedef struct {
    int max;    // ���� �뷮
    int ptr;    // ���� ������ 
    int* stk;   // ������ ù ��ҿ� ���� ������
} IntStack;

/*--- ���� �ʱ�ȭ ---*/
int Initialize(IntStack* s, int max);

/*--- ���ÿ� �����͸� Ǫ�� ---*/
int Push(IntStack* s, int x);

/*--- ���ÿ��� �����͸� �� ---*/
int Pop(IntStack* s, int* x);

/*--- ���ÿ��� �����͸� ��ũ ---*/
int Peek(const IntStack* s, int* x);

/*--- ���� ���� ---*/
void Clear(IntStack* s);

/*--- ���� �뷮 ---*/
int Capacity(const IntStack* s);

/*--- ���ÿ� ����� ������ �� ---*/
int Size(const IntStack* s);

/*--- ������ ��� �ִ°�? ---*/
int IsEmpty(const IntStack* s);

/*--- ������ ���� á�°�? ---*/
int IsFull(const IntStack* s);

/*--- ���ÿ��� �˻� ---*/
int Search(const IntStack* s, int x);

/*--- ��� ������ ��� ---*/
void Print(const IntStack* s);

/*--- ���� ���� ---*/
void Terminate(IntStack* s);

#endif

// int�� ���� IntStack(�ҽ�)


/*--- ���� �ʱ�ȭ ---*/
int Initialize(IntStack* s, int max)
{
    s->ptr = 0;
    if ((s->stk = calloc(max, sizeof(int))) == NULL) {
        s->max = 0;                             // �迭�� ������ ����
        return -1;
    }
    s->max = max;
    return 0;
}

/*--- ���ÿ� ������ Ǫ�� ---*/
int Push(IntStack* s, int x)
{
    if (s->ptr >= s->max)                       // ������ ���� ��
        return -1;
    s->stk[s->ptr++] = x;
    return 0;
}

/*--- ���ÿ��� �����͸� �� ---*/
int Pop(IntStack* s, int* x)
{
    if (s->ptr <= 0)                            // ������ ��� ����
        return -1;
    *x = s->stk[--s->ptr];
    return 0;
}

/*--- ���ÿ��� �����͸� ��ũ ---*/
int Peek(const IntStack* s, int* x)
{
    if (s->ptr <= 0)                            // ������ ��� ����
        return -1;
    *x = s->stk[s->ptr - 1];
    return 0;
}

/*--- ������ ��� ��� ����(Ŭ����) ---*/
void Clear(IntStack* s)
{
    s->ptr = 0;
}

/*--- ������ �ִ� �뷮 ---*/
int Capacity(const IntStack* s)
{
    return s->max;
}

/*--- ���ÿ� �׿� �ִ� ������ �� ---*/
int Size(const IntStack* s)
{
    return s->ptr;
}

/*--- ������ ��� �ִ°�? ---*/
int IsEmpty(const IntStack* s)
{
    return s->ptr <= 0;
}

/*--- ������ ���� á�°�? ---*/
int IsFull(const IntStack* s)
{
    return s->ptr >= s->max;
}

/*--- ���ÿ��� �˻� ---*/
int Search(const IntStack* s, int x)
{
    for (int i = s->ptr - 1; i >= 0; i--)   // �����(top) �� �ٴ�(bottom)���� ���� �˻�
        if (s->stk[i] == x)
            return i;       // �˻� ����
    return -1;              // �˻� ����
}

/*--- ��� ������ ��� ---*/
void Print(const IntStack* s)
{
    for (int i = 0; i < s->ptr; i++)        // �ٴ�(bottom) �� �����(top)�� ��ĵ
        printf("%d ", s->stk[i]);
    putchar('\n');
}

/*--- ���� ���� ---*/
void Terminate(IntStack* s)
{
    if (s->stk != NULL)
        free(s->stk);       // �迭�� ����
    s->max = s->ptr = 0;
}

// ����4-1 int�� ���� IntStack�� ���

int exstack(void)
{
    IntStack s;

    if (Initialize(&s, 64) == -1) {
        puts("���� ������ �����߽��ϴ�.");
        return 1;
    }

    while (1) {
        int menu, x;
        int idx;

        printf("���� ������ ��:%d / %d\n", Size(&s), Capacity(&s));
        printf("(1)Ǫ�� (2)�� (3)��ũ (4)��� (5)�˻� (6) Ŭ���� (7) ������� ���� (0) ����: ");
        scanf("%d", &menu);

        if (menu == 0) break;

        switch (menu) {
        case 1: /*--- Ǫ�� ---*/
            printf("������: ");
            scanf("%d", &x);
            if (Push(&s, x) == -1)
                puts("\a����: Ǫ�ÿ� �����߽��ϴ�.");
            break;

        case 2: /*--- �� ---*/
            if (Pop(&s, &x) == -1)
                puts("\a����: �˿� �����߽��ϴ�.");
            else
                printf("�� �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 3: /*--- ��ũ ---*/
            if (Peek(&s, &x) == -1)
                puts("\a����: ��ũ�� �����߽��ϴ�.");
            else
                printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 4: /*--- ��� ---*/
            Print(&s);
            break;

        case 5: /*--- �˻� ---*/
            printf("�˻��� ������: ");
            scanf("%d", &x);
            if ((idx = Search(&s, x)) == -1)
                puts("\a����: �˻��� �����߽��ϴ�.");
            else
                printf("�� �����ʹ� �ε���%d�� ��ġ�� �ֽ��ϴ�.\n", idx);
            break;

        case 6: /*--- Ŭ���� ---*/
            Clear(&s);
            break;

        case 7: /*--- ����ִ��� ���� ---*/
            printf("������ %s��\n", IsEmpty(&s) ? "��� �ֽ��ϴ�" : "��� ���� �ʽ��ϴ�");
            printf("������ %s��\n", IsFull(&s) ? "���� á���ϴ�" : "���� ���� �ʾҽ��ϴ�");
            break;
        }
    }

    Terminate(&s);

}

// ����4-6 int�� ��ť IntDequeue(���)
#ifndef ___IntDequeue
#define ___IntDequeue

/*--- ��ť�� �����ϴ� ����ü ---*/
typedef struct {
    int max;        // ��ť�� �ִ� �뷮
    int num;        // ������ ������ ��
    int front;      // �� �� ��� Ŀ��
    int rear;       // �� �� ��� Ŀ��
    int* que;       // ��ť�� �� �� ��ҿ� ���� ������
} IntDequeue;

/*--- ��ť  �ʱ�ȭ ---*/
int Initialize(IntDequeue* q, int max);

/*--- ��ť�� �� �տ� �����͸� ��ť ---*/
int EnqueFront(IntDequeue* q, int x);

/*--- ��ť�� �� �ڿ� �����͸� ��ť ---*/
int EnqueRear(IntDequeue* q, int x);

/*--- ��ť�� �� �տ��� �����͸� ��ť ---*/
int DequeFront(IntDequeue* q, int* x);

/*--- ��ť�� �� �ڿ��� �����͸� ��ť ---*/
int DequeRear(IntDequeue* q, int* x);

/*--- ��ť�� �� �տ��� �����͸� ��ũ ---*/
int PeekFront(const IntDequeue* q, int* x);

/*--- ��ť�� �� �ڿ��� �����͸� ��ũ ---*/
int PeekRear(const IntDequeue* q, int* x);

/*--- ��� ������ ���� ---*/
void Clear(IntDequeue* q);

/*--- ��ť �� �ִ� �뷮 ---*/
int Capacity(const IntDequeue* q);

/*--- ��ť �� ����� ������ �� ---*/
int Size(const IntDequeue* q);

/*--- ��ť �� ��� �ִ°�? ---*/
int IsEmpty(const IntDequeue* q);

/*--- ��ť �� ���� á�°�? ---*/
int IsFull(const IntDequeue* q);

/*--- ��ť ���� �˻� ---*/
int Search(const IntDequeue* q, int x);

/*--- ��ť ���� �˻�(���� �ε����� ��ȯ) ---*/
int Search2(const IntDequeue* q, int x);

/*--- ��� ������ ��� ---*/
void Print(const IntDequeue* q);

/*--- ��ť  ���� ---*/
void Terminate(IntDequeue* q);

#endif

// ����4-6 int�� ��ť IntDequeue(�ҽ�)
#include <stdio.h>
#include <stdlib.h>
#include "IntDequeue.h"

/*--- ��ť �ʱ�ȭ ---*/
int Initialize(IntDequeue* q, int max)
{
    q->num = q->front = q->rear = 0;
    if ((q->que = calloc(max, sizeof(int))) == NULL) {
        q->max = 0;                         // �迭 ������ ����
        return -1;
    }
    q->max = max;
    return 0;
}

/*--- ��ť�� �� �տ� �����͸� ��ť ---*/
int EnqueFront(IntDequeue* q, int x)
{
    if (q->num >= q->max)
        return -1;                          // ��ť�� ���� ��
    else {
        q->num++;
        if (--q->front < 0)
            q->front = q->max - 1;
        q->que[q->front] = x;
        return 0;
    }
}

/*--- ��ť�� �� �ڿ� �����͸� ��ť ---*/
int EnqueRear(IntDequeue* q, int x)
{
    if (q->num >= q->max)
        return -1;                          // ��ť�� ���� ��
    else {
        q->num++;
        q->que[q->rear++] = x;
        if (q->rear == q->max)
            q->rear = 0;
        return 0;
    }
}

/*--- ��ť�� �� �տ��� �����͸� ��ť ---*/
int DequeFront(IntDequeue* q, int* x)
{
    if (q->num <= 0)                        // ��ť�� ��� ����
        return -1;
    else {
        q->num--;
        *x = q->que[q->front++];
        if (q->front == q->max)
            q->front = 0;
        return 0;
    }
}

/*--- ��ť�� �� �ڿ��� �����͸� ��ť ---*/
int DequeRear(IntDequeue* q, int* x)
{
    if (q->num <= 0)                        // ��ť�� ��� ����
        return -1;
    else {
        q->num--;
        if (--q->rear < 0)
            q->rear = q->max - 1;
        *x = q->que[q->rear];
        return 0;
    }
}

/*--- ��ť�� �� �տ��� �����͸� ��ũ ---*/
int PeekFront(const IntDequeue* q, int* x)
{
    if (q->num <= 0)                        // ��ť�� ��� ����
        return -1;
    *x = q->que[q->front];
    return 0;
}

/*--- ��ť�� �� �ڿ��� �����͸� ��ũ ---*/
int PeekRear(const IntDequeue* q, int* x)
{
    if (q->num <= 0)                        // ��ť�� ��� ����
        return -1;
    *x = q->que[q->rear];
    return 0;
}

/*--- ��� ������ ���� ---*/
void Clear(IntDequeue* q)
{
    q->num = q->front = q->rear = 0;
}

/*--- ��ť�� �ִ� �뷮 ---*/
int Capacity(const IntDequeue* q)
{
    return q->max;
}

/*--- ��ť�� �׿� �ִ� ������ �� ---*/
int Size(const IntDequeue* q)
{
    return q->num;
}

/*--- ��ť�� ��� �ִ°�? ---*/
int IsEmpty(const IntDequeue* q)
{
    return q->num <= 0;
}

/*--- ��ť�� ���� á�°�? ---*/
int IsFull(const IntDequeue* q)
{
    return q->num >= q->max;
}

/*--- ��ť���� �˻� ---*/
int Search(const IntDequeue* q, int x)
{
    int idx;

    for (int i = 0; i < q->num; i++) {
        if (q->que[idx = (i + q->front) % q->max] == x)
            return idx;     // �˻� ����
    }
    return -1;              // �˻� ����
}

/*--- ��ť���� �˻�(���� �ε����� ��ȯ) ---*/
int Search2(const IntDequeue* q, int x)
{
    for (int i = 0; i < q->num; i++) {
        if (q->que[(i + q->front) % q->max] == x)
            return i;       // �˻� ����
    }
    return -1;              // �˻� ����
}

/*--- ��� ������ ��� ---*/
void Print(const IntDequeue* q)
{
    for (int i = 0; i < q->num; i++)
        printf("%d ", q->que[(i + q->front) % q->max]);
    putchar('\n');
}

/*--- ��ť ���� ---*/
void Terminate(IntDequeue* q)
{
    if (q->que != NULL)
        free(q->que);                           // �迭�� ����
    q->max = q->num = q->front = q->rear = 0;
}

// ����4-6 int�� ��ť IntDequeue�� ����ϴ� ���α׷�
#include <stdio.h>
#include "IntDequeue.h"

int main(void)
{
    IntDequeue que;

    if (Initialize(&que, 64) == -1) {
        puts("ť�� ������ �����߽��ϴ�.");
        return 1;
    }

    while (1) {
        int m, x;
        int idx;

        printf("���� ������ ��:%d/%d\n", Size(&que), Capacity(&que));
        printf("(1)�� �տ� ��ť (2)�� �տ������� ��ť (3)�� �տ������� ��ũ (4)���\n"
            "(5)�� �ڿ� ��ť (6)�� �ڿ������� ��ť (7)�� �ڿ������� ��ũ (8)�˻�\n"
            "(9)Ŭ����          (10)��� �ִ��� ����       (0) ����: ");
        scanf("%d", &m);

        if (m == 0) break;

        switch (m) {
        case 1: /*--- �� �տ� ��ť ---*/
            printf("������: ");   scanf("%d", &x);
            if (EnqueFront(&que, x) == -1)
                puts("\a����: ��ť�� �����߽��ϴ�.");
            break;

        case 2: /*--- �� �տ������� ��ť ---*/
            if (DequeFront(&que, &x) == -1)
                puts("\a����: ��ť�� �����߽��ϴ�.");
            else
                printf("��ť �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 3: /*--- �� �տ������� ��ũ ---*/
            if (PeekFront(&que, &x) == -1)
                puts("\a����: ��ũ�� �����߽��ϴ�.");
            else
                printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 4: /*--- ��� ---*/
            Print(&que);
            break;

        case 5: /*--- �� �ڿ� ��ť ---*/
            printf("������: ");   scanf("%d", &x);
            if (EnqueRear(&que, x) == -1)
                puts("\a����: ��ť�� �����߽��ϴ�.");
            break;

        case 6: /*--- �� �ڿ������� ��ť ---*/
            if (DequeRear(&que, &x) == -1)
                puts("\a����: ��ť�� �����߽��ϴ�.");
            else
                printf("��ť �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 7: /*--- �� �ڿ������� ��ũ ---*/
            if (PeekRear(&que, &x) == -1)
                puts("\a����: ��ũ�� �����߽��ϴ�.");
            else
                printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
            break;

        case 8: /*--- �˻� ---*/
            printf("�˻��� ������: ");
            scanf("%d", &x);
            if ((idx = Search(&que, x)) == -1)
                puts("\a����: �˻��� �����߽��ϴ�.");
            else {
                printf("�� �����ʹ� �ε���%d�� ��ġ�� �ֽ��ϴ�.\n", idx);
                printf("ť�� �� �� ��ҷκ��� %d�� ���� ��ġ�Դϴ�.\n", Search2(&que, x));
            }
            break;

        case 9: /*--- Ŭ���� ---*/
            Clear(&que);
            break;

        case 10: /*--- ��� �ִ��� ���� ---*/
            printf("ť�� %s��\n", IsEmpty(&que) ? "��� �ֽ��ϴ�" : "��� ���� �ʽ��ϴ�");
            printf("ť�� %s��\n", IsFull(&que) ? "���� á���ϴ�" : "���� ���� �ʾҽ��ϴ�");
            break;
        }
    }

    Terminate(&que);

    return 0;
}