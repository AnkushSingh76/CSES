#include<bits/stdc++.h>
using namespace std;
char grid[1001][1001];
bool visited[1001][1001];
int n,m,ans=0;
bool isvalid(int i,int j){
    if(i<0)return 0;
    if(j<0)return 0;
    if(i>=n)return 0;
    if(j>=m)return 0;
    if(grid[i][j]=='#')return 0;
    return 1;
}
void dfs(int i,int j){
    visited[i][j]=1;
    int delcol[]={0,0,-1,1};
    int delrow[]={-1,1,0,0};
    for(int k=0;k<4;k++){
        int ncol=i+delcol[k];
        int nrow=j+delrow[k];
        if(isvalid(ncol,nrow)){
            if(!visited[ncol][nrow]){
                dfs(ncol,nrow);
            }
        }
    } 
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            visited[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.'&&!visited[i][j]){
                dfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans;
}