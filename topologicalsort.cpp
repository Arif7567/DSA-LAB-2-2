#include<bits/stdc++.h>
using namespace std;
int main()
{
    int vertices,edge;
    cin>>vertices>>edge;
    vector<vector<pair<int,int>>>graph(vertices);
    for(int i=0;i<edge;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));

    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    int visited[vertices];
    for(int i=0;i<vertices;i++)
    {
        visited[i]=0;
    }
    int start_node=0;
    pq.push(make_pair(0,start_node));
    int totalcost=0;
    while(!pq.empty())
    {
        pair<int,int> p=pq.top();
        pq.pop();
        int top_item=p.second;
        int weight=p.first;
        if(visited[top_item]==1)
        {
            continue;
        }
        visited[top_item]=1;
        totalcost=totalcost+weight;
        cout<<top_item<<" ";
        for(int i=0;i<graph[top_item].size();i++)
        {
            int v=graph[top_item][i].first;
            int w=graph[top_item][i].second;
            if(visited[v]==0)
            {
                pq.push(make_pair(w,v));
            }

        }

    }
    cout<<endl;
    cout<<"totalcost:"<<totalcost;


}
