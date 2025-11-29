#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int find_max(int arr[],int n)
{
    int max=arr[0];
    for(int i=1;i<n;i++)
        if(arr[i]>max)
    {
        max=arr[i];
    }
        return max;
}
int getnumber(int number,int p)
{
    return (number/p)%10;
}

int main()
{

 int arr[]={100,95,97,9,25,10,12,26};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max_item=find_max(arr,n);
    int count[max_item+1];
    for(int i=0;i<max_item;i++)
    {
        count [i]=0;
    }
    for(int i=0;i<n;i++)
    {
        count [arr[i]]++;
    }
    for(int i=1;i<=max_item;i++)
    {
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=0;i<n;i++)
    {
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }cout<<"Sorted Array is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<output[i]<<" ";
    }
    return 0;
}
