#include <limits.h>
#include <iostream>

using namespace std;

# define V 6

//void print(int dis[])
//{
 //   cout<<"Vertex \t\t Distance from Source\n";
  //  for (int i = 0; i < V; i++)
//        cout<<i<<" \t\t "<<dis[i]<<"\n";
//}

void dijkstra(int graph[V][V], int src, int sink)
{
    int dis[V];
    int parent[V];
    parent[src] = -1;
    int u,v,i;
    for(int i=0;i<V;i++)
    {
        dis[i] = -INT_MAX;
    }
    dis[src] = INT_MAX;
    int MAX_bandwidth = 0;
    for(u = 0;u<V;u++)
    {
        for(v=0;v<V;v++)
        {
            if(graph[u][v])
            {
                dis[v] = max(min(dis[u],graph[u][v]),dis[v]);
                parent[v] = u;
                if( MAX_bandwidth != dis[v])
                {
                    MAX_bandwidth = dis[v];
                    
                }
            }
        }
    }
    
    for(i = sink;i>0;i = parent[i])
    {
        cout<<i+1<<"  ---  ";
    }
    //MAX_bandwidth = dis[sink];
    cout<<"Max bandwidth of the graph : - "<<MAX_bandwidth<<endl;
}


int main()
{
    int graph[V][V] = { {0,20,11,0,0,0},
                        {0,0,0,5,15,0},
                        {0,0,0,13,5,0},
                        {0,0,0,0,0,18},
                        {0,0,0,0,0,20},
                        {0,0,0,0,0,0}};

    dijkstra(graph, 0,5);

    return 0;
}