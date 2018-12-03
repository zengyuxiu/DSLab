/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-10-31 16:52
#
# Filename: Sq_sort.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include "SqList.h"
Status SqSort_insertion(SqList &L){
    for(ElemType i=1;i<L.length;i++){
        ElemType key = L.elem[i];
        ElemType j = i -1;
        while(j>=0 && key>L.elem[j]){
            L.elem[j+1] = L.elem[j];
            j--;
        }
        L.elem[j+1] = key;
    }
    return OK;
}
