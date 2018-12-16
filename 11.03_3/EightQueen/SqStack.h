/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified:	2018-12-02 12:27
#
# Filename:		stack.h
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include <stdlib.h>
#ifndef SQSTACK
#define SQSTACK
#define STACK_INIT_SIZE 100;
#define STACKINCREMENT 10;
#define TURE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
typedef int Status;
typedef  int SElemType;
typedef struct {
   SElemType  *base;
   SElemType  *top;
   int stacksize;
}SqStack;
Status InitStack(SqStack &S){
   S.stacksize = STACK_INIT_SIZE; 
   S.base = (SElemType *)malloc(S.stacksize*sizeof(SElemType));
   if(!S.base)
       exit(OVERFLOW);
   S.top = S.base;
   return OK;
}
Status DestroyStack (SqStack &S){
    free(S.base);
    S.base = NULL;
    S.top = NULL;
    S.stacksize = 0;
    return OK;
}
Status ClearStack(SqStack &S){
    SElemType * newbase = (SElemType *)realloc(S.base,0);
    if(!newbase)
        exit(OVERFLOW);
    S.base = newbase;
    S.top = S.base;
    S.stacksize = 0;
    return OK;
}
Status StackEmpty(SqStack S){
   if(!S.base)
        exit(ERROR);
    if(S.base == S.top)
        return TURE;
    else    
        return FALSE;
}
int StackLength(SqStack S){
    int len = (S.top - S.base)/sizeof(SElemType);
    return len-1;
}
Status GetTop(SqStack S,SElemType &e){
    if(StackEmpty(S))
        return ERROR;
    e = *S.top;
    return OK;
}
Status Push(SqStack &S,SElemType e){
   if(StackLength(S) == S.stacksize) {
       S.stacksize+=STACKINCREMENT;
       SElemType * newbase = (SElemType *)realloc(S.base,S.stacksize);
       S.base = newbase;
       SElemType *p = S.top;
       p++;
       *p = e;
   }
   else{
       S.top++;
       *S.top = e;
   }
    return OK;
}
Status Pop(SqStack &S,SElemType &e){
    if(StackEmpty(S))
        return ERROR;
    e = *S.top;
    S.top--;
    return OK;
}
#endif
