#include<iostream>
using namespace std;
int main()
{
    int n1,n2;
    cin>>n1;
    cin>>n2;
    int a1[n1],a2[n2],a3[n1+n2];
    for(int i=0;i<n1;i++)
    {
        cin>>a1[i];
    }
    for(int i=0;i<n2;i++)
    {
        cin>>a2[i];
    }
    for(int i=0;i<n1;i++)
    {
        a3[i]=a1[i];
    }
    for(int i=0;i<n2;i++)
    {
        a3[i+n1]=a2[i];
    }

    int n=n1+n2;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a3[j]<a3[j+1])
            {
                int temp=a3[j+1];
                a3[j+1]=a3[j];
                a3[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a3[i]<<" ";
    }
    return 0;
}
