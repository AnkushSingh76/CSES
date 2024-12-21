#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t;
    cin>>n>>t;
    int a;
    vector<int>temp(n+1);
    for(int i=0;i<n;i++){
        cin>>a;
        temp[a]=i;
    }
    int ans=1;
    for(int i=1;i<n;i++){
        if(temp[i+1]<temp[i]){
            ans++;
        }
    }
    cout<<ans<<'\n';
    while(t--){
        int a,b;
        cin>>a>>b;
        swap(temp[a],temp[b]);
        solve(n,temp);
    }
}