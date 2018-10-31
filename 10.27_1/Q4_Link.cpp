/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-10-28 11:05
#
# Filename: Q4.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include "LkList.h"
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
Status Move(LkList &L,int move[]){
    if(LkListEmpty(L)) 
        return ERROR;
    int Number = move[0];
    int Longtitude = move[1];
    int newPos = Number + Longtitude;
    if (newPos >L.len||newPos<1)
        return OVERFLOW;
    LNode e;
    LkListDelte(L,Number,e);
    LkListInsert(L,newPos,e);
    return OK;
}
int main(void){
    int times = 0;
    int n = 0;
    int p = 0,q = 0;
    int move[times+1][2];
    scanf("%d",&n);
    scanf("%d",&times);
    for (int r= 0;r<= times;r++){
        scanf("%d %d",&p,&q);
        move[r][0] = p;
        move[r][1] = q;
    }
    LkList L;
    CreateLkList(L,n);
    for (int r= 0;r<=times;r++){
        Move(L,move[r]);
    }
}


