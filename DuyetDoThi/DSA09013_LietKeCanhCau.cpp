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

int n, m;
vi adj[1005];
bool visited[1005];
vector<pii> dsCanh;

void DFS(int u, int x, int y){
	visited[u] = true;
	for (int v : adj[u]){
		if ((u == x && v == y) || (u == y && v == x))
			continue;
		if (!visited[v])
			DFS(v, x, y);
	}
}

int tplt(int x, int y){
	int res = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			++res;
			DFS(i, x, y);
		}
	}
	return res;
}

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
		dsCanh.pb({x, y});
	}

	for (auto it : dsCanh){
		int x = it.fi;
		int y = it.se;
		int cc = tplt(-1, -1);

		if (cc < tplt(x, y))
			cout << x << ' ' << y << ' ';
	}
	cout << EL;
	for (int i = 1; i <= n; i++)
	adj[i].clear();
	dsCanh.clear();
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