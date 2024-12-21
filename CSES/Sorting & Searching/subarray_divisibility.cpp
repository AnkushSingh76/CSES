#include<bits/stdc++.h>
using namespace std;
int main(){ 
    long long n;
    cin>>n;
    vector<long long>arr(n);
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<long long,long long>mp;
    long long cnt=0;
    long long total_sum=0;
    mp[0]=1;
    for(long long i=0;i<n;i++){
        total_sum+=arr[i];
        long long mod=(total_sum%n+n)%n;
        if(mp.find(mod)!=mp.end()){
            cnt+=mp[mod];
        }
        mp[mod]++;
    }
    cout<<cnt;
}