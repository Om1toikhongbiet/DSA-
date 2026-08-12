#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    bool stop = false;
    int step = 1;
    vector<string> results; 

    while (stop == false) {
        stop = true;
        
        for (int j = 0; j < n - 1; j++) {
            if (v[j] > v[j + 1]) { 
                swap(v[j], v[j + 1]); 
                stop = false; 
            }
        }

        // Thoát ngay nếu không có phép hoán vị nào (mảng đã sắp xếp xong)
        if (stop) break;

        // Lưu vào chuỗi s
        string s = "Buoc " + to_string(step) + ":";
        for (int x : v) {
            s += " " + to_string(x);
        }
        
        results.push_back(s);
        step++;
    }

    // In ngược mảng kết quả
    for (int i = results.size() - 1; i >= 0; i--) {
        cout << results[i] << "\n";
    }
}

int main() {
    // Đọc số lượng bộ test
    int t;
    cin >> t;
    while (t--) {
        solve(); // Chạy hàm xử lý cho từng bộ test
    }
    return 0;
}