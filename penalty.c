#include "manage.h"
#include <stdio.h>

void Penalty(struct History *pHistory,struct Students *pStudents){
    float penalty;
    if(pHistory->borrow_day>DEADLINE){
        penalty = (pHistory->borrow_day-DEADLINE)*PENALTY;
        pStudents->account_balance = pStudents->account_balance-penalty;
        pStudents->credit_value = pStudents->credit_value-CREDIT_VALUE_PENALTY
        if(pStudents->account_balance<=penalty){
            printf("余额不足，请联系用户");
            printf("用户姓名：%s",pStudents->name);
            printf("用户联系方式：%s",pStudents->phone_number);
        }
        if(pStudents->credit_value<60){
            printf("信用值为：%d小于60，需要一周后重新办卡",pStudents->credit_value);
        }
        printf("违约金为%f",pHistory->penalty);
    }
}