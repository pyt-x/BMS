#include <stdio.h>
#include "manage.h"
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#define SSQQ "qwertyuiop"//最高管理员密匙（用于创建管理员账号）

void Register_manage_door();
void Register_user_door();
void Login_in_manage_door();
void Login_in_user_door();
void tsmain();//修改密码

void Login_manage_home(){
    while (1){
        system("cls");
        printf("\033[35m _      _____ _     ____  ____  _      _____\n"
               "/ \\  /|/  __// \\   /   _\\/  _ \\/ \\__/|/  __/\n"
               "| |  |||  \\  | |   |  /  | / \\|| |\\/|||  \\  \n"
               "| |/\\|||  /_ | |_/\\|  \\__| \\_/|| |  |||  /_ \n"
               "\\_/  \\|\\____\\\\____/\\____/\\____/\\_/  \\|\\____\\\n"
               "                                            \n\033[0m");
        printf("*************欢迎来到图书管理系统**************\n"
               "********* 1、登录 ********** 2、注册 *********\n");
        printf("     *************0、返回************\n");
        switch (Check()) {
            case '1':Login_in_manage_door();break;
            case '2':Register_manage_door();break;
            case '0':return;
            default:printf("输入有误");return;
        }
    }
}

void Login_user_home(){
    while (1){
        system("cls");
        printf("\033[35m _      _____ _     ____  ____  _      _____\n"
               "/ \\  /|/  __// \\   /   _\\/  _ \\/ \\__/|/  __/\n"
               "| |  |||  \\  | |   |  /  | / \\|| |\\/|||  \\  \n"
               "| |/\\|||  /_ | |_/\\|  \\__| \\_/|| |  |||  /_ \n"
               "\\_/  \\|\\____\\\\____/\\____/\\____/\\_/  \\|\\____\\\n"
               "                                            \n\033[0m");
        printf("*************欢迎来到图书管理系统**************\n"
               "********* 1、登录 ********** 2、注册 *********\n");
        printf("     *************0、返回************\n");
        switch (Check()) {
            case '1':Login_in_user_door();break;
            case '2':Register_user_door();break;
            case '0':return;
            default:printf("输入有误");return;
        }
    }
}

void Login_in_manage_door(){
    system("cls");
    FILE *fp;
    char account[11],pass[7];
    printf("\033[31m _     ____  _____ _  _     \n"
           "/ \\   /  _ \\/  __// \\/ \\  /|\n"
           "| |   | / \\|| |  _| || |\\ ||\n"
           "| |_/\\| \\_/|| |_//| || | \\||\n"
           "\\____/\\____/\\____\\\\_/\\_/  \\|\n\033[0m");
    printf("请输入你的账号密码：");
    scanf("%s %s",account,pass);
    if ((fp = fopen("manage.txt", "r")) == NULL){
        printf("文件打开失败!\n");
        system("pause");
        return;
    }
    if(Login_in(fp,account,pass)){
        Manager(account);
    }
}

void Login_in_user_door(){
    system("cls");
    FILE *fp;
    char account[11],pass[7];
    printf("\033[31m _     ____  _____ _  _     \n"
           "/ \\   /  _ \\/  __// \\/ \\  /|\n"
           "| |   | / \\|| |  _| || |\\ ||\n"
           "| |_/\\| \\_/|| |_//| || | \\||\n"
           "\\____/\\____/\\____\\\\_/\\_/  \\|\n\033[0m");
    printf("请输入你的账号密码：");
    scanf("%s %s",account,pass);
    if ((fp = fopen("students_password.txt", "r")) == NULL){
        printf("文件打开失败!\n");
        system("pause");
        return;
    }
    if(Login_in(fp,account,pass)){
        User(account);
    }
}


int Login_in(FILE *FP,char account[],char pass[]){
    char sno0[11],pass0[7];
    for (;;){
        while (!feof(FP))
        {
            fscanf(FP, "%s",sno0);
            if (strcmp(account,sno0) == 0)
            {
                fscanf(FP, "%s",pass0);
                if (strcmp(pass,pass0) == 0)
                {
                    printf("登录成功!\n");
                    system("pause");
                    return 1;
                }
                else
                {
                    printf("密码错误!\n");
                    system("pause");
                    return 0;
                }
            }
        }
        printf("无此账号！\n");
        system("pause");
        return 0;
    }
}

void Register_manage_door(){
    system("cls");
    FILE *fp;
    printf("\033[31m ____  _____ _____ _  ____  _____  _____ ____ \n"
           "/  __\\/  __//  __// \\/ ___\\/__ __\\/  __//  __\\\n"
           "|  \\/||  \\  | |  _| ||    \\  / \\  |  \\  |  \\/|\n"
           "|    /|  /_ | |_//| |\\___ |  | |  |  /_ |    /\n"
           "\\_/\\_\\\\____\\\\____\\\\_/\\____/  \\_/  \\____\\\\_/\\_\\\n\033[0m");
    printf("请输入最高管理员密匙：\n");
    char SQ[15];
    gets(SQ);
    if(strcmp(SQ,SSQQ)==0){
        if ((fp = fopen("manage.txt", "r+")) == NULL){
            printf("打开文件失败!\n");
            system("pause");
            exit(0);
        }
        if(Register(fp)){
            Login_in_manage_door();
        }
    }
    else{
        printf("警告！密匙错误\n");
        system("pause");
    }
}

void Register_user_door(){
    system("cls");
    FILE *fp;
    printf(" \033[31m____  _____ _____ _  ____  _____  _____ ____ \n"
           "/  __\\/  __//  __// \\/ ___\\/__ __\\/  __//  __\\\n"
           "|  \\/||  \\  | |  _| ||    \\  / \\  |  \\  |  \\/|\n"
           "|    /|  /_ | |_//| |\\___ |  | |  |  /_ |    /\n"
           "\\_/\\_\\\\____\\\\____\\\\_/\\____/  \\_/  \\____\\\\_/\\_\\\n\033[0m");
    if ((fp = fopen("students_password.txt", "r+")) == NULL){
        printf("打开文件失败!\n");
        system("pause");
        exit(0);
    }
    if(Register(fp)){
        Login_in_user_door();
    }
}

int Register(FILE *FP){
    char account[11],sno0[11],mima[7],mima0[7];
    system("cls");
    loop:
    printf("请输入账号(十位数):\n");
    scanf("%s",account);
    int len=strlen(account);
    if(len!=10){printf("请输入10位数字!\n");  goto loop;}
    while(!feof(FP))
    {
        fscanf(FP,"%s",sno0);
        if(strcmp(account,sno0)==0){printf("存在此账号！请重新输入\n");
            goto loop;}
    }
    mima:
    printf("请输入密码(6位数):\n");
    scanf("%s",mima);
    len=strlen(mima);
    if(len!=6){printf("请输入6位数！\n");goto mima;}
    printf("请再次输入密码确认:\n");
    scanf("%s",mima0);
    if(strcmp(mima,mima0)==0)
    {
        system("cls");
        fprintf(FP, "%s %s\n", account, mima);
        fclose(FP);
        printf("创建成功！\n");
        system("pause");
        return 1;
    }
    else
    {
        printf("两次输入密码不一致,请重新输入\n"
               "退出请按0");
        int a=getch();
        if(!a)
            return 0;
        goto mima;
    }
}

void tsmain(FILE *FP,int k,char account[]){
    system("cls");
    printf("\033[31m ____  _     ____  _      _____ _____\n"
           "/   _\\/ \\ /|/  _ \\/ \\  /|/  __//  __/\n"
           "|  /  | |_||| / \\|| |\\ ||| |  _|  \\  \n"
           "|  \\_ | | ||| |-||| | \\||| |_//|  /_ \n"
           "\\____/\\_/ \\|\\_/ \\|\\_/  \\|\\____\\\\____\\\n\n\033[0m");
    struct User{
        char account[11];
        char password[7];
    }user0;
    strcpy(user0.account,account);

    //统计文件中账号密码个数
    int i=0;
    char m[11],n[7];
    while (!feof(FP))
    {
        fscanf(FP,"%s %s",m,n);
        i++;
    }
    fseek(FP,0L,SEEK_SET);
    i=i-1;
    //修改密码
    int j=0;
    struct User user[i];
    while(!feof(FP)){
        fscanf(FP,"%s %s",user[j].account,user[j].password);
        if(strcmp(user0.account,user[j].account)==0)
        {
            printf("请输入要修改为的密码：\n");
            scanf("%s",user0.password);
            strcpy(user[j].password,user0.password);
            printf("修改成功\n");
        }
        j++;
    }
    fclose(FP);
    //将修改后的信息重新写入文件
    if(k)
    {if((FP=fopen("manage.txt","w"))==NULL){
            printf("打开文件失败!");
            exit(0);}}
    else
    {if((FP=fopen("students_password.txt","w"))==NULL){
            printf("打开文件失败!");
            exit(0);}}
    for(j=0;j<=i-1;j++){
        fprintf(FP,"%s %s\n",user[j].account,user[j].password);
    }
    fclose(FP);
}

void Change_manage_password(char account[]){
    FILE *fp;
    if ((fp = fopen("manage.txt", "r")) == NULL){
        printf("打开文件失败！");
        exit(0);
    }
    tsmain(fp, 1, account);
}

void Change_user_password(char account[]){
    FILE *fp;
    if ((fp = fopen("students_password.txt", "r")) == NULL){
        printf("打开文件失败！");
        exit(0);
    }
    tsmain(fp, 1, account);
}