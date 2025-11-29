#include<iostream>
#include<algorithm>
using namespace std;
struct Item{
    float w,p,pwp;

};
bool compareBypwp(const Item&a,const Item &b)
{

    return a.pwp>b.pwp;
}

int main()
{

    int n,cap;
    cout<<"Enter Capacity:"<<endl;
    cin>>cap;
    cout<<"Enter number of item:"<<endl;
    cin>>n;
    Item ara[n];
    cout<<"enter items weight and profit:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>ara[i].w>>ara[i].p;
    }
    for(int i=0;i<n;i++)
{
    ara[i].pwp = ara[i].p / ara[i].w;
}
    sort(ara,ara+n,compareBypwp);
    float curr_weight=0,curr_profit=0;
    int items_picked[n];
    int total_weight=0;
    for(int i=0;i<n;i++)
    {
        if(curr_weight>=cap)
        {
            break;
        }
        if(ara[i].w<=cap-curr_weight)
        {
            curr_weight+=ara[i].w;
            curr_profit+=ara[i].p;
            items_picked[i]=1;
        }
        else{
            float weightleft=cap-curr_weight;
            curr_weight+=weightleft;
            curr_profit+=(ara[i].pwp*weightleft);
            break;
        }


    }
    cout<<"weight taken:"<<curr_weight;
    cout<<"profit taken:"<<curr_profit;
    cout<<"items taken:";
    for(int i=0;i<n;i++)
    {
        if(items_picked[i]==1){
            cout<<i+1<<" ";
    }
}
cout<<endl;
return 0;
}
