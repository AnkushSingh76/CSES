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
long long query_tree(long long start,long long end,long long i,long long l,long long r,vector<long long>&seg_tree){
    if(start>r||end<l){
        return 0;
    }
    else if(start<=l&&end>=r){
        return seg_tree[i];
    }
    long long mid=(l+r)>>1;
    return query_tree(start,end,2*i+1,l,mid,seg_tree)+query_tree(start,end,2*i+2,mid+1,r,seg_tree);
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
    long long n,q;
    cin>>n>>q;
    vector<long long>v(n);
    for(long long i=0;i<n;i++){
        cin>>v[i];
    }
    vector<long long>seg_tree(4*n);
    build_tree(0,0,n-1,v,seg_tree);
    for(long long i=0;i<q;i++){
        long long l,val;
        cin>>l>>val;
        update_tree(l-1,val,0,0,n-1,seg_tree);
        cout<<query_tree(0,n-1,0,0,n-1,seg_tree)<<endl;
    }
}