#include <stdio.h>
#include "manage.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N sizeof(Books)
#define M sizeof(History)

History *creat_history(void);
void book_return(char bookname[],long int student_num);//�黹


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

