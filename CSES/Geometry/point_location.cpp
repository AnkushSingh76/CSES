#include<bits/stdc++.h>
using namespace std;
string solve(vector<int>v){
    int x1=v[0];
    int y1=v[1];
    int x2=v[2];
    int y2=v[3];
    int x3=v[4];
    int y3=v[5];
    if((y3-y1)*(x2-x1)==(y2-y1)*(x3-x1)){
        return "TOUCH";
    }
    else if((y3-y1)*(x2-x1)>(y2-y1)*(x3-x1)){
        return "LEFT";
    }
    return "RIGHT";
}
int main(){
    int t;
    cin>>t;
    vector<string>ans;
    while(t--){
        vector<int>v;
        for(int i=0;i<6;i++){
            cin>>v[i];
        }
        ans.push_back(solve(v));
    }
    for(auto it:ans){
        cout<<it<<endl;
    }
}