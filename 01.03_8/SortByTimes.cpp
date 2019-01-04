/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2019 All rights reserved.
#
# Last modified: 2019-01-04 09:11
#
# Filename: SortByTimes.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include<iostream>
#include<array>
#include "Sort/SqList.h"
#include "Sort/HeapSort.cpp"
int main(){
    int n = 0;
    int numbers[MAXSIZE] ={0};
    std::cin >> n;
    SqList L;
    for(int i = 1;i<n;++i){
        int number = 0;
        std::cin >> number;
        numbers[number]++;
    }
    int length = 0;
    auto p = L.r+1;
    for(int r = 0;r<MAXSIZE;++r)
        if(numbers[r]){
            p->key = numbers[r];
            p->OtherInfo = r;
            p++;
            length++;
        }
    L.length = length;
    HeapSort(L);
    for(int i =L.length;i>=1;--i)
        std::cout << L.r[i].OtherInfo << " " << L.r[i].key << std::endl;
}
