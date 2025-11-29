
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


    }
    for(int i=0;i<graph.size();i++)
    {
        for(int j=0;j<graph[i].size();j++)
        {
            cout<<graph[i][j]<<" ";

        }
         cout<<endl;
    }

}



