#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a;

// Hàm kiểm tra tính thuận nghịch (đối xứng)
bool isPalindrome() {
    for (int i = 0; i < n / 2; i++) {
        if (a[i] != a[n - 1 - i]) {
            return false; // Khác nhau phát là báo sai luôn
        }
    }
    return true; // Nếu duyệt qua hết mà không có lỗi thì là xâu thuận nghịch
}

// Hàm quay lui sinh xâu nhị phân
void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j; // Thử điền 0 hoặc 1 vào vị trí thứ i
        
        if (i == n - 1) { 
            // Nếu đã điền đủ n phần tử thì mang đi kiểm tra
            if (isPalindrome()) {
                // In ra nếu đúng
                for (int k = 0; k < n; k++) {
                    cout << a[k] << " ";
                }
                cout << endl;
            }
        } else {
            // Nếu chưa đủ, đệ quy điền tiếp vị trí i + 1
            Try(i + 1);
        }
    }
}

int main() {
    // Đọc số lượng bộ test nếu đề có yêu cầu (ở ví dụ này chỉ nhập 1 lần n)
    cin >> n;
    
    // Cấp phát đủ n phần tử cho vector
    a.resize(n); 
    
    // Bắt đầu sinh từ vị trí số 0
    Try(0); 
    
    return 0;
}