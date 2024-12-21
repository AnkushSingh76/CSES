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
        long long l,r;
        cin>>l>>r;
        cout<<query_tree(l-1,r-1,0,0,n-1,seg_tree)<<endl;
    }
    /*for(int i=1;i<n;i++){
        v[i]+=v[i-1];
    }
    int l,r;
    vector<long long>ans(q);
    for(int i=0;i<q;i++){
        cin>>l>>r;
        if(l==1){
            ans[i]=v[r-1];
        }
        else{
            ans[i]=v[r-1]-v[l-2];
        }
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<endl;
    }*/
}