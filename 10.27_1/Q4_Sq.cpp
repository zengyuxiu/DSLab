/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-10-28 13:16
#
# Filename: Q4_Sq.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
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
Status Move(SqList &L,int move[]){
    if(SqListEmpty(L)) 
        return ERROR;
    int Number = move[0];
    int Longtitude = move[1];
    int Locate = SqLocateElem(L,Number,Equal);
    int newPos = Locate + Longtitude;
    if (newPos >L.length||newPos<1)
        return OVERFLOW;
    ElemType e;
    SqListDelte(L,Locate,e);
    SqListInsert(L,newPos,e);
    return OK;
}
int main(void){
    int times = 0;
    int n = 0;
    int p = 0,q = 0;
    scanf("%d",&n);
    scanf("%d",&times);
    int move[times-1][2]={0};
    for (int r= 0;r<= times-1;r++){
        scanf("%d %d",&p,&q);
        move[r][0] = p;
        move[r][1] = q;
    }
    SqList L;
    CreatSqList(L,n);
    for (int r= 0;r<times;r++){
        Move(L,move[r]);
    }
    for (int re=0,*p = L.elem ;re<L.length; re++,p++){
            printf("%d",*p);
        }
    printf("\n");
}

