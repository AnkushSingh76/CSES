#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int temp;
    set<int>s;
    for(int i=0;i<n;i++){
        cin>>temp;
        s.insert(temp);
    }
    cout<<s.size()<<endl;
}