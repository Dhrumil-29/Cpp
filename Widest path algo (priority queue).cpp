#include <iostream>
#include <limits.h>
#include <queue>
using namespace std;

#define V 6


void maxDijkstra(int graph[V][V],int s)
{
    int dis[V];
    int i,u,v;
    dis[s] = INT_MAX;
    for(i = 1;i<V ; i++)
    {
        dis[i] = 0;
    }
    
    priority_queue <int> q;
    for(i = 0 ; i< V ; i++)
    {
        q.push(dis[i]);
    }
    u=0;
    
    while(!q.empty())
    {
        q.pop();
        for(v=0;v<V;v++)
        {
            if(graph[u][v])
            {
                dis[v] = max(min(dis[u],graph[u][v]),dis[v]);
            }
        }
        u++;
    }
    
    cout<<"Max bandwidth is :- "<<dis[V-1];
}

int main()
{
    int graph[V][V] = { {0,20,11,0,0,0},
                        {0,0,0,5,15,0},
                        {0,0,0,13,5,0},
                        {0,0,0,0,0,18},
                        {0,0,0,0,0,10},
                        {0,0,0,0,0,0}};

    maxDijkstra(graph,0);
    return 0;
}