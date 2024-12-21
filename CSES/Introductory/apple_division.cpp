#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<long long>arr(n);
    long long total_sum=0;
    for(long long i=0;i<n;i++){
        cin>>arr[i];
        total_sum+=arr[i];
    }
    long long ans=1e15+7;
    for(long long i=0;i<(1<<n);i++){
        long long temp_sum=0;
        for(long long j=0;j<n;j++){
            if(i&(1<<j)){
                temp_sum+=arr[j];
            }
        }
        ans=min(ans,abs(2*temp_sum-total_sum));
    }
    cout<<ans;
}    