#include<bits/stdc++.h>
using namespace std;
int farthest_node(vector<vector<int>>&adj,int n){
    queue<int>q;
    vector<int>visited(n+1,0);
    q.push(1);
    visited[1]=1;
    int last;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        last=node;
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
        }
    }
    return last;
}
int farthest_dist(vector<vector<int>>&adj,int node,int n){
    vector<int>dist(n+1,INT_MAX);
    dist[node]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,node});
    while(!pq.empty()){
        pair<int,int>p=pq.top();
        pq.pop();
        for(auto it:adj[p.second]){
            if(dist[it]>p.first+1){
                dist[it]=p.first+1;
                pq.push({dist[it],it});
            }
        }
    }
    return *max_element(dist.begin()+1,dist.end());
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>adj(n+1);
    int a,b;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int start=farthest_node(adj,n);
    cout<<farthest_dist(adj,start,n);
}