#include<bits/stdc++.h>
using namespace std;
 
 
void solve(){
    int n;
    string s;
    cin >> n;
    cin >> s;
 
    vector<int>freq(26, 0);
    int ans = 0;
    for(int i =0; i<n; i++){
        if(freq[s[i]-'a'] == 0){
            freq[s[i]-'a'] = 1;
            ans += (n-i);
        }
        //else
        //donot count as the strings which this letter will continute would have been 
        // already contributed by the first occurence of this letter
    }
 
    cout << ans << endl;
}
int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}