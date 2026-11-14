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
    int n, m, a, b, t;
    cin >> n >> m >> a >> b >> t;

    vector<vector<Edge>> adj(n + 1), radj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        radj[v].push_back({u, w});
    }

    vector<long long> dist_a, dist_b, dist_t_rev;
    vector<int> parent_a, parent_b, parent_t_rev;
    dijkstra(a, n, adj, dist_a, parent_a);
    dijkstra(b, n, adj, dist_b, parent_b);
    dijkstra(t, n, radj, dist_t_rev, parent_t_rev);

    long long best_cost = INF;
    int best_x = -1;

    for (int x = 1; x <= n; ++x) {
        if (dist_a[x] >= INF || dist_b[x] >= INF || dist_t_rev[x] >= INF) continue;
        long long cur_cost = dist_a[x] + dist_b[x] + dist_t_rev[x];
        if (cur_cost < best_cost) {
            best_cost = cur_cost;
            best_x = x;
        }
    }

    if (q == 1) {
        cout << best_cost << "\n";
    } else {
        vector<long long> dist_x;
        vector<int> parent_x;
        dijkstra(best_x, n, adj, dist_x, parent_x);

        vector<int> path_a = get_path(a, best_x, parent_a);
        vector<int> path_b = get_path(b, best_x, parent_b);
        vector<int> path_t = get_path(best_x, t, parent_x);

        cout << best_x << "\n";
        for (size_t i = 0; i < path_a.size(); ++i) {
            cout << path_a[i] << (i + 1 == path_a.size() ? "" : " ");
        }
        cout << "\n";
        for (size_t i = 0; i < path_b.size(); ++i) {
            cout << path_b[i] << (i + 1 == path_b.size() ? "" : " ");
        }
        cout << "\n";
        for (size_t i = 0; i < path_t.size(); ++i) {
            cout << path_t[i] << (i + 1 == path_t.size() ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}
