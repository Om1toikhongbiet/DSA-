#include <bits/stdc++.h>
using namespace std;

map<long long, long long> f;
long long mod = 1e9 + 7;

long long fibo(long long n) {
    if (f.count(n)) return f[n];
    long long k = n / 2;
    long long f1 = fibo(k), f2 = fibo(k + 1);
    if (n % 2 == 0) return f[n] = (f1 * (2 * f2 - f1 + mod)) % mod;
    return f[n] = (f1 * f1 + f2 * f2) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    f[0] = 0; f[1] = 1; f[2] = 1;
    int t;
    if (cin >> t) {
        while (t--) {
            long long n;
            cin >> n;
            cout << fibo(n) << "\n";
        }
    }
    return 0;
}
