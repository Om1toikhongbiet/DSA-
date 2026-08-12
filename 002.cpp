#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a; // Mảng chứa dữ liệu đầu vào
vector<int> x; // Mảng lưu cấu hình nhị phân (0 hoặc 1)
int count_ans = 0; // Biến đếm số lượng dãy con thỏa mãn

void Try(int i) {
    // Thử 2 giá trị 0 và 1 cho vị trí x[i]
    for (int j = 0; j <= 1; j++) {
        x[i] = j;
        
        // Nếu đã điền đủ N phần tử cho cấu hình nhị phân
        if (i == n - 1) {
            int sum = 0;
            // Duyệt lại cấu hình, chỗ nào là số 1 thì cộng giá trị A tương ứng vào
            for (int c = 0; c < n; c++) {
                if (x[c] == 1) {
                    sum += a[c];
                }
            }
            
            // Kiểm tra tổng, nếu bằng K thì in ra dãy con đó
            if (sum == k) {
                for (int c = 0; c < n; c++) {
                    if (x[c] == 1) {
                        cout << a[c] << " ";
                    }
                }
                cout << endl;
                count_ans++; // Tăng biến đếm lên 1
            }
        } 
        // Nếu chưa điền đủ, gọi đệ quy để điền tiếp vị trí i + 1
        else {
            Try(i + 1);
        }
    }
}

int main() {
    cin >> n >> k;
    
    // Cấp phát đủ N phần tử cho 2 vector
    a.resize(n);
    x.resize(n);
    
    // Nhập mảng A
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Gọi hàm quay lui bắt đầu từ vị trí 0
    Try(0);
    
    // In ra tổng số dãy con tìm được ở dòng cuối cùng
    cout << count_ans << endl;
    
    return 0;
}