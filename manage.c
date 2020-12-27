#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "manage.h"
#include <windows.h>
#include<string.h>
#include <conio.h>

#define M sizeof(Students)

void input_students();//录入用户
void save_students(Students *p);//保存用户信息进文件
void search_students();//查询用户信息

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
        printf("请输入有效数字：");
    }
}

void Home(){
    system("cls");
    printf("\033[32m ***********************欢迎使用图书管理系统*************************** ");
    printf("\n                ||-------1 : 管理员界面-------------||\n");
    printf("                ||-------2 : 普通用户界面-----------||\n");
    printf("                ||-------3 : 联系开发者-------------||\n");
    printf("                ||-------0 : 退出------------------||\033[0m");
}

void Land(){
    while(1){
        Home();
        printf("\n请按照前面的序号进行操作:");
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
                printf("采集参数失败");
        }
    }
}

void Manager(char account[]){
    char bookname[30];
    while(1){
        system("cls");
        printf("\033[33m***********************欢迎来到管理员界面***************************");
        printf("\n                         查看图书-------1");
        printf("\n                         出借图书-------2");
        printf("\n                         归还图书-------3");
        printf("\n                         录入图书-------4");
        printf("\n                         删除图书-------5");
        printf("\n                         录入用户信息---6");
        printf("\n                         删减图书-------7");
        printf("\n                         查看用户-------8");
        printf("\n                         修改密码-------9");
        printf("\n                         返回----------0\033[0m");
        printf("\n请按照前面的序号进行操作:");
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
                printf("请给出要删除图书的名字");
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
                printf("采集参数失败");
        }
    }
}

void User(char account[]){
    while(1){
        system("cls");
        printf("\033[32m***********************欢迎使用图书管理系统***************************");
        printf("\n                           查看个人信息----1");
        printf("\n                           查看图书-------2");
        printf("\n                           修改密码-------3");
        printf("\n                           返回----------0\033[0m\n");
        printf("\n请按照前面的序号进行操作:");
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
                printf("采集参数失败");
        }
    }
}

void Contact_developer(){
    printf("\033[32m手机：14754586583\n");
    printf("邮箱：1348063327@qq.com\033[0m\n");
    printf("按任意键继续");
    getch();
}

void input_students(){    //用户信息录入
    while(1){             //利用死循环可有效防止其他按键干扰
        system("cls");
        Students *pstudent;
        pstudent = (Students*)malloc(M);     //申请空间
        printf("请输入学号(工号)：");
        scanf("%lu",&pstudent->student_id);

        printf("请输入姓名：");
        scanf("%s",pstudent->name);

        printf("请输入班级(小于10位数)：");
        scanf("%s",pstudent->class);

        printf("请输入联系方式(小于10位数)：");
        scanf("%s",pstudent->phone_number);

        printf("请输入账户余额(小于10位数)：");
        scanf("%d",&pstudent->account_balance);

        printf("请输入信用值(小于10位数)：");
        scanf("%d",&pstudent->credit_value);

        save_students(pstudent);
        system("cls");

        printf("-------------------------\n");
        printf("|   保存成功！是否继续？  |\n");
        printf("| 1.是             2.否 |\n");
        printf("-------------------------\n");

        switch (Check()) {
            case '1':break;
            case '2':return;
            default:printf("输入有误\n");break;
        }
    }
}

void save_students(Students *p){   //将p中内容写入文件
    FILE *fp;    //文件指针
    fp = fopen("students.txt","ab");   //以追加的方式打开名字为mybook的二进制文件
    if(fp == NULL){
        printf("cannot open file");
    }
    else{   //将p所指向的一段大小为N的内容存入fp所指向的文件中
        fprintf(fp,"%lu %s %s %s %d %d\n",p->student_id,p->name,p->class,p->phone_number,p->account_balance,p->credit_value);
    }
    fclose(fp);    //关闭文件
}

void search_students(){
    Students stu;//学生信息
    history his;//借阅信息

    FILE *fp0,*fp1;//文件指针
    time_t tend_time;//当前时间戳
    long int t;//借阅实际天数

    int n;
    char fname[30];//存放输入
    unsigned long int fstudent_id;
    printf("\n请输入学号:  ");
    scanf("%lu",&fstudent_id);
    printf("请输入姓名:  ");
    scanf("%s",fname);

    if ((fp0 = fopen("students.txt","r")) == NULL){//打开文件
        printf("\n文件不存在!按任意键返回\n");
        getch();
        system("pause");
        return;
    }
    else{
        for(int i=0;!feof(fp0);i++){//打开学生信息文件
            fscanf(fp0,"%lu %s %s %s %d %d\n",&stu.student_id,stu.name,stu.class,stu.phone_number,&stu.account_balance,&stu.credit_value);//读取文件
            if(stu.student_id == fstudent_id && strcmp(stu.name,fname) == 0){
                n++;
                break;
            }
        }
        if(n == 0){
            printf("查无此人,按任意键返回\n");
            getch();
            return;
        }
        if((fp1 = fopen("history.txt","r")) != NULL){//打开借阅信息文件
            for(int i=0;!feof(fp1);i++){
                fscanf(fp1,"%lu %s %ld %d %f",&his.student_id,his.books,&his.start_time,&his.borrow_day,&his.penalty);//读取文件
                if(his.student_id == fstudent_id){
                    break;
                }
            }
        }
        else{
            printf("\n文件不存在！按回车键返回\n");
            getch();
            return;
        }
    }
    fclose(fp0);//关闭文件
    fclose(fp1);

    t = ( (long)(time(&tend_time)) - his.start_time) / (3600 * 24);//实际借阅天数

    printf("\n学号:%lu\n姓名:%s\n班级:%s\n联系方式:%s\n账户余额:%d\n信用值:%d\n",stu.student_id,stu.name,stu.class,stu.phone_number,stu.account_balance,stu.credit_value);
    printf("\n借阅书籍:%s\n借书时长（天）:%d\n违约金:%f\n",his.books,his.borrow_day,his.penalty);
    if(t > DEADLINE){
        printf("已过期未还\n");
    }
    else{
        printf("在借阅期限内\n");
    }
    system("pause");
    return;
}