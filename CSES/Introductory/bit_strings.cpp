#include<bits/stdc++.h>
using namespace std;
int solve(int n,int mod){
    if(n==0){
        return 1;
    }
    long long ans=solve(n/2,mod)%mod;
    ans=(ans*ans)%mod;
    if(n%2==1){
        ans=(ans*2)%mod;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    int mod=1e9+7;
    int ans=solve(n,mod);
    cout<<ans;
}