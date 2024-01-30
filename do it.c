// 연습3-1　선형 검색(보초법: for 문)
#include <stdio.h>
#include <stdlib.h>

/*--- 요소의 개수가 n인 배열 a에서 key와 일치하는 요소를 선형 검색(보초법) ---*/
int search(int a[], int n, int key)
{
    int i, count = 0;

    a[n] = key;         // 보초를 추가
    printf("   | 0 1 2 3 4 5 6\n"); //배열 인덱
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
    puts("선형 검색(보초법)");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx + 1, sizeof(int));   // 요소의 개수가 (nx + 1)인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {          // 주의: 값을 읽은 것은 nx개
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    printf("검색값: ");
    scanf("%d", &ky);

    int idx = search(x, nx, ky);            // 배열 x에서 값이 ky인 요소를 선형 검색

    if (idx == -1)
        puts("검색에 실패했습니다.");
    else
        printf("%d(은)는 x[%d]에 있습니다.\n", ky, idx);

    free(x);                                // 배열 x를 해제
}

int search_idx(const int a[], int n, int key, int idx[]) {
    int i = 0;
    for (int j = 0; j < n; j++) {
        if (a[j] == key)
            idx[i++] = j;
    }return i;
}


// 연습3-4　이진 검색(검색 과정을 출력)

/*--- 요소의 개수가 n인 배열 a에서 key와 일치하는 요소를 이진 검색 ---*/
int bin_search(const int a[], int n, int key)
{
    int pl = 0;                     // 검색 범위 맨 앞의 인덱스
    int pr = n - 1;                 // 검색 범위 맨 끝의 인덱스

    printf("   |");
    for (int i = 0; i < n; i++) printf("%4d", i);
    printf("\n---+");
    for (int i = 0; i < n; i++) printf("----", i);
    printf("--\n");

    do {
        int pc = (pl + pr) / 2;     // 검색 범위 한가운데의 인덱스

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

        if (a[pc] == key)           // 검색 성공
            return pc;
        else if (a[pc] < key)
            pl = pc + 1;            // 검색 범위를 뒤쪽 절반으로 좁힘
        else
            pr = pc - 1;            // 검색 범위를 앞쪽 절반으로 좁힘

        printf("   |\n");

    } while (pl <= pr);

    return -1;                      // 검색 실패
}

int bin_search2(const int a[], int n, int key)
{
    int pl = 0;                     // 검색 범위 맨 앞의 인덱스
    int pr = n - 1;                 // 검색 범위 맨 끝의 인덱스

    do {
        int pc = (pl + pr) / 2;     // 검색 범위 한가운데의 인덱스
        if (a[pc] == key) {         // 검색 성공
            while (pc > pl && a[pc - 1] == key) //pc보다 작은 index에 key가 있으면!
                pc--;               //pc를 감소시킨다.
            return pc;
        }
        else if (a[pc] < key)
            pl = pc + 1;            // 검색 범위를 뒤쪽 절반으로 좁힘
        else
            pr = pc - 1;            // 검색 범위를 앞쪽 절반으로 좁힘
    } while (pl <= pr);

    return -1;                      // 검색 실패
}

return min;
}
void binary_search(void)
{
    int nx, ky;

    puts("이진 검색");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    printf("오름차순으로 입력하세요.\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);

    for (int i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i - 1]);      // 바로 앞의 값보다 작으면 다시 입력
    }
    printf("검색값: ");
    scanf("%d", &ky);

    int idx = bin_search2(x, nx, ky);    // 배열 x에서 값이 ky인 요소를 이진 검색

    if (idx == -1)
        puts("검색에 실패했습니다.");
    else
        printf("%d는(은) x[%d]에 있습니다.\n", ky, idx);

    free(x);                            // 배열 x를 해제
}

// 연습3-6　bsearch 함수를 사용하여 내림차순으로 정렬한 long형 배열에서 검색

/*--- 정수를 비교하는 함수(long형 내림차순) ---*/
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

    puts("bsearch 함수를 사용하여 검색");
    printf("요소 개수: ");
    scanf("%d", &nx);
    long* x = calloc(nx, sizeof(long)); // 요소의 개수가 nx인 long형 배열 x를 생성

    printf("내림차순으로 입력하세요.\n");

    printf("x[0] : ");
    scanf("%ld", &x[0]);

    for (int i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%ld", &x[i]);
        } while (x[i] > x[i - 1]);      // 바로 앞의 값보다 크면 다시 입력
    }

    printf("검색값: ");
    scanf("%d", &ky);

    long* p = bsearch(
        &ky,                            // 검색값에 대한 포인터
        x,                              // 배열
        nx,                             // 요소의 개수
        sizeof(int),                    // 요소의 크기
        (int (*)(const void*, const void*))long_cmpr  // 비교 함수
    );

    if (p == NULL)
        puts("검색에 실패했습니다.");
    else
        printf("%d는(은) x[%d]에 있습니다.\n", ky, (int)(p - x));

    free(x);                            // 배열 x를 해제
}


// 연습3-7　bsearch 함수와 같은 형식의 선형 탐색 함수

/*--- base가 가리키는 요소의 크기가 size이고 요소의 개수가 nmemb인 배열에서 key와 일치하는 요소를
      비교 함수 compar를 사용해서 선형 검색 ---*/
void* seqsearch(const void* key, const void* base, size_t nmemb, size_t size,
    int (*compar)(const void*, const void*))
{
    char* x = (char*)base;

    for (size_t i = 0; i < nmemb; i++)
        if (!compar((const void*)&x[i * size], key))
            return (&x[i * size]);
    return NULL;                            // 검색 실패
}

/*--- 정수를 비교하는 함수 ---*/
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

    puts("seqsearch 함수로 검색");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    for (int i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    printf("검색값: ");
    scanf("%d", &ky);

    int* p = seqsearch(
        &ky,                            // 검색값에 대한 포인터
        x,                              // 배열
        nx,                             // 요소의 개수
        sizeof(int),                    // 요소의 크기
        (int (*)(const void*, const void*))int_cmp    // 비교 함수
    );

    if (p == NULL)
        puts("검색에 실패했습니다.");
    else
        printf("%d는(은) x[%d]에 있습니다.\n", ky, (int)(p - x));

    free(x);                            // 배열 x를 해제
}

// 연습3-9　bsearch 함수를 확장한 함수(맨 앞에 있는 요소를 검색)
#include <stdio.h>
#include <stdlib.h>

/*--- base가 가리키는 요소의 크기가 size이고 요소의 개수가 nmemb인 배열에서 key와 일치하는 요소를
      비교 함수 compar를 이용해서 이진 검색
      ※ key와 같은 요소가 여러 개 있으면 맨 앞의 요소를 검색 ---*/
void* bsearchx(const void* key, const void* base, size_t nmemb, size_t size,
    int (*compar)(const void*, const void*))
{
    char* x = (char*)base;
    size_t pl = 0;                          // 검색 범위 맨 앞의 인덱스
    size_t pr = nmemb - 1;                  // 검색 범위 맨 끝의 인덱스

    if (nmemb > 0) {
        while (1) {
            size_t pc = (pl + pr) / 2;      // 검색 범위 한가운데의 인덱스
            int comp = compar((const void*)&x[pc * size], key);

            if (comp == 0) {                // 검색 성공
                for (; pc > pl; pc--)      // key와 같은 앞쪽 요소를 검색
                    if (compar((const void*)&x[(pc - 1) * size], key))
                        break;
                return &x[pc * size];
            }
            else if (pl == pr)
                break;
            else if (comp < 0)
                pl = pc + 1;                // 검색 범위를 뒤쪽 절반으로 좁힘
            else
                pr = pc - 1;                // 검색 범위를 앞쪽 절반으로 좁힘
        }
    }

    return NULL;                            // 검색 실패
}

/*--- 정수를 비교하는 함수 ---*/
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

    puts("bsearchx 함수로 검색");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int* x = calloc(nx, sizeof(int));   // 요소 개수가 nx인 int형 배열 x를 생성

    printf("오름차순으로 입력하세요.\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);

    for (int i = 1; i < nx; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i - 1]);      // 바로 앞의 값보다 작으면 다시 입력
    }

    printf("검색값: ");
    scanf("%d", &ky);

    int* p = bsearchx(
        &ky,                            // 검색값에 대한 포인터
        x,                              // 배열
        nx,                             // 요소의 개수
        sizeof(int),                    // 요소의 크기
        (int (*)(const void*, const void*))int_cmp    // 비교 함수
    );

    if (p == NULL)
        puts("검색에 실패했습니다.");
    else
        printf("%d는(은) x[%d]에 있습니다.\n", ky, (int)(p - x));

    free(x);                            // 배열 x를 해제

}


// int형 스택 IntStack(헤더)
#ifndef ___IntStack
#define ___IntStack

/*--- 스택을 구현하는 구조체 ---*/
typedef struct {
    int max;    // 스택 용량
    int ptr;    // 스택 포인터 
    int* stk;   // 스택의 첫 요소에 대한 포인터
} IntStack;

/*--- 스택 초기화 ---*/
int Initialize(IntStack* s, int max);

/*--- 스택에 데이터를 푸시 ---*/
int Push(IntStack* s, int x);

/*--- 스택에서 데이터를 팝 ---*/
int Pop(IntStack* s, int* x);

/*--- 스택에서 데이터를 피크 ---*/
int Peek(const IntStack* s, int* x);

/*--- 스택 비우기 ---*/
void Clear(IntStack* s);

/*--- 스택 용량 ---*/
int Capacity(const IntStack* s);

/*--- 스택에 저장된 데이터 수 ---*/
int Size(const IntStack* s);

/*--- 스택은 비어 있는가? ---*/
int IsEmpty(const IntStack* s);

/*--- 스택은 가득 찼는가? ---*/
int IsFull(const IntStack* s);

/*--- 스택에서 검색 ---*/
int Search(const IntStack* s, int x);

/*--- 모든 데이터 출력 ---*/
void Print(const IntStack* s);

/*--- 스택 종료 ---*/
void Terminate(IntStack* s);

#endif

// int형 스택 IntStack(소스)


/*--- 스택 초기화 ---*/
int Initialize(IntStack* s, int max)
{
    s->ptr = 0;
    if ((s->stk = calloc(max, sizeof(int))) == NULL) {
        s->max = 0;                             // 배열의 생성에 실패
        return -1;
    }
    s->max = max;
    return 0;
}

/*--- 스택에 데이터 푸시 ---*/
int Push(IntStack* s, int x)
{
    if (s->ptr >= s->max)                       // 스택이 가득 참
        return -1;
    s->stk[s->ptr++] = x;
    return 0;
}

/*--- 스택에서 데이터를 팝 ---*/
int Pop(IntStack* s, int* x)
{
    if (s->ptr <= 0)                            // 스택이 비어 있음
        return -1;
    *x = s->stk[--s->ptr];
    return 0;
}

/*--- 스택에서 데이터를 피크 ---*/
int Peek(const IntStack* s, int* x)
{
    if (s->ptr <= 0)                            // 스택이 비어 있음
        return -1;
    *x = s->stk[s->ptr - 1];
    return 0;
}

/*--- 스택의 모든 요소 삭제(클리어) ---*/
void Clear(IntStack* s)
{
    s->ptr = 0;
}

/*--- 스택의 최대 용량 ---*/
int Capacity(const IntStack* s)
{
    return s->max;
}

/*--- 스택에 쌓여 있는 데이터 수 ---*/
int Size(const IntStack* s)
{
    return s->ptr;
}

/*--- 스택은 비어 있는가? ---*/
int IsEmpty(const IntStack* s)
{
    return s->ptr <= 0;
}

/*--- 스택은 가득 찼는가? ---*/
int IsFull(const IntStack* s)
{
    return s->ptr >= s->max;
}

/*--- 스택에서 검색 ---*/
int Search(const IntStack* s, int x)
{
    for (int i = s->ptr - 1; i >= 0; i--)   // 꼭대기(top) → 바닥(bottom)으로 선형 검색
        if (s->stk[i] == x)
            return i;       // 검색 성공
    return -1;              // 검색 실패
}

/*--- 모든 데이터 출력 ---*/
void Print(const IntStack* s)
{
    for (int i = 0; i < s->ptr; i++)        // 바닥(bottom) → 꼭대기(top)로 스캔
        printf("%d ", s->stk[i]);
    putchar('\n');
}

/*--- 스택 종료 ---*/
void Terminate(IntStack* s)
{
    if (s->stk != NULL)
        free(s->stk);       // 배열을 삭제
    s->max = s->ptr = 0;
}

// 연습4-1 int형 스택 IntStack의 사용

int exstack(void)
{
    IntStack s;

    if (Initialize(&s, 64) == -1) {
        puts("스택 생성에 실패했습니다.");
        return 1;
    }

    while (1) {
        int menu, x;
        int idx;

        printf("현재 데이터 수:%d / %d\n", Size(&s), Capacity(&s));
        printf("(1)푸시 (2)팝 (3)피크 (4)출력 (5)검색 (6) 클리어 (7) 비었는지 판정 (0) 종료: ");
        scanf("%d", &menu);

        if (menu == 0) break;

        switch (menu) {
        case 1: /*--- 푸시 ---*/
            printf("데이터: ");
            scanf("%d", &x);
            if (Push(&s, x) == -1)
                puts("\a오류: 푸시에 실패했습니다.");
            break;

        case 2: /*--- 팝 ---*/
            if (Pop(&s, &x) == -1)
                puts("\a오류: 팝에 실패했습니다.");
            else
                printf("팝 데이터는 %d입니다.\n", x);
            break;

        case 3: /*--- 피크 ---*/
            if (Peek(&s, &x) == -1)
                puts("\a오류: 피크에 실패했습니다.");
            else
                printf("피크 데이터는 %d입니다.\n", x);
            break;

        case 4: /*--- 출력 ---*/
            Print(&s);
            break;

        case 5: /*--- 검색 ---*/
            printf("검색할 데이터: ");
            scanf("%d", &x);
            if ((idx = Search(&s, x)) == -1)
                puts("\a오류: 검색에 실패했습니다.");
            else
                printf("그 데이터는 인덱스%d의 위치에 있습니다.\n", idx);
            break;

        case 6: /*--- 클리어 ---*/
            Clear(&s);
            break;

        case 7: /*--- 비어있는지 판정 ---*/
            printf("스택은 %s。\n", IsEmpty(&s) ? "비어 있습니다" : "비어 있지 않습니다");
            printf("스택은 %s。\n", IsFull(&s) ? "가득 찼습니다" : "가득 차지 않았습니다");
            break;
        }
    }

    Terminate(&s);

}

// 연습4-6 int형 디큐 IntDequeue(헤더)
#ifndef ___IntDequeue
#define ___IntDequeue

/*--- 디큐를 구현하는 구조체 ---*/
typedef struct {
    int max;        // 디큐의 최대 용량
    int num;        // 현재의 데이터 수
    int front;      // 맨 앞 요소 커서
    int rear;       // 맨 뒤 요소 커서
    int* que;       // 디큐의 맨 앞 요소에 대한 포인터
} IntDequeue;

/*--- 디큐  초기화 ---*/
int Initialize(IntDequeue* q, int max);

/*--- 디큐의 맨 앞에 데이터를 인큐 ---*/
int EnqueFront(IntDequeue* q, int x);

/*--- 디큐의 맨 뒤에 데이터를 인큐 ---*/
int EnqueRear(IntDequeue* q, int x);

/*--- 디큐의 맨 앞에서 데이터를 디큐 ---*/
int DequeFront(IntDequeue* q, int* x);

/*--- 디큐의 맨 뒤에서 데이터를 디큐 ---*/
int DequeRear(IntDequeue* q, int* x);

/*--- 디큐의 맨 앞에서 데이터를 피크 ---*/
int PeekFront(const IntDequeue* q, int* x);

/*--- 디큐의 맨 뒤에서 데이터를 피크 ---*/
int PeekRear(const IntDequeue* q, int* x);

/*--- 모든 데이터 삭제 ---*/
void Clear(IntDequeue* q);

/*--- 디큐 의 최대 용량 ---*/
int Capacity(const IntDequeue* q);

/*--- 디큐 에 저장된 데이터 수 ---*/
int Size(const IntDequeue* q);

/*--- 디큐 가 비어 있는가? ---*/
int IsEmpty(const IntDequeue* q);

/*--- 디큐 가 가득 찼는가? ---*/
int IsFull(const IntDequeue* q);

/*--- 디큐 에서 검색 ---*/
int Search(const IntDequeue* q, int x);

/*--- 디큐 에서 검색(논리적 인덱스를 반환) ---*/
int Search2(const IntDequeue* q, int x);

/*--- 모든 데이터 출력 ---*/
void Print(const IntDequeue* q);

/*--- 디큐  종료 ---*/
void Terminate(IntDequeue* q);

#endif

// 연습4-6 int형 디큐 IntDequeue(소스)
#include <stdio.h>
#include <stdlib.h>
#include "IntDequeue.h"

/*--- 디큐 초기화 ---*/
int Initialize(IntDequeue* q, int max)
{
    q->num = q->front = q->rear = 0;
    if ((q->que = calloc(max, sizeof(int))) == NULL) {
        q->max = 0;                         // 배열 생성에 실패
        return -1;
    }
    q->max = max;
    return 0;
}

/*--- 디큐의 맨 앞에 데이터를 인큐 ---*/
int EnqueFront(IntDequeue* q, int x)
{
    if (q->num >= q->max)
        return -1;                          // 디큐가 가득 참
    else {
        q->num++;
        if (--q->front < 0)
            q->front = q->max - 1;
        q->que[q->front] = x;
        return 0;
    }
}

/*--- 디큐의 맨 뒤에 데이터를 인큐 ---*/
int EnqueRear(IntDequeue* q, int x)
{
    if (q->num >= q->max)
        return -1;                          // 디큐가 가득 참
    else {
        q->num++;
        q->que[q->rear++] = x;
        if (q->rear == q->max)
            q->rear = 0;
        return 0;
    }
}

/*--- 디큐의 맨 앞에서 데이터를 디큐 ---*/
int DequeFront(IntDequeue* q, int* x)
{
    if (q->num <= 0)                        // 디큐가 비어 있음
        return -1;
    else {
        q->num--;
        *x = q->que[q->front++];
        if (q->front == q->max)
            q->front = 0;
        return 0;
    }
}

/*--- 디큐의 맨 뒤에서 데이터를 디큐 ---*/
int DequeRear(IntDequeue* q, int* x)
{
    if (q->num <= 0)                        // 디큐가 비어 있음
        return -1;
    else {
        q->num--;
        if (--q->rear < 0)
            q->rear = q->max - 1;
        *x = q->que[q->rear];
        return 0;
    }
}

/*--- 디큐의 맨 앞에서 데이터를 피크 ---*/
int PeekFront(const IntDequeue* q, int* x)
{
    if (q->num <= 0)                        // 디큐가 비어 있음
        return -1;
    *x = q->que[q->front];
    return 0;
}

/*--- 디큐의 맨 뒤에서 데이터를 피크 ---*/
int PeekRear(const IntDequeue* q, int* x)
{
    if (q->num <= 0)                        // 디큐가 비어 있음
        return -1;
    *x = q->que[q->rear];
    return 0;
}

/*--- 모든 데이터 삭제 ---*/
void Clear(IntDequeue* q)
{
    q->num = q->front = q->rear = 0;
}

/*--- 디큐의 최대 용량 ---*/
int Capacity(const IntDequeue* q)
{
    return q->max;
}

/*--- 디큐에 쌓여 있는 데이터 수 ---*/
int Size(const IntDequeue* q)
{
    return q->num;
}

/*--- 디큐가 비어 있는가? ---*/
int IsEmpty(const IntDequeue* q)
{
    return q->num <= 0;
}

/*--- 디큐가 가득 찼는가? ---*/
int IsFull(const IntDequeue* q)
{
    return q->num >= q->max;
}

/*--- 디큐에서 검색 ---*/
int Search(const IntDequeue* q, int x)
{
    int idx;

    for (int i = 0; i < q->num; i++) {
        if (q->que[idx = (i + q->front) % q->max] == x)
            return idx;     // 검색 성공
    }
    return -1;              // 검색 실패
}

/*--- 디큐에서 검색(논리적 인덱스를 반환) ---*/
int Search2(const IntDequeue* q, int x)
{
    for (int i = 0; i < q->num; i++) {
        if (q->que[(i + q->front) % q->max] == x)
            return i;       // 검색 성공
    }
    return -1;              // 검색 실패
}

/*--- 모든 데이터 출력 ---*/
void Print(const IntDequeue* q)
{
    for (int i = 0; i < q->num; i++)
        printf("%d ", q->que[(i + q->front) % q->max]);
    putchar('\n');
}

/*--- 디큐 종료 ---*/
void Terminate(IntDequeue* q)
{
    if (q->que != NULL)
        free(q->que);                           // 배열을 해제
    q->max = q->num = q->front = q->rear = 0;
}

// 연습4-6 int형 디큐 IntDequeue를 사용하는 프로그램
#include <stdio.h>
#include "IntDequeue.h"

int main(void)
{
    IntDequeue que;

    if (Initialize(&que, 64) == -1) {
        puts("큐의 생성에 실패했습니다.");
        return 1;
    }

    while (1) {
        int m, x;
        int idx;

        printf("현재 데이터 수:%d/%d\n", Size(&que), Capacity(&que));
        printf("(1)맨 앞에 인큐 (2)맨 앞에서부터 디큐 (3)맨 앞에서부터 피크 (4)출력\n"
            "(5)맨 뒤에 인큐 (6)맨 뒤에서부터 디큐 (7)맨 뒤에서부터 피크 (8)검색\n"
            "(9)클리어          (10)비어 있는지 판정       (0) 종료: ");
        scanf("%d", &m);

        if (m == 0) break;

        switch (m) {
        case 1: /*--- 맨 앞에 인큐 ---*/
            printf("데이터: ");   scanf("%d", &x);
            if (EnqueFront(&que, x) == -1)
                puts("\a오류: 인큐에 실패했습니다.");
            break;

        case 2: /*--- 맨 앞에서부터 디큐 ---*/
            if (DequeFront(&que, &x) == -1)
                puts("\a오류: 디큐에 실패했습니다.");
            else
                printf("디큐 데이터는 %d입니다.\n", x);
            break;

        case 3: /*--- 맨 앞에서부터 피크 ---*/
            if (PeekFront(&que, &x) == -1)
                puts("\a오류: 피크에 실패했습니다.");
            else
                printf("피크 데이터는 %d입니다.\n", x);
            break;

        case 4: /*--- 출력 ---*/
            Print(&que);
            break;

        case 5: /*--- 맨 뒤에 인큐 ---*/
            printf("데이터: ");   scanf("%d", &x);
            if (EnqueRear(&que, x) == -1)
                puts("\a오류: 인큐에 실패했습니다.");
            break;

        case 6: /*--- 맨 뒤에서부터 디큐 ---*/
            if (DequeRear(&que, &x) == -1)
                puts("\a오류: 디큐에 실패했습니다.");
            else
                printf("디큐 데이터는 %d입니다.\n", x);
            break;

        case 7: /*--- 맨 뒤에서부터 피크 ---*/
            if (PeekRear(&que, &x) == -1)
                puts("\a오류: 피크에 실패했습니다.");
            else
                printf("피크 데이터는 %d입니다.\n", x);
            break;

        case 8: /*--- 검색 ---*/
            printf("검색할 데이터: ");
            scanf("%d", &x);
            if ((idx = Search(&que, x)) == -1)
                puts("\a오류: 검색에 실패했습니다.");
            else {
                printf("그 데이터는 인덱스%d의 위치에 있습니다.\n", idx);
                printf("큐의 맨 앞 요소로부터 %d개 뒤의 위치입니다.\n", Search2(&que, x));
            }
            break;

        case 9: /*--- 클리어 ---*/
            Clear(&que);
            break;

        case 10: /*--- 비어 있는지 판정 ---*/
            printf("큐가 %s。\n", IsEmpty(&que) ? "비어 있습니다" : "비어 있지 않습니다");
            printf("큐가 %s。\n", IsFull(&que) ? "가득 찼습니다" : "가득 차지 않았습니다");
            break;
        }
    }

    Terminate(&que);

    return 0;
}