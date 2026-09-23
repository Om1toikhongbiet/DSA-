#include <bits/stdc++.h>
using namespace std;


int X; 


bool cmp(int a, int b) {
   
    return abs(X - a) < abs(X - b); 
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n >> X;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        
        stable_sort(a.begin(), a.end(), cmp);
        
        // In kết quả
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}