#include<bits/stdc++.h>
using namespace std;
vector<long long int>solve(long long int n){
    vector<long long int>ans;
    ans.push_back(n);
    while(n!=1){
        if(n%2!=0){
            n=(3*n+1);
        }
        else{
            n=n/2;
        }
        ans.push_back(n);
    }
    return ans;
}
int main(){
    long long int n;
    cin>>n;
    vector<long long int>ans=solve(n);
    for(auto it:ans){
        cout<<it<<" ";
    }
}