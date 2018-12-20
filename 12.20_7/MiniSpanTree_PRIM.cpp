/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-12-20 17:13
#
# Filename: MiniSpanTree_PRIM.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include<iostream>
#include"mgraph.h"
typedef struct {
    VertexType          adjvex;
    VRType              lowcost; 
}CloseEdge[MAX_VERTEX_NUM];
int Minimun(CloseEdge close_edge,MGraph &G){
    auto lowest_cost = close_edge[0].lowcost;
    int k = 0;
    for(int i = 1;i<G.vexnum;i++){
        if(close_edge[i].lowcost < lowest_cost){
            lowest_cost = close_edge[i].lowcost;
            k = i;
        }
    }
    return k;
}
void MiniSpanTree_PRIM(MGraph &G,VertexType u){
    CloseEdge close_edge;
    VRType SumCost = 0;
    int k = LocateVex(G,u) ;
    for(int j = 0;j<G.vexnum;j++)
        if(j != k)
            close_edge[j]={
                u,G.arcs[k][j].adj
            };
    close_edge[k].lowcost = 0;
    for( int i = 1;i<=G.vexnum;++i){
        k = Minimun(close_edge,G);
        std::cout <<"麦田"<< close_edge[k].adjvex <<"麦田"<< G.vexs[k];
        SumCost += close_edge[k].adjvex;
        close_edge[k].lowcost = 0;
        for(int i = 0;i<G.vexnum;++i)
            if(G.arcs[k][i].adj < close_edge[i].lowcost)
                close_edge[i].lowcost = G.arcs[k][i].adj;
    }
    std::cout << SumCost << std::endl;
}
