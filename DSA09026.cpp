#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
vector<int> adj[MAX];
bool visited[MAX];
int parentNode[MAX];

void bfs(int s, int t) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
-
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == t) break;

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parentNode[v] = u;
                q.push(v);
            }
        }
    }
}

void solve() {
    int v, e, s, t;
    if (!(cin >> v >> e >> s >> t)) return;

    for (int i = 1; i <= v; i++) {
        adj[i].clear();
        visited[i] = false;
        parentNode[i] = 0;
    }

    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // Đồ thị có hướng
    }

    bfs(s, t);

    if (!visited[t]) {
        cout << -1 << "\n";
    } else {
        vector<int> path;
        for (int curr = t; curr != 0; curr = parentNode[curr]) {
            path.push_back(curr);
        }
        reverse(path.begin(), path.end());
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i] << (i + 1 == path.size() ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
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
