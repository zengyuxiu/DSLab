/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2019 All rights reserved.
#
# Last modified: 2019-01-03 22:39
#
# Filename: HeapSort.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include"SqList.h"
typedef SqList HeapType;
void HeapAdjust(HeapType &H,int s,int m){
    auto rc = H.r[s];
    for(int j =2;j<=m;j*=2){
        if(j<m&&H.r[j].key < H.r[j+1].key)
            ++j;
        if(rc.key >= H.r[j].key)
            break;
        H.r[s] = H.r[j];
        s = j;
    }
    H.r[s] = rc;
}
void HeapSort(HeapType &H){
    for(int i = H.length/2;i>0;--i)
        HeapAdjust(H,i,H.length);
    for(int i = H.length;i>1;--i){
        auto tmp = H.r[1];
        H.r[1] = H.r[i];
        H.r[i] = tmp;
        HeapAdjust(H,1,i-1);
    }
}
