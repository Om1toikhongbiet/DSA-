#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, v;
    cin >> n >> v;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<int> dp(v + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = v; j >= a[i]; j--) {
            dp[j] = max(dp[j], dp[j - a[i]] + c[i]);
        }
    }
    cout << dp[v] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}