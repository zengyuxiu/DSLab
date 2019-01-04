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
#define NaN 102400
typedef int Status;
#define Left -1
#define Right 1
typedef int Flag;

typedef int    TElemType; 
typedef int   Def[1024]; // 中序遍历结果N
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
    if(!T){
        T = (BiTNode *)malloc(sizeof(BiTNode));
    }
    if(*definition != NaN){
        CreateBiTree(T->rchild,definition);
        T->data = *(++definition);
        CreateBiTree(T->lchild,++definition);
    }
    return OK;
}
Status ClearBiTree(BiTree &T){
    DestroyBiTree(T);
    InitBiTree(T);
    return OK;
}
Status BiTreeEmpty(BiTree &T){
    if(!T)
        return TURE;
    else return FALSE;
}
BiTree Root(BiTree &T){
    if(BiTreeEmpty(T))
        return ERROR;
    else 
        return T;
}
TElemType Value(BiTree &T,BiTNode *e){
    if(BiTreeEmpty(T))
        return ERROR;
    else
        return e->data;
}
Status Assign(BiTree &T,BiTNode *e,TElemType value){
    if(BiTreeEmpty(T))
        return ERROR;
    else{
        e->data = value;
        return OK;
    }
}
BiTNode *Parent(BiTree &T,BiTNode *e){
   if(!T) 
       return NULL;
   else{
       if(T->lchild == e||T->rchild == e)
           return T;
       else {
           BiTNode * p = Parent(T->rchild,e);
           if(p)
               return p;
           else 
               return Parent(T->lchild,e);
       }
   }
}
BiTNode *LeftChild(BiTree &T,BiTNode* e){
    if(!T)
        return(e->lchild);
    else 
        return NULL;
}
BiTNode *RightChild(BiTree &T,BiTNode* e){
    if(!T)
        return(e->lchild);
    else 
        return NULL;
}
BiTNode *LeftSibling(BiTree &T,BiTNode* e){
    if(T->lchild == e)
        return NULL;
    else{
        BiTNode * parent = Parent(T,e);
        return parent->lchild;
    }
}
BiTNode *RightSibling(BiTree &T,BiTNode* e){
    if(T->rchild == e)
        return NULL;
    else{
        BiTNode * parent = Parent(T,e);
        return parent->rchild;
    }
}
Status InsertChild(BiTree &T,BiTNode *p,Flag RL,BiTree &c){
    if(!T&&!c)
        return ERROR;
    if(RL == Right){
        c->rchild = p->lchild;
        p->rchild = c;
    }
    else{
        c->rchild = p->rchild;
        p->lchild = c;
    }
    return OK;
}
Status DeleteChild(BiTree &T,BiTNode *p,Flag RL){
    if(!T)
        return ERROR;
    if(RL == Right){
        DestroyBiTree(p->rchild);
        return OK;
    }
    else {
        DestroyBiTree(p->lchild);
        return OK;
    }
}
#endif
