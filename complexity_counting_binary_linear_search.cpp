#include<iostream>
using namespace std;
int main()
{
    int ara[1000];
    for(int i=0;i<1000;i++)
    {
        ara[i]=i;
    }
    int key=550;
    int flag=0,step_linear=0;
    for(int i=0;i<1000;i++)
    {
        step_linear++;
        if(ara[i]==key)
            {flag=1;
        cout<<"Found"<<endl;
        break;
    }
    }
    if(flag==0)
    {
        step_linear++;
        cout<<"not found"<<endl;

    }
    cout<<"Step counter for linear search:"<<step_linear<<endl;
int low=0,high=999,mid;
flag=0;
int step_binary=0;
while(low<=high)
{
    step_binary++;
    mid=(high+low)/2;
    if(ara[mid]==key)
    {
        cout<<"found"<<endl;
        flag =1;
        break;
    }
    else if(ara[mid]>key)
    {
        high=mid-1;
    }
    else{
            low=mid+1;
    }
}
if(flag==0)
{
    step_binary++;
    cout<<"not found"<<endl;
}
cout<<"Step count for binary search:"<<step_binary<<endl;
    return 0;
}
