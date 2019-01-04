/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2019 All rights reserved.
#
# Last modified: 2019-01-03 15:59
#
# Filename: BST.h
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include"bitree.h"
#ifndef BST
#define BST
Status SearchBST(BiTree T,TElemType key,BiTNode * f,BiTree & p){
    if(!T){
        p = f;
        return FALSE;
    }
    else 
        if(key == T->data){
            p = T;
            return TURE;
        }
        else
            if(key<T->data)
                return SearchBST(T->lchild,key,T,p);
            else
                return SearchBST(T->rchild,key,T,p);
}
Status InsertBST(BiTree &T,TElemType key){
    BiTNode * p= NULL;
    if(!SearchBST(T,key,NULL,p)){
        auto * s = new BiTNode;
        s->data = key;
        s->lchild = s->rchild = NULL;
        if(!p)
            T = s;
        else if(key<p->data)
            p->lchild = s;
        else p->rchild = s;
        return TURE;
    }
    else return FALSE;
}
Status Delete(BiTNode * p);
Status DeleteBST(BiTree &T,TElemType key){
    if(!T)
        return FALSE;
    else{
        if(key == T->data)
            return Delete(T);
        else 
            if(key < T->data)
                return DeleteBST(T->lchild,key);
            else 
                return DeleteBST(T->rchild,key);
    }
}
Status Delete(BiTNode * p){
    if(!p->rchild){
        auto q = p;
        p = p->lchild;
        delete q;
    }
    else
        if(!p->lchild){
            auto q = p;
            p = p->rchild;
            delete  q;
        }
        else{
            auto q = p;
            auto s = p->lchild;
            while(s->rchild){
                q = p;
                s = s->rchild;
            }
            p->data = s->data;
            if(q != p)
                q->rchild = s->lchild;
            else q->lchild = s->lchild;
            delete s;
        }
    return TURE;
}
#endif
