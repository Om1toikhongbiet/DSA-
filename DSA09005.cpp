#include <bits/stdc++.h>
using namespace std;

// Hàm duyệt đồ thị theo chiều rộng (BFS) bắt đầu từ đỉnh start
void bfs(int start, int v, const vector<vector<int>>& adj) {
    vector<bool> visited(v + 1, false);
    queue<int> q;

    // Đưa đỉnh bắt đầu vào hàng đợi và đánh dấu đã thăm
    q.push(start);
    visited[start] = true;

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        // Duyệt các đỉnh kề với u theo thứ tự tăng dần
        for (int neighbor : adj[u]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    // In danh sách các đỉnh theo thứ tự duyệt BFS
    for (size_t i = 0; i < order.size(); i++) {
        cout << order[i] << (i + 1 == order.size() ? "" : " ");
    }
    cout << "\n";
}

void solve() {
    int v, e, u;
    if (!(cin >> v >> e >> u)) return;

    // Khởi tạo danh sách kề cho đồ thị vô hướng
    vector<vector<int>> adj(v + 1);
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); // Đồ thị vô hướng
    }

    // Sắp xếp danh sách kề để ưu tiên duyệt đỉnh có thứ tự nhỏ hơn
    for (int i = 1; i <= v; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    bfs(u, v, adj);
}

int main() {
    // Tối ưu hóa I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }

    return 0;
}
