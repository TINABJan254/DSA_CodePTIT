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

bool visited[1005];
vector<pii> BE;
vi adj[1005];
int n, m;
int tmer;
int disc[1005], low[1005];

void Init(){
	memset(disc, 0, sizeof(disc));
	memset(low, 0, sizeof(low));	
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++)
		adj[i].clear();
	BE.clear();
	tmer = 0;
}

void DFS(int u, int parent){
	visited[u] = true;
	disc[u] = low[u] = ++tmer;
	for (int v : adj[u]){
		if (v == parent)
			continue;
		if (!visited[v]){
			DFS(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > disc[u])
				BE.pb({min(u, v), max(u, v)});
		}
		else{
			low[u] = min(low[u], disc[v]);
		}
	}
}	

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	
	Init();
	for (int i = 1; i <= n; i++)	
		if (!visited[i]){
			DFS(i, -1);
		}
	
	sort(BE.begin(), BE.end());
	for (auto x : BE)
		cout << x.fi << ' ' << x.se << " ";

	//release
	cout << EL;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
	#endif
	faster();
	int TC; cin >> TC;
	while (TC--){
		solve();
	}
	return 0;
}

/*

*/
