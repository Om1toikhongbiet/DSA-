#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;

struct Edge {
    int to;
    long long w;
};

void spfa(int src, int n, const vector<vector<Edge>>& adj, vector<long long>& dist, vector<int>& parent) {
    dist.assign(n + 1, INF);
    parent.assign(n + 1, -1);
    vector<bool> in_q(n + 1, false);
    queue<int> q;

    dist[src] = 0;
    q.push(src);
    in_q[src] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_q[u] = false;

        for (const auto& e : adj[u]) {
            if (dist[u] != INF && dist[u] + e.w < dist[e.to]) {
                dist[e.to] = dist[u] + e.w;
                parent[e.to] = u;
                if (!in_q[e.to]) {
                    q.push(e.to);
                    in_q[e.to] = true;
                }
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
    int n, m, s, t, k;
    cin >> n >> m >> s >> t >> k;

    vector<int> candidates(k);
    for (int i = 0; i < k; ++i) {
        cin >> candidates[i];
    }

    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<long long> dist_s;
    vector<int> parent_s;
    spfa(s, n, adj, dist_s, parent_s);

    long long best_cost = INF;
    int best_x = -1;

    for (int x : candidates) {
        if (dist_s[x] >= INF) continue;
        vector<long long> dist_x;
        vector<int> parent_x;
        spfa(x, n, adj, dist_x, parent_x);
        if (dist_x[t] >= INF) continue;
        long long cur_cost = dist_s[x] + dist_x[t];
        if (cur_cost < best_cost || (cur_cost == best_cost && (best_x == -1 || x < best_x))) {
            best_cost = cur_cost;
            best_x = x;
        }
    }

    if (q == 1) {
        cout << best_cost << "\n";
    } else {
        vector<long long> dist_x;
        vector<int> parent_x;
        spfa(best_x, n, adj, dist_x, parent_x);

        vector<int> p1 = get_path(s, best_x, parent_s);
        vector<int> p2 = get_path(best_x, t, parent_x);
        vector<int> full = p1;
        for (size_t i = 1; i < p2.size(); ++i) {
            full.push_back(p2[i]);
        }
        cout << best_x << "\n";
        for (size_t i = 0; i < full.size(); ++i) {
            cout << full[i] << (i + 1 == full.size() ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}
