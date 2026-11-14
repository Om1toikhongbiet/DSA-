#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

struct Edge {
    int to;
    long long w;
};

void dijkstra(int src, int n, const vector<vector<Edge>>& adj, vector<long long>& dist, vector<int>& parent) {
    dist.assign(n + 1, INF);
    parent.assign(n + 1, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (const auto& e : adj[u]) {
            if (dist[u] + e.w < dist[e.to]) {
                dist[e.to] = dist[u] + e.w;
                parent[e.to] = u;
                pq.push({dist[e.to], e.to});
            }
        }
    }
}

vector<int> get_path(int src, int dst, const vector<int>& parent) {
    vector<int> path;
    for (int cur = dst; cur != -1; cur = parent[cur]) {
        path.push_back(cur);
        if (cur == src) break;
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (freopen("DT.INP", "r", stdin)) {}
    if (freopen("DT.OUT", "w", stdout)) {}

    int q;
    if (!(cin >> q)) return 0;
    int n, m, s, p, t;
    cin >> n >> m >> s >> p >> t;
    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<long long> dist_s, dist_p;
    vector<int> parent_s, parent_p;
    dijkstra(s, n, adj, dist_s, parent_s);
    dijkstra(p, n, adj, dist_p, parent_p);

    if (q == 1) {
        cout << dist_s[p] + dist_p[t] << "\n";
    } else {
        vector<int> p1 = get_path(s, p, parent_s);
        vector<int> p2 = get_path(p, t, parent_p);
        vector<int> full = p1;
        for (size_t i = 1; i < p2.size(); ++i) {
            full.push_back(p2[i]);
        }
        for (size_t i = 0; i < full.size(); ++i) {
            cout << full[i] << (i + 1 == full.size() ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}
