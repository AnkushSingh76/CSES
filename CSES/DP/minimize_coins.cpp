#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>v,int sum){
    int n=v.size();
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=sum;i++){
        dp[0][i]=INT_MAX-1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(v[i-1]<=j){
                dp[i][j]=min(1+dp[i][j-v[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum]==INT_MAX-1?-1:dp[n][sum];
}
int main(){
    int n,sum;
    cin>>n>>sum;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<solve(v,sum);
}