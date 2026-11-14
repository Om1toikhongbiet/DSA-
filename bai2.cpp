#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    long long w;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (freopen("DT.INP", "r", stdin)) {}
    if (freopen("DT.OUT", "w", stdout)) {}

    int q;
    if (!(cin >> q)) return 0;
    int n, m, s, t, k;
    cin >> n >> m >> s >> t >> k;
    vector<bool> forbidden(n + 1, false);
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        forbidden[x] = true;
    }

    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (const auto& e : adj[u]) {
            if (forbidden[e.to]) continue;
            if (dist[u] + e.w < dist[e.to]) {
                dist[e.to] = dist[u] + e.w;
                parent[e.to] = u;
                pq.push({dist[e.to], e.to});
            }
        }
    }

    if (q == 1) {
        cout << dist[t] << "\n";
    } else {
        vector<int> path;
        for (int cur = t; cur != -1; cur = parent[cur]) {
            path.push_back(cur);
            if (cur == s) break;
        }
        reverse(path.begin(), path.end());
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i] << (i + 1 == path.size() ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}
