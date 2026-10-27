#include <iostream>

using namespace std;

long long f[93];

void init() {
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= 92; ++i) {
        f[i] = f[i - 2] + f[i - 1];
    }
}

char solve(int n, long long k) {
    while (n > 2) {
        if (k <= f[n - 2]) {
            n -= 2;
        } else {
            k -= f[n - 2];
            n -= 1;
        }
    }
    if (n == 1) return 'A';
    return 'B';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        long long k;
        cin >> n >> k;
        cout << solve(n, k) << "\n";
    }

    return 0;
}
