#include<bits/stdc++.h>
using namespace std;
int main(){
    int x,n;
    cin>>x>>n;
    set<int>s;
    multiset<int>s1;
    s.insert(0);
    s.insert(x);
    s1.insert(x-0);
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        s.insert(val);
        auto it=s.find(val);
        int prv=*prev(it);
        int nxt=*next(it);
        s1.erase(s1.find(nxt-prv));
        s1.insert(val-prv);
        s1.insert(nxt-val);
        cout<<*s1.rbegin()<<'\n';
    }
}