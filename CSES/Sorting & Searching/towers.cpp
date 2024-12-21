#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        auto it=upper_bound(v.begin(),v.end(),num);
        if(it==v.end()){
            v.push_back(num);
        }
        else{
            *it=num;
        }
    }
    cout<<v.size();
}