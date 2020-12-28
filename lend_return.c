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
    printf("请输入借阅书籍名字: ");
    scanf("%s",bookname);
    printf("请输入借阅者ID: ");
    scanf("%lu",&student_num);
    time_t bstart_time;//用于获得借阅的当天时间
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

                fp=fopen("library.txt","w");//清空文件，只写打开，然后关闭
                fclose(fp);
                fp=fopen("library.txt","a");//追加文件

                for (;head!=NULL;){//把链表内容覆盖到文件
                    fprintf(fp,"%s %s %s %d %s %f %d %c\n",head->book_id,head->title
                            ,head->publisher,head->book_version,head->author
                            ,head->price,head->number,head->available);
                    head = head->next;
                }
                fclose(fp);
                printf("出借成功！");
                system ("pause");
                break;
            }
            else{
                printf("此书已被借完!");//否则输出此书已被借完
                system("pause");
                break;
            }
        }
        p1 = p1->next;
    }
    if(flag == 0){
        printf("查无此书\n");
    }
}

history *creat_his(void)      //将文件中的内容读出到链表中，返回值为表头地址
{

    FILE *fp;       //文件指针
    history *head = NULL;
    history *p2,*p1;
    int n = 0;
    if((fp = fopen("history.txt","r")) == NULL)
    {
        printf("\n文件不存在!按任意键返回\n");
        system("pause");
    }     //以只读的方式打开文件

    if(fp == NULL){
        printf("cannot open file\n");
    }
    for(n=0;!feof(fp);n++)        //判断文件结束标志
    {
        p1 = (history*)malloc(N); //向内存申请一段空间
        fscanf(fp,"%ld %s %ld %d %lf\n",&p1->student_id,p1->books,&p1->start_time,&p1->borrow_day,&p1->penalty);//将fp所指向的文件中的内容赋给p ,&p1->price,p1->available
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

void book_return()//归还图书
{
    char bookname[30];unsigned long int student_num;
    printf("请输入要删除的书名: ");
    gets(bookname);
    printf("请输入借阅者名字");
    scanf("%lu",&student_num);
    FILE *fp,*fp1;
    Books *p1,*head;
    history *his,*his_head;

    int i,x;
    time_t bend_time;//用于获得归还的当天时间
    int t;//存放实际借阅天数
    p1 = creat();//返回图书链表头地址
    head = p1;
    his = creat_his();//返回历史链表头地址
    his_head = his;

    while(p1 != NULL )
    {
        if(!strcmp(p1->title,bookname))
        {
            x++;
            //if(p1->number > 0)
            p1->number++;
            fp=fopen("library.txt","w");//清空文件，只写打开，然后关闭
            fclose(fp);
            fp=fopen("library.txt","a");//追加文件

            for (;head!=NULL;)//把链表内容覆盖到图书信息文件
            {
                fprintf(fp,"%s %s %s %d %s %lf %d %c\n",head->book_id,head->title,head->publisher,head->book_version,head->author,head->price,head->number,head->available);
                head = head->next;
            }
            fclose(fp);
            system ("cls");//清屏
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
            his->borrow_day = ( (long)(time(&bend_time)) - his->start_time) / (3600 * 24);//实际借阅天数

            fp1=fopen("history.txt","w");//清空文件，只写打开，然后关闭
            fclose(fp1);
            fp1=fopen("history.txt","a");//追加文件

            for(;his_head != NULL;)//把链表内容覆盖到借阅历史文件
            {
                fprintf(fp1,"%lu %s %ld %d %lf\n",his_head->student_id,his_head->books,his_head->start_time,his_head->borrow_day,his_head->penalty);
                his_head = his_head->next;
            }
            fclose(fp1);

            system ("cls");//清屏
            break;
        }
        his = his->next;
    }
    free(his);

    if(i == 0 && x == 0)
    {
        printf("未查询到有借阅此书的记录且管内无此图书\n任意键退出\n");
        system("pause");
    }
    else
    {
        printf("归还成功\n任意键退出\n");
        system("pause");
    }
}
