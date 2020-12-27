#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "manage.h"
#include <windows.h>
#include<string.h>
#include <conio.h>

#define M sizeof(Students)

void input_students();//¼���û�
void save_students(Students *p);//�����û���Ϣ���ļ�
void search_students();//��ѯ�û���Ϣ

char Check(){
    char c, flag;
    int i;
    while(1){
        for(i = 0; (c = getchar()) != '\n'; flag = c, ++i)
            ;
        if(i == 1){
            if('0'<=flag && flag<='9'){
                return flag;
            }
        }else if(i == 0){
            continue;
        }
        printf("��������Ч���֣�");
    }
}

void Home(){
    system("cls");
    printf("\033[32m ***********************��ӭʹ��ͼ�����ϵͳ*************************** ");
    printf("\n                ||-------1 : ����Ա����-------------||\n");
    printf("                ||-------2 : ��ͨ�û�����-----------||\n");
    printf("                ||-------3 : ��ϵ������-------------||\n");
    printf("                ||-------0 : �˳�------------------||\033[0m");
}

void Land(){
    while(1){
        Home();
        printf("\n�밴��ǰ�����Ž��в���:");
        switch(Check()){
            case '1':
                system("cls");
                Login_manage_home();
                break;
            case '2':
                system("cls");
                Login_user_home();
                break;
            case '3':
                system("cls");
                Contact_developer();
                break;
            case '0':
                system("cls");
                Sleep(1500);
                exit(0);
            default:
                printf("�ɼ�����ʧ��");
        }
    }
}

void Manager(char account[]){
    char bookname[30];
    while(1){
        system("cls");
        printf("\033[33m***********************��ӭ��������Ա����***************************");
        printf("\n                         �鿴ͼ��-------1");
        printf("\n                         ����ͼ��-------2");
        printf("\n                         �黹ͼ��-------3");
        printf("\n                         ¼��ͼ��-------4");
        printf("\n                         ɾ��ͼ��-------5");
        printf("\n                         ¼���û���Ϣ---6");
        printf("\n                         ɾ��ͼ��-------7");
        printf("\n                         �鿴�û�-------8");
        printf("\n                         �޸�����-------9");
        printf("\n                         ����----------0\033[0m");
        printf("\n�밴��ǰ�����Ž��в���:");
        switch(Check()){
            case '1':
                system("cls");
                find_book();
                break;
            case '2':
                system("cls");
                lend_book();
                break;
            case '3':
                system("cls");
                //return_book();
                break;
            case '4':
                system("cls");
                input_book();
                break;
            case '5':
                system("cls");
                printf("�����Ҫɾ��ͼ�������");
                book_delete(bookname);
                break;
            case '6':
                system("cls");
                input_students();
                break;
            case '7':
                system("cls");
                break;
            case '8':
                system("cls");
                search_students();
                break;
            case '9':
                system("cls");
                Change_manage_password(account);
                break;
            case '0':
                system("cls");
                return;
            default:
                printf("�ɼ�����ʧ��");
        }
    }
}

void User(char account[]){
    while(1){
        system("cls");
        printf("\033[32m***********************��ӭʹ��ͼ�����ϵͳ***************************");
        printf("\n                           �鿴������Ϣ----1");
        printf("\n                           �鿴ͼ��-------2");
        printf("\n                           �޸�����-------3");
        printf("\n                           ����----------0\033[0m\n");
        printf("\n�밴��ǰ�����Ž��в���:");
        switch(Check()){
            case '1':
                system("cls");
                search_students();
                break;
            case '2':
                system("cls");
                find_book();
                break;
            case '3':
                system("cls");
                Change_user_password(account);
                break;
            case '0':
                system("cls");
                return;
            default:
                printf("�ɼ�����ʧ��");
        }
    }
}

void Contact_developer(){
    printf("\033[32m�ֻ���14754586583\n");
    printf("���䣺1348063327@qq.com\033[0m\n");
    printf("�����������");
    getch();
}

void input_students(){    //�û���Ϣ¼��
    while(1){             //������ѭ������Ч��ֹ������������
        system("cls");
        Students *pstudent;
        pstudent = (Students*)malloc(M);     //����ռ�
        printf("������ѧ��(����)��");
        scanf("%lu",&pstudent->student_id);

        printf("������������");
        scanf("%s",pstudent->name);

        printf("������༶(С��10λ��)��");
        scanf("%s",pstudent->class);

        printf("��������ϵ��ʽ(С��10λ��)��");
        scanf("%s",pstudent->phone_number);

        printf("�������˻����(С��10λ��)��");
        scanf("%d",&pstudent->account_balance);

        printf("����������ֵ(С��10λ��)��");
        scanf("%d",&pstudent->credit_value);

        save_students(pstudent);
        system("cls");

        printf("-------------------------\n");
        printf("|   ����ɹ����Ƿ������  |\n");
        printf("| 1.��             2.�� |\n");
        printf("-------------------------\n");

        switch (Check()) {
            case '1':break;
            case '2':return;
            default:printf("��������\n");break;
        }
    }
}

void save_students(Students *p){   //��p������д���ļ�
    FILE *fp;    //�ļ�ָ��
    fp = fopen("students.txt","ab");   //��׷�ӵķ�ʽ������Ϊmybook�Ķ������ļ�
    if(fp == NULL){
        printf("cannot open file");
    }
    else{   //��p��ָ���һ�δ�СΪN�����ݴ���fp��ָ����ļ���
        fprintf(fp,"%lu %s %s %s %d %d\n",p->student_id,p->name,p->class,p->phone_number,p->account_balance,p->credit_value);
    }
    fclose(fp);    //�ر��ļ�
}

void search_students(){
    Students stu;//ѧ����Ϣ
    history his;//������Ϣ

    FILE *fp0,*fp1;//�ļ�ָ��
    time_t tend_time;//��ǰʱ���
    long int t;//����ʵ������

    int n;
    char fname[30];//�������
    unsigned long int fstudent_id;
    printf("\n������ѧ��:  ");
    scanf("%lu",&fstudent_id);
    printf("����������:  ");
    scanf("%s",fname);

    if ((fp0 = fopen("students.txt","r")) == NULL){//���ļ�
        printf("\n�ļ�������!�����������\n");
        getch();
        system("pause");
        return;
    }
    else{
        for(int i=0;!feof(fp0);i++){//��ѧ����Ϣ�ļ�
            fscanf(fp0,"%lu %s %s %s %d %d\n",&stu.student_id,stu.name,stu.class,stu.phone_number,&stu.account_balance,&stu.credit_value);//��ȡ�ļ�
            if(stu.student_id == fstudent_id && strcmp(stu.name,fname) == 0){
                n++;
                break;
            }
        }
        if(n == 0){
            printf("���޴���,�����������\n");
            getch();
            return;
        }
        if((fp1 = fopen("history.txt","r")) != NULL){//�򿪽�����Ϣ�ļ�
            for(int i=0;!feof(fp1);i++){
                fscanf(fp1,"%lu %s %ld %d %f",&his.student_id,his.books,&his.start_time,&his.borrow_day,&his.penalty);//��ȡ�ļ�
                if(his.student_id == fstudent_id){
                    break;
                }
            }
        }
        else{
            printf("\n�ļ������ڣ����س�������\n");
            getch();
            return;
        }
    }
    fclose(fp0);//�ر��ļ�
    fclose(fp1);

    t = ( (long)(time(&tend_time)) - his.start_time) / (3600 * 24);//ʵ�ʽ�������

    printf("\nѧ��:%lu\n����:%s\n�༶:%s\n��ϵ��ʽ:%s\n�˻����:%d\n����ֵ:%d\n",stu.student_id,stu.name,stu.class,stu.phone_number,stu.account_balance,stu.credit_value);
    printf("\n�����鼮:%s\n����ʱ�����죩:%d\nΥԼ��:%f\n",his.books,his.borrow_day,his.penalty);
    if(t > DEADLINE){
        printf("�ѹ���δ��\n");
    }
    else{
        printf("�ڽ���������\n");
    }
    system("pause");
    return;
}