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

int parent[200005];
int degree[200005];
int inc[200005];
ll val[200005];
int n;

void Init(){
	cin >> n;
	for (int i = 2; i <= n; i++){
		int x; cin >> x;
		degree[x]++;
		parent[i] = x;
	}
	
	parent[1] = 0;
	fill(val, val + n + 1, 1);
	fill(inc, inc + n + 1, 1);
	for (int i = 1; i <= n; i++){
		if (degree[i] == 0){
			val[i] = 1; //leaf
		}
	}
}

void calc(){
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (degree[i] == 0)
			q.push(i);
	
	while (!q.empty()){
		int u = q.front(); q.pop();
		val[parent[u]] += (val[u] + inc[u]);
		inc[parent[u]] += inc[u];
		--degree[parent[u]];
		if (degree[parent[u]] == 0)
			q.push(parent[u]);
	}
}

void solve(){
	Init();
	calc();
	for (int i = 1; i <= n; i++)
		cout << val[i] << ' ';
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
	#endif
	faster();
	solve();
	return 0;
}

/*

*/
