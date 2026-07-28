#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
 
    vector<int> prefix(n, 0), bestb(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            prefix[i] = a[i];
            bestb[i] = b[i];
        }
        else
        {
            prefix[i] = prefix[i - 1] + a[i];
            bestb[i] = max(bestb[i - 1], b[i]);
        }
    }
 
    int ans = 0;
    int curr;
    for (int i = 0; i < min(n, k); i++)
    {
        // maximum points that i can make if I stop wxploriing further quests at this index
        curr = prefix[i] + ((k-i-1)*bestb[i]);
        ans = max(ans, curr);
    }
    cout << ans << endl;
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