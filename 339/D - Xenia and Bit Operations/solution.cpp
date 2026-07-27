#include<bits/stdc++.h>
using namespace std;
void build(int ind, int low, int high, vector<int>&arr, vector<int>&segTree, int orr){
    if(low == high){
        segTree[ind] = arr[low];
        return;
    }
 
    int mid = low + (high - low)/2;
    build(2*ind+1, low, mid, arr, segTree,  !orr);
    build(2*ind+2, mid+1, high, arr,segTree,  !orr);
    if(orr) segTree[ind] = segTree[2*ind+1] | segTree[2*ind+2];
    else segTree[ind] = segTree[2*ind+1] ^ segTree[2*ind+2];
}
void update(int ind, int low, int high, int i, int val, vector<int>&segTree, int orr){
    if(low == high){
        segTree[ind] = val;
        return;
    }
 
    int mid = low + (high - low)/2;
    if(i <= mid) update(2*ind+1, low, mid, i, val, segTree,!orr);
    else update(2*ind+2, mid+1, high, i, val, segTree,!orr);
 
    if(orr) segTree[ind] = segTree[2*ind+1] | segTree[2*ind+2];
    else segTree[ind] = segTree[2*ind+1] ^ segTree[2*ind+2];
}
void solve(){
    int n, q;
    cin >> n >> q;
    int s = pow(2, n);
    vector<int>arr(s);
    for(int i=0; i<s; i++){
        cin >> arr[i];
    }
    vector<int>segTree(4*s);
    if(n%2==0){
        build(0, 0, s-1, arr, segTree, 0);
    }
    else{
        build(0, 0, s-1, arr, segTree, 1);
    }
    while(q--){
        int i, val;
        cin >> i >> val;
        i--;
        if(n%2==0){
            update(0, 0, s-1, i, val, segTree, 0);
        }
        else{
            update(0, 0, s-1, i, val, segTree, 1);
        }
        cout << segTree[0] << endl;
    }
}
int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}