#include <bits/stdc++.h>
using namespace std;

// Khai báo X ở phạm vi toàn cục để hàm cmp có thể sử dụng được
int X; 

// Hàm so sánh tùy chỉnh
bool cmp(int a, int b) {
    // Chỉ so sánh theo giá trị tuyệt đối của hiệu số
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
        
        // Dùng stable_sort để giữ nguyên thứ tự ban đầu nếu abs bằng nhau
        stable_sort(a.begin(), a.end(), cmp);
        
        // In kết quả
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}