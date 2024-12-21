#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<char>>&v,int n){
    int mod=1e9+7;
    int dp[n][n];
    if(v[0][0]=='.'){
        dp[0][0]=1;
    }
    else{
        dp[0][0]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j==0){
                continue;
            }
            if(v[i][j]=='*'){
                dp[i][j]=0;
            }
            else{
                int ans1=i>0?dp[i-1][j]:0;
                int ans2=j>0?dp[i][j-1]:0;
                dp[i][j]=(ans1+ans2)%mod;
            }
        }
    }
    return dp[n-1][n-1];
}
int main(){
    int n;
    cin>>n;
    vector<vector<char>>v(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    cout<<solve(v,n);
}