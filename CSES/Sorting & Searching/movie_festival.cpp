#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),cmp);
    int ans=1;
    int end=v[0].second;
    for(int i=1;i<n;i++){
        if(v[i].first>=end){
            ans++;
            end=v[i].second;
        }
    }
    cout<<ans;
}