#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long a;
        cin>>a;
        long long digits=1,count=9,start=1;   //1-9:9 digits   10-99:180 digits  100-999:2700 digits and so on
        while(a>digits*count){
            a=a-digits*count;
            digits++;
            count=count*10;
            start=start*10;
        }
        start=start+(a-1)/digits;         //ex: 10000 upon iteration, a=7111 and digits=4
        string s=to_string(start);        //so required no. is 7111th digit in 4 digit no. series
        cout<<s[(a-1)%digits]<<endl;      //exact no. will be start of 4 digit nos.(1000)+(7111/4)-1
    }                                     //to find the exact position in 2776, we will find 2776[7111%4]=7
}