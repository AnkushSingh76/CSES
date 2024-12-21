#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    vector<int>temp(n+1,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
        temp[v[i]]=i;
    }
    int ans=1;
    for(int i=2;i<=n;i++){
        if(temp[i]<temp[i-1]){
            ans++;
        }
    }
    cout<<ans;
}