/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified:	2018-10-27 14:05
#
# Filename:		SqList.h
#
# Description: 
#
=============================================================================*/
#ifndef SQLINK
#define SQLINK


#define TURE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
typedef int Status;
typedef int ElemType;
#define LIST_INTT_SIZE      100
#define LISTINCREASEMENT    10
#include <stdlib.h>
#include <stdio.h>
typedef struct{
    ElemType* elem;
    int length;
    int listsize;
}SqList;

Status InitSqList(SqList &L){
    L.elem = (ElemType *)malloc(LIST_INTT_SIZE * sizeof (ElemType ));
    if (!L.elem) exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INTT_SIZE;
    return OK;
}
Status DestroySqList(SqList &L){
    if (!L.elem) exit(ERROR);
    free(L.elem);
    return OK;
}
Status ClearSqList(SqList &L){
    if (!L.elem) exit(ERROR);
    free(L.elem);
    L.elem = (ElemType *)malloc(L.listsize * sizeof (ElemType ));
    L.length = 0;
    return  OK;
}
Status SqListEmpty(SqList L){
    if (!L.elem) exit(ERROR);
    if (!L.length)   
        return TURE;
    else 
        return ERROR;
}
int SqListLength(SqList L){
    if (!L.elem) exit(ERROR);
    return L.length;
}
void SqGetElem(SqList L,int i,ElemType &e){
    if (!L.elem || SqListEmpty(L)) exit(ERROR);
    if (i>=1&&i<=L.length)
        e = *(L.elem + i -1);
    else 
        exit(OVERFLOW);
}
Status Equal(ElemType param1,ElemType param2){
    if (param1 == param2)
        return TURE;
    else 
        return FALSE;
}
int SqLocateElem(SqList L,ElemType e,Status (*compare)(ElemType ,ElemType )){
    if (!L.elem || SqListEmpty(L)) exit(ERROR);
    int *p = NULL;
    for(p = L.elem;(p-L.elem)<=L.length;p++){
        if (compare(*p,e))
            return (p-L.elem+1);
    }
    return 0;
}
int SqPriorElem(SqList L,ElemType *cur_e,ElemType &pre_e){
    if (!L.elem || SqListEmpty(L)) exit(ERROR);
    if (cur_e == L.elem)
        return ERROR;
    else 
        pre_e = *(cur_e - 1);
    return OK;
}
int SqNextElem(SqList L,ElemType *cur_e,ElemType &next_e){
    if (!L.elem || SqListEmpty(L)) exit(ERROR);
    if (cur_e == (L.elem+L.length -1))
        return ERROR;
    else 
        next_e = *(cur_e + 1);
    return OK;
}
Status SqListInsert(SqList &L,int i,ElemType e){
    ElemType * newbase =NULL;
    ElemType * p =NULL;
    ElemType * q =NULL;
    if (!L.elem || SqListEmpty(L)) exit(ERROR);
    if (i<1 || i> L.length+1) return ERROR;
    if (L.length >= L.listsize){
        newbase = (ElemType *)realloc(L.elem,(L.listsize+LISTINCREASEMENT)*sizeof(ElemType ));
        if(!newbase) exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LISTINCREASEMENT;
    }
    q = &(L.elem[i-1]);
    for (p = &(L.elem[L.length-1]);p>=q;--p)
        *(p+1) = *p;
    *q = e;
    ++L.length;
    return OK;
}
Status SqListDelte(SqList &L, int i ,ElemType &e){
    if (!L.elem || SqListEmpty(L)) exit(ERROR);
    if((i<1) || (i>L.length)) return ERROR;
    ElemType *p = &(L.elem[i-1]);
    ElemType *q = L.elem+L.length-1;
    e = *p;
    for(++p;p<=q;++p)
        *(p-1)=*p;
    --L.length;
    return OK;
}
Status print(ElemType *e){
    if(printf("%d",*e))
        return OK;
    else 
        return ERROR;
}
Status SqListTraverse(SqList &L,Status visit(ElemType *e)){
    if (!L.elem || SqListEmpty(L)) exit(ERROR);
    ElemType *p = L.elem;
    ElemType *q = L.elem + L.length -1;
    for(;p<=q;++p)
        if(!visit(p))
            return ERROR;
    return OK;
}
#endif
