/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-10-28 09:57
#
# Filename: Q3_Link.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include "LkList.h"
void recycle(int m ,int n,LkList &L){
    int num = 0;
    int NumberOfPersons = n;
    int code = m;
    LNode e;
    while (NumberOfPersons>1){
        n=NumberOfPersons;
        m = code+num;
        while(n){
            num = m%n;
            n/=m;
        }
        LkListDelte(L,num+1,e);
        printf("%d",e.data);
        NumberOfPersons--;
    }
}
Status CreateLkList(LkList &L,int n){
    if(!L.head)
        exit (ERROR);
    InitLkList(L);
    Position p = L.head;
    for (int r = 1;r<=n;r++){
        LNode * NewnNode = (LNode *)malloc(sizeof(LNode));
        NewnNode->next = NULL;
        NewnNode ->data = r;
        p->next = NewnNode;
        L.tail = NewnNode;
        p = p->next;
        L.len++;
    }
    return  OK;
}

int main(void){
    int m,n;
    scanf("%d%d",&m,&n);
    LkList L;
    CreateLkList(L,n);
    recycle(m,n,L);
    printf("\nSurvival:%d",L.head->next->data);
    DestroyLkList(L);
}
