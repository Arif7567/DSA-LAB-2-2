#include<iostream>
using namespace std;
int fibonacci(int n)
{


        if(n==0 || n==1)

            {
                return n;
            }
            else
            {
                int a=fibonacci(n-1);
                int b=fibonacci(n-2);


            return a+b;
            }

        }



int main()
{
    int n;
    cin>>n;
    int fib=fibonacci(n);
    cout<<fib;
    return 0;
}
