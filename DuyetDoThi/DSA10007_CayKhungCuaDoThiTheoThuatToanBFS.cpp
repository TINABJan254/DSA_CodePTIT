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

int n, m, s;
vi adj[10005];
vector<pii> res;
bool visited[10005];

void BFS(int u){
	queue<int> q;
	visited[u] = true;
	q.push(u);
	while (!q.empty()){
		int v = q.front(); q.pop();
		for (int x : adj[v]){
			if (!visited[x]){
				q.push(x);
				visited[x] = true;
				res.pb({v, x});
			}
		}
	}
}

void solve(){
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	memset(visited, false, sizeof(visited));
	BFS(s);

	//display result
	if (res.sz == n - 1){
		for (auto e : res)
			cout << e.fi << ' ' << e.se << EL;
	}
	else
		cout << "-1\n";
	//free memory
	for (int i = 0; i <= n; i++)
			adj[i].clear();
	res.clear();
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
Cho đồ thị vô hướng G=(V, E). Hãy xây dựng một cây khung của đồ thị G với đỉnh u ∈ V là gốc của cây bằng thuật toán BFS.

Input

Dòng đầu tiên gồm một số nguyên T (1 ≤ T ≤ 20) là số lượng bộ test.

Tiếp theo là T bộ test, mỗi bộ test có dạng sau:

Dòng đầu tiên gồm 3 số nguyên N=|V|, M=|E|, u (1 ≤ N ≤ 103, 1 ≤ M ≤ 105, 1 ≤ u ≤ N).
M dòng tiếp theo, mỗi dòng gồm 2 số nguyên a, b (1 ≤ a, b ≤ N, a ≠ b) tương ứng cạnh nối hai chiều từ a tới b.
Dữ liệu đảm bảo giữa hai đỉnh chỉ tồn tại nhiều nhất một cạnh nối.
Output

Với mỗi bộ test, nếu tồn tại cây khung thì in ra N – 1 cạnh của cây khung với gốc là đỉnh u trên N – 1 
dòng theo thứ tự duyệt của thuật toán BFS. Ngược lại nếu không tồn tại cây khung thì in ra -1.

Ví dụ

Input
2
4 4 2
1 2
1 3
2 4
3 4
4 2 2
1 2
3 4

Output
2 1
2 4
1 3
-1
*/
