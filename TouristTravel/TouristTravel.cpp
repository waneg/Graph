#include <iostream>
#include "AdjustList.h"
#include "TouristTravel.h"

using namespace std;

int main()
{
    int select = 0;
    int returnValue;
    string start, end;
    ALGraph G;
    while (1)
    {
        MenuAndSelect(select);
        switch (select)
        {
        case 1:
            returnValue = CreateGraph(G);
            if (returnValue)
            {
                cout << "路线图创建成功" << endl;
            }
            else
            {
                cout << "创建失败" << endl;
            }
            break;
        case 2:
            cout << "请输入起点，终点" << endl;
            cin >> start >> end;
            ShortestPath_Dijkstra(G, LocateVex(G, start), LocateVex(G, end));
            break;
        case 0:
            break;
        default:
            break;
        }
    }
}