#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int ,int> &a, pair<int ,int> &b){
    return a.first < b.first;
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<long long, int>>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<long long> prefix(n);
    for (int i = 0; i < n; i++){
        if (i == 0){
            prefix[i] = a[i].first;
        }
        else{
            prefix[i] = a[i].first + prefix[i - 1];
        }
    }
    vector<int> ans(n);
    // for(int i =0; i<n; i++){ //over TC of this loop is NlogN, because j jump lower_bound posistions
 
    //     int j = i;
    //     int removedCnt = i;
    //     while(j < n){
    //         // // pair<long long, int> temp = {prefix[j]+1, INT_MIN}; 
    //         // //way to find lower_bound in this kind of pair<int, int>vector
    //         // //we did prefix[i]+1 --> to find last value <= preifx[i] --> this is a common STL Trick
    //         // int ind = lower_bound(a.begin(), a.end(), temp) - a.begin(); //logn
    //         // ind--;
 
    //         //or we coundhave done upper_bound() and then ind--;
    //         pair<long long, int> temp = {prefix[j], INT_MAX};
    //         int ind = upper_bound(a.begin(), a.end(), temp) - a.begin(); //logn
    //         ind--;
 
    //         if(ind == j) break;
    //         removedCnt += ind-j;
    //         j = ind;
    //     }
    //     ans[a[i].second] = removedCnt;
 
    // }
    vector<int> reach(n);
    reach[n-1] = n-1;
    //reach[i] represnets if I have already reaced index i, how far can I go next
    for(int i =n-2; i>=0; i--){
        if(prefix[i] >=a[i+1].first){
            reach[i] = reach[i+1]; //can go uptill whatever reach[i+1] suggests
        }
        else{
            reach[i] = i; // cant go further next
        }
    }
 
    for(int i =0; i<n; i++){
        ans[a[i].second] = reach[i];
    }
 
    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }
 
    cout << endl;
}
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}