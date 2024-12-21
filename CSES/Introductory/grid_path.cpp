#include<bits/stdc++.h>
using namespace std;
void solve(int i,int j,int idx,int &cnt,string s,vector<vector<bool>>&visited){
    if(i==6&&j==0){
        if(idx==48){
            cnt++;
        }
        return;
    }
    if(idx>=48){
        return;
    }
    visited[i][j]=true;
    if(s[idx]=='?'||s[idx]=='U'){
        if(i>=1&&!visited[i-1][j]){
            solve(i-1,j,idx+1,cnt,s,visited);
        }
    }
    if(s[idx]=='?'||s[idx]=='D'){
        if(i<6&&!visited[i+1][j]){
            solve(i+1,j,idx+1,cnt,s,visited);
        }
    }
    if(s[idx]=='?'||s[idx]=='L'){
        if(j>=1&&!visited[i][j-1]){
            solve(i,j-1,idx+1,cnt,s,visited);
        }
    }
    if(s[idx]=='?'||s[idx]=='R'){
        if(i<6&&!visited[i][j+1]){
            solve(i,j+1,idx+1,cnt,s,visited);
        }
    }
    visited[i][j]=false;
}
int main(){
    string s;
    cin>>s;
    int cnt=0;
    vector<vector<bool>>visited(7,vector<bool>(7,0));
    solve(0,0,0,cnt,s,visited);
    cout<<cnt;  
}