/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified:	2018-12-07 13:17
#
# Filename:		Window.h
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include<iostream>
#include "LkList.h"
Status CreateWindows(LkList &L,int position[2][2],int number){
    LNode *NewWindows = (LNode *) malloc(sizeof(LNode));
    if(!NewWindows)
        exit(OVERFLOW);
    NewWindows->next = NULL;
    NewWindows->Number = number;
    for(int r = 0;r<=1;r++) 
        for(int i =0 ;i<=1;i++)
            NewWindows->pos[r][i] = position[r][i];
    Position PreHeadNext = L.head->next;
    L.head->next = NewWindows;
    NewWindows ->next = PreHeadNext;
    L.len++;
    return OK;
}
Status Compare(int WindowsPositon[2][2],int PointPosition[2]){
    if(WindowsPositon[0][0]<=PointPosition[0]&&
       WindowsPositon[0][1]<=PointPosition[1]&&
       WindowsPositon[1][0]>=PointPosition[0]&&
       WindowsPositon[1][1]>=PointPosition[1])
        return OK;
    else    return ERROR;
}
Status FocusWindows(LkList &L,int pos[2]){
    //if(LkListEmpty(L))
        //return  ERROR;
    Position p = L.head;
    while(p){
        Position pre_p= p;
        p = p->next;
        if(Compare(p->pos,pos)){
            Position PreHeadNext = L.head->next;
            if(p != PreHeadNext){
                L.head->next = p;
                pre_p->next = p->next;
                p->next = PreHeadNext;
            }
            std::cout<<p->Number;
            return OK;
        }
    }
    std::cout <<"IGNORED"<<std::endl;
    return OK;
}

