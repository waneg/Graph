#pragma once
#include "AdjustList.h"
#include <stack>
#include <cstring>
#include <queue>
#define Pathmatrix int
#define ShortPathTable int

void MenuAndSelect(int& select)
{
    if (select)
    {
        cout << "��ѡ����Ҫ���еĲ���:";
        cin >> select;
    }
    system("cls");
    cout << "\n====����ӭʹ�����ξ��㵼��ϵͳ��=======\n\n";
    cout << " *****\t   1.��������ϵͳ  \t\t*****\n";
    cout << " *****\t   2.��ȡ���·��    \t*****\n";
    cout << " *****\t   0.�˳�����               \t*****\n\n";
    cout << "=============================================\n";
    if (!select)
    {
        cout << "��ѡ����Ҫ���еĲ���:";
        cin >> select;
    }
}

/*���·���㷨*/
void ShortestPath_Dijkstra(ALGraph G, int v0, int v)
{
    int k;
    int D[MAX_VERTEX_NUM];
    int P[MAX_VERTEX_NUM];
    int final[MAX_VERTEX_NUM];
    memset(final, 0, MAX_VERTEX_NUM);
    memset(D, INF, MAX_VERTEX_NUM);
    memset(P, 0, MAX_VERTEX_NUM);
    ArcNode* p = G.vertices[v0].firstarc;
    while (p != nullptr)
    {
        D[p->adjvex] = p->weight;
        P[p->adjvex] = v0;
        p = p->nextarc;
    }
    D[v0] = 0;
    final[v0] = 1;
    P[v0] = -1;
    /*��ʼ��ѭ����ÿ�����v0��������������·��*/
    for (int i = 1; i < G.vexnum; i++) 
    {
        int min = INF;
        for (int j = 0; j < G.vexnum; j++)
        {
            if (!final[j] && D[j] < min)
            {
                k = j;
                min = D[j];
            }
        }
        final[k] = 1;
        ArcNode* p = G.vertices[k].firstarc;
        while (p != nullptr)
        {
            if (!final[p->adjvex] && (min + p->weight < D[p->adjvex]))
            {
                /*˵���ҵ��˸��̵�·����D��P*/
                D[p->adjvex] = min + p->weight;
                P[p->adjvex] = k;
            }
            p = p->nextarc;
        }
    }
    /*������·��*/
    int pre = P[v];
    stack<int> path;
    while (pre != -1)
    {
        path.push(pre);
        pre = P[pre];
    }
    cout << G.vertices[v0].data << "��" << G.vertices[v].data << "����̾���Ϊ" << D[v] << endl;
    cout << "���·��Ϊ��";
    while (!path.empty()) {
        int tmp = path.top();
        cout << G.vertices[tmp].data << "-->";
        path.pop();
    }
    cout << G.vertices[v].data << endl;
}