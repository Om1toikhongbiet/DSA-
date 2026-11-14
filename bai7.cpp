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

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        if (edges[i].u > edges[i].v) {
            swap(edges[i].u, edges[i].v);
        }
        edges[i].id = i + 1;
    }

    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return tie(a.w, a.u, a.v, a.id) > tie(b.w, b.u, b.v, b.id);
    });

    DSU dsu(n);
    long long total_weight = 0;
    vector<pair<int, int>> mst_edges;

    for (const auto& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            total_weight += e.w;
            mst_edges.push_back({e.u, e.v});
            if ((int)mst_edges.size() == n - 1) break;
        }
    }

    cout << total_weight << "\n";
    for (const auto& p : mst_edges) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
