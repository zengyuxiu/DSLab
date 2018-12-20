/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-11-25 08:13
#
# Filename: algraph.h
#
# Description: 
#
=============================================================================*/
#ifndef ALGRAPH
#define ALGRAPH
#define MAX_VERTEX_NUM 20
#define TURE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
typedef int Status;
typedef enum {
    DG,DN,UDG,UDN
}GraphKind;
typedef char        InfoType;
typedef int         VertexType;
typedef struct ArcNode{
    int             adjvex;
    struct ArcNode  * nextarc;
    InfoType        * Info;
}ArcNode;
typedef struct VNode {
    VertexType      data;
    ArcNode         *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct{
    AdjList         vertices;
    int             vexnum,arcnum;
    GraphKind       kind;
}ALGraph;
Status FindInDegree(ALGraph &G,int indegree[G.vexnum]){
    for(int i = 0;i<G.vexnum;++i)
        indegree[i] = 0;
    for(int i = 0;i<G.vexnum;++i)
        for(ArcNode * arc = G.vertices[i].firstarc;arc;arc = arc->nextarc)
            indegree[arc->adjvex] ++;
    return OK;
}
#endif
