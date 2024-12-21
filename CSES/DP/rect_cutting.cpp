#include<bits/stdc++.h>
using namespace std;
int solve(int a,int b){
    int dp[a+1][b+1];
    memset(dp,1e9+7,sizeof(dp));
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j){
                dp[i][j]=0;
                continue;
            }
            for(int h=1;h<i;h++){
                dp[i][j]=min(dp[i][j],1+dp[h][j]+dp[i-h][j]);
            }
            for(int v=1;v<j;v++){
                dp[i][j]=min(dp[i][j],1+dp[i][v]+dp[i][j-v]);
            }
        }
    }
    return dp[a][b];
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<solve(a,b);
}