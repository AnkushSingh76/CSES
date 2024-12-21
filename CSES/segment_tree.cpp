#include<bits/stdc++.h>
using namespace std;
//baically all nodes will act as a leaf node, then make similar thought as huffman encoding to build tree
//Ex: arr[]={3,1,2,7}   seg_tree[]={13,4,9,3,1,2,7}
//generally size of seg_tree will be 2*n(but we take 4*n, because we take 2*n leaf nodes, so that it pair-up)
void build_tree(int i,int l,int r,vector<int>arr,vector<int>&seg_tree){
    if(l==r){
        seg_tree[i]=arr[l];
        return;
    }
    int mid=(l+r)>>1;
    build_tree(2*i+1,l,mid,arr,seg_tree);
    build_tree(2*i+2,mid+1,r,arr,seg_tree);
    seg_tree[i]=seg_tree[2*i+1]+seg_tree[2*i+2];
}
//in update query, if we change value at any index 'idx' with a value 'val', then node values will be changed
void update_tree(int idx,int val,int i,int l,int r,vector<int>arr,vector<int>&seg_tree){
    if(l==r){
        seg_tree[i]=val;
        return;
    }
    int mid=(l+r)>>1;
    if(idx<=mid){
        update_tree(idx,val,2*i+1,l,mid,arr,seg_tree);
    }
    else{
        update_tree(idx,val,2*i+2,mid+1,r,arr,seg_tree);
    }
    seg_tree[i]=seg_tree[2*i+1]+seg_tree[2*i+2];
}
//it basically finds the query from range [start,end] & [l,r] is the range of nodes
int query_tree(int start,int end,int i,int l,int r,vector<int>arr,vector<int>seg_tree){
    if(start>r||end<l){
        return 0;
    }
    else if(start<=l&&end>=r){
        return seg_tree[i];
    }
    int mid=(l+r)>>1;
    return query_tree(start,end,2*i+1,l,mid,arr,seg_tree)+query_tree(start,end,2*i+2,mid+1,r,arr,seg_tree);
}
//if we want to update for a certain range, then lazy propagation is used
//if we use above method(update_tree) for updating individual nodes, total time of nlogn will be required
//time complexity is improved from O(nlogn) to O(logn)
void update_range_tree(int start,int end,int val,int i,int l,int r,vector<int>&seg_tree,vector<int>&lazy_arr){
    if(lazy_arr[i]!=0){
        seg_tree[i]+=(r-l+1)*lazy_arr[i];
        if(l!=r){
            lazy_arr[2*i+1]+=lazy_arr[i];
            lazy_arr[2*i+2]+=lazy_arr[i];
        }
        lazy_arr[i]=0;
    }    
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
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>seg_tree(2*n);  //generally we take 4*n size instead of 2*n, as explained above
    //Ex taken: arr[]={3,1,2,7}
    build_tree(0,0,n-1,arr,seg_tree);
    for(auto it:seg_tree){
        cout<<it<<" ";
    }
    cout<<endl;
    int ans=query_tree(1,2,0,0,n-1,arr,seg_tree);
    cout<<ans<<endl;
    update_tree(1,2,0,0,n-1,arr,seg_tree);
    for(auto it:seg_tree){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<int>lazy_arr(4*n,0);
    update_range_tree(1,3,2,0,0,n-1,seg_tree,lazy_arr);
    for(auto it:seg_tree){
        cout<<it<<" ";
    }
    cout<<endl;
}