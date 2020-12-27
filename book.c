#include "manage.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define N sizeof(Books)

Books *creat(void){      //将文件中的内容读出到链表中，返回值为表头地址
    FILE *fp;       //文件指针
    Books *head=NULL;
    Books *p2,*p1;
    if((fp = fopen("library.txt","r")) == NULL){
        printf("\n文件不存在!按任意键返回\n");
        getch();
        exit(0);
    }     //以只读的方式打开文件
    if(fp == NULL){
        printf("打开文件失败\n");
    }
    p1 = p2;
    for(int n=0;!feof(fp);n++){         //判断文件结束标志
        p1 = (Books*)malloc(N);         //向内存申请一段空间
        fscanf(fp,"%s %s %s %d %s %f %c\n",p1->book_id,p1->title,p1->publisher,&p1->book_version,p1->author,&p1->price,&p1->available);//将fp所指向的文件中的内容赋给p ,&p1->price,p1->available
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


void find_book(){//查询图书
    system("cls");  //清屏
    printf("\033[33m                  图书查询\n");
    printf("        *     1.书名  查询      *\n");
    printf("        *     2.作者  查询      *\n");
    printf("        *     3.出版社查询      *\n");
    printf("        *     4.类别  查询      *\n");
    printf("              按0返回主菜单      \033[0m\n");
    switch(Check()){
        case '0':return;
        case '1':find_name_book();break;
        case '2':find_author_book();break;
        case '3':find_publish_book();break;
        case '4':find_kinds_book();break;
        default :
            printf("\n输入有误");
            break;
    }
}

void book_delete(char bookname[])
{
    FILE *fp;
    Books *p1,*p2,*head;
    int i;
    p1 = creat();
    head = p1;
    while(p1 != NULL)
    {
        if(!strcmp(p1->title,bookname))
        {
            i++;
            p2->next = p1->next;

            fp=fopen("library.txt","w");//清空文件，只写打开，然后关闭
            fclose(fp);
            fp=fopen("library.txt","a");//追加文件

            for (;head!=NULL;)//把链表内容覆盖到文件
            {
                fprintf(fp,"%s %s %s %d %s %lf %d %c\n",head->book_id,head->title,head->publisher,head->book_version,head->author,head->price,head->number,head->available);
                head = head->next;
            }
            break;
        }
        p2 = p1;
        p1 = p1->next;
    }
    if(i == 0)
    {
        printf("该图书不存在\n");
    }
    else
    {
        printf("删除成功\n");
    }
}


void input_book(){   //图书录入
    while(1){
        system("cls");
        Books *pbook;
        pbook = (Books*)malloc(N);     //申请空间
        //输入图书信息
        printf("请输入书名(小于10位数)：");
        scanf("%s",pbook->title);getchar();
        printf("请输入作者名(小于10位数)：");
        scanf("%s",pbook->author);getchar();
        printf("请输入图书类别(小于10位数)：");
        scanf("%s",pbook->book_id);getchar();
        printf("请输入图书版本(小于10位数)：");
        scanf("%d",&pbook->book_version);getchar();
        printf("请输入图书出版单位(小于10位数)：");
        scanf("%s",pbook->publisher);getchar();
        printf("请输入图书价格：");
        scanf("%f",&pbook->price);

        pbook->available = 'Y';
        printf("请输入图书数量：");
        scanf("%d",&pbook->number);
        save_book(pbook);

        system("cls");
        printf("-------------------------\n");
        printf("| 保存成功！是否继续？  |\n");
        printf("| 1.是             2.否 |\n");
        printf("-------------------------\n");

        switch (Check()) {
            case '1':break;
            case '2':return;
            default:printf("输入有误");break;
        }
    }
}

void save_book(Books *p){   //将p中内容写入文件
    FILE *fp;    //文件指针
    fp = fopen("library.txt","ab");   //以追加的方式打开名字为mybook的二进制文件
    if(fp == NULL){
        printf("cannot open file");
    }
    else{   //将p所指向的一段大小为N的内容存入fp所指向的文件中
        fprintf(fp,"%s %s %s %d %s %lf %c\n",p->book_id,p->title,p->publisher,p->book_version,p->author,p->price,p->available);//写进文件
    }
    fclose(fp);    //关闭文件
}

void find_name_book(){//按名字查询
    system("cls");
    Books *pbook;
    int i=0;
    pbook=creat();
    char name[20];
    printf("请输入您要查询图书的书名：");
    gets(name);
    printf("\n*********************************************图书总览****************************************************\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("图书类别        书名        出版单位            图书版本          作者名             价格        是否可借\n");
    while(pbook!=NULL){
        if(pbook!=NULL && strcmp(pbook->title,name) == 0){
            i++;
            printf("%3s%18s%18s%15d%18s              %.2lf%10c\n",pbook->book_id,pbook->title,pbook->publisher,pbook->book_version,pbook->author,pbook->price,pbook->available);
            break;
        }
        pbook = pbook->next;
    }
    if(i == 0){//查询完毕没有则退出
        system("cls");
        printf("查无此书,按任意键盘返回\n");
        getch();
        return;
    }
    printf("按任意键返回！");
    getch();
}

void find_author_book(){    //按作者查询
    system("cls");
    Books *head,*p;
    int i=0;
    head=creat();
    char name[40];
    printf("请输入您要查询图书的作者名：");
    gets(name);
    p=head;
    printf("*********************************************图书总览****************************************************\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("图书类别        书名        出版单位            图书版本          作者名             价格        是否可借\n");
    while(p!=NULL){
        if(p!=NULL && strcmp(p->author,name) == 0){
            i++;
            printf("%3s%18s%18s%15d%18s              %.2lf%10c\n",p->book_id,p->title,p->publisher,p->book_version,p->author,p->price,p->available);
        }
        p = p->next;
    }
    if(i == 0){//查询完毕没有则退出
        system("cls");
        printf("\n查无此作者,按任意键返回\n");
        getch();
        return;
    }
    printf("按回车键返回！");
    getch();
}

void find_publish_book()//按出版社查询
{
    system("cls");
    Books *head,*p;
    int i=0;
    head=creat();
    char name[20];
    printf("请输入您要查询图书的出版社：");
    gets(name);
    p=head;
    printf("*********************************************图书总览****************************************************\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("图书类别        书名        出版单位            图书版本          作者名             价格        是否可借\n");
    while(p!=NULL)
    {
        if(p!=NULL && strcmp(p->publisher,name) == 0)
        {
            i++;
            printf("%3s%18s%18s%15d%18s              %.2lf%10c\n",p->book_id,p->title,p->publisher,p->book_version,p->author,p->price,p->available);
        }
        p = p->next;
    }
    if(i == 0)//查询完毕没有则退出
    {
        system("cls");
        printf("\n查无此出版社图书,按任意键返回\n");
        getch();
        find_book();
    }

    printf("按任意键返回！");
    getch();
    find_book();
}

void find_kinds_book(){//按图书种类查询
    system("cls");
    Books *head,*p;
    int i=0;
    head=creat();
    char name[20];
    printf("请输入您要查询图书的种类：");
    gets(name);
    p=head;
    printf("*********************************************图书总览****************************************************\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("图书类别        书名        出版单位            图书版本          作者名             价格        是否可借\n");
    //printf("-------------------------------------------------------------------------------------------------------------");
    while(p!=NULL){
        if(p!=NULL && strcmp(p->book_id,name) == 0){
            i++;
            //printf("%s%14s%14s%14s   %14s   %18s         %.2f%12d\n",p->number,p->name,p->author,p->type,p->publish,p->time,p->price,p->num);
            printf("%3s%18s%18s%15d%18s              %.2lf%10c\n",p->book_id,p->title,p->publisher,p->book_version,p->author,p->price,p->available);
        }
        p = p->next;
    }

    if(i == 0)//查询完毕没有则退出
    {
        system("cls");
        printf("\n查无此类图书,按任意键返回\n");
        getch();
        find_book();
    }

    printf("按任意键返回！");
    getch();
    find_book();
}