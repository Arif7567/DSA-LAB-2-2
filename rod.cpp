#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cout<<"Enter The number of rod pieces:";
    cin>>n;
     int length[n],price[n];
     cout<<"Enter The length of Rods Pieces:";
     for(int i=0;i<n;i++)
     {
         cin>>length[i];
     }
     cout<<"enter the price of each rods pieceS"<<endl;
     for(int i=0;i<n;i++)
     {
         cin>>price[i];
     }

    int Target;
    cout<<"Enter total length of rod:";
    cin>>Target;
    int dp[Target+1];
    for(int j=0;j<=Target;j++)
    {
        dp[j]=0;

    }

for(int i=0;i<n;i++)
{
    for(int j=length[i];j<=Target;j++)
    {


        dp[j]=max(dp[j],price[i]+dp[j-length[i]]);
}
}
cout<<"maximum price:"<<dp[Target]<<endl;
return 0;
}

