
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>			// 메모리 누수를 확인하기 위해 CRT 디버그 함수 사용

#define MAXSTRLEN	16

//------------------------------------------------------------
// Week5_exer1
// Ver3: dummy head 노드 이용
//------------------------------------------------------------

// 단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct _LISTNODE_ {
	float coef;
	int expo;
	struct _LISTNODE_* next;
} LISTNODE;

// 리스트의 시작을 나타내는 head 노드를 구조체로 정의
typedef struct _LINKEDLIST_ {
	LISTNODE* head;
	int numOfData;
} LINKEDLIST;

/*
 * 연결 리스트 초기화, dummy head 노드 메모리 할당
 */
void InitList(LINKEDLIST* pList)
{
	pList->head = (LISTNODE*)calloc(1, sizeof(LISTNODE));
	pList->head->next = NULL;
	pList->numOfData = 0;
}

/*
 * 연결 리스트 메모리 해제
 */
void FreeList(LINKEDLIST* pList)
{
	LISTNODE* pre = pList->head;
	LISTNODE* cur = pList->head->next;

	while (cur != NULL)
	{
		pre = cur;
		cur = cur->next;

		free(pre);
		pre = NULL;
	}
	free(pList->head);
	pList->head = NULL;
}



/*
 * 리스트의 마지막에 새로운 노드 추가
 */
void InsertLast(LINKEDLIST* pList, float coef , int expo)
{
	LISTNODE* pre = NULL;
	LISTNODE* cur = NULL;
	LISTNODE* newNode = NULL;

	newNode = (LISTNODE*)calloc(1, sizeof(LISTNODE));
	newNode->coef = coef;
	newNode->expo = expo;
	newNode->next = NULL;

	pre = pList->head;
	cur = pList->head->next;		// head는 초기화 과정에서 dummy로 만들어주었으므로, head->next 부터 순회

	while (cur != NULL)
	{
		pre = cur;
		cur = cur->next;
	}
	//newNode->next = NULL;			// NULL임
	newNode->next = pre->next;		// NULL 임
	pre->next = newNode;
	pList->numOfData += 1;			// 데이터 수 증가
}



/*
* List A와 List B를 더해 List C를 저장한다.
*/
void AddPoly(LINKEDLIST* ListA, LINKEDLIST* ListB, LINKEDLIST* ListC) {
	LISTNODE* p = NULL;
	LISTNODE* q = NULL;

	p = ListA->head->next;
	q = ListB->head->next;

	float r;

	while (p && q) {
		if (p->expo == q->expo) {					//ListA 와 ListB가 같은 차항일 경우
			r = p->coef + q->coef;					//두 계수를 더한 것.
			InsertLast(ListC, r, p->expo);		    //r을 ListC에 저장
			p = p->next; q = q->next;				//다음 차항을 가리킴
		}
		else if (p->expo > q->expo) {							//ListA의 차수가 ListB의 차수보다 클 경우
			InsertLast(ListC, p->coef, p->expo); p = p->next;
		}
		else {													//ListB의 차수가 ListA의 차수보다 클 경우
			InsertLast(ListC, q->coef, q->expo); q = q->next;
		}
	}

	for(;p!=NULL;p=p->next)						// ListA의 남은 것들을 C에 추가
		InsertLast(ListC, p->coef, p->expo);

	for (; q != NULL; q = q->next)				//ListB의 남은 것들을 C에 추가
		InsertLast(ListC, q->coef, q->expo);
}

/*
 * list의 정보를 출력
 */
void PrintList(LINKEDLIST* pList)
{
	LISTNODE* cur = NULL;

	cur = pList->head->next;

	
	while (cur != NULL)
	{
		printf("%2.1fx^%d", cur->coef,cur->expo);
		cur = cur->next;
		if (cur != NULL)
		{
			printf(" + ");
		}
	}
	printf("\n");
}

int main()
{
	LINKEDLIST polyA,polyB,polyC;
	LISTNODE* find = NULL;

	InitList(&polyA);
	InitList(&polyB);
	InitList(&polyC);

	//A 다항식 생성
	InsertLast(&polyA,4,3);
	InsertLast(&polyA,3,2);
	InsertLast(&polyA,1,1);
	InsertLast(&polyA,2,0);
	
	//B 다항식 생성
	InsertLast(&polyB, 4, 3);
	InsertLast(&polyB, 3, 2);
	InsertLast(&polyB, 5, 1);

	//A,B를 더해 C에 저장
	AddPoly(&polyA, &polyB, &polyC);
	
	//A,B,C 출력
	printf("A(x) : "); PrintList(&polyA);
	printf("B(x) : "); PrintList(&polyB);
	printf("C(x) : "); PrintList(&polyC);

	FreeList(&polyA); FreeList(&polyB); FreeList(&polyC);

	return 0;
}
