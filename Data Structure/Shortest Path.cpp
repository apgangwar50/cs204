#include <bits/stdc++.h>
using namespace std;
#define INF 99999
#define v 7

void display(int dist[][v])
{
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (dist[i][j] == INF)
                cout<<"INF"<<"     ";
            else
                cout<<dist[i][j]<<"     ";
        }
        cout<<endl;
    }
}

void shrpth(int graph[][v])
{
    int dist[v][v], i, j, k;

    for (i = 0; i < v; i++)
        for (j = 0; j < v; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < v; k++)
    {
        for (i = 0; i < v; i++)
        {
            for (j = 0; j < v; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
   display(dist);
}



int main()
{
    int graph[v][v] = {
                        {0, 3, 6, INF, INF, INF, INF},
                        {3, 0, 2, 1, INF, INF, INF},
                        {6, 2, 0, 1, 4, 2, INF},
                        {INF, 1, 1, 0, 2, INF, 4},
                        {INF, INF, 4, 2, 0, 2, 1},
                        {INF, INF, 2, INF, 2, 0, 1},
                        {INF, INF, INF, 4, 1, 1, 0}
                       };

    shrpth(graph);
    return 0;
}
