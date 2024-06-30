
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>			// �޸� ������ Ȯ���ϱ� ���� CRT ����� �Լ� ���

#define MAXSTRLEN	16

//------------------------------------------------------------
// Week5_exer1
// Ver3: dummy head ��� �̿�
//------------------------------------------------------------

// �ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct _LISTNODE_ {
	float coef;
	int expo;
	struct _LISTNODE_* next;
} LISTNODE;

// ����Ʈ�� ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct _LINKEDLIST_ {
	LISTNODE* head;
	int numOfData;
} LINKEDLIST;

/*
 * ���� ����Ʈ �ʱ�ȭ, dummy head ��� �޸� �Ҵ�
 */
void InitList(LINKEDLIST* pList)
{
	pList->head = (LISTNODE*)calloc(1, sizeof(LISTNODE));
	pList->head->next = NULL;
	pList->numOfData = 0;
}

/*
 * ���� ����Ʈ �޸� ����
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
 * ����Ʈ�� �������� ���ο� ��� �߰�
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
	cur = pList->head->next;		// head�� �ʱ�ȭ �������� dummy�� ������־����Ƿ�, head->next ���� ��ȸ

	while (cur != NULL)
	{
		pre = cur;
		cur = cur->next;
	}
	//newNode->next = NULL;			// NULL��
	newNode->next = pre->next;		// NULL ��
	pre->next = newNode;
	pList->numOfData += 1;			// ������ �� ����
}



/*
* List A�� List B�� ���� List C�� �����Ѵ�.
*/
void AddPoly(LINKEDLIST* ListA, LINKEDLIST* ListB, LINKEDLIST* ListC) {
	LISTNODE* p = NULL;
	LISTNODE* q = NULL;

	p = ListA->head->next;
	q = ListB->head->next;

	float r;

	while (p && q) {
		if (p->expo == q->expo) {					//ListA �� ListB�� ���� ������ ���
			r = p->coef + q->coef;					//�� ����� ���� ��.
			InsertLast(ListC, r, p->expo);		    //r�� ListC�� ����
			p = p->next; q = q->next;				//���� ������ ����Ŵ
		}
		else if (p->expo > q->expo) {							//ListA�� ������ ListB�� �������� Ŭ ���
			InsertLast(ListC, p->coef, p->expo); p = p->next;
		}
		else {													//ListB�� ������ ListA�� �������� Ŭ ���
			InsertLast(ListC, q->coef, q->expo); q = q->next;
		}
	}

	for(;p!=NULL;p=p->next)						// ListA�� ���� �͵��� C�� �߰�
		InsertLast(ListC, p->coef, p->expo);

	for (; q != NULL; q = q->next)				//ListB�� ���� �͵��� C�� �߰�
		InsertLast(ListC, q->coef, q->expo);
}

/*
 * list�� ������ ���
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

	//A ���׽� ����
	InsertLast(&polyA,4,3);
	InsertLast(&polyA,3,2);
	InsertLast(&polyA,1,1);
	InsertLast(&polyA,2,0);
	
	//B ���׽� ����
	InsertLast(&polyB, 4, 3);
	InsertLast(&polyB, 3, 2);
	InsertLast(&polyB, 5, 1);

	//A,B�� ���� C�� ����
	AddPoly(&polyA, &polyB, &polyC);
	
	//A,B,C ���
	printf("A(x) : "); PrintList(&polyA);
	printf("B(x) : "); PrintList(&polyB);
	printf("C(x) : "); PrintList(&polyC);

	FreeList(&polyA); FreeList(&polyB); FreeList(&polyC);

	return 0;
}
