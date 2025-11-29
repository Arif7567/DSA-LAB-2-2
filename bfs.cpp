
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int vertices,edges;
    cout<<"Enter The Value Of Vertices and Edges"<<endl;
    cin>>vertices>>edges;

    vector<vector<int>>graph(vertices);

    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
       graph[v].push_back(u);
       // graph[v][u]=1;for directed this line no need
       //graph[v][u]=w;//this line needed when undirected graph
    }
    int root_node;
    cin>>root_node;


    int visited[vertices];
    queue<int>q;
    for(int i=0;i<vertices;i++)
    {
     visited[i]=0;
    }

    q.push(root_node);
    visited[root_node]=1;
    cout<<"BFS Traversal is:"<<endl;
    while(!q.empty())
    {
        int top_item=q.front();
        q.pop();
        cout<<top_item<<endl;
        for(int i=0;i<graph[top_item].size();i++)
        {
            if(!visited[graph[top_item][i]]){
            visited[graph[top_item][i]]=1;
            q.push(graph[top_item][i]);
            }
        }
    }







}




