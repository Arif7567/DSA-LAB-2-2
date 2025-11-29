#include<iostream>
using namespace std;
int partition(int a[],int s,int e)
{
    int pos=s;
    for(int i=s;i<=e;i++)
    {
        if(a[i]<=a[e])
            {swap(a[i],a[pos]);
            pos++;}
    }
    return pos-1;



}
void quickSort(int a[],int s,int e)
{
    if(s>=e)
        return;
    int p=partition(a,s,e);
    partition(a,s,e);
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
}
int main()
{
    int a[6]={4,6,2,9,3,5};
    quickSort(a,0,6);
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<" ";
    }


    return 0;
}
