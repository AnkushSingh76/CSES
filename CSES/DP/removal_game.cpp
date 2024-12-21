#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>v){
    int n=v.size();
    vector<vector<long long>>dp(n,vector<long long>(n,0));
    for(int i=0;i<n;i++){
        dp[i][i]=v[i];
    }
    for(int len=2;len<=n;len++){
        for(int i=0;i<n-len+1;i++){
            int j=i+len-1;
            int pickLeft=v[i]+min((i + 2 <= j) ? dp[i + 2][j] : 0, (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0);
            int pickRight=v[j]+min((i <= j - 2) ? dp[i][j - 2] : 0, (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0);
            dp[i][j] = max(pickLeft, pickRight);
        }
    }
    return dp[0][n-1];
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<solve(v);
}