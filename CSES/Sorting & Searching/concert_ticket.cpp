#include<bits/stdc++.h> 
using namespace std;
int main(){
    long long n,m;
    cin>>n>>m;
    multiset<long long>s;
    for(long long i=0;i<n;i++){
        long long temp1;
        cin>>temp1;
        s.insert(temp1);
    }
    for(long long i=0;i<m;i++){
        long long temp;
        cin>>temp;
        auto it=s.upper_bound(temp);
        if(it==s.begin()){
            cout<<-1<<endl;
        }
        else{
            it--;
            cout<<*it<<endl;
            s.erase(it);    
        }
    }
}