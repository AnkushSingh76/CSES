#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector<long long>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    stack<long long>st;
    st.push(0);
    long long i=0;
    while(i<n){
        while(st.top()!=0&&arr[st.top()-1]>=arr[i]){  
            st.pop();
        }
        cout<<st.top()<<" ";
        st.push(i+1);
        i++;
    }
}