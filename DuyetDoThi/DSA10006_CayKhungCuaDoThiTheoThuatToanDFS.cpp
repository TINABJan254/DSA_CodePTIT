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
vi adj[1005];
int n, m, s;
vector<pii> res;

void DFS(int u){
	visited[u] = true;
	for (int v : adj[u])
		if (!visited[v]){
			res.pb({u, v});
			DFS(v);	
		}
			
}

void solve(){
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	
	memset(visited, false, sizeof(visited));
	DFS(s);
	
	//result
	if (res.sz == n - 1){
		for (auto x : res)
			cout << x.fi << ' ' << x.se << EL;
	}
	else
		cout << "-1\n";
	
	//free memory
	for (int i = 1; i <= n; i++)
		adj[i].clear();
	res.clear();
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
chú ý: nếu return luôn trong trường hợp ko tồn tại nghiệm thì nhớ phải free memory nha,
ví dụ như này:
	if (res.sz != n - 1){
		cout << "-1\n"; 
		return;
	}
	for (auto x : res)
		cout << x.fi << ' ' << x.e << EL;

	//free memory
	res.clear();
	adj[all].clear()
-> Vậy thì nếu ko có nghiệm ta in ra -1 xong rồi kết thúc ctrinh luôn mà ko free memory ở phía dưới
Cho đồ thị vô hướng G=(V, E). Hãy xây dựng một cây khung của đồ thị G với 
đỉnh u ∈ V là gốc của cây bằng thuật toán DFS.

Input

Dòng đầu tiên gồm một số nguyên T (1 ≤ T ≤ 20) là số lượng bộ test.

Tiếp theo là T bộ test, mỗi bộ test có dạng sau:

Dòng đầu tiên gồm 3 số nguyên N=|V|, M=|E|, u (1 ≤ N ≤ 103, 1 ≤ M ≤ 105, 1 ≤ u ≤ N).
M dòng tiếp theo, mỗi dòng gồm 2 số nguyên a, b (1 ≤ a, b ≤ N, a ≠ b) tương ứng cạnh nối hai chiều từ a tới b.
Dữ liệu đảm bảo giữa hai đỉnh chỉ tồn tại nhiều nhất một cạnh nối.
Output

Với mỗi bộ test, nếu tồn tại cây khung thì in ra N – 1 cạnh của cây khung với gốc là đỉnh u trên 
N – 1 dòng theo thứ tự duyệt của thuật toán DFS. Ngược lại nếu không tồn tại cây khung thì in ra -1.

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
1 3
3 4
-1
*/
