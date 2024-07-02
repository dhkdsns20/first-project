#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100  // 큐의 최대 크기

typedef char element; // 이진 탐색 트리 element의 자료형을 char로 정의

typedef struct treeNode {
    char key;                // 데이터 필드
    struct treeNode* left;   // 왼쪽 서브 트리 링크 필드
    struct treeNode* right;  // 오른쪽 서브 트리 링크 필드
} treeNode;

typedef treeNode* tree_pointer; // treeNode의 포인터를 tree_pointer로 정의
tree_pointer queue[MAX_QUEUE_SIZE];

// 큐에 원소를 추가하는 함수
void addq(int front, int* rear, tree_pointer item) {
    if ((*rear + 1) % MAX_QUEUE_SIZE == front) {
        printf("큐에 공간이 없습니다.\n");
        return;
    }
    *rear = (*rear + 1) % MAX_QUEUE_SIZE;
    queue[*rear] = item; 
}

// 큐에서 원소를 삭제하는 함수
tree_pointer deleteq(int* front, int* rear) {
    if (*front == *rear) {
        //printf("큐가 비었습니다.\n");
        return NULL;
    }
    *front = (*front + 1) % MAX_QUEUE_SIZE;
    return queue[*front];
}

// 레벨 순회 출력 함수
void displayLevelorder(tree_pointer ptr) {
    int front = 0, rear = 0;

    tree_pointer queue[MAX_QUEUE_SIZE];

    if (!ptr) return; // 트리가 비어 있는 경우

    addq(front, &rear, ptr);

    for (;;) {
        ptr = deleteq(&front, &rear, queue);
        if (!ptr) break; //ptr이 NULL인 경우 큐에 원소가 없다는 의미 이므로 break로 함수 종료
        printf("%c ", ptr->key);
        if (ptr->left) //BFS 이므로 자식노드를 왼쪽부터 탐색한다.
            addq(front, &rear, ptr->left);
        if (ptr->right)
            addq(front, &rear, ptr->right);
    }
}

// 이진 탐색 트리에서 키값이 x인 노드의 위치를 탐색하는 연산
treeNode* searchBST(treeNode* root, char x) {
    treeNode* p;
    p = root;
    while (p != NULL) {
        if (x < p->key) p = p->left;
        else if (x == p->key) return p;
        else p = p->right;
    }
    printf("\n 찾는 키가 없습니다!");
    return p;
}

// 포인터 p가 가리키는 노드와 비교하여 노드 x를 삽입하는 연산
treeNode* insertNode(treeNode* p, char x) {
    treeNode* newNode;
    if (p == NULL) {
        newNode = (treeNode*)malloc(sizeof(treeNode));
        newNode->key = x;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else if (x < p->key)  p->left = insertNode(p->left, x);
    else if (x > p->key)  p->right = insertNode(p->right, x);
    else  printf("\n 이미 같은 키가 있습니다! \n");

    return p;
}

// 이진 탐색 트리를 중위 순회하면서 출력하는 연산
void displayInorder(treeNode* root) {
    if (root) {
        displayInorder(root->left);
        printf("%c_", root->key);
        displayInorder(root->right);
    }
}

int main() {
    treeNode* root = NULL;

    root = insertNode(root, 'G');
    insertNode(root, 'I');
    insertNode(root, 'H');
    insertNode(root, 'D');
    insertNode(root, 'B');
    insertNode(root, 'M');
    insertNode(root, 'N');
    insertNode(root, 'A');
    insertNode(root, 'J');
    insertNode(root, 'E');
    insertNode(root, 'Q');
    displayInorder(root);
    printf("\n");
    displayLevelorder(root);

    return 0;
}
