/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-12-14 16:51
#
# Filename: bitree.h
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include<stdlib.h>
#ifndef BITREE
#define BITREE
#define TURE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
typedef int Status;

typedef int    TElemType; 
typedef int *  Def;
typedef struct BiTNode{
    TElemType           data;
    struct BiTNode      *lchild = NULL,*rchild = NULL;
}BiTNode,*BiTree;
Status InitBiTree(BiTree &T){
    BiTNode * base = (BiTNode* )malloc(sizeof(BiTNode));
    if(!base)
        exit(OVERFLOW);
    else 
        T = base;
    return OK;
}
Status DestroyBiTree(BiTree &T){
    if(T->rchild){
        DestroyBiTree(T->rchild);
        free(T->rchild);
        if(T->lchild){
            DestroyBiTree(T->lchild);
            free(T->lchild);
            free(T);
        }
    }
    return OK;
}
Status CreateBiTree(BiTree &T,Def definition){
    if(!T)
        exit(ERROR);

}
#endif
