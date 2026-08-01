#include<bits/stdc++.h>
using namespace std;
void solve(){
   string s;
   cin >> s;
   //delete first 0
    size_t ind0 = s.find('0');
    if(ind0 != string::npos){
        s.erase(ind0, 1);
    }
 
    //delete first 1;
    size_t ind1 = s.find('1');
    if(ind1 != string::npos){
        s.erase(ind1, 1);
    }
 
    cout << s << endl;
}
int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}