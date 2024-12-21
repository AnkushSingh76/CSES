#include<bits/stdc++.h>
using namespace std;
vector<int>solve(int n){
    /*vector<int>arr(n);
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    vector<int>ans;
    int idx=0;
    while(arr.size()>0){
        idx=(idx+1)%arr.size();
        ans.push_back(arr[idx]);
        arr.erase(arr.begin()+idx);
    }
    return ans;*/
    queue<int>q;
    vector<int>ans;
    for(int i=1;i<=n;i++){
        q.push(i);
    }
    while(q.size()>1){
        int temp=q.front();
        q.pop();
        if(q.size()>0){
            ans.push_back(q.front());
            q.pop();
        }
        q.push(temp);
    }
    ans.push_back(q.front());
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>ans=solve(n);
    for(auto it:ans){
        cout<<it<<" ";
    }
}