#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v,w;
};

int main()
{
    int vertex,edge;
    cin>>vertex>>edge;
    Edge graph[edge];

    for(int i=0; i<edge; i++)
    {
        cin>>graph[i].u>>graph[i].v>>graph[i].w;
    }

    int distance[vertex];
    int source=0;
    for(int i=0; i<vertex; i++){
        distance[i]=INT_MAX;
    }
    distance[source]=0;
    for(int i=0; i<vertex-1; i++){
        for(int j=0; j<edge; j++){
            int u=graph[j].u;
            int v=graph[j].v;
            int w=graph[j].w;
            if(distance[u]!=INT_MAX && distance[v]>distance[u]+w){
                distance[v]=distance[u]+w;
            }
        }
    }
    bool negativeCycle = false;
    for(int j=0; j<edge; j++){
        int u=graph[j].u;
        int v=graph[j].v;
        int w=graph[j].w;
        if(distance[u]!=INT_MAX && distance[v]>distance[u]+w){
            negativeCycle = true;
            break;
        }
    }
    if(negativeCycle){
        cout<<"Negative cycle detected in the graph!"<<endl;
    }
    else{
        cout<<"Shortest distances from source node "<<source<<":"<<endl;
        for(int i=0; i<vertex; i++)
        {
            cout<<"Node: "<<i<<"\tDistance: "<<distance[i]<<endl;
        }
    }
    return 0;
}