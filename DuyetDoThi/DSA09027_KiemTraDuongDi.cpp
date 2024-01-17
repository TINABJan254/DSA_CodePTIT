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
bool visited[1005];
vi adj[1005];
int cnt = 0;
int tplt[1005];

void DFS(int u){
	visited[u] = true;
	tplt[u] = cnt;
	for (int v : adj[u]){
		if (!visited[v])
			DFS(v);
	}
}

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	memset(visited, false, sizeof(visited));
	cnt = 0;
	for (int i = 1; i <= n; i++)
		if (!visited[i]){
			++cnt;
			DFS(i);
		}

	//querry
	int Q; cin >> Q;
	while (Q--){
		int x, y; cin >> x >> y;
		if (tplt[x] == tplt[y])
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	//release
	for (int i = 1; i <= n; i++)
		adj[i].clear();

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