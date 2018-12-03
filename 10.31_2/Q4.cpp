/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-11-03 16:23
#
# Filename: Q4.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include "Sq_sort.cpp"

int FindMiddleNumber(SqList &L){
   SqSort_insertion(L); 
   int number[2][2]={{0},{0}};
   ElemType mid_num1 = L.elem[L.length/2];
   ElemType mid_num2 = L.elem[L.length/2+1];
   for(int r = 1;r<=L.length;r++){
        if(L.elem[r-1]<mid_num1)
           number[0][0]++;
        if(L.elem[r-1]>mid_num1)
           number[0][1]++;
        if(L.elem[r-1]<mid_num2)
           number[1][0]++;
        if(L.elem[r-1]>mid_num2)
           number[1][1]++;
   }
   if(number[0][0] == number [0][1])
        return mid_num1;
   else if (number[1][0] == number[1][0])
       return mid_num2;
   return -1;
}
int main (void){
    SqList L;
    int n;
    int mid_num = 0;
    char s[100];
    scanf("%d",&n);
    scanf("%s",s);
    CreatSqList(L,6,s);
    mid_num = FindMiddleNumber(L);
}
