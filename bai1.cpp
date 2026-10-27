#include <bits/stdc++.h>
using namespace std;

int main() {
    // Tối ưu tốc độ nhập/xuất trong C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t; // Nhập số lượng bộ test
    
    while (t--) {
        int n;
        cin >> n; // Nhập số lượng phần tử của dãy
        
        vector<long long> a(n);
        // Map dùng để đếm tần số xuất hiện của từng phần tử: freq[giá_trị] = số_lần_xuất_hiện
        map<long long, int> freq;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++; // Tăng số lần xuất hiện của phần tử a[i]
        }
        
        // Tìm phần tử đầu tiên (có chỉ số xuất hiện nhỏ nhất) mà có số lần xuất hiện > 1
        long long ans = -1; // Mặc định gán -1 là chưa tìm thấy
        for (int i = 0; i < n; i++) {
            if (freq[a[i]] > 1) { // Nếu phần tử a[i] xuất hiện nhiều hơn 1 lần
                ans = a[i];       // Lưu lại kết quả
                break;            // Dừng vòng lặp ngay vì đây là phần tử đầu tiên trong mảng
            }
        }
        
        // Nếu không có phần tử nào lặp lại thì in NO, ngược lại in ra giá trị tìm được
        if (ans == -1) cout << "NO\n";
        else cout << ans << "\n";
    }
    
    return 0;
}
