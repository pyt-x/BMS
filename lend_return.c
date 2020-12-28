#include <stdio.h>
#include "manage.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N sizeof(Books)
#define M sizeof(History)

history *creat_his(void) ;


void lend_book(){
    char bookname[30];unsigned long int student_num;
    FILE *fp,*fp1;
    Books *p1,*head;
    history his;
    int flag;
    printf("����������鼮����: ");
    scanf("%s",bookname);
    printf("�����������ID: ");
    scanf("%lu",&student_num);
    time_t bstart_time;//���ڻ�ý��ĵĵ���ʱ��
    long t;
    p1 = creat();
    head = p1;
    while(p1 != NULL){
        if(!strcmp(p1->title,bookname))
        {
            flag++;
            if(p1->number > 0){
                p1->number--;
                t = time(&bstart_time);
                his.student_id = student_num;
                strcpy(his.books,bookname);
                his.start_time = t;
                his.borrow_day = 0;
                his.penalty = 0.0;

                fp1 = fopen("history.txt","a");
                fprintf(fp1,"\n%lu %s %ld %d %lf",student_num,his.books,his.start_time,his.borrow_day,his.penalty);
                fclose(fp1);

                fp=fopen("library.txt","w");//����ļ���ֻд�򿪣�Ȼ��ر�
                fclose(fp);
                fp=fopen("library.txt","a");//׷���ļ�

                for (;head!=NULL;){//���������ݸ��ǵ��ļ�
                    fprintf(fp,"%s %s %s %d %s %f %d %c\n",head->book_id,head->title
                            ,head->publisher,head->book_version,head->author
                            ,head->price,head->number,head->available);
                    head = head->next;
                }
                fclose(fp);
                printf("����ɹ���");
                system ("pause");
                break;
            }
            else{
                printf("�����ѱ�����!");//������������ѱ�����
                system("pause");
                break;
            }
        }
        p1 = p1->next;
    }
    if(flag == 0){
        printf("���޴���\n");
    }
}

history *creat_his(void)      //���ļ��е����ݶ����������У�����ֵΪ��ͷ��ַ
{

    FILE *fp;       //�ļ�ָ��
    history *head = NULL;
    history *p2,*p1;
    int n = 0;
    if((fp = fopen("history.txt","r")) == NULL)
    {
        printf("\n�ļ�������!�����������\n");
        system("pause");
    }     //��ֻ���ķ�ʽ���ļ�

    if(fp == NULL){
        printf("cannot open file\n");
    }
    for(n=0;!feof(fp);n++)        //�ж��ļ�������־
    {
        p1 = (history*)malloc(N); //���ڴ�����һ�οռ�
        fscanf(fp,"%ld %s %ld %d %lf\n",&p1->student_id,p1->books,&p1->start_time,&p1->borrow_day,&p1->penalty);//��fp��ָ����ļ��е����ݸ���p ,&p1->price,p1->available
        if(n == 0 ){
            head = p1;
        }
        else{
            p2->next = p1;
        }
        p2 = p1;
    }
    p2->next = NULL;
    fclose(fp);
    return(head);
}

void book_return()//�黹ͼ��
{
    char bookname[30];unsigned long int student_num;
    printf("������Ҫɾ��������: ");
    gets(bookname);
    printf("���������������");
    scanf("%lu",&student_num);
    FILE *fp,*fp1;
    Books *p1,*head;
    history *his,*his_head;

    int i,x;
    time_t bend_time;//���ڻ�ù黹�ĵ���ʱ��
    int t;//���ʵ�ʽ�������
    p1 = creat();//����ͼ������ͷ��ַ
    head = p1;
    his = creat_his();//������ʷ����ͷ��ַ
    his_head = his;

    while(p1 != NULL )
    {
        if(!strcmp(p1->title,bookname))
        {
            x++;
            //if(p1->number > 0)
            p1->number++;
            fp=fopen("library.txt","w");//����ļ���ֻд�򿪣�Ȼ��ر�
            fclose(fp);
            fp=fopen("library.txt","a");//׷���ļ�

            for (;head!=NULL;)//���������ݸ��ǵ�ͼ����Ϣ�ļ�
            {
                fprintf(fp,"%s %s %s %d %s %lf %d %c\n",head->book_id,head->title,head->publisher,head->book_version,head->author,head->price,head->number,head->available);
                head = head->next;
            }
            fclose(fp);
            system ("cls");//����
            break;
        }
        p1 = p1->next;
    }
    free(p1);

    while(his != NULL)
    {
        if(!strcmp(his->books,bookname))
        {
            i++;
            his->borrow_day = ( (long)(time(&bend_time)) - his->start_time) / (3600 * 24);//ʵ�ʽ�������

            fp1=fopen("history.txt","w");//����ļ���ֻд�򿪣�Ȼ��ر�
            fclose(fp1);
            fp1=fopen("history.txt","a");//׷���ļ�

            for(;his_head != NULL;)//���������ݸ��ǵ�������ʷ�ļ�
            {
                fprintf(fp1,"%lu %s %ld %d %lf\n",his_head->student_id,his_head->books,his_head->start_time,his_head->borrow_day,his_head->penalty);
                his_head = his_head->next;
            }
            fclose(fp1);

            system ("cls");//����
            break;
        }
        his = his->next;
    }
    free(his);

    if(i == 0 && x == 0)
    {
        printf("δ��ѯ���н��Ĵ���ļ�¼�ҹ����޴�ͼ��\n������˳�\n");
        system("pause");
    }
    else
    {
        printf("�黹�ɹ�\n������˳�\n");
        system("pause");
    }
}
