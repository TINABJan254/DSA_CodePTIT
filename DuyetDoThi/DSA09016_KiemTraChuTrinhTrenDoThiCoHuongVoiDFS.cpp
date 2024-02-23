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
int color[1005];

void releaseMemory(){
	for (int i = 1; i <= n; i++)
		adj[i].clear();
}

bool DFS(int u){
	visited[u] = true;
	color[u] = 1;
	for (int v : adj[u]){
		if (color[v] == 1){
			return true;
		}
		else if (color[v] == 0){
			if (DFS(v))
				return true;
		}
	}
	color[u] = 2;
	return false;
}

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
	}

	memset(visited, false, sizeof(visited));
	memset(color, 0, sizeof(color));
	
	for (int i = 1; i <= n; i++)
		if (color[i] == 0){
			if (DFS(i)){
				cout << "YES\n";
				releaseMemory();
				return;
			}
		}

	//release
	cout << "NO\n";
	releaseMemory();
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