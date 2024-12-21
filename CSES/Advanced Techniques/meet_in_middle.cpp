#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,sum;
    cin>>n>>sum;
    vector<long long>arr(n);
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<long long>>dp(n+1,vector<long long>(sum+1,0));
    for(long long i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(long long i=1;i<n+1;i++){
        for(long long j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][sum];
}