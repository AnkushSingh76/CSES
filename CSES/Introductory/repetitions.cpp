#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int ans=1;
    int i=0;
    while(i<s.length()-1){
        if(s[i]==s[i+1]){
            int len=1;
            while(s[i]==s[i+1]){
                len++;
                i++;
            }
            ans=max(ans,len);
        }
        else{
            i++;
        }
    }
    cout<<ans;
}