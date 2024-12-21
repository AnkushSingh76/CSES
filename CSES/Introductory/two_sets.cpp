#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long sum=(n*(n+1))/2;
    if(sum%2==1){
        cout<<"NO";
    }
    else{
        vector<long long>v1,v2;
        sum=sum/2;
        for(long long i=n;i>=1;i--){
            if(i<=sum){
                v1.push_back(i);
                sum=sum-i;
            }
            else{
                v2.push_back(i);
            }
        }
        if(v1.size()>0&&v2.size()>0){
            reverse(v1.begin(),v1.end());
            reverse(v2.begin(),v2.end());
            cout<<"YES"<<endl;
            cout<<v1.size()<<endl;
            for(long long it:v1){
                cout<<it<<" ";
            }
            cout<<endl;
            cout<<v2.size()<<endl;
            for(long long it:v2){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"NO";
        }
    }
}