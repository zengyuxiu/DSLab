/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-11-01 12:27
#
# Filename: Combine.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include "SqList.h"
#include "LkList.h"
Status DeleteSameElem_Sq(SqList &L){
    for(int r = 0;(r+1)<=L.length-1;){
        ElemType elem = 0;
        if (L.elem[r]==L.elem[r+1])
            SqListDelte(L,r+1,elem);
        else
            r++;
    }
    return OK;
}
Status DeleteSameElem_Lk(LkList &L){
    Position p = L.head->next;
    for(int r = 1;(r+1)<=L.len;){
        LNode elem;
        if (p->data==p->next->data)
            LkListDelte(L,r+1,elem);
        else{
            r++;
            p=p->next;
        }
    }
    return OK;
}
Status Combine(SqList &A,LkList &B,SqList &C){
    DeleteSameElem_Lk(B);
    DeleteSameElem_Sq(A);
    A.elem = (ElemType *)realloc(A.elem,(B.len+A.length)*sizeof(ElemType));
    if(!A.elem)
        exit(OVERFLOW);
    int r = 1;
    Position p = B.head->next;
    for(r = 1;r<=A.length;){
        for(;p != NULL;p = p->next){
            if(p->data == A.elem[r]){
                r++;
                continue;
            }
        }
        ElemType e;
       SqListDelte(A,r,e);

    }
    C.elem = A.elem;
    C.length  = A.length;
    C.listsize = A.listsize;
    DestroyLkList(B);
    return OK;
}
int main(void){
   SqList A,C; 
   LkList B;
   char s[100];
   InitSqList(A);
   InitSqList(C);
   InitLkList(B);
   scanf("%s",s);
   CreatSqList(A,6,s);
   CreateLkList(B,s);
   Combine(A,B,C);
   for(int r=1;r<=C.length;r++){
       printf("%d\t",C.elem[r-1]);
   }
}
