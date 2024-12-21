#include<bits/stdc++.h>
using namespace std;
int main(){ 
    long long n,k;
    cin>>n>>k;
    vector<long long>arr(n);
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<long long>temp(k);
    vector<long long>ans;
    int i=0;
    int j=0;
    while(j<n){
        long long idx=lower_bound(temp.begin(),temp.end(),arr[j])-temp.begin();
        if(j-i+1<k){
            temp[idx]=arr[j];
            j++;
        }
        else if(j-i+1==k){
            temp[idx]=arr[j];
            if(k%2==1){
                ans.push_back(temp[k/2]);
            }
            else{
                ans.push_back(min(temp[k/2],temp[k/2-1]));
            }
            j++;
            i++;
        }
    }
    for(auto it:ans){
        cout<<it<<" ";
    }
}