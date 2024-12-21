#include<bits/stdc++.h>
using namespace std;
void precompute(vector<long long>&divisors){
    for(int i=1;i<1000005;i++){
        for(int j=i;j<1000005;j+=i){
            divisors[j]++;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<long long>divisors(1000005);
    precompute(divisors);
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        cout<<divisors[n]<<endl;
    }
}