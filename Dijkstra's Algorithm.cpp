#include <limits.h>
#include <iostream>
# define V 9
using namespace std;
int min_dis(int dis[], bool sptSet[])
{
    int minimum = 100000;
    int min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dis[v] <= minimum)
           {
               minimum = dis[v];
               min_index = v;
           }
    return min_index;
}

void print(int dis[])
{
    cout<<"Vertex \t\t Distance from Source\n";
    for (int i = 0; i < V; i++)
        cout<<i<<" \t\t "<<dis[i]<<"\n";
}

void dijkstra(int graph[V][V], int src)
{
    int dis[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        {
            dis[i] = 100000;
            sptSet[i] = false;
            dis[src] = 0;
        }

    for (int count = 0; count < V - 1; count++) {

        int u = min_dis(dis, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++)

            if (!sptSet[v] && graph[u][v] && dis[u] != 100000
                && dis[u] + graph[u][v] < dis[v])
                dis[v] = dis[u] + graph[u][v];
    }

    print(dis);
}


int main()
{

    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);

    return 0;
}