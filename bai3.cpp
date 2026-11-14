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

vector<int> combine(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3) {
    vector<int> res = p1;
    for (size_t i = 1; i < p2.size(); ++i) res.push_back(p2[i]);
    for (size_t i = 1; i < p3.size(); ++i) res.push_back(p3[i]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (freopen("DT.INP", "r", stdin)) {}
    if (freopen("DT.OUT", "w", stdout)) {}

    int q;
    if (!(cin >> q)) return 0;
    int n, m, s, a, b, t;
    cin >> n >> m >> s >> a >> b >> t;

    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<long long> dist_s, dist_a, dist_b;
    vector<int> parent_s, parent_a, parent_b;
    spfa(s, n, adj, dist_s, parent_s);
    spfa(a, n, adj, dist_a, parent_a);
    spfa(b, n, adj, dist_b, parent_b);

    long long cost1 = INF;
    if (dist_s[a] < INF && dist_a[b] < INF && dist_b[t] < INF) {
        cost1 = dist_s[a] + dist_a[b] + dist_b[t];
    }

    long long cost2 = INF;
    if (dist_s[b] < INF && dist_b[a] < INF && dist_a[t] < INF) {
        cost2 = dist_s[b] + dist_b[a] + dist_a[t];
    }

    if (q == 1) {
        cout << min(cost1, cost2) << "\n";
    } else {
        vector<int> ans;
        if (cost1 <= cost2) {
            ans = combine(get_path(s, a, parent_s), get_path(a, b, parent_a), get_path(b, t, parent_b));
        } else {
            ans = combine(get_path(s, b, parent_s), get_path(b, a, parent_b), get_path(a, t, parent_a));
        }
        for (size_t i = 0; i < ans.size(); ++i) {
            cout << ans[i] << (i + 1 == ans.size() ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}
