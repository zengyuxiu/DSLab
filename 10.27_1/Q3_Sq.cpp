/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-10-27 17:05
#
# Filename: Q3.cpp
#
# Description: 
#
=============================================================================*/
#include <stdio.h>
#include <iostream>
#include "SqList.h"
Status CreatSqList(SqList &L,int n){
    InitSqList(L);
    if (!L.elem)                                //exist?
        return ERROR;
    if (n>L.listsize){
        int size = ((n-LIST_INTT_SIZE)/LISTINCREASEMENT+1)*LISTINCREASEMENT;
        ElemType * newbase = (ElemType *)malloc((size+LIST_INTT_SIZE)*sizeof(ElemType));
        free(L.elem);
        L.elem = newbase;
    }
    ElemType *p = L.elem;
    int r=1;
    while(r<=n){
       *p++ = r++; 
    }
    L.length = n;
    return OK;
}
int recycle(int m,int n,SqList &L){
    int num = 0;
    int NumberOfPersons = n;
    int code = m;
    int e= 0;
    while (NumberOfPersons>1){
        n=NumberOfPersons;
        m = code+num;
        while(n){
            num = m%n;
            n/=m;
        }
        SqListDelte(L,num+1,e);
        printf("%d ",e);
        NumberOfPersons--;
    }
    return *L.elem;
}
int main(){
    int m,n;
    scanf("%d%d",&n,&m);
    SqList L;
    CreatSqList(L,10);
    recycle(38,10,L);
    printf("\nSurvival:%d",*L.elem);
    DestroySqList(L);
}
