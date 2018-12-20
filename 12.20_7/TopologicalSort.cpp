/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-12-20 13:59
#
# Filename: TopologicalSort.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include <iostream>
#include<stack>
#include "algraph.h"
Status TopologicalSort(ALGraph &G){
    int indegree[G.vexnum];
    FindInDegree(G,indegree);
    std::stack<int> S;
    for(int i = 0;i<G.vexnum;++i){
        if(!indegree[i])
            S.push(i);
    }
    int count = 0;
    while(!S.empty()){
        int i = S.top();
        S.pop();
        std::cout << i <<G.vertices[i].data;
        ++count;
        for(ArcNode * p = G.vertices[i].firstarc ;p;p= p->nextarc){
            int k = p ->adjvex;
            if(!(--indegree[k]))
                S.push(k);
        }
    }
    if(count<G.vexnum)
        return ERROR;
    else return OK;
}
