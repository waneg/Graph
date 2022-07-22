#pragma once
#include <iostream>
#define INF 65535
#define MAX_VERTEX_NUM 20
#define VertexType string
#define InfoType int
using namespace std;

/* ����ͼ���ڽӱ�ṹ */
typedef struct ArcNode
{
	int             adjvex;
	struct ArcNode* nextarc;
	InfoType weight;	/*�ߵ�Ȩ��*/
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
	return -1;	//�ö��㲻����
}

bool CreateGraph(ALGraph& G)
{
	cout << "�������������εľ�������·��������";
	cin >> G.vexnum >> G.arcnum;
	cout << "����������ÿ�����ξ�������ƣ�";
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	cout << "����������ߵ��������㼰���룬�ÿո�������磺v w 3\n";
	VertexType head, tail;	//�ߵ���������
	int archead, arctail;	//���������Ӧ��λ��
	int cost;
	ArcNode* s;	//�߽��
	ArcNode* p;
	G.kind = 0;
	for (int i = 0; i < G.arcnum; i++)
	{
		cin >> tail >> head >> cost;
		arctail = LocateVex(G, tail);
		archead = LocateVex(G, head);
		if (arctail == -1 || archead == -1)
			cout << "�ö��㲻���ڣ��������룡";
		else
		{
			s = (ArcNode*)malloc(sizeof(ArcNode));
			if (!s)
				return false;
			s->adjvex = archead;
			s->nextarc = NULL;
			s->weight = cost;
			if (G.vertices[arctail].firstarc == NULL)//��û�б߽��
			{
				G.vertices[arctail].firstarc = s;
			}
			else
			{
				p = G.vertices[arctail].firstarc;//�ҵ�������������в���
				while (p->nextarc)
					p = p->nextarc;
				p->nextarc = s;
			}


			if (G.kind == 0)//����ͼ��������ԳƱ�
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

