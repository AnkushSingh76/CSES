#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>v,int n){
    vector<int>temp;
    temp.push_back(v[0]);
    int len=1;
    for(int i=1;i<n;i++){
        if(v[i]>temp.back()){
            temp.push_back(v[i]);
            len++;
        }
        else{
            int pos=lower_bound(temp.begin(),temp.end(),v[i])-temp.begin();
            temp[pos]=v[i];
        }
    }
    return len;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<solve(v,n);
}    
