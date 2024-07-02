#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100  // ť�� �ִ� ũ��

typedef char element; // ���� Ž�� Ʈ�� element�� �ڷ����� char�� ����

typedef struct treeNode {
    char key;                // ������ �ʵ�
    struct treeNode* left;   // ���� ���� Ʈ�� ��ũ �ʵ�
    struct treeNode* right;  // ������ ���� Ʈ�� ��ũ �ʵ�
} treeNode;

typedef treeNode* tree_pointer; // treeNode�� �����͸� tree_pointer�� ����
tree_pointer queue[MAX_QUEUE_SIZE];

// ť�� ���Ҹ� �߰��ϴ� �Լ�
void addq(int front, int* rear, tree_pointer item) {
    if ((*rear + 1) % MAX_QUEUE_SIZE == front) {
        printf("ť�� ������ �����ϴ�.\n");
        return;
    }
    *rear = (*rear + 1) % MAX_QUEUE_SIZE;
    queue[*rear] = item; 
}

// ť���� ���Ҹ� �����ϴ� �Լ�
tree_pointer deleteq(int* front, int* rear) {
    if (*front == *rear) {
        //printf("ť�� ������ϴ�.\n");
        return NULL;
    }
    *front = (*front + 1) % MAX_QUEUE_SIZE;
    return queue[*front];
}

// ���� ��ȸ ��� �Լ�
void displayLevelorder(tree_pointer ptr) {
    int front = 0, rear = 0;

    tree_pointer queue[MAX_QUEUE_SIZE];

    if (!ptr) return; // Ʈ���� ��� �ִ� ���

    addq(front, &rear, ptr);

    for (;;) {
        ptr = deleteq(&front, &rear, queue);
        if (!ptr) break; //ptr�� NULL�� ��� ť�� ���Ұ� ���ٴ� �ǹ� �̹Ƿ� break�� �Լ� ����
        printf("%c ", ptr->key);
        if (ptr->left) //BFS �̹Ƿ� �ڽĳ�带 ���ʺ��� Ž���Ѵ�.
            addq(front, &rear, ptr->left);
        if (ptr->right)
            addq(front, &rear, ptr->right);
    }
}

// ���� Ž�� Ʈ������ Ű���� x�� ����� ��ġ�� Ž���ϴ� ����
treeNode* searchBST(treeNode* root, char x) {
    treeNode* p;
    p = root;
    while (p != NULL) {
        if (x < p->key) p = p->left;
        else if (x == p->key) return p;
        else p = p->right;
    }
    printf("\n ã�� Ű�� �����ϴ�!");
    return p;
}

// ������ p�� ����Ű�� ���� ���Ͽ� ��� x�� �����ϴ� ����
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
    else  printf("\n �̹� ���� Ű�� �ֽ��ϴ�! \n");

    return p;
}

// ���� Ž�� Ʈ���� ���� ��ȸ�ϸ鼭 ����ϴ� ����
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
