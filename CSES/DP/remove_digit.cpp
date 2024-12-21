#include<bits/stdc++.h>
using namespace std;
int solve(int n){
    vector<int>dp(n+1,0);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int temp=i;
        int minsteps=1e6+7;
        while(temp){
            int digit=temp%10;
            temp=temp/10;
            if(digit!=0){
                minsteps=min(minsteps,1+dp[i-digit]);
            }
        }
        dp[i]=minsteps;
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}