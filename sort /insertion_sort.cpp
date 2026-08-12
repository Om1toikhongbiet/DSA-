 #include <bits/stdc++.h>
using namespace std;

int main () {
    int n; 
    cin >> n;
    vector<int> a(n); // Khuyên dùng vector thay vì int a[n] để tránh lỗi tùy thuộc vào compiler
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Thuật toán Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int lc = i; // lc (min_index) giả sử là phần tử đầu tiên của đoạn chưa sắp xếp
        
        // Vòng lặp tìm phần tử nhỏ nhất trong mảng còn lại
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[lc]) {
                lc = j; // Cập nhật lại vị trí nhỏ nhất
            }
        }
        
        // Đổi chỗ phần tử nhỏ nhất tìm được với phần tử ở vị trí i
        swap(a[i], a[lc]); 
        
        // In ra theo format của đề bài ngay sau mỗi bước
        cout << "Buoc " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << a[k] << " ";
        }
        cout << endl;
    }
    
    return 0;
}