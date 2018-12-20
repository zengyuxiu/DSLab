/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-12-19 18:16
#
# Filename: huffman_tree.h
#
# Description: 
#
=============================================================================*/
#include <string.h>
#include<stdlib.h>
#include<stdio.h>
#include <vector>
typedef struct {
    unsigned int wight;
    unsigned int parent,lchild,rchild;
}HTNode, *HuffmanTree;
typedef char ** HuffmanCode;
#define TURE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
typedef int Status;
void Select(HuffmanTree &HT,int i,int s1,int s2){
    unsigned int st_min = HT[1].wight;
    unsigned int nd_min = HT[1].wight;
    for(int r = 2;r <= i;r++){
        if(HT[r].wight < st_min){
            st_min = HT[r].wight ;
            s1 = r; 
        }
        else if(HT[r].wight > st_min && HT[r].wight < nd_min){
            nd_min = HT[r].wight ;
            s2 = r;
        }
    }
}
void HuffmanCoding (HuffmanTree &HT,HuffmanCode &HC,unsigned int *w,int n){
    if(n <= 1)
        return ;
    int m = 2*n-1;
    HT  = (HuffmanTree)malloc((m+1)*sizeof(HTNode));
    HuffmanTree p = NULL;
    int i = 0;
    for(p = HT,i = 1;i<=n;++i,++p,++w)
        *p = {
            *w ,0,0,0
        };
    for(;i<=m;++i,++p)
        *p = {
            0,0,0,0
        };
    for(i = n+1;i<=m;++i){
        int s1 = 0,s2 = 0;
        Select(HT,i-1,s1,s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].lchild = s2;
        HT[i].wight = HT[s1].wight + HT[s2].wight;
    }
    HC = (HuffmanCode)malloc((n+1)*sizeof(char *));
    char *cd = (char *)malloc(n*sizeof(char));
    cd[n-1] = '\0';
    for(i = 1;i<=n;++i){
        int start = n-1;
        unsigned int c = 0;
        unsigned int f = 0;
        for(c = 1,f = HT[i].parent;f!=0;c = f,f = HT[f].parent){
            if(HT[f].lchild == c)
                cd[--start] = '0';
            else 
                cd[--start] = '1';
        }
        HC[i] = (char *)malloc((n-start)*sizeof(char));
        strcpy(HC[i],&cd[start]);
    }
    free(cd);
}
