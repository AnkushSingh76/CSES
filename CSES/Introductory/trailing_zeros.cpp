#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i=1;
    int cnt=0;
    while(1){
        int temp=n/pow(5,i);
        if(temp==0){
            break;
        }
        cnt+=temp;
        i++;
    }
    cout<<cnt;
}