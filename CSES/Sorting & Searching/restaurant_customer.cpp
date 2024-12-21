#include<bits/stdc++.h> 
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, -1});
    }
    int ans = 0;
    int temp = 0;
    sort(v.begin(), v.end());
    for (int i = 0; i < 2 * n; i++) {
        temp += v[i].second;
        ans = max(ans, temp);
    }
    cout << ans << endl;
}
