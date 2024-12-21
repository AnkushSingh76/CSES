#include<bits/stdc++.h>
using namespace std;
string solve(int a,int n){
    string ans="";
    for(int i=0;i<n;i++){
        if(a&(1<<i)){
            ans=ans+'1';
        }
        else{
            ans=ans+'0';
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<(1<<n);i++){
        int temp=i^(i>>1);
        cout<<solve(temp,n)<<endl;
    }
}