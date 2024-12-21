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
void propagate_lazy(long long i,long long l,long long r,vector<long long>&seg_tree,vector<long long>&lazy_arr){
    if(lazy_arr[i]!=0){
        seg_tree[i]+=(r-l+1)*lazy_arr[i];
        if(l!=r){
            lazy_arr[2*i+1]+=lazy_arr[i];
            lazy_arr[2*i+2]+=lazy_arr[i];
        }
        lazy_arr[i]=0;
    } 
}
long long query_tree(long long start,long long end,long long i,long long l,long long r,vector<long long>&seg_tree,vector<long long>&lazy_arr){
    propagate_lazy(i,l,r,seg_tree,lazy_arr);
    if(start>r||end<l){
        return 0;
    }
    else if(start<=l&&end>=r){
        return seg_tree[i];
    }
    long long mid=(l+r)>>1;
    return query_tree(start,end,2*i+1,l,mid,seg_tree,lazy_arr)+query_tree(start,end,2*i+2,mid+1,r,seg_tree,lazy_arr);
}
void update_range_tree(long long start,long long end,long long val,long long i,long long l,long long r,vector<long long>&seg_tree,vector<long long>&lazy_arr){
    propagate_lazy(i,l,r,seg_tree,lazy_arr);
    if(start>r||end<l){
        return;
    }
    else if(start<=l&&end>=r){
        seg_tree[i]+=(r-l+1)*val;
        if(l!=r){
            lazy_arr[2*i+1]+=val;
            lazy_arr[2*i+2]+=val;
        }
        return;    
    }
    int mid=(l+r)>>1;
    update_range_tree(start,end,val,2*i+1,l,mid,seg_tree,lazy_arr);
    update_range_tree(start,end,val,2*i+2,mid+1,r,seg_tree,lazy_arr);
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
    vector<long long>lazy_arr(4*n,0);
    for(long long i=0;i<q;i++){
        long long query;
        cin>>query;
        if(query==2){
            long long l;
            cin>>l;
            cout<<query_tree(l-1,l-1,0,0,n-1,seg_tree,lazy_arr)<<endl;
        }
        if(query==1){
            long long l,r,val;
            cin>>l>>r>>val;
            update_range_tree(l-1,r-1,val,0,0,n-1,seg_tree,lazy_arr);
        }
    }
}