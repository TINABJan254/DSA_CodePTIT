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

void solve(){
	vi adj[1005];
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	for (int i = 1; i <= n; i++){
		sort(adj[i].begin(), adj[i].end());
	}
	for (int i = 1; i <= n; i++){
		cout << i << ": ";
		if (adj[i].size() == 0)
			continue;
		for (int x : adj[i])
			cout << x << ' ';
		cout << EL;
	}
}

int main(){
	faster();
	int t; cin >> t;
	while (t--){
		solve();	
	}
	
	return 0;
}

/*

*/