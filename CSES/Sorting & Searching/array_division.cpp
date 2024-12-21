#include<bits/stdc++.h>
using namespace std;
bool solve(vector<long long>&arr,long long mid,long long k,long long n){
    long long cnt=1;
    long long sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>mid){
            cnt++;
            sum=arr[i];
        }
        if(cnt>k){
            return 0;
        }
    }
    return 1;
}
int main(){ 
    long long n,k;
    cin>>n>>k;
    vector<long long>arr(n);
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    long long i=*max_element(arr.begin(),arr.end());
    long long j=accumulate(arr.begin(),arr.end(),0LL);
    long long ans=j;
    while(i<=j){
        long long mid=(i+j)>>1;
        if(solve(arr,mid,k,n)){
            ans=mid;
            j=mid-1;
        }
        else{
            i=mid+1;
        }
    }
    cout<<ans;
}