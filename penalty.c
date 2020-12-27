#include "manage.h"
#include <stdio.h>

void Penalty(struct History *pHistory,struct Students *pStudents){
    float penalty;
    if(pHistory->borrow_day>DEADLINE){
        penalty = (pHistory->borrow_day-DEADLINE)*PENALTY;
        pStudents->account_balance = pStudents->account_balance-penalty;
        pStudents->credit_value = pStudents->credit_value-CREDIT_VALUE_PENALTY
        if(pStudents->account_balance<=penalty){
            printf("���㣬����ϵ�û�");
            printf("�û�������%s",pStudents->name);
            printf("�û���ϵ��ʽ��%s",pStudents->phone_number);
        }
        if(pStudents->credit_value<60){
            printf("����ֵΪ��%dС��60����Ҫһ�ܺ����°쿨",pStudents->credit_value);
        }
        printf("ΥԼ��Ϊ%f",pHistory->penalty);
    }
}