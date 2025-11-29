#include<bits/stdc++.h>
using namespace std;
int getMaxRodProfit(vector<int>price,int n) {
    vector<int>dp(n+1,0);
    for (int i=1;i <=n;i++) {
        int maximumProfit=INT_MIN;
        for (int j=0;j<i;j++) {
            maximumProfit=max(maximumProfit,price[j]+dp[i-j-1]);
        }
        dp[i]=maximumProfit;
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    vector<int>price(n);
    for (int i = 0; i<n;i++) {
        cin>>price[i];
    }
    cout << "Maximum profit: "<<getMaxRodProfit(price, n)<<endl;
    return 0;
}
