/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-10-27 10:24
#
# Filename: LkList.h
#
# Description: 
#
=============================================================================*/
#ifndef  LINKLIST
#define  LINKLIST



#define TURE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
typedef int Status;
typedef int ElemType;
#include <stdlib.h>
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}* Position, *Link;
typedef struct{
    Link head,tail;
    int len;
}LkList;


Status InitLkList(LkList &L){
    L.head = (LNode *)malloc(sizeof(LNode));//有头节点
    L.head->next = NULL;
    L.tail = L.head;
    if(!L.head) exit(OVERFLOW);
    L.len= 0;
    return OK;
}
Status ClearLkList(LkList &L){
    Position pre_p = NULL;
    if (!L.head||!L.len)   return ERROR;
    Position p = NULL;
    for(p=L.head;p!=L.tail;){
       pre_p = p;
       p = p->next; 
       free(pre_p);
    }
    free(L.tail);
    L.tail = L.head;
    L.len = 0;
    return OK;
}
Status DestroyLkList(LkList &L){
    Position pre_p = NULL;
    if (!L.head||!L.len)   return ERROR;
    Position p = NULL;
    for(p=L.head;p!=L.tail;){
       pre_p = p;
       p = p->next; 
       free(pre_p);
    }
    free(L.head);
    free(L.tail);
    L.head = NULL;
    L.tail = NULL;
    return OK;
}
Status LkListEmpty(LkList L){
    if(!L.head)  exit(ERROR);
    if(!L.len)
        return TURE;
    else 
        return FALSE;
}
int LkListLength(LkList L){
    if(!LkListEmpty(L))
        return L.len;
    else
        exit(ERROR);
}
void LinkGetElem(LkList L,int t,int &e){
    if(LkListEmpty(L))  exit(ERROR);
    Position p = L.head->next;
    int SqNum = 1;
    for(;SqNum<t;SqNum++)
        p = p->next;
    e = p->data;
}
int LinkLocateElem(LkList L,ElemType e,Status compare(ElemType ,ElemType )){
    if(LkListEmpty(L))   exit(ERROR);
    Position p = L.head->next;
    int SqNum = 1;
    for(;p->next != NULL;p = p->next,SqNum++)
        if(compare(p->data,e))
            return SqNum;
    return 0;
}
Status LinkPriorElem(LkList L,LNode cur_e,LNode &pre_e){
    if(LkListEmpty(L)) exit(ERROR);
    Position p = L.head->next;
    for(;p->next == NULL;p= p->next)
        if(p->next == &cur_e){
            pre_e = *p;
            return  OK;
        }
    return ERROR;
}
Status LinkNextElem(LkList L,LNode cur_e,LNode &pre_e){
    if(LkListEmpty(L)) exit(ERROR);
    Position p = L.head->next;
    for(;p->next == NULL;p= p->next)
        if(p == &cur_e){
            pre_e = *p->next;
            return  OK;
        }
    return ERROR;
}
Status LkListInsert(LkList &L,int i,LNode &e){
    if(LkListEmpty(L))  exit(ERROR);
        Position p = L.head->next;
        int SqNum = 1;
        for(;SqNum<i-1;SqNum++)
            p = p->next;
    Position q = p->next;
    p->next = &e;
    e.next = q;
    L.len++;
    return OK;
}
Status LkListDelte(LkList &L,int i,LNode &e){
    if(LkListEmpty(L))  exit(ERROR);
        Position p = L.head->next;
        int SqNum = 1;
        for(;SqNum<i-1;SqNum++)
            p = p->next;
    Position q = p->next;
    p->next = q->next;
    e.data = q->data;
    free (q);
    L.len--;
    return OK;
}
Status LkListTraverse(LkList &L,Status visit(LNode *e)){
    if(LkListEmpty(L)) exit(ERROR);
    Position p = L.head->next;
    for(;p->next != NULL ;p = p->next)
        if(!visit(p))
            return ERROR;
    return OK;
}
Status CreateLkList(LkList &L,char *s){
    if(!L.head)
        exit (ERROR);
    InitLkList(L);
    Position p = L.head;
    for (char *r = s;*r!='*';r++){
        LNode * NewnNode = (LNode *)malloc(sizeof(LNode));
        NewnNode->next = NULL;
        NewnNode ->data = (*r-48);
        p->next = NewnNode;
        L.tail = NewnNode;
        p = p->next;
        L.len++;
    }
    return  OK;
}
#endif
