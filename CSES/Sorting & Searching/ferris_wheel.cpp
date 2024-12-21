#include<bits/stdc++.h> 
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int i=0,ans=0,j=n-1;
    while(i<j){
        if(a[i]+a[j]<=x){
            ans++;
            i++;
            j--;
        }
        else{
            if(a[i]>a[j]){
                ans++;
                i++;
            }
            else{
                ans++;
                j--;
            }
        }
    }
    if(i==j){
        ans++;
    }
    cout<<ans;
}