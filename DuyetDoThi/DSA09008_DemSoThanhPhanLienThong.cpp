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

void BFS(int u){
	queue<int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()){
		int x = q.front();
		q.pop();
		for (int y : adj[x]){
			if (!visited[y]){
				q.push(y);
				visited[y] = true;
			}
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

	memset(visited, false, sizeof(visited));
	int res = 0;
	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			++res;
			BFS(i);
		}
	}
	cout << res;

	//release
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
