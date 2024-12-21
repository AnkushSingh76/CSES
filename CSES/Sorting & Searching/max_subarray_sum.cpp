#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long currsum=0;
    long long maxsum=0;
    long long c=0;
    long long maxsum1=-1e15;
    for(long long i=0;i<n;i++){
        long long temp;
        cin>>temp;
        currsum+=temp;
        maxsum=max(maxsum,currsum);
        if(temp<0){
            c++;
            maxsum1=max(maxsum1,temp);
        }
        if(currsum<0){
            currsum=0;
        }
    }
    if(c==n){
        cout<<maxsum1;
        return 0;
    }
    cout<<maxsum;
}