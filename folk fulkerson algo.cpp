#include <iostream>
#include <limits.h> 
#include <string.h> 
#include <queue>
using namespace std;
//Numbers of vertices in given graph
#define V 6

//For Find Augmenting path use BFS 
/* Returns true if there is a path from source 's' to sink 't' in 
  residual graph. Also fills parent[] to store the path */
 bool bfs (int rGraph[V][V] , int s , int t , int parent[])
 {
     bool visited[V];
     memset ( visited , 0 , sizeof(visited) );
     
     //create a queue and enqueue the source and set as a visited 
     queue <int> q;
     q.push(s);
     visited[s] = true;
     parent[s] = -1;
     
     while( !q.empty() )
     {
         int u = q.front();
         q.pop();
         
         for(int v = 0; v < V ; v++)
         {
             if(visited[v] == false && rGraph[u][v] > 0)
             {
                 q.push(v);
                 parent[v] = u;
                 visited[v] = true;
             }
         }
     }
     return (visited[t] == true);
 }

//Return the maximum flow from s to t in the graph where s is stand for source and t stand for sink


int fordFulkerson(int Graph[V][V] , int s , int t)
{
    int u,v;
    int rGraph[V][V];
    
    for (u = 0;u < V;u++)
    {
        for (v = 0;v < V;v++)
        {
            rGraph[u][v] = Graph[u][v];
        }
    }
    
    //parent array is used for the store the parent vertex of the vertex in the augmenting path
    int parent[V];
    
    int max_flow = 0;
    
    //Find the augmenting paths and then find the minimum path_flow so that the flow became the maximum in the graph
    while ( bfs ( rGraph , s , t , parent ) )
    {
        int  path_flow = INT_MAX;
        // Find minimum residual capacity of the edges along the 
        // path filled by BFS. Or we can say find the maximum flow 
        // through the path found. 
        for( v = t ; v != s ; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow , rGraph[u][v]);
        }
        
        // update residual capacities of the edges and reverse edges 
        // along the path
        for( v = t ; v != s ; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
        
        cout<<path_flow<<endl;
        for (u = 0;u < V;u++)
        {
            cout<<endl;
            for (v=0;v<V;v++)
                {
                    cout<<rGraph[u][v]<<"\t";;
                }
        }
        cout<<endl<<endl;
    }
    
    
    return max_flow;
}
int main() {
    //create the directed graph by adjecent matrix
    int Graph [V][V] = { {0,16,13,0,0,0}, 
                         {0,0,10,12,0,0},
                         {0,4,0,0,14,0},
                         {0,0,9,0,0,20},
                         {0,0,0,7,0,4},
                         {0,0,0,0,0,0}
                        };
    for (int u = 0;u < V;u++)
        {
            cout<<endl;
            for (int v=0;v<V;v++)
                {
                    cout<<Graph[u][v]<<"\t";;
                }
        }
        cout<<endl<<endl;
    cout<< " The maximum possible flow is "<<fordFulkerson(Graph,0,5);
	return 0;
}