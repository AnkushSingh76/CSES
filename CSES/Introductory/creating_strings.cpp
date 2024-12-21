#include<bits/stdc++.h>
using namespace std;
void solve(int i,string &str,set<string>&s){
    if(i==str.length()){
        s.insert(str);
        return;
    }
    for(int idx=i;idx<str.length();idx++){
        swap(str[i],str[idx]);
        solve(i+1,str,s);
        swap(str[i],str[idx]);
    }
}
int main(){
    string str;
    cin>>str;
    set<string>s;
    solve(0,str,s);
    cout<<s.size()<<endl;
    for(auto it:s){
        cout<<it<<endl;
    }
}