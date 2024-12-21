//DP on trees
#include<bits/stdc++.h>
using namespace std;
void dfs1(long long node,long long parent,vector<vector<long long>>&adj,vector<long long>&sumdist,vector<long long>&subtreesize){
    subtreesize[node]=1;
    for(auto it:adj[node]){
        if(it!=parent){
            dfs1(it,node,adj,sumdist,subtreesize);
            subtreesize[node]+=subtreesize[it];
            sumdist[node]+=sumdist[it]+subtreesize[it];
        }
    }
}
//concept of re-rooting
//as initially we choosed 1 as root, we'll shift our root from 1 to different nodes
//Ex: root=2, then sumdist of subtrees of node 2 will decrease by 1 and increase by 1 for other nodes
void dfs2(long long node,long long parent,vector<vector<long long>>&adj,long long n,vector<long long>&sumdist,vector<long long>&subtreesize){
    for(auto it:adj[node]){
        if(it!=parent){
            sumdist[it]=sumdist[node]+(n-2*subtreesize[it]);
            dfs2(it,node,adj,n,sumdist,subtreesize);
        }
    }
}
int main(){
    long long n;
    cin>>n;
    vector<vector<long long>>adj(n+1);
    vector<long long>sumdist(n+1,0);
    vector<long long>subtreesize(n+1,0);
    long long a,b;
    for(long long i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1,0,adj,sumdist,subtreesize);
    dfs2(1,0,adj,n,sumdist,subtreesize);
    for(long long i=1;i<n+1;i++){
        cout<<sumdist[i]<<" ";
    }
}