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
    long long element=v[v.size()/2];
    long long ans=0;
    for(auto it:v){
        ans+=abs(it-element);
    }
    cout<<ans;
}