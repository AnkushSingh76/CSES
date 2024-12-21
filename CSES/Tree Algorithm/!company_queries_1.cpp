#include<bits/stdc++.h>
using namespace std;
void solve(long long &node,long long x,long long parent,long long k,vector<vector<long long>>&adj){
    if(k==0){
        node=x;
        return;
    }
    for(auto it:adj[x]){
        if(it!=parent){
            solve(node,it,node,k-1,adj);
        }
    }
}
int main(){
    long long n,q;
    cin>>n>>q;
    long long a;
    vector<vector<long long>>adj(n+1);
    for(long long i=2;i<n+1;i++){
        cin>>a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    long long x,k;
    while(q--){
        cin>>x>>k;
        long long node;
        solve(node,x,0,k,adj);
        cout<<node<<endl;
    }
}