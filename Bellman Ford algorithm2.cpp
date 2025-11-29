#include<bits/stdc++.h>
#include<map>
using namespace std;

struct Edge{
    int u,v,w;
};

int main()
{
    int vertex,edge;
    cin>>vertex>>edge;
    Edge graph[edge];
    map<char,int>mp;

    for(int i=0; i<edge; i++)
    {
        int w;
        char u,v;
        cin>>u>>v>>w;


    int idx=0;
    if(mp.find(u)==mp.end())
    {
        mp[u]=idx;
        idx++;

    }
    if(mp.find(v)==mp.end())
    {
        mp[v]=idx;
        idx++;

    }
    graph[i].u=mp[u];
    graph[i].v=mp[v];
    graph[i].w=w;
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
            cout<<"Node: "<<mp[i]<<"\tDistance: "<<distance[i]<<endl;
        }
    }
    for(auto cons& p:mp)
    {
        cout<<"key: "<<
    }
    return 0;
}

