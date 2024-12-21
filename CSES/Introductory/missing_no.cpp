#include<bits/stdc++.h>
using namespace std;
int solve(int n,vector<int>&arr){
    vector<int>temp(n+1,0);
    for(int i=0;i<n;i++){
        if(arr[i]>=1&&arr[i]<=n){
            temp[arr[i]-1]++;
        }
    }
    for(int i=0;i<n;i++){
        if(temp[i]==0){
            return i+1;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=solve(n,arr);
    cout<<ans;
}