#include<bits/stdc++.h>
using namespace std;
long long solve(long long a,long long b,long long mod){
    if(b==0){
        return 1;
    }
    long long temp=solve(a,b/2,mod)%mod;
    temp=(temp*temp)%mod;
    if(b%2==1){
        return (a*temp)%mod;
    }
    else{
        return temp;
    }
}
int main(){
    long long t;
    long long mod=1e9+7;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        cout<<solve(a,b,mod)<<endl;
    }
}