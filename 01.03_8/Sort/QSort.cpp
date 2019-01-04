/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2019 All rights reserved.
#
# Last modified: 2019-01-03 22:17
#
# Filename: QSort.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include"SqList.h"
int Partition(SqList &L,int low,int high){
    L.r[0] = L.r[low];
    auto pivotkey = L.r[low].key;
    while(low < high){
        while(low<high&&L.r[high].key>=pivotkey)
            --high;
        L.r[low] = L.r[high];
        while(low<high&&L.r[low].key<=pivotkey)
            ++low;
        L.r[high] = L.r[low];
    }
    L.r[low] = L.r[0];
    return low;
}
void QSort(SqList &L,int low,int high){
    if(low < high){
        auto pivotkey = Partition(L,low,high);
        QSort(L,low,pivotkey);
        QSort(L,pivotkey+1,high);
    }
}
void QSort(SqList &L){
    QSort(L,1,L.length);
}
