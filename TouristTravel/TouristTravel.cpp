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
                cout << "·��ͼ�����ɹ�" << endl;
            }
            else
            {
                cout << "����ʧ��" << endl;
            }
            break;
        case 2:
            cout << "��������㣬�յ�" << endl;
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