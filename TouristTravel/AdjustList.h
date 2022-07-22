#pragma once
#include <iostream>
#define INF 65535
#define MAX_VERTEX_NUM 20
#define VertexType string
#define InfoType int
using namespace std;

/* 无向图的邻接表结构 */
typedef struct ArcNode
{
	int             adjvex;
	struct ArcNode* nextarc;
	InfoType weight;	/*边的权重*/
}ArcNode;

typedef struct VNode
{
	VertexType  data;
	ArcNode* firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
	int kind;
}ALGraph;


int LocateVex(ALGraph G, VertexType u)
{
	for (int v = 0; v < G.vexnum; v++)
		if (G.vertices[v].data == u)
			return v;
	return -1;	//该顶点不存在
}

bool CreateGraph(ALGraph& G)
{
	cout << "请依次输入旅游的景点数和路径条数：";
	cin >> G.vexnum >> G.arcnum;
	cout << "请依次输入每个旅游经典的名称：";
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	cout << "请依次输入边的两个顶点及距离，用空格隔开，如：v w 3\n";
	VertexType head, tail;	//边的两个顶点
	int archead, arctail;	//两个顶点对应的位置
	int cost;
	ArcNode* s;	//边结点
	ArcNode* p;
	G.kind = 0;
	for (int i = 0; i < G.arcnum; i++)
	{
		cin >> tail >> head >> cost;
		arctail = LocateVex(G, tail);
		archead = LocateVex(G, head);
		if (arctail == -1 || archead == -1)
			cout << "该顶点不存在，请检查输入！";
		else
		{
			s = (ArcNode*)malloc(sizeof(ArcNode));
			if (!s)
				return false;
			s->adjvex = archead;
			s->nextarc = NULL;
			s->weight = cost;
			if (G.vertices[arctail].firstarc == NULL)//还没有边结点
			{
				G.vertices[arctail].firstarc = s;
			}
			else
			{
				p = G.vertices[arctail].firstarc;//找到边链表的最后进行插入
				while (p->nextarc)
					p = p->nextarc;
				p->nextarc = s;
			}


			if (G.kind == 0)//无向图，生成其对称边
			{
				int temp = archead;
				archead = arctail;
				arctail = temp;
				s = (ArcNode*)malloc(sizeof(ArcNode));
				if (!s)
					return false;
				s->adjvex = archead;
				s->nextarc = NULL;
				s->weight = cost;
				if (G.vertices[arctail].firstarc == NULL)
				{
					G.vertices[arctail].firstarc = s;
				}
				else
				{
					p = G.vertices[arctail].firstarc;
					while (p->nextarc)
						p = p->nextarc;
					p->nextarc = s;
				}
			}
		}
	}
	for (int i = 0; i < G.vexnum; i++) {
		ArcNode* p = G.vertices[i].firstarc;
		while (p != NULL)
		{
			cout << G.vertices[i].data << "--" << G.vertices[p->adjvex].data << ' ';
			p = p->nextarc;
		}
		cout << endl;
	}
	return true;
}

