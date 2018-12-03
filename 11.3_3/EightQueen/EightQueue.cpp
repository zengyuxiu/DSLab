/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-12-02 12:27
#
# Filename: EightQueue.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include<iostream>
#include "SqStack.h"
#define QueenNumber         8
Status PostionJudgement(SqStack &S){
    SElemType * p = S.base+1;
    SElemType * q = S.top;
    if(p == q)
        return OK;
    for(;p!=q;p++){
        int dx = (p-q)/sizeof(SElemType);
        int dy = (*p-*q);
        if((dy==dx)||(dy==-dx))
            return ERROR;
        if(*q == *p)
            return ERROR;    
    }
    return OK;
}
Status EightQueen(SqStack &S){
    int p = 1;
    Push(S,p);
    while(StackLength(S)<=QueenNumber){
        GetTop(S,p);
        while(p<=QueenNumber&&!PostionJudgement(S))
            p++;
        if(p<=QueenNumber){
            if(p == QueenNumber)
                return OK;
            else{
                p = 1;
                Push(S,p);
                GetTop(S,p);
            }
        }
        else{
            Pop(S,p);
            GetTop(S,p);
        }
    }
    return ERROR;
}
int main(void){
    SqStack S;
    InitStack(S);
    EightQueen(S);
    DestroyStack(S);
}
