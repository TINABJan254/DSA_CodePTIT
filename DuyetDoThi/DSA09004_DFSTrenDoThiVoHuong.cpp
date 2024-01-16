#include <bits/stdc++.h>

using namespace std;

#define EL "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

vi adj[1005];
bool visited[1005];

void DFS(int u){
	visited[u] = true;
	cout << u << ' ';
	for (int v : adj[u]){
		if (!visited[v])
			DFS(v);
	}
}

void solve(){
	int n, m, st; cin >> n >> m >> st;
	
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	for (int i = 1; i <= n; i++){
		sort(adj[i].begin(), adj[i].end());
	}

	DFS(st);

	for (int i = 1; i <= n; i++)
		adj[i].clear();
	cout << EL;
}

int main(){
	faster();
	int TC; cin >> TC;
	while (TC--){
		solve();
	}
	return 0;
}

/*

*/