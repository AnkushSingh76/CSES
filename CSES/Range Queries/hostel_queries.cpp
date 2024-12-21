#include<bits/stdc++.h>
using namespace std;
void build_tree(long long i,long long l,long long r,vector<long long>&arr,vector<long long>&seg_tree){
    if(l==r){
        seg_tree[i]=arr[l];
        return;
    }
    long long mid=(l+r)>>1;
    build_tree(2*i+1,l,mid,arr,seg_tree);
    build_tree(2*i+2,mid+1,r,arr,seg_tree);
    seg_tree[i]=seg_tree[2*i+1]+seg_tree[2*i+2];
}
long long query_tree(long long val,vector<long long>&seg_tree){
    long long i=0;
    long long n=seg_tree.size()/4;
    long long ans=-1;
    while(i<n){
        if(seg_tree[2*i+1]>=val){
            i=2*i+1;
        }
        else{
            val=val-seg_tree[2*i+1];
            i=2*i+2;
        }
    }
    return i-n;
}
void update_tree(long long idx,long long val,long long i,long long l,long long r,vector<long long>&seg_tree){
    if(l==r){
        seg_tree[i]=val;
        return;
    }
    long long mid=(l+r)>>1;
    if(idx<=mid){
        update_tree(idx,val,2*i+1,l,mid,seg_tree);
    }
    else{
        update_tree(idx,val,2*i+2,mid+1,r,seg_tree);
    }
    seg_tree[i]=seg_tree[2*i+1]+seg_tree[2*i+2];
}
int main(){
    long long n,m;
    cin>>n>>m;
    vector<long long>v(n);
    for(long long i=0;i<n;i++){
        cin>>v[i];
    }
    vector<long long>v1(m);
    for(long long i=0;i<m;i++){
        cin>>v1[i];

    }
    vector<long long>seg_tree(4*n);
    build_tree(0,0,n-1,v,seg_tree);
    for(long long it:v1){
        long long idx=query_tree(it,seg_tree);
        cout<<idx+1<<endl;
        if(idx!=-1){
            update_tree(idx,seg_tree[idx]-it,0,0,n-1,seg_tree);
        }
    }
}