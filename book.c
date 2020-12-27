#include "manage.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define N sizeof(Books)

Books *creat(void){      //���ļ��е����ݶ����������У�����ֵΪ��ͷ��ַ
    FILE *fp;       //�ļ�ָ��
    Books *head=NULL;
    Books *p2,*p1;
    if((fp = fopen("library.txt","r")) == NULL){
        printf("\n�ļ�������!�����������\n");
        getch();
        exit(0);
    }     //��ֻ���ķ�ʽ���ļ�
    if(fp == NULL){
        printf("���ļ�ʧ��\n");
    }
    p1 = p2;
    for(int n=0;!feof(fp);n++){         //�ж��ļ�������־
        p1 = (Books*)malloc(N);         //���ڴ�����һ�οռ�
        fscanf(fp,"%s %s %s %d %s %f %c\n",p1->book_id,p1->title,p1->publisher,&p1->book_version,p1->author,&p1->price,&p1->available);//��fp��ָ����ļ��е����ݸ���p ,&p1->price,p1->available
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


void find_book(){//��ѯͼ��
    system("cls");  //����
    printf("\033[33m                  ͼ���ѯ\n");
    printf("        *     1.����  ��ѯ      *\n");
    printf("        *     2.����  ��ѯ      *\n");
    printf("        *     3.�������ѯ      *\n");
    printf("        *     4.���  ��ѯ      *\n");
    printf("              ��0�������˵�      \033[0m\n");
    switch(Check()){
        case '0':return;
        case '1':find_name_book();break;
        case '2':find_author_book();break;
        case '3':find_publish_book();break;
        case '4':find_kinds_book();break;
        default :
            printf("\n��������");
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

            fp=fopen("library.txt","w");//����ļ���ֻд�򿪣�Ȼ��ر�
            fclose(fp);
            fp=fopen("library.txt","a");//׷���ļ�

            for (;head!=NULL;)//���������ݸ��ǵ��ļ�
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
        printf("��ͼ�鲻����\n");
    }
    else
    {
        printf("ɾ���ɹ�\n");
    }
}


void input_book(){   //ͼ��¼��
    while(1){
        system("cls");
        Books *pbook;
        pbook = (Books*)malloc(N);     //����ռ�
        //����ͼ����Ϣ
        printf("����������(С��10λ��)��");
        scanf("%s",pbook->title);getchar();
        printf("������������(С��10λ��)��");
        scanf("%s",pbook->author);getchar();
        printf("������ͼ�����(С��10λ��)��");
        scanf("%s",pbook->book_id);getchar();
        printf("������ͼ��汾(С��10λ��)��");
        scanf("%d",&pbook->book_version);getchar();
        printf("������ͼ����浥λ(С��10λ��)��");
        scanf("%s",pbook->publisher);getchar();
        printf("������ͼ��۸�");
        scanf("%f",&pbook->price);

        pbook->available = 'Y';
        printf("������ͼ��������");
        scanf("%d",&pbook->number);
        save_book(pbook);

        system("cls");
        printf("-------------------------\n");
        printf("| ����ɹ����Ƿ������  |\n");
        printf("| 1.��             2.�� |\n");
        printf("-------------------------\n");

        switch (Check()) {
            case '1':break;
            case '2':return;
            default:printf("��������");break;
        }
    }
}

void save_book(Books *p){   //��p������д���ļ�
    FILE *fp;    //�ļ�ָ��
    fp = fopen("library.txt","ab");   //��׷�ӵķ�ʽ������Ϊmybook�Ķ������ļ�
    if(fp == NULL){
        printf("cannot open file");
    }
    else{   //��p��ָ���һ�δ�СΪN�����ݴ���fp��ָ����ļ���
        fprintf(fp,"%s %s %s %d %s %lf %c\n",p->book_id,p->title,p->publisher,p->book_version,p->author,p->price,p->available);//д���ļ�
    }
    fclose(fp);    //�ر��ļ�
}

void find_name_book(){//�����ֲ�ѯ
    system("cls");
    Books *pbook;
    int i=0;
    pbook=creat();
    char name[20];
    printf("��������Ҫ��ѯͼ���������");
    gets(name);
    printf("\n*********************************************ͼ������****************************************************\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("ͼ�����        ����        ���浥λ            ͼ��汾          ������             �۸�        �Ƿ�ɽ�\n");
    while(pbook!=NULL){
        if(pbook!=NULL && strcmp(pbook->title,name) == 0){
            i++;
            printf("%3s%18s%18s%15d%18s              %.2lf%10c\n",pbook->book_id,pbook->title,pbook->publisher,pbook->book_version,pbook->author,pbook->price,pbook->available);
            break;
        }
        pbook = pbook->next;
    }
    if(i == 0){//��ѯ���û�����˳�
        system("cls");
        printf("���޴���,��������̷���\n");
        getch();
        return;
    }
    printf("����������أ�");
    getch();
}

void find_author_book(){    //�����߲�ѯ
    system("cls");
    Books *head,*p;
    int i=0;
    head=creat();
    char name[40];
    printf("��������Ҫ��ѯͼ�����������");
    gets(name);
    p=head;
    printf("*********************************************ͼ������****************************************************\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("ͼ�����        ����        ���浥λ            ͼ��汾          ������             �۸�        �Ƿ�ɽ�\n");
    while(p!=NULL){
        if(p!=NULL && strcmp(p->author,name) == 0){
            i++;
            printf("%3s%18s%18s%15d%18s              %.2lf%10c\n",p->book_id,p->title,p->publisher,p->book_version,p->author,p->price,p->available);
        }
        p = p->next;
    }
    if(i == 0){//��ѯ���û�����˳�
        system("cls");
        printf("\n���޴�����,�����������\n");
        getch();
        return;
    }
    printf("���س������أ�");
    getch();
}

void find_publish_book()//���������ѯ
{
    system("cls");
    Books *head,*p;
    int i=0;
    head=creat();
    char name[20];
    printf("��������Ҫ��ѯͼ��ĳ����磺");
    gets(name);
    p=head;
    printf("*********************************************ͼ������****************************************************\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("ͼ�����        ����        ���浥λ            ͼ��汾          ������             �۸�        �Ƿ�ɽ�\n");
    while(p!=NULL)
    {
        if(p!=NULL && strcmp(p->publisher,name) == 0)
        {
            i++;
            printf("%3s%18s%18s%15d%18s              %.2lf%10c\n",p->book_id,p->title,p->publisher,p->book_version,p->author,p->price,p->available);
        }
        p = p->next;
    }
    if(i == 0)//��ѯ���û�����˳�
    {
        system("cls");
        printf("\n���޴˳�����ͼ��,�����������\n");
        getch();
        find_book();
    }

    printf("����������أ�");
    getch();
    find_book();
}

void find_kinds_book(){//��ͼ�������ѯ
    system("cls");
    Books *head,*p;
    int i=0;
    head=creat();
    char name[20];
    printf("��������Ҫ��ѯͼ������ࣺ");
    gets(name);
    p=head;
    printf("*********************************************ͼ������****************************************************\n");
    printf("---------------------------------------------------------------------------------------------------------\n");
    printf("ͼ�����        ����        ���浥λ            ͼ��汾          ������             �۸�        �Ƿ�ɽ�\n");
    //printf("-------------------------------------------------------------------------------------------------------------");
    while(p!=NULL){
        if(p!=NULL && strcmp(p->book_id,name) == 0){
            i++;
            //printf("%s%14s%14s%14s   %14s   %18s         %.2f%12d\n",p->number,p->name,p->author,p->type,p->publish,p->time,p->price,p->num);
            printf("%3s%18s%18s%15d%18s              %.2lf%10c\n",p->book_id,p->title,p->publisher,p->book_version,p->author,p->price,p->available);
        }
        p = p->next;
    }

    if(i == 0)//��ѯ���û�����˳�
    {
        system("cls");
        printf("\n���޴���ͼ��,�����������\n");
        getch();
        find_book();
    }

    printf("����������أ�");
    getch();
    find_book();
}