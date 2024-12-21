#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,sum;
    cin>>n>>sum;
    vector<long long>arr(n);
    vector<pair<long long,long long>>temp(n);
    for(long long i=0;i<n;i++){
        cin>>arr[i];
        temp[i]={arr[i],i+1};
    }
    sort(temp.begin(),temp.end());
    for(int h=0;h<n-3;h++){
        for(long long i=h+1;i<n-2;i++){
            long long req_sum=sum-temp[h].first-temp[i].first;
            long long j=i+1;
            long long k=n-1;
            while(j<k){
                if(temp[j].first+temp[k].first==req_sum){
                    vector<long long>v;
                    v.push_back(temp[h].second);
                    v.push_back(temp[i].second);
                    v.push_back(temp[j].second);
                    v.push_back(temp[k].second);
                    sort(v.begin(),v.end());
                    cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3];
                    return 0;
                }
                else if(temp[j].first+temp[k].first<req_sum){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
    }    
    cout<<"IMPOSSIBLE";
    return 0;
}