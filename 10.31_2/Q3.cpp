/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified:	2018-11-03 11:25
#
# Filename:		Q3.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include"SqList.h"
int FindTurning(SqList &L){
    int point_flags[2][L.length-1]={
        0
    };
    int point_number = 0;
    for(int r = 1;r<=(L.length-1);r++){
        if(L.elem[r-1]>=L.elem[r])
            point_flags[1][r-1] = 1;
        else 
            point_flags[1][r-1] = 0;
    }
    int flag = point_flags[1][0];
    for(int r = 2;r<=(L.length-1);r++){
        if(point_flags[1][r-1] != flag) {
            point_number ++;
            flag = point_flags[1][r-1];
        }
    }
    return point_number;
}
int main(void){
    SqList L;
    char s[100];
    int n = 10;
    CreatSqList(L,n,s);
    FindTurning(L);
}
