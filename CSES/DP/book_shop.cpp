#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>cost,vector<int>pages,int sum,int n){
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=sum;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(cost[i-1]<=j){
                dp[i][j]=max(dp[i-1][j-cost[i-1]]+pages[i-1],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}    
int main(){
    int n,sum;
    cin>>n>>sum;
    vector<int>cost(n);
    vector<int>pages(n);
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    cout<<solve(cost,pages,sum,n);
    return 0;
}