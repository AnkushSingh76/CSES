#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,k;
    cin>>n>>k;
    vector<long long>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    multiset<long long>left,right;
    auto balance=[&](){
        while(left.size()>right.size()){
            right.insert(*left.rbegin());
            left.erase(prev(left.end()));
        }
        while(left.size()<right.size()){
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    };
    for(long long i=0;i<k;i++){
        left.insert(arr[i]);
    }
    balance();
    cout<<*left.rbegin()<<" ";
    for(long long i=k;i<n;i++){
        long long out=arr[i-k];
        if(left.count(out)){
            left.erase(left.find(out));
        }
        else{
            right.erase(right.find(out));
        }
        if(arr[i]<=*left.rbegin()) {
            left.insert(arr[i]);
        } 
        else{
            right.insert(arr[i]);
        }
        balance();
        cout << *left.rbegin() << " ";
    }
}