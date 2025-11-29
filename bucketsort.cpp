#include<bits/stdc++.h>
using namespace std;
int find_max(int ara[],int n)
{
    int max=ara[0];
    for(int i=1;i<n;i++)
    {
        if(ara[i]>max)
        {
            max=ara[i];
        }
    }
    return max;
}
int find_min(int ara[],int n)
{
    int min=ara[0];
    for(int i=1;i<n;i++)
    {
        if(ara[i]<min)
        {
            min=ara[i];
        }
    }
    return min;
}
void insertionSort(int bucket[],int n)
{
    for(int i=1;i<n;i++)
    {
        int num=bucket[i];
        int j=i-1;
        while(j>=0&&bucket[j]>num)
        {
            bucket[j+1]=bucket[j];
            j--;
        }
        bucket[j+1]=num;
    }
}
void bucketsort(int ara[],int n)
{
    int min_val=find_min(ara,n);
    int max_val=find_max(ara,n);
    int bucketNumber=5;
    int buckets[5][10];
    int bucketSize[bucketNumber]={0};
    for(int i=0;i<n;i++)
    {
        int index=floor((ara[i]-min_val)/(max_val-min_val)*bucketNumber);
        index=min(index,bucketNumber-1);
        buckets[index][bucketSize[index]] = ara[i];
        bucketSize[index]++;
    }
    for(int i=0;i<bucketNumber;i++)
    {
        if(bucketSize[i]>0)

        {
            insertionSort(buckets[i],bucketSize[i]);
        }
    }
    int index=0;
    for (int i=0;i<bucketNumber;i++)
    {
        for(int j=0;j<bucketSize[i];j++)
        {
            ara[index++]=buckets[i][j];
    }
    }
}

int main()
{
    int ara[]={150,30,70,90,160,130,120,10,90,80};
    int n=sizeof(ara)/sizeof(ara[0]);
    bucketsort(ara,n);
    cout<<"Finally Sorted Array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<ara[i]<<" ";
    }
return 0;}
