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
        cout << "请选择您要进行的操作:";
        cin >> select;
    }
    system("cls");
    cout << "\n====→欢迎使用旅游景点导航系统←=======\n\n";
    cout << " *****\t   1.创建景点系统  \t\t*****\n";
    cout << " *****\t   2.获取最短路径    \t*****\n";
    cout << " *****\t   0.退出程序               \t*****\n\n";
    cout << "=============================================\n";
    if (!select)
    {
        cout << "请选择您要进行的操作:";
        cin >> select;
    }
}

/*最短路径算法*/
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
    /*开始主循环，每次求得v0到其他顶点的最短路径*/
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
                /*说明找到了更短的路径，D和P*/
                D[p->adjvex] = min + p->weight;
                P[p->adjvex] = k;
            }
            p = p->nextarc;
        }
    }
    /*输出最短路径*/
    int pre = P[v];
    stack<int> path;
    while (pre != -1)
    {
        path.push(pre);
        pre = P[pre];
    }
    cout << G.vertices[v0].data << "到" << G.vertices[v].data << "的最短距离为" << D[v] << endl;
    cout << "最短路径为：";
    while (!path.empty()) {
        int tmp = path.top();
        cout << G.vertices[tmp].data << "-->";
        path.pop();
    }
    cout << G.vertices[v].data << endl;
}