#include<bits/stdc++.h>
using namespace std;
int farthest_node1(vector<vector<int>>&adj,int n){
    queue<int>q;
    vector<int>visited(n+1,0);
    q.push(1);
    visited[1]=1;
    int last=1;
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
int farthest_node2(vector<vector<int>>&adj,int &node,int n){
    queue<int>q;
    vector<int>dist(n+1,-1);
    q.push(node);
    dist[node]=0;
    int last=node;
    while(!q.empty()){
        int adjnode=q.front();
        q.pop();
        for(auto it:adj[adjnode]){
            if(dist[it]==-1){
                dist[it]=dist[adjnode]+1;
                q.push(it);
                if(dist[it]>dist[adjnode]){
                    last=it;
                }
            }
        }
    }
    return last;
}
vector<int>farthest_dist(vector<vector<int>>&adj,int &node,int n){
    queue<int>q;
    vector<int>dist(n+1,-1);
    q.push(node);
    dist[node]=0;
    while(!q.empty()){
        int adjnode=q.front();
        q.pop();
        for(auto it:adj[adjnode]){
            if(dist[it]==-1){
                dist[it]=dist[adjnode]+1;
                q.push(it);
            }
        }
    }
    return dist;
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
    int start=farthest_node1(adj,n);
    int end=farthest_node2(adj,start,n);
    vector<int>dist1=farthest_dist(adj,start,n);
    vector<int>dist2=farthest_dist(adj,end,n);
    for(int i=1;i<n+1;i++){
        cout<<max(dist1[i],dist2[i])<<" ";
    }
}