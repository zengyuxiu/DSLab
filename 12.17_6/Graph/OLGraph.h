/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-11-25 08:33
#
# Filename: OLGraph.h
#
# Description: 
#
=============================================================================*/
#ifndef OLGRAPH
#define OLGRAPH
#define MAX_VERTEC_NUM  20
typedef char            *InfoType;
typedef int             VertexType;
typedef struct  ArcBox{
    int                 tailvex,headvex;
    struct  ArcBox      *hlink,*tlink;
    InfoType            *info;
}ArcBox;
typedef struct VexNode{
    VertexType          data;
    ArcBox              *fisrtin,*firstout;
}VexNode;
typedef struct{
    VexNode             xlist[MAX_VERTEC_NUM];
    int                 vexnum,arcnum;
}OLGraph;
#endif
