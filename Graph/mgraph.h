/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-11-25 08:14
#
# Filename: mgraph.h
#
# Description: 
#
=============================================================================*/
#ifndef MATRIX_GRAPH
#define MATRIX_GRAPH
#define INFINITY    1024
#define MAX_VERTEX_NUM 20
typedef int     VertexType;
typedef int     VRType;
typedef char    InfoType;
typedef enum {
    DG,DN,UDG,UDN
}GraphKind;
typedef struct ArcCell{
    VRType      adj;
    InfoType    *info;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct{
    VertexType  vexs[MAX_VERTEX_NUM];
    AdjMatrix   arcs;
    int         vexnum,arcnum;
    GraphKind   kind;
}MGraph;
#endif
