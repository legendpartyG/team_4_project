/*
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define toString(variable) #variable

typedef struct Node {
    struct Node* next;
    int data;
}Node;

void appendFirst(Node* ptr, int newData);
void append(Node* ptr, int newData);
void showList(Node* ptr);
void deleteList(Node* ptr);
int getNodeLength(Node* ptr);
void insert(Node* ptr, int position, int NewData);
void swapNodeData(Node* node1, Node* node2);
void bubbleSortNode(Node* ptr, int size);
void showListMemory(Node* ptr);
void arrayToList(Node* ptr, int array[], int arraySize);
bool searchList(Node* ptr, int number);
Node* getList();
void generateLottoList(Node* list);


int main(int argc, char const* argv[])
{
    int count = 0;
    int length = 0;

    // list1 ����Ʈ �� �տ� �߰��ϱ�
    printf("[�� �տ� ����Ʈ �߰��ϱ�]\n");

    Node* list1 = malloc(sizeof(Node));
    list1->next = NULL;

    count = 10;
    for (int i = 1; i <= count; i++)
    {
        if (i % 2 == 0) appendFirst(list1, i);
    }
    showList(list1);
    length = getNodeLength(list1);
    printf("list1 length : %d\n\n", length);
    deleteList(list1);

    // list2 ����Ʈ �������� �߰��ϱ�

    printf("[�������� ����Ʈ �߰��ϱ�]\n");

    Node* list2 = malloc(sizeof(Node));
    list2->next = NULL;

    count = 10;
    for (int i = 1; i <= count; i++)
    {
        if (i % 2 == 1) append(list2, i);
    }
    showList(list2);

    length = getNodeLength(list2);
    printf("list2 length : %d\n\n", length);
    deleteList(list2);

    // list3 �־��� ��ġ�� ����Ʈ �����ϱ�

    printf("[Ư�� ��ġ�� ����Ʈ �߰��ϱ�]\n");

    Node* list3 = malloc(sizeof(Node));
    list3->next = NULL;

    count = 5;
    for (int i = 1; i <= count; i++)
    {
        append(list3, i);
    }

    printf("*������: ");
    showList(list3);
    length = getNodeLength(list3);
    printf("list3 length : %d\n\n", length);

    insert(list3, 0, 1523);
    insert(list3, 0, 7);

    printf("*��ġ (0) �� (1523,7) ������:\n");
    showList(list3);
    length = getNodeLength(list3);
    printf("list3 length : %d\n\n", length);

    insert(list3, 1, 99);
    insert(list3, 5, 23);
    insert(list3, getNodeLength(list3), 777);

    printf("*��ġ (1, 5, ������)�� (99, 23, 777) ������:\n");
    showList(list3);
    length = getNodeLength(list3);
    printf("list3 length : %d\n", length);
    deleteList(list3);

    // list4 �����Ʈ�� �����ϱ�

    printf("\n[�迭�� ����Ʈ�� �Է��ϰ� �����Ʈ�� �����ϱ�]\n");

    int array[] = { 14, 80, 99, 77, 5, 300, 55, 70, 7, 24, 9, 150, 3, 70, 1 };

    Node* list4 = malloc(sizeof(Node));
    list4->next = NULL;

    // �迭�� ����Ʈ�� �Է��Ѵ�.
    int arrSize = sizeof(array) / sizeof(int);
    arrayToList(list4, array, arrSize);

    printf("\n*������ �迭�� ����Ʈ�� �Է�\n");
    showList(list4);
    bubbleSortNode(list4, getNodeLength(list4));

    printf("\n*�����Ʈ�� ���� �� ����Ʈ\n");
    showList(list4);

    printf("\n*80�� �ε��� ã��\n");
    searchList(list4, 80);

    printf("\n*55�� �ε��� ã��\n");
    searchList(list4, 55);

    printf("\n*999�� �ε��� ã��(���� ���)\n");
    searchList(list4, 999);

    // ����Ʈ�� �޸� Ȯ���ϱ�

    printf("[����Ʈ�� �޸� ������ Ȯ���ϱ�]\n");
    showListMemory(list4);
    deleteList(list4);

    // list5 ����Ʈ ������ �ʱ�ȭ �Լ�

    printf("\n[���� �ζ� ����Ʈ ���� �� �ʱ�ȭ]\n");

    Node* list5 = getList();
    generateLottoList(list5);
    bubbleSortNode(list5, getNodeLength(list5));
    showList(list5);
    deleteList(list5);

    printf("\nLinked List closed");

    return 0;
}

// �Լ� ����

void appendFirst(Node* list, int newData) {
    struct Node* newNode = malloc(sizeof(Node));
    newNode->next = list->next;
    newNode->data = newData;

    list->next = newNode;
}

void append(Node* list, int newData) {
    if (list->next == NULL) {
        Node* newNode = malloc(sizeof(Node));
        newNode->data = newData;
        newNode->next = NULL;

        list->next = newNode;
    }
    else
    {
        Node* cur = list;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        Node* newNode = malloc(sizeof(Node));
        newNode->data = newData;
        newNode->next = NULL;

        cur->next = newNode;
    }
}

void showList(Node* list) {
    Node* cur = list->next;
    printf("[ ");
    while (cur != NULL)
    {
        printf("%d, ", cur->data);
        cur = cur->next;
    }
    printf("]\n");
}

void deleteList(Node* list) {
    Node* cur = list;
    Node* next;
    while (cur != NULL)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }
}

int getNodeLength(Node* list)
{
    int count = -1; // except for list head
    Node* cur = list;

    while (cur != NULL)
    {
        count++;
        cur = cur->next;
    }
    return count;
}

void insert(Node* list, int pos, int data)
{
    // ���� ���
    Node* cur = list;

    // ���ο� ��� �ʱ�ȭ
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // ��ġ�� 0�� ���
    if (pos == 0) {
        newNode->next = list->next;
        list->next = newNode;
    }
    // �׹ۿ�
    else {
        int count = 0;

        while (count != pos) {
            if (count == (pos - 1)) {
                newNode->next = cur->next;
                cur->next = newNode;
            }
            cur = cur->next;
            count++;
        }
    }
}

/* �� ����� �����͸� �ٲ۴�.
void swapNodeData(Node* node1, Node* node2)
{
    int temp;
    temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}
*/
/* ��带 ���� ��Ʈ�� �����Ѵ�
void bubbleSortNode(Node* list, int size) {

    // head node
    Node* cur;
    cur = list;

    // head ��� �����ϴϱ� �ʱ�ȭ�Ѵ�.
    cur->data = 0;
    cur = cur->next;

    for (int i = 0; i < size; i++)
    {
        if (cur->next == NULL) break;
        for (int j = 0; j < size - 1 - i; j++)
        {
            // if �� �ۼ�
            if (cur->data > cur->next->data) {
                swapNodeData(cur, cur->next);
            }
            cur = cur->next;
        }
        cur = list->next;
    }
}
*/
/*
void showListMemory(Node* list) {

    Node* cur = list;

    int i;
    int size = getNodeLength(list);

    printf("\n=======================================\n");
    printf("====== show list memory and data ======\n");
    printf("=======================================\n\n");

    for (i = 0; i <= size; i++) {
        printf("cur       : %p | \n", cur);
        printf("cur->next : %p | ", cur->next);
        printf("cur->data : %d\n", cur->data);
        cur = cur->next;
    }
}

void arrayToList(Node* list, int array[], int size) {


    for (int i = 0; i < size; i++)
    {
        append(list, array[i]);
    }

}

bool searchList(Node* list, int number) {
    Node* cur = list;

    int count = 0;

    while (cur != NULL)
    {
        if (cur->data == number) {
            printf("-> found at index : %d, cur->data : %d\n", count, cur->data);
            return true;
        }
        cur = cur->next;
        count++;
    }

    printf("-> nothing found searching for [%d]\n\n", number);
    return false;
}

Node* getList() {
    Node* newList = malloc(sizeof(Node));
    newList->data = 0;    // �ʱ�ȭ 0
    newList->next = NULL; // �ʱⰪ NULL
    return newList;
}
*/
/*
void generateLottoList(Node* list) {

    int i, j;
    int random[6];
    srand(time(NULL));

    for (i = 0; i < 6; i++)
    {
        random[i] = rand() % 45 + 1;
        for (j = 0; j < i; j++)
        {
            if (random[i] == random[j])
            {
                i--;
                break;
            }
        }
    }
    int arrSize = sizeof(random) / sizeof(int);
    arrayToList(list, random, arrSize);
}
*/