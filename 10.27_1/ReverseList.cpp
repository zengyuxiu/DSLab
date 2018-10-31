/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-10-27 15:22
#
# Filename: ReverseList.cpp
#
# Description: 
#
=============================================================================*/
#include "LkList.h"
#include "SqList.h"
#include <stdlib.h>
Status ReverseLkList(LkList &L){
    if(LkListEmpty(L))
        exit(ERROR);
    Position tmp=NULL,p=NULL;
    tmp = L.head->next;
    while((tmp)!=NULL){
        p=tmp->next;
        tmp->next = p->next;
        p->next = L.head->next;
        L.head = p;
    }
    L.tail = tmp;
    return OK;
}
Status ReverseSqList(SqList &L){
    if (SqListEmpty(L)) exit(ERROR);
    int tmp,i;
    for(i=0;i<L.length/2;i++){
        tmp=L.elem[i];
        L.elem[i] = L.elem[L.length-i-1];
        L.elem[L.length-i-1] = tmp;
    }
    return OK;
}
