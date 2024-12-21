#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<long long>v(n);
    for(long long i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    long long ans=1;
    for(long long i=0;i<n;i++){
        if(v[i]>ans){
            break;
        }
        ans+=v[i];
    }
    cout<<ans;
}