#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,sum;
    cin>>n>>sum;
    vector<long long>arr(n);
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    unordered_map<long long,long long>mp;
    long long cnt=0;
    long long total_sum=0;
    for(long long i=0;i<n;i++){
        total_sum+=arr[i];
        if(mp.find(total_sum-sum)!=mp.end()){
            cnt+=mp[total_sum-sum];
        }
        if(total_sum==sum){
            cnt++;
        }
        mp[total_sum]++;
    }
    cout<<cnt;
}