#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");

    int t, n, m;
    fin >> t >> n >> m;

    vector<vector<int>> B(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            fin >> B[i][j];

    vector<int> deg(n + 1, 0);
    vector<vector<int>> adj(n + 1);

    for (int j = 1; j <= m; j++) {
        vector<int> endpoints;
        for (int i = 1; i <= n; i++)
            if (B[i][j] == 1)
                endpoints.push_back(i);
        if (endpoints.size() == 2) {
            int u = endpoints[0], v = endpoints[1];
            deg[u]++;
            deg[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    if (t == 1) {
        for (int i = 1; i <= n; i++)
            fout << deg[i] << (i < n ? " " : "\n");
        int pendant = 0;
        for (int i = 1; i <= n; i++)
            if (deg[i] == 1) pendant++;
        fout << pendant << "\n";
    } else {
        for (int i = 1; i <= n; i++) {
            fout << deg[i];
            for (int j = 0; j < (int)adj[i].size(); j++)
                fout << " " << adj[i][j];
            fout << "\n";
        }
    }

    fin.close();
    fout.close();
    return 0;
}
