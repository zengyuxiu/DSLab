/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-12-08 15:43
#
# Filename: NeighborNumber.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#define MAXNUMBER 10000
int main(void){
    int flag[MAXNUMBER+1]={0};
    int n = 0;
    int pairs = 0;
    scanf("%d",&n);
    while(n--){
        int number = -1;
        scanf("%d",&number);
        flag[number] = 1;
        if(flag[number-1])
            pairs++;
        if(flag[number+1])
            pairs++;
    }
    printf("%d",pairs);
    return 0;
}
