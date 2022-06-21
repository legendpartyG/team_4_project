#pragma once
/*
   @brief	: ����ť(��⿭ ��ü)�� ť(������ ���帮��Ʈ)�� �̿��� ��⿭ ���α׷�
   @author	: �����, �ڹα�, �ڹο�, �ּ���
   @date	: 2022_06_21_16:13
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define _CRT_SECURE_NO_WARNINGS

/**
 * @brief  :���� ť ���� ��ũ��.
 */

#define True 1
#define False 0
#define Error -1
#define MaxQueSize 6 

/**
 * @brief	:person����ü �迭 ���� ��ũ��
 * @details :�̸�, ��ȭ��ȣ, ȸ�����, ������ ��, ���̺� �־��� ������ ���� �ִ밪�� ����
 *			 userName, userPhone, userBirth, userName ���̺�
 * @bug     :��ȭ��ȣ�� �ڸ����� int�� max(2147483647) ���� >> ���ڿ�
 */
#define MAX_NAME_LEN 10
#define MAX_PHONENUMBER_LEN 12  
#define MAX_GRADE_LEN 10 
#define MaxComfirmNum 200 
#define DataNum 5 


 /**
  * @brief	:person����ü ����
  * @details :Circle_Queue.h�� ���� struct element �� struct person ����
  * @todo    :birth���� ����(������ �迭 �ʿ�x)
  */
typedef struct person { 
	int id;
	char name[MAX_NAME_LEN];
	int birth; 
	char phone[MAX_PHONENUMBER_LEN]; 
	char grade[MAX_GRADE_LEN];
}person;

/**
 * @brief	:�� �������� ���̺� �ִ� ���� person[i]�� �� ���ҿ� �����ϴ� �Լ�
 */

void SetUserData(person* p, int id, char name[DataNum], int birth[DataNum], char phone[DataNum], char grade[DataNum]) { 
	for (int i = 0; i < DataNum; i++)
	{
		p[i].id = i;
		*p[i].name = name[i];
		p[i].birth = birth[i];
		*p[i].phone = phone[i];
		*p[i].grade = grade[i];
	}
}

/**
 * @brief	:char�� �迭 �ʱ�ȭ �Լ�.
 */
void InitCharArray(char arr[]) { for (int i = 0; i < strlen(arr); i++) arr[i] = 0; }

/**
 * @brief	:char�� �迭�� char�� �迭�� ���� �����ϴ� �Լ�, arr1(�� ����), arr2(�� ����)
 */
void CollegeCharArray(char arr1[], char arr2[])
{
	/*if (strlen(arr1) == strlen(arr2)) //�� �迭�� ����� �ٸ� ��
		for (int i = 0; i < strlen(arr2); i++) arr1[i] = arr2[i];
	else
	{
		if (strlen(arr1) < strlen(arr2)) {
			//[��û] �� �ٿ� arr1�� �迭�� ���̸� arr2Size�� �ٲ� ������ �ϱ�
			for (int i = 0; i < strlen(arr1); i++) arr1[i] = 0;
			for (int i = 0; i < strlen(arr2); i++) arr1[i] = arr2[i];
		}
		else {
			for (int i = 0; i < strlen(arr1); i++) arr1[i] = 0;
			for (int i = 0; i < strlen(arr2); i++) arr1[i] = arr2[i];
		}
	}*/
	InitCharArray(arr1);
	for (int i = 0; i < strlen(arr2); i++) arr1[i] = arr2[i];
}

/**
 * @brief	:ARRAY EXCEPTION CODE CHECK NUMBER,SPECIAL ALPHA(�迭 ����ó��)
 * @details	:���ڿ��� ����, Ư�����ڰ� ����ִ��� Ȯ��.ASCII�ڵ� ���� ����
 */
int isStringCheck(char* s) {
	size_t size = strlen(s);
	if (size == 0)
		return 0;

	for (int i = 0; i < (int)size; i++)
	{
		if (s[i] < 32 || s[i]>65)
			if (s[i] < 91 || s[i]>96)
				if (s[i] < 123 || s[i]>126)
					return 0;
	}

	return 1;
}

/**
 * @brief	:EXCEPTION CODE CHECK ALPHA,SPECIAL ALPHA
 * @details	:����, Ư�����ڰ� ����ִ��� Ȯ��.ASCII�ڵ� ���� ����
 */
int isStringCheck1(char* s) {
	size_t size = strlen(s);
	if (size == 0)
		return 0;

	for (int i = 0; i < (int)size; i++)
	{
		if (s[i] > 47 || s[i] < 0)
			if (s[i] < 58 || s[i]>127)
				return 0;
	}

	return 1;
}

/**
 * @brief   :CircleQueue ���� �ڵ�.
 */
int cur_size = 0;
/**
 * @brief   :Queue����ü ���� .
 * @todo    :insert_Queue�� ���� �߰�
 */
typedef struct circlequeue {
	int rear;
	int front;
	person* data;
}Queue;

void init_Queue(Queue* q);
void insert_Queue(Queue* q, int id, char name[MAX_NAME_LEN], int birth, char phone[MAX_PHONENUMBER_LEN], char grade[MAX_GRADE_LEN]); //[E][����] ���� �߰�
person delete_Queue(Queue* q);
bool is_full(Queue* q);
bool is_empty(Queue* q);
void Queue_print(Queue q);

void init_Queue(Queue* q)
{
	q->front = 0;
	q->rear = 0;
	q->data = (person*)malloc(sizeof(person) * MaxQueSize);
}
/**
 * @todo	:(q->data[q->rear].name, name) char�� �迭 ���� �Լ� ȣ��
 */
void insert_Queue(Queue* q, int id, char name[MAX_NAME_LEN], int birth, char phone[MAX_PHONENUMBER_LEN], char grade[MAX_GRADE_LEN])
{
	if (is_full(q)) {
		printf("��⿭�� �� á���ϴ�.\n");
		return;
	}
	else
	{
		q->rear = (q->rear + 1) % (MaxQueSize); 
		q->data[q->rear].id = id;
		CollegeCharArray(q->data[q->rear].name, name); 
		q->data[q->rear].birth = birth;
		CollegeCharArray(q->data[q->rear].phone, phone);
		CollegeCharArray(q->data[q->rear].grade, grade);
	}
	cur_size++;
	return;
}

person delete_Queue(Queue* q)
{
	if (is_empty(q))
	{
		printf("��⿭�� ������ϴ�.\n");
	}
	q->front = (q->front + 1) % (MaxQueSize);
	return q->data[q->front];
	cur_size--;
}

bool is_empty(Queue* q) {
	if (q->front == q->rear)
		return True;
	else
		return False;
}

bool is_full(Queue* q)
{
	if (((q->rear + 1) % MaxQueSize) == q->front)
		return True;
	else
		return False;
}
/**
 * @todo	:void del_data ���� �߰�, (q->data[i].name) char�� �迭 �ʱ�ȭ �Լ�(InitCharArray) ȣ��,
 *			 (q->data[target].name, q->data[i].name) char�� �迭 ���� �Լ�(CollegeCharArray) ȣ��
 */
void del_data(Queue* q, int del_id){
	printf("������ id: %d\n", del_id);
	int cnt = 0;
	for (int i = q->front; i <= q->rear; i = (i + 1) % (MaxQueSize+1))
	{
		if (q->data[i].id == del_id)
		{
			q->data[i].id = 0;
			InitCharArray(q->data[i].name); 
			q->data[i].birth = 0;
			InitCharArray(q->data[i].phone);
			InitCharArray(q->data[i].grade);
			cnt++;
		}
		/*else if (cnt > 0)
		{
			int target = i - cnt;
			if (target < 0)
				target += MaxQueSize;
			q->data[target].id = q->data[i].id;
			CollegeCharArray(q->data[target].name, q->data[i].name); 
			q->data[target].birth = q->data[i].birth;
			CollegeCharArray(q->data[target].phone, q->data[i].phone);
			CollegeCharArray(q->data[target].grade, q->data[i].grade);

			q->data[i].id = 0;
			InitCharArray(q->data[i].name); 
			q->data[i].birth = 0;
			InitCharArray(q->data[i].phone);
			InitCharArray(q->data[i].grade);
		}*/
	}
}

void Queue_print(Queue q)
{
	int i = q.front;
	if (is_empty(&q)) {
		printf("��⿭�� ����ֽ��ϴ�.\n");
		return;
	}

	do {
		i = (i + 1) % MaxQueSize;
		printf("����� id : %d   ||", q.data[i].id);
		printf("   ����� �̸� : %s", q.data[i].name); 
		printf("   ||   ����� ������� : %d", q.data[i].birth);
		printf("   ||   ����� ����ó : %s", q.data[i].phone);
		printf("   ||   ����� ��� : %s", q.data[i].grade);
		printf("   ||   (rear : % d)\n", q.rear);
		printf("\n\n");
		if (i == q.rear)
			break;
	} while (i != q.front);
	printf("\n\n\n");
}
