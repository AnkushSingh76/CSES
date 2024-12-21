#include<bits/stdc++.h>
using namespace std;
+int solve(int n){
    int mod=1e9+7;
    vector<int>dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i-j>=0){
                dp[i]=(dp[i-j]+dp[i])%mod;
            }
        }
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    cout<<solve(n);
    return 0;
}
/*int solve(string s,int n){
    //water:1,snake:2,gun:3
    vector<int>ans;
    while(s.length()>0){
        if(s.length()>=5){
            if(s.substr(0,5)=="water"){
                ans.push_back(1);
                s=s.substr(5);
            }
            else if(s.substr(0,5)=="snake"){
                ans.push_back(2);
                s=s.substr(5);
            }
            else if(s.substr(0,3)=="gun"){
                ans.push_back(3);
                s=s.substr(3);
            }
        }
        else if(s.length()>=3){
            if(s.substr(0,3)=="gun"){
                ans.push_back(3);
                s=s.substr(3);
            }
        }
    }
    int res=0;
    for(int i=0;i<ans.size();i+=2){
        if(ans[i]==2&&ans[i+1]==1){
            res++;
        }
        else if(ans[i]==1&&ans[i+1]==3){
            res++;
        }
        else if(ans[i]==3&&ans[i+1]==2){
            res++;
        }
    }
    return res;
}
int main(){
    string s;
    int n;
    cin>>s>>n;
    cout<<solve(s,n);
}*/