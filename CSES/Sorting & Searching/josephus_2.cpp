#include<bits/stdc++.h>
using namespace std;
vector<long long>solve(long long n,long long k){
    vector<long long>people;
    for(long long i=1;i<=n;i++){
        people.push_back(i);
    }
    long long idx=0;
    vector<long long>ans;
    while(!people.empty()){
        idx=(idx+k)%people.size();
        ans.push_back(people[idx]);
        people.erase(people.begin()+idx);
    }
    return ans;
}
int main(){
    long long n,k;
    cin>>n>>k;
    vector<long long>ans=solve(n,k);
    for(auto it:ans){
        cout<<it<<" ";
    }
}