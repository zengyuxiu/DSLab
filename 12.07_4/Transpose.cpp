/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-12-07 17:54
#
# Filename: Transpose.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include"TSMartix.h"
Status TransposeSMatrix(TSMatrix M,TSMatrix &T){
    T.mu = M.mu;
    T.nu = M.nu;
    T.tu = M.tu;
    if(T.tu){
        int q = 1;
        for(int col = 1;col<=M.nu;++col)
            for(int p=1;p<=M.tu;++p)
                if(M.data[p].j == col){
                    T.data[q].i = M.data[p].j;
                    T.data[q].j = M.data[p].i;
                    T.data[q].e = M.data[p].e;
                    ++q;
                }
    }
    return OK;
}
