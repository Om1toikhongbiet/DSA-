`#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> res;

void gen(int pos, int ones, string cur) {
    if (ones > k || (n - pos) < (k - ones)) return;
    if (pos == n) {
        if (ones == k) res.push_back(cur);
        return;
    }
    gen(pos + 1, ones, cur + "0");
    gen(pos + 1, ones + 1, cur + "1");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        res.clear();
        gen(0, 0, "");
        for (auto& s : res) cout << s << "\n";
    }
    return 0;
}
