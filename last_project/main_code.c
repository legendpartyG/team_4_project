#include <stdio.h>
#pragma warning(disable:4996)
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Circle_Queue.h"
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    int id;
    char name[MAX_NAME_LEN];
    int birth; //[E][����] �����迭 ���ʿ�
    char phone[MAX_PHONENUMBER_LEN]; //[E][����] pn >> phone
    char grade[MAX_GRADE_LEN]; //grade: ȸ�����
    person user[DataNum] = { 0 }; //DECLARE ARRANGEMENT LENGTH X //[E][����] ����ü �迭 struct person arr >> struct person user
    person* p = user;
    char* userName[DataNum] = { "Harry", "David", "Liam", "Michael", "Jenney" }; //[E][�߰�] userName���̺�;
    char* userPhone[DataNum] = { "01092928123","01044332281","01038492021","01038921230", "01036563048" }; //[E][�߰�] userPhone���̺� //[E][����] ��ȭ��ȣ�� �ڸ����� int�� max(2147483647) ���� >> ���ڿ�];
    int userBirth[DataNum] = { 20220210, 202220310, 20220410, 20220510, 20220610 }; //[E][�߰�] userBirth���̺�;
    char* userGrade[DataNum] = { "vip", "normal", "normal", "normal", "vip" }; //[E][�߰�] userName���̺�;

    /*PrintIntArray(userBirth, MaxComfirmNum); //[E][�׽���]���̺� Ȯ��, ����
    printf("\n");
    PrintIntArray(userPhone, MaxComfirmNum);*/
    int check;
    int person_cnt = 0;
    Queue q;
    init_Queue(&q);

    for (int i = 0; i < 5; i++)
    {
        insert_Queue(&q, i+1, userName[i], userBirth[i], userPhone[i], userGrade[i]);
    }
    Queue_print(q);
    /*while (1)
    {
        printf("=============================\n");
        printf("���� (1)\n");
        printf("���� ��� (2)\n");
        printf("���� ��⿭ Ȯ��(3)\n");
        printf("���α׷� ���� (1, 2�� ������ ��� ����)\n");

        scanf_s("%d", &check);

        if (check == 1)
        {
            printf("������� : ");
            scanf("%s", user[person_cnt].birth);
            printf("��ȭ��ȣ : ");
            scanf("%s", user[person_cnt].phone);
            printf("�̸� : ");
            scanf("%s", user[person_cnt].name);
            printf("ȸ����� : ");
            scanf("%s", user[person_cnt].grade);
            user[person_cnt].id = person_cnt + 1;
            insert_Queue(&q, user[person_cnt].id, user[person_cnt].name, user[person_cnt].birth, user[person_cnt].phone, user[person_cnt].grade);
            person_cnt++;

        }
        else if (check == 2)
        {
            printf("����� ȸ�������?");
            scanf("%s", grade);
            printf("������� : ");
            scanf_s("%s", birth);
            printf("��ȭ��ȣ : ");
            scanf("%s", phone);
            printf("�̸� : ");
            scanf("%s", name);
            printf("ȸ����� : ");
            scanf("%s", grade);
            printf("id: ");
            scanf("%d", &id);
            del_data(&q, id, name, birth, phone, grade);
            person_cnt--;
        }
        else if (check == 3)
        {
            printf("============�Ϲ� ��⿭============\n");
            Queue_print(q);
            printf("\n");
        }
        
    }*/
    free(q.data);

    return 0;
}