/*=============================================================================
#
# Author:Yuxiu Zeng
#
# Copyright (C) 2018 All rights reserved.
#
# Last modified: 2018-12-25 00:31
#
# Filename: ShortestPath_DIJ.cpp
#
# Description: 
#
=============================================================================*/
#include<stdio.h>
#include <vector>
#include <queue>
#include "Graph/mgraph.h"
typedef struct Arc:public ArcCell{
    int Start_Dest_Vex[2];
    Arc(ArcCell arc_cell,int Start,int Dest){
        this->assign(arc_cell);
        this->Start_Dest_Vex[0] = Start;
        this->Start_Dest_Vex[1] = Dest;
    }
    void operator = (ArcCell arc_cell){
        this->assign(arc_cell);
    }
    int & operator [](int i){
        return this->Start_Dest_Vex[i];
    }
}Arc;
typedef std::vector<Arc> Path;
typedef struct ShortPathTable{
    int             VexNum;
    std::vector<Path>            ShortPath;
    VRType          *Length;
    bool            *finish;
    VertexType      current_new_vex;
    ShortPathTable(int VexNum){
        this->VexNum = VexNum;
        //this->ShortPath.assign(VexNum,{{0,0}});
        for(int i = 0;i<VexNum;++i){
            Path            init_path;
            init_path.clear();
            this->ShortPath.push_back(init_path);
        }
        this->Length = new int[VexNum];
        this->finish = new bool[VexNum] {FALSE};
    }
    int Add(VertexType &v,MGraph &G);
    int & operator ()(int v,MGraph &G){
        int i = LocateVex(G,v);
        return this->Length[i];
    }
}ShortPathTable;
int ShortPathTable::Add(VertexType &v, MGraph &G){
    std::vector<VRType> path_length;
    VRType Length;
    for(auto arc:this->ShortPath[LocateVex(G,v)]) {
        auto arc_cell = G.arcs[arc[0]][arc[1]];
        if(arc_cell.info)  // go with SmallRoad
            path_length.push_back(arc_cell.adj);
        //wide Road
        else {
            if(!path_length.empty()){
                VRType SumOfNarrowPath = 0;
                for(auto len:path_length)
                    SumOfNarrowPath += len;
                SumOfNarrowPath *= SumOfNarrowPath;
                Length = SumOfNarrowPath + arc_cell.adj;
                path_length.clear();
            }
            Length += arc_cell.adj;
        }
    }
    if(!path_length.empty()){
        VRType SumOfNarrowPath = 0;
        for(auto len:path_length)
            SumOfNarrowPath += len;
        SumOfNarrowPath *= SumOfNarrowPath;
        path_length.clear();
    }
    return Length;
}
void ShortestPath_DIJ(MGraph &G, int v0 ,ShortPathTable &D){
    for(int v = 0;v<G.vexnum;++v) {
        int i = LocateVex(G,v0);
        int j = LocateVex(G,v);
        auto arc_cell = G.arcs[i][j];
        D.finish[i]  = FALSE;
        if(arc_cell.info) //narrow path
            D(v,G)= arc_cell.adj * arc_cell.adj;
        // wider path
        else
            D(v,G) = arc_cell.adj;
        //D(v,G) = G.arcs[v0][v].adj;
        //for(int w = 0;w<G.vexnum;++w) 
        //   P[v][w] = FALSE;
        if(D(v,G) < INFINITY) {
            Arc v_path(arc_cell,i,j);
            D.ShortPath[j].push_back(v_path);
            //D.ShortPath[j].push_back({i,j});
        }
    }
    D(v0,G) = 0;
    D.finish[LocateVex(G,v0)] = TURE;
    for(int i = 1;i<G.vexnum;++i){
        VRType min = INFINITY; 
        for(int w = 0;w<G.vexnum;++w)
            if(!D.finish[LocateVex(G,w)])
                if(D(w,G)<min){
                    D.current_new_vex = w;
                    min = D(D.current_new_vex ,G);
                }
        D.finish[LocateVex(G,D.current_new_vex)] = TURE;
    }
    for(int w = 0;w<G.vexnum;++w){
        if(!D.finish[LocateVex(G,w)] && D.Add(w,G)<D(w,G)){
            int i = LocateVex(G,D.current_new_vex);
            int j = LocateVex(G,w);
            Arc new_path(G.arcs[i][j],i,j);
            D(w,G) = D.Add(w,G);
            D.ShortPath[j].clear();
            D.ShortPath[j] = D.ShortPath[i];
            D.ShortPath[j].push_back(new_path);
        }
    }
}
