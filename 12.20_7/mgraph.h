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
#include<iostream>
#include <queue>
#ifndef MATRIX_GRAPH
#define MATRIX_GRAPH
#define INFINITY    1024
#define MAX_VERTEX_NUM 20
#define TURE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE  -1
#define OVERFLOW    -2
typedef int Status;

typedef int     VertexType;
typedef int     VRType;
typedef char    InfoType;
bool Visit[MAX_VERTEX_NUM] ;
VertexType NOT_A_VERTEX;
typedef enum {
    DG,DN,UDG,UDN
}GraphKind;
typedef struct ArcCell{
    VRType      adj;
    InfoType    *info;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct{
    VertexType  vexs[MAX_VERTEX_NUM] = {
        NOT_A_VERTEX
    };
    AdjMatrix   arcs;
    int         vexnum,arcnum;
    GraphKind   kind;
}MGraph;
int LocateVex(MGraph &G,VertexType v){
    for(int i = 0;i<MAX_VERTEX_NUM;i++)
        if(G.vexs[i] == v)
            return i;
    return INFEASIBLE;
}
Status CreateUDN(MGraph &G){
    std::cin >> G.vexnum >> G.arcnum;
    for (int i=0;i<G.vexnum;++i)
        G.vexs[i] = i+1;
    for (int i=0;i<G.vexnum;++i)
        for(int j=0;i<G.vexnum;++j)
            G.arcs[i][j] = {INFINITY,NULL};
    for(int k=0;k<G.arcnum;++k){
        VertexType v1,v2;
        VRType w;
        std::cin >> v1 >> v2 >> w;
        int i = LocateVex(G,v1);
        int j = LocateVex(G,v2);
        G.arcs[i][j].adj = w;
        G.arcs[j][i] = G.arcs[i][j];
    }
    return OK;
}
Status CreateUDG(MGraph &G){
    std::cin >> G.vexnum >> G.arcnum;
    for (int i=0;i<G.vexnum;++i)
        std::cin >> G.vexs[i];
    for (int i=0;i<G.vexnum;++i)
        for(int j=0;i<G.vexnum;++j)
            G.arcs[i][j] = {INFINITY,NULL};
    for(int k=0;k<G.arcnum;++k){
        VertexType v1,v2;
        std::cin >> v1 >> v2 ;
        int i = LocateVex(G,v1);
        int j = LocateVex(G,v2);
        G.arcs[i][j].adj = 1;
        G.arcs[j][i] = G.arcs[i][j];
    }
    return OK;
}
Status CreateDG(MGraph &G){
    std::cin >> G.vexnum >> G.arcnum;
    for (int i=0;i<G.vexnum;++i)
        std::cin >> G.vexs[i];
    for (int i=0;i<G.vexnum;++i)
        for(int j=0;i<G.vexnum;++j)
            G.arcs[i][j] = {INFINITY,NULL};
    for (int k=0;k<G.arcnum;++k){
        VertexType StartVex,DestVex;
        std::cin >> StartVex>> DestVex;
        int i = LocateVex(G,StartVex);
        int j = LocateVex(G,DestVex);
        G.arcs[i][j].adj = 1;
    }
    return OK;
}
Status CreateDN(MGraph &G){
    std::cin >> G.vexnum >> G.arcnum;
    for (int i=0;i<G.vexnum;++i)
        std::cin >> G.vexs[i];
    for (int i=0;i<G.vexnum;++i)
        for(int j=0;i<G.vexnum;++j)
            G.arcs[i][j] = {INFINITY,NULL};
    for(int k=0;k<G.arcnum;++k){
        VertexType StartVex,DestVex;
        VRType w;
        std::cin >> StartVex>> DestVex>> w;
        int i = LocateVex(G,StartVex);
        int j = LocateVex(G,DestVex);
        G.arcs[i][j].adj = w;
    }
    return OK;
}
Status CreateGraph(MGraph &G){
    int kind = INFEASIBLE;
    GraphKind graph_kind[4]={
        DG,DN,UDG,UDN
    };
    std::cin >> kind;
    G.kind = graph_kind[kind] ;
    switch (G.kind){
        case DG:
            return CreateDG(G);
            break;
        case DN:
            return CreateDN(G);
            break;
        case UDG:
            return CreateUDG(G);
            break;
        case UDN:
            return CreateUDN(G);
            break;
        default:
            return ERROR;
            break;
    }
}
//Status DestoryGraph(MGraph &G){
//
//    return OK;
//}
VertexType GetVex(MGraph &G,VertexType v){
    if(LocateVex(G,v) != INFEASIBLE)
        return v;
    else  
        exit(ERROR);
}
Status PutVex(MGraph &G,VertexType v,VertexType value){
    int j = LocateVex(G,v);
    if(j != INFEASIBLE) {
        G.vexs[j] = value;
        return OK;
    }
    else
        return ERROR;
        
}
VertexType & FirstAdjVex(MGraph &G,VertexType v){
    int i = LocateVex(G,v);
    if(i != INFEASIBLE){
        for(VertexType &vex:G.vexs){
            int j = LocateVex(G,vex);
            if(G.arcs[i][j].adj)
                return vex;
        }
        return NOT_A_VERTEX;
    }
    return NOT_A_VERTEX;
}
VertexType & NextAdjVex(MGraph &G,VertexType v,VertexType w){
    int i = LocateVex(G,v);
    if(i != INFEASIBLE){
        for(VertexType &vex:G.vexs){
            if(vex == w)
                continue;
            int j = LocateVex(G,vex);
            if(G.arcs[i][j].adj)
                return vex;
        }
        return NOT_A_VERTEX;
    }
    return NOT_A_VERTEX;
}
Status InsertVex(MGraph &G,VertexType v){
    for (int i=0;i<G.vexnum;++i)
        if(G.vexs[i] == NOT_A_VERTEX){
            G.vexs[i] = v;
            return OK;
        }
    return OVERFLOW;
}
Status DeleteVex(MGraph &G,VertexType v){
    int i = LocateVex(G,v);
    if(i != INFEASIBLE){
        G.vexs[i] = NOT_A_VERTEX;
        return OK;
    }
    else
        return ERROR;
}
Status InsertArc(MGraph &G,VertexType v,VertexType w){
    for(int k=0;k<G.arcnum;++k){
        int i = LocateVex(G,v);
        int j = LocateVex(G,w);
        G.arcs[i][j].adj = 1;
        if(G.kind == UDG)
            G.arcs[j][i] = G.arcs[i][j];
    }
    return OK;
}
Status DeleteArc(MGraph &G,VertexType v,VertexType w){
    for(int k=0;k<G.arcnum;++k){
        int i = LocateVex(G,v);
        int j = LocateVex(G,w);
        G.arcs[i][j] = {INFINITY,NULL};
        if(G.kind == UDG)
            G.arcs[i][j] = {INFINITY,NULL};
    }
    return OK;
}
Status VisitFunc(VertexType v){
    if(v != NOT_A_VERTEX){
        std::cout << v;
        return OK;
    }
    else return ERROR;

}
void DFS(MGraph &G,int v,Status (*visit)(VertexType v)){
    Visit[v] = TURE;
    visit(G.vexs[v]);
    for( VertexType w = FirstAdjVex(G,v);w != NOT_A_VERTEX;w=NextAdjVex(G,v,w) ){
        if(!Visit[w])
            DFS(G,w,VisitFunc);
    }
}
void DFSTraverse(MGraph &G){
    for(int i = 0;i<G.vexnum;++i)
        Visit[i] = FALSE;
    for(int i = 0;i<G.vexnum;++i)
        if(!Visit[i])
            DFS(G,i,VisitFunc);
}
void BFSTraverse(MGraph &G,Status (*visit)(VertexType v)){
    for(int i = 0;i<G.vexnum;++i)
        Visit[i] = FALSE;
    std::queue<VertexType &> Q;
    for( int v= 0;v<G.vexnum;++v) 
        if(!Visit[v]){
            Visit[v] = TURE;
            visit(G.vexs[v]);
            Q.push(G.vexs[v]);
            while (!Q.empty()){
                VertexType u = Q.front();
                Q.pop();
                for(VertexType w = FirstAdjVex(G,u);w!=NOT_A_VERTEX;w=NextAdjVex(G,u,w)){
                    int i = LocateVex(G,w);
                    if(!Visit[i]){
                        Visit[i] = TURE;
                        visit(w);
                        Q.push(w);
                    }
                }
            }
        }
}

#endif
