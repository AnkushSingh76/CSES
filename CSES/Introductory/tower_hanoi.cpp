#include<bits/stdc++.h>
using namespace std;
void solve(int n,int source,int dest,int helper,vector<vector<int>>&arr){
    if(n==1){
        arr.push_back({source,dest});
        return;
    }
    solve(n-1,source,helper,dest,arr);
    arr.push_back({source,dest});
    solve(n-1,helper,dest,source,arr);
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr;
    solve(n,1,3,2,arr);
    cout<<arr.size()<<endl;
    for(auto it:arr){
        cout<<it[0]<<" "<<it[1]<<endl;
    }
}