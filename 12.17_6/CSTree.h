/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-12-19 21:57
#
# Filename: CSTree.h
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include <iostream>
typedef int CSTElemType ;
typedef struct CSNode{
    CSTElemType data = 0; 
    struct CSNode * FirstChild = NULL, * NextSibling = NULL;
}CSNode,*CSTree;

int Depth(CSTree &T,int depth = 0,int flag = 0){
    if(T){
        if(flag)
            depth++;
        if(T->FirstChild)
            Depth(T->FirstChild,depth,1);
        if(T->NextSibling)
            Depth(T->FirstChild,depth);
        if(!T->FirstChild && !T->NextSibling)
            return depth;
    }
    return -1;
}
