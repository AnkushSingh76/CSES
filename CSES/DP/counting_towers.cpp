#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp(1e6+1,vector<int>(2));
int main(){
    int mod=1e9+7;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        dp[0][0]=1;
        dp[0][1]=1;
        for(int i=1;i<=n;i++){
            dp[i][0]=(2LL*dp[i-1][0]+dp[i-1][1])%mod;
            dp[i][1]=(4LL*dp[i-1][1]+dp[i-1][0])%mod;
        }
        cout<<(dp[n-1][0]+dp[n-1][1])%mod<<endl;
    }
}