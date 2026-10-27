#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> x(n);
        for (int i = 0; i < n; i++) cin >> x[i];
        next_permutation(x.begin(), x.end());
        for (int i = 0; i < n; i++) cout << x[i] << " \n"[i == n - 1];
    }
    return 0;
}
