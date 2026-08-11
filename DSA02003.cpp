#include <bits/stdc++.h>
using namespace std;

long long n, a[12][12], ok = 0;

void BackTrack(string s, long long i, long long j) {
    // Điều kiện dừng: tới đích
    if(i == (n - 1) && j == (n - 1)) {
        cout << s << " ";
        ok = 1;
        return;
    }
    // Ưu tiên đi xuống (D) trước để đảm bảo thứ tự từ điển
    if(i + 1 < n && a[i + 1][j] == 1) BackTrack(s + "D", i + 1, j);
    // Sau đó đi sang phải (R)
    if(j + 1 < n && a[i][j + 1] == 1) BackTrack(s + "R", i, j + 1);
}

int main() {
    int test; 
    cin >> test;
    while (test--) {
        cin >> n;
        for(long long i = 0; i < n; i++) {
            for(long long j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        
        ok = 0; // Sửa lỗi 1: Reset cờ đánh dấu cho test case mới
        
        // Sửa lỗi 3: Kiểm tra tính hợp lệ của ô xuất phát và ô đích
        if (a[0][0] == 1 && a[n-1][n-1] == 1) {
            BackTrack("", 0, 0);
        }
        
        // Nếu không có đường đi (ok vẫn bằng 0), in ra -1
        if(!ok) cout << -1;
        
        cout << endl; // Sửa lỗi 2: Xuống dòng sau khi kết thúc một test case
    }
    return 0;
}