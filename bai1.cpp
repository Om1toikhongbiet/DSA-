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
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        
        map<long long, int> freq;
        for (int i = 0; i < n; i++) freq[a[i]]++;
        
    
        long long ans = -1;
        for (int i = 0; i < n; i++) {
            if (freq[a[i]] > 1) {
                ans = a[i];
                break;
            }
        }
        
        if (ans == -1) cout << "NO\n";
        else cout << ans << "\n";
    }
    
    return 0;
}
