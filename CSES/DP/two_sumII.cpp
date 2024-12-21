#include<bits/stdc++.h>
using namespace std;
int solve(int n){
    int mod=1e9+7;
    int sum=(n*(n+1))/2;
    if(sum&1){
        return 0;
    }
    sum=sum>>1;
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=0;i<=sum;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(i<=j){
                dp[i][j]=(dp[i-1][j-i]+dp[i-1][j])%mod;
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int main(){
    int n;
    cin>>n;
    cout<<solve(n);
}
