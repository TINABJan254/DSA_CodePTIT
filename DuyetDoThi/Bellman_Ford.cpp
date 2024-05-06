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
int n, m;
vector<edge> edge_list;
int d[10005];

void Init(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y, z; cin >> x >> y >> z;
		edge_list.pb({x, y, z});
	}
}

void Bellman_Ford(int s){
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
		cout << d[i] << '-';
}

void solve(){
	Init();
	Bellman_Ford(1);
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Bellman-Ford là thuật toán tìm đường đi từ 1 đỉnh tới mọi đỉnh trên đồ thị
Bellman-Ford có thể áp dụng cho đồ thị với cạnh có trọng số âm, nhưng ko thể áp dụng với
đồ thị có chu trình âm
Độ phức tạp: O(V*E).

d[i] : luu khoang cach tu s toi i
Thuật toán lặp n - 1 bước, mỗi bước sẽ xét tất cả các cặp cạnh (u, v) có trọng số w.
Nếu d[v] > d[u] + w thì cập nhật lại d[v];
*/