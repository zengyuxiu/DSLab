#ifndef ALGRAPH
#define ALGRAPH
#define MAX_VERTEX_NUM 20
#include "ArcSet.h"
typedef int InfoType;
typedef int VertexType;
typedef int Status;
typedef struct ArcNode{
	int	adjvex;
	struct ArcNode *nextarc;
	InfoType *info;
}ArcNode;
typedef struct VNode{
	VertexType data;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct {
	AdjList vertices;
	int vexnum,arcnum;
	int kind;
}ALGraph;
Status CreateALGraph(ALGraph &G,ArcSet &arcset,)
#endif
