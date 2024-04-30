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
vector<pii> adj[100005];
bool used[100005];

void Prim(int s){
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	used[s] = true;
	for (pii e : adj[s]){
		if (!used[e.fi]) //cac dinh chua nam trong cay khung
			pq.push({e.se, e.fi});
	}
	
	ll d = 0;
	while (!pq.empty()){
		//pq.top() : canh co trong so nho nhat
		pii e = pq.top(); pq.pop();
		int w = e.fi, dest = e.se;
		if (!used[dest]){
			d += w;
			used[dest] = true;
			for (pii tmp : adj[dest]){
				if (!used[tmp.fi])
					pq.push({tmp.se, tmp.fi});
			}
		}
	}
	
	cout << d;
}

void solve(){
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int x, y, w; cin >> x >> y >> w;
		adj[x].pb({y, w});
		adj[y].pb({x, w});
	}
	memset(used, false, sizeof(used));
	for (int i = 1; i <= n; i++)
		adj[i].clear();
	Prim(1);
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
Tư tưởng thuật toán Prim:
Chọn các cạnh có trọng số nhỏ nhất để đưa vào cây khung
Chọn bằng cách chọn 1 đỉnh thuộc cây khung và 1 đỉnh ko thuộc cây khung
như thế thì chắc chắn cạnh chọn được sẽ ko tạo thành chu trình
*/
