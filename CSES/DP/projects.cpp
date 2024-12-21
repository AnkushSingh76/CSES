#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>>v,int n){
    sort(v.begin(),v.end());
    
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(3));
    vector<int>temp;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        temp.push_back(a);
        temp.push_back(b);
        temp.push_back(c);
        v.push_back(temp);
        temp.clear();
    }
    cout<<solve(v,n);
}