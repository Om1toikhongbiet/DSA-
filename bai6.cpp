#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long w;
    int id;
};

struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (freopen("DT.INP", "r", stdin)) {}
    if (freopen("DT.OUT", "w", stdout)) {}

    int t_query;
    if (!(cin >> t_query)) return 0;

    int n, m, excluded_id = -1;
    if (t_query == 1) {
        cin >> n >> m;
    } else {
        cin >> n >> m >> excluded_id;
    }

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        if (edges[i].u > edges[i].v) {
            swap(edges[i].u, edges[i].v);
        }
        edges[i].id = i + 1;
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        if (a.w != b.w) return a.w < b.w;
        if (a.u != b.u) return a.u < b.u;
        if (a.v != b.v) return a.v < b.v;
        return a.id < b.id;
    });

    DSU dsu(n);
    long long total_weight = 0;
    vector<pair<int, int>> mst_edges;

    for (const auto& e : edges) {
        if (t_query == 2 && e.id == excluded_id) continue;
        if (dsu.unite(e.u, e.v)) {
            total_weight += e.w;
            mst_edges.push_back({e.u, e.v});
            if ((int)mst_edges.size() == n - 1) break;
        }
    }

    if (t_query == 1) {
        cout << total_weight << "\n";
        for (const auto& p : mst_edges) {
            cout << p.first << " " << p.second << "\n";
        }
    } else {
        if ((int)mst_edges.size() == n - 1) {
            cout << total_weight << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
