/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2019 All rights reserved.
#
# Last modified: 2019-01-03 16:31
#
# Filename: SqList.h
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#ifndef SQLIST
#define SQLIST
#define MAXSIZE 1024
typedef int KeyType;
typedef int InfoType;
typedef struct{
    KeyType                     key = 0;
    InfoType                    OtherInfo = 0;
}RcdType;
typedef struct{
    RcdType                     r[MAXSIZE];
    int                         length;
}SqList;
#endif
