#include <stdio.h>
#include "manage.h"
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#define SSQQ "qwertyuiop"//��߹���Ա�ܳף����ڴ�������Ա�˺ţ�

void Register_manage_door();
void Register_user_door();
void Login_in_manage_door();
void Login_in_user_door();
void tsmain();//�޸�����

void Login_manage_home(){
    while (1){
        system("cls");
        printf("\033[35m _      _____ _     ____  ____  _      _____\n"
               "/ \\  /|/  __// \\   /   _\\/  _ \\/ \\__/|/  __/\n"
               "| |  |||  \\  | |   |  /  | / \\|| |\\/|||  \\  \n"
               "| |/\\|||  /_ | |_/\\|  \\__| \\_/|| |  |||  /_ \n"
               "\\_/  \\|\\____\\\\____/\\____/\\____/\\_/  \\|\\____\\\n"
               "                                            \n\033[0m");
        printf("*************��ӭ����ͼ�����ϵͳ**************\n"
               "********* 1����¼ ********** 2��ע�� *********\n");
        printf("     *************0������************\n");
        switch (Check()) {
            case '1':Login_in_manage_door();break;
            case '2':Register_manage_door();break;
            case '0':return;
            default:printf("��������");return;
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
        printf("*************��ӭ����ͼ�����ϵͳ**************\n"
               "********* 1����¼ ********** 2��ע�� *********\n");
        printf("     *************0������************\n");
        switch (Check()) {
            case '1':Login_in_user_door();break;
            case '2':Register_user_door();break;
            case '0':return;
            default:printf("��������");return;
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
    printf("����������˺����룺");
    scanf("%s %s",account,pass);
    if ((fp = fopen("manage.txt", "r")) == NULL){
        printf("�ļ���ʧ��!\n");
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
    printf("����������˺����룺");
    scanf("%s %s",account,pass);
    if ((fp = fopen("students_password.txt", "r")) == NULL){
        printf("�ļ���ʧ��!\n");
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
                    printf("��¼�ɹ�!\n");
                    system("pause");
                    return 1;
                }
                else
                {
                    printf("�������!\n");
                    system("pause");
                    return 0;
                }
            }
        }
        printf("�޴��˺ţ�\n");
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
    printf("��������߹���Ա�ܳף�\n");
    char SQ[15];
    gets(SQ);
    if(strcmp(SQ,SSQQ)==0){
        if ((fp = fopen("manage.txt", "r+")) == NULL){
            printf("���ļ�ʧ��!\n");
            system("pause");
            exit(0);
        }
        if(Register(fp)){
            Login_in_manage_door();
        }
    }
    else{
        printf("���棡�ܳ״���\n");
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
        printf("���ļ�ʧ��!\n");
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
    printf("�������˺�(ʮλ��):\n");
    scanf("%s",account);
    int len=strlen(account);
    if(len!=10){printf("������10λ����!\n");  goto loop;}
    while(!feof(FP))
    {
        fscanf(FP,"%s",sno0);
        if(strcmp(account,sno0)==0){printf("���ڴ��˺ţ�����������\n");
            goto loop;}
    }
    mima:
    printf("����������(6λ��):\n");
    scanf("%s",mima);
    len=strlen(mima);
    if(len!=6){printf("������6λ����\n");goto mima;}
    printf("���ٴ���������ȷ��:\n");
    scanf("%s",mima0);
    if(strcmp(mima,mima0)==0)
    {
        system("cls");
        fprintf(FP, "%s %s\n", account, mima);
        fclose(FP);
        printf("�����ɹ���\n");
        system("pause");
        return 1;
    }
    else
    {
        printf("�����������벻һ��,����������\n"
               "�˳��밴0");
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

    //ͳ���ļ����˺��������
    int i=0;
    char m[11],n[7];
    while (!feof(FP))
    {
        fscanf(FP,"%s %s",m,n);
        i++;
    }
    fseek(FP,0L,SEEK_SET);
    i=i-1;
    //�޸�����
    int j=0;
    struct User user[i];
    while(!feof(FP)){
        fscanf(FP,"%s %s",user[j].account,user[j].password);
        if(strcmp(user0.account,user[j].account)==0)
        {
            printf("������Ҫ�޸�Ϊ�����룺\n");
            scanf("%s",user0.password);
            strcpy(user[j].password,user0.password);
            printf("�޸ĳɹ�\n");
        }
        j++;
    }
    fclose(FP);
    //���޸ĺ����Ϣ����д���ļ�
    if(k)
    {if((FP=fopen("manage.txt","w"))==NULL){
            printf("���ļ�ʧ��!");
            exit(0);}}
    else
    {if((FP=fopen("students_password.txt","w"))==NULL){
            printf("���ļ�ʧ��!");
            exit(0);}}
    for(j=0;j<=i-1;j++){
        fprintf(FP,"%s %s\n",user[j].account,user[j].password);
    }
    fclose(FP);
}

void Change_manage_password(char account[]){
    FILE *fp;
    if ((fp = fopen("manage.txt", "r")) == NULL){
        printf("���ļ�ʧ�ܣ�");
        exit(0);
    }
    tsmain(fp, 1, account);
}

void Change_user_password(char account[]){
    FILE *fp;
    if ((fp = fopen("students_password.txt", "r")) == NULL){
        printf("���ļ�ʧ�ܣ�");
        exit(0);
    }
    tsmain(fp, 1, account);
}