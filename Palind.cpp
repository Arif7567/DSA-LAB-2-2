#include<iostream>
using namespace std;
int palindrome(int x)
{
    static int y=0;
    
    if(x==0)
    {
        return y;
    }
    y=(y*10)+x%10;
return palindrome(x/10);
}
int main()
{
    int w;
    int n=727;
    
    w=palindrome(n);
    if(w==n)
    {
        cout<<"palindrome"<<endl;
    }
    else{
        cout<<"not Palindrome"<<endl;
    }
    return 0;
}