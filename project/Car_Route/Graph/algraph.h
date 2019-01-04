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
#endif
