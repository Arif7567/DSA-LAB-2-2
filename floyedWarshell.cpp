#include<iostream>
#include <climits>
using namespace std;
int main()
    {
        int vertex,edge;
        cin>>vertex>>edge;
        int matrix[vertex][vertex]={INT_MAX};
        for(int i=0;i<edge;i++)
            {
                int u,v,weight;
                cin>>u>>v>>weight;
                matrix[u][v]=weight;
            } 
            
             
        for(int k=0;k<vertex;k++)
        {
            for(int i=0;i<vertex;i++)
            {
                for(int j=0;j<vertex;j++)
                {
                    if(matrix[i][k]!=INT_MAX && matrix[k][j]!=INT_MAX)
                    {
                        matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                    }
                }
            }
        }
        for(int i=0;i<vertex;i++) 
        {
            for(int j=0;j<vertex;j++)
            
            {

                cout<<matrix[i][j]<<" ";
            

            }
            cout<<endl;
            }
    

           

        return 0;

    


    
    }