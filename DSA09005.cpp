#include <bits/stdc++.h>
using namespace std;
vector<int> adj[105];
int n,m,s;
bool visited[105];
void bfs(int s)
{
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while(!q.empty())
	{
		int v =q.front();
		q.pop();
		cout << v << " ";
		for(auto c : adj[v])
		{
			if(!visited[c])
			{
				q.push(c);
				visited[c] = true;
			}
		}
	}
}
void setup()
{
	memset(visited,false,sizeof(visited));
	cin >> n >> m >> s;
	for(int i = 1; i <= m;i++)
	{
		int u,v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}
int main()
{
	int t; cin >> t;
	while(t--)
	{
		setup();
		bfs(s);
	}
	return 0;
}
