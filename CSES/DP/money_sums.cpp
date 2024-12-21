#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>v,int n){
    vector<bool>dp(1e5+7,0);
    dp[0]=1;
    int total=0;
    set<int>s;
    for(auto coin:v){
        total+=coin;
        for(int i=total;i>=coin;i--){
            if(dp[i-coin]&&!dp[i]){
                dp[i]=1;
                s.insert(i);
            }
        }
    }
    cout<<s.size()<<endl;
    for(auto it:s){
        cout<<it<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    solve(v,n);
}