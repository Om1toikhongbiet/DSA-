 #include <iostream>
    #include <vector>
    #include <algorithm>
    
    using namespace std;
    
    int A[9][9];
    bool col[9];         // Đánh dấu cột
    bool diag1[18];      // Đánh dấu đường chéo xuôi: i - j + 8
    bool diag2[18];      // Đánh dấu đường chéo ngược: i + j
    int max_score;
    int current_score;
    
    void Try(int row) {
        // Thử đặt quân hậu ở hàng 'row' vào cột 'c'
        for (int c = 1; c <= 8; ++c) {
            // Kiểm tra xem vị trí (row, c) có bị khống chế không
            if (!col[c] && !diag1[row - c + 8] && !diag2[row + c]) {
                // Đặt quân hậu vào (row, c)
                col[c] = true;
                diag1[row - c + 8] = true;
                diag2[row + c] = true;
                current_score += A[row][c];
    
                // Nếu đã đặt xong 8 quân hậu (ở cả 8 hàng)
                if (row == 8) {
                    max_score = max(max_score, current_score);
                } else {
                    Try(row + 1); // Tiếp tục đặt quân hậu cho hàng kế tiếp
                }
    
                // Quay lui (Backtrack): khôi phục lại trạng thái ban đầu
                col[c] = false;
                diag1[row - c + 8] = false;
                diag2[row + c] = false;
                current_score -= A[row][c];
            }
        }
    }
    
    void solve(int test_num) {
        // Nhập ma trận bàn cờ 8x8
        for (int i = 1; i <= 8; ++i) {
            for (int j = 1; j <= 8; ++j) {
                cin >> A[i][j];
            }
        }
    
        // Reset trạng thái trước mỗi bộ test
        max_score = 0;
        current_score = 0;
        fill(col, col + 9, false);
        fill(diag1, diag1 + 18, false);
        fill(diag2, diag2 + 18, false);
    
        // Bắt đầu quay lui từ hàng 1
        Try(1);
    
        // In theo định dạng yêu cầu của đề: "Test <k>: <max_score>"
        cout << "Test " << test_num << ": " << max_score << "\n";
    }

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int T;
        if (cin >> T) {
            for (int t = 1; t <= T; ++t) {
                solve(t);
            }
        }
        return 0;
    }