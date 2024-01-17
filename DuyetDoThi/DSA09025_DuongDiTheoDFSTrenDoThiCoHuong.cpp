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

int n, m, s, t;
vi adj[1005];
bool visited[1005];
int parent[1005];

int cnt = 0;
vi res;

void DFS(int u){
	res.pb(u);
	visited[u] = true;
	if (u == t)
		return;
	for (int v : adj[u]){
		if (!visited[v]){
			parent[v] = u;
			DFS(v);
		}
	}
}

void solve(){
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
	}

	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());
	memset(visited, false, sizeof(visited));
	DFS(s);
	if (!visited[t]){
		cout << "-1";
	}
	else{
		vi path;
		while (t != s){
			path.pb(t);
			t = parent[t];
		}
		path.pb(t);
		for (int i = path.sz - 1; i >= 0; i--)
			cout << path[i] << ' ';
	}
	
	//release
	for (int i = 1; i <= n; i++)
	    adj[i].clear();
	res.clear();
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