#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>v;
    pair<int,int>start;
    pair<int,int>end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
            if(v[i][j]=='A'){
                start={i,j};
            }
            if(v[i][j]=='B'){
                end={i,j};
            }
        }
    }
    vector<vector<int>>visited(n,vector<int>(m,0));
    queue<pair<int,int>>q;
    q.push(start);
    int delrow[4]={0,-1,0,1};
    int delcol[4]={-1,0,1,0};
    visited[start.first][start.second]=1;
    while(!q.empty()){
        int i=q.front().first;
        int j=q.front().second;
        q.pop();
        if(i==end.first&&j==end.second){
            cout<<"YES";
            return 0;
        }
        for(int k=0;k<4;k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!visited[nrow][ncol]&&v[nrow][ncol]=='.'){
                visited[nrow][ncol]=1;
                q.push({nrow,ncol});
            }
        }
    }
    cout<<"NO";
    return 0;
}