#include<iostream>
#include<algorithm>
using namespace std;

int min(int a,int b)
{

    if(a<=b)
    {return a;
}
return b;
}
int main()
{
int sum;
    cout<<"enter the sum:"<<endl;
    cin>>sum;
    int n;
    cout<<"Enter The number:"<<endl;
    cin>>n;

    int v[n];
     cout<<"enter coin:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0)
            {
                dp[i][j]=INT_MAX;
            }
            else if(j==0)
            {
                dp[i][j]=0;

            }
           else if (v[i-1] > j || dp[i][j - v[i-1]] == INT_MAX)
            {
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j] = min(dp[i-1][j], 1 + dp[i][j-v[i]]);

            }
        }
    }
    if(dp[n][sum]==INT_MAX)
    {
        cout<<"not possible";
    }
    else
        cout<<dp[n][sum];
}
