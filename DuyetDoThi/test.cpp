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

struct edge{
	int src, des, w;
};

int INF = (int)1e9;
int n, m, s;
vector<edge> edge_list;
int d[10005];

void Init(){
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++){
		int x, y, z; cin >> x >> y >> z;
		edge_list.pb({x, y, z});
	}
}

void Bellman_Ford(){
	fill(d + 1, d + n + 1, INF);
	d[s] = 0;
	for (int i = 1; i <= n - 1; i++){
		for (edge e : edge_list){
			int u = e.src, v = e.des, W = e.w;
			if (d[u] < INF){
				d[v] = min(d[v], d[u] + W);
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		cout << d[i] << ' ';
	cout << EL;
	
	//free memory
	edge_list.clear();
}

void solve(){
	Init();
	Bellman_Ford();
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
Bellman-Ford l� thu?t to�n t�m du?ng di t? 1 d?nh t?i m?i d?nh tr�n d? th?
Bellman-Ford c� th? �p d?ng cho d? th? v?i c?nh c� tr?ng s? �m, nhung ko th? �p d?ng v?i
d? th? c� chu tr�nh �m
�? ph?c t?p: O(V*E).

d[i] : luu khoang cach tu s toi i
Thu?t to�n l?p n - 1 bu?c, m?i bu?c s? x�t t?t c? c�c c?p c?nh (u, v) c� tr?ng s? w.
N?u d[v] > d[u] + w th� c?p nh?t l?i d[v];
*/
