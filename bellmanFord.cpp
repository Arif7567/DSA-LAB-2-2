#include<iostream>
using namespace std;
struct Edge
{
    int u,v,w;
};
int main()
{
    int vertex,edge;
    cin>>vertex>>edge;
    Edge graph[edge];
    for(int i=0;i<edge;i++)
    {
        cin>>graph[i].u>>graph[i].v>>graph[i].w;
    }
    int source=0;
    int distance[vertex]={INT_MAX};
    distance[source]=0;
    for(int i=0;i<vertex-1;i++)
    {
        for(int j=0;j<edge;j++)
        {
            int u=graph[j].u;
            int v=graph[j].v;
            int w=graph[j].w;
            if (distance[u]!=INT_MAX && distance[v]>distance[u]+w)
            
            {
                distance[v]=distance[u]+w;
            }
        }
    }
    
    bool isNegativeCycle(struct graph[],int source,int distance[] )
    {
        bool visited[vertex]=false;
        int distance[vertex];
        isNegativeCycle(graph,source,distance)
        {
            for(int i=0;i<vertex-1;i++)
            {
                visited[i]=false;
                distance[i]=INT_MAX;
            }

            if(visited[i]==true)
            {
                cout<<"The graph has negative cycle";
                return true;

            }
            else
            { return false
                cout<<"The graph has not negative cycle";
            }
        
    }
    cout<<"Distance are:\n";
    for(int i=0;i<vertex;i++)
    {
        cout<<"Node: "<<i<<"Distance: "<<distance[i]<<endl;
    }
    

    return 0;
}
}