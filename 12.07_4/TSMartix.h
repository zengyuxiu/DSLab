/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-12-07 17:54
#
# Filename: TSMartix.h
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#ifndef TSMATRIX
#define TSMATRIX
#define MAXSIZE 12500
#define TURE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
typedef int Status;

typedef int ELemtype;
typedef struct{
    int                 i,j;
    ELemtype            e;
}Triple;
typedef struct{
    Triple              data[MAXSIZE + 1];
    int                 mu,nu,tu;
}TSMatrix;
#endif
