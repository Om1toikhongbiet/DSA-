#include <bits/stdc++.h>
using namespace std;

int n;
int A[105][105];
bool visited[105];

vector<int> bfs(int start) {
    vector<int> comp;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        comp.push_back(u);
        for (int v = 1; v <= n; v++) {
            if (A[u][v
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            ] && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    sort(comp.begin(), comp.end());
    return comp;
}

int main() {
   


    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");

    int t;
    fin >> t >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fin >> A[i][j];

    memset(visited, false, sizeof(visited));

    vector<vector<int>> components;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components.push_back(bfs(i));
        }
    }

    int lt = components.size();

    if (t == 1) {
        fout << lt << " " << (lt == 1 ? 1 : 0) << "\n";
    } else {
        int best = 0;
        for (int i = 1; i < (int)components.size(); i++) {
            if (components[i].size() > components[best].size()) {
                best = i;
            }
        }
        fout << components[best].size() << "\n";
        for (int i = 0; i < (int)components[best].size(); i++)
            fout << components[best][i] << (i + 1 < (int)components[best].size() ? " " : "\n");
    }

    fin.close();
    fout.close();
    return 0;
}