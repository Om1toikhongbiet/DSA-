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
        vector<int> s(n), f(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        for (int i = 0; i < n; i++) cin >> f[i];

        vector<pair<int,int>> acts(n);
        for (int i = 0; i < n; i++) acts[i] = {f[i], s[i]};
        sort(acts.begin(), acts.end());

        int count = 0, lastEnd = -1;
        for (auto& [fi, si] : acts) {
            if (si >= lastEnd) {
                count++;
                lastEnd = fi;
            }
        }
        cout << count << "\n";
    }
    return 0;
}
