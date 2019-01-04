/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2019 All rights reserved.
#
# Last modified: 2019-01-03 16:36
#
# Filename: SimpleSort.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include"SqList.h"
void InsertSort(SqList &L){
    for(int i = 2;i<=L.length;++i){
        if(L.r[i].key<L.r[i-1].key){
            L.r[0] = L.r[i];
            L.r[i] = L.r[i-1];
            int j = 0;
            for(int j=i-2;L.r[0].key<L.r[j].key;--j)
                L.r[j+1] = L.r[j];
            L.r[j+1] = L.r[0];
        }
    }
}
int SelectMin(SqList &L,int i){
    auto min = L.r[i].key;
    int pos = i;
    for(int j = i+1;j<=L.length;++j)
        if(L.r[j].key < min){
            pos = j;
            min = L.r[j].key;
        }
    return pos;
}
void SelectSort(SqList &L){
    for(int i = 1;i<=L.length;++i){
        int j = SelectMin(L,i);
        if(i != j){
            auto tmp = L.r[i];
            L.r[i].key = L.r[j].key;
            L.r[j].key = tmp.key;
        }
    }
}
void Merge(RcdType *SR,RcdType *TR,int i ,int m,int n){
    int j = m+1,k = i;
    for(;i<=m&&j<=n;++k){
        if(SR[i].key <SR[j].key) 
            TR[k] = SR[i++];
        else
            TR[k] = SR[j++];
    }
    if(i<=m)
        for(int r = 0;r+i<=m;r++)
            TR[k+r] = SR[i+r];
    if(j<=n)
        for(int r = 0;r+j<=n;r++)
            TR[k+r] = SR[j+r];
}
void MSort(RcdType * SR,RcdType *TR1,int s,int t){
    if(s == t)
        TR1[s] = SR[s];
    else{
        RcdType *TR2 = new RcdType[t-s+1+1];
        auto m = (s+t)/2;
        MSort(SR,TR2,s,m);
        MSort(SR,TR2,m+1,t);
        Merge(TR2,TR1,s,m,t);
        //有内存泄漏问题
        //delete[] TR2;  
    }
}
void MergeSort(SqList &L){
    MSort(L.r,L.r,1,L.length);
}
