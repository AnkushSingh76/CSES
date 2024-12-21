#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    map<char,int>mp;
    for(char it:s){
        mp[it]++;
    }
    string mid="";
    string half="";
    int cnt=0;
    for(auto it:mp){
        if(it.second%2==1){
            mid=it.first;
            cnt++;
        }
        if(cnt>1){
            cout<<"NO SOLUTION";
            return 0;
        }
        half=half+string(it.second/2,it.first);
    }
    string ans=half;
    if(mid!=""){
        ans+=mid;
    }
    reverse(half.begin(),half.end());
    ans+=half; 
    cout<<ans;
}