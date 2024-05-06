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
vector<pii> adj[100005];

void Init(){
	cin >> n >> m >> s;
	for (int i = 1; i <= m; i++){
		int x, y, w; cin >> x >> y >> w;
		adj[x].pb({y, w});
		adj[y].pb({x, w});
	}
}

void Dijkstra(){
	vector<int> d(n + 5, 1e9);
	d[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, s});
	while (!pq.empty()){
		pii p1 = pq.top(); pq.pop();
		int dis = p1.fi, u = p1.se;
		if (dis > d[u]) continue;
		for (pii x : adj[u]){
			int v = x.fi, w = x.se;
			if (d[v] > d[u] + w){
				d[v] = d[u] + w;
				pq.push({d[v], v});
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << d[i] << ' ';
	cout << EL;
	//free memory
	for (int i = 0; i <= n; i++)
		adj[i].clear();
}

void solve(){
	Init();
	Dijkstra();
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
Cho đồ thị có trọng số không âm G=<V, E> được biểu diễn dưới dạng danh sách cạnh trọng số. 
Hãy viết chương trình tìm đường đi ngắn nhất từ đỉnh uÎV đến tất cả các đỉnh còn lại trên đồ thị.

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm |E|+1 dòng: dòng đầu tiên đưa vào hai ba số |V|, |E| tương ứng với số đỉnh và uÎV là đỉnh bắt đầu; |E| dòng tiếp theo mỗi dòng đưa vào bộ ba uÎV, vÎV, w tương ứng với một cạnh cùng với trọng số canh của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra kết quả của mỗi test theo từng dòng. Kết quả mỗi test là trọng số đường đi ngắn nhất từ đỉnh u đến các đỉnh còn lại của đồ thị theo thứ tự tăng dần các đỉnh.
     Ví dụ:

Input:
1
9  12 1
1  2  4
1  8  8
2  3  8
2  8  11
3  4  7
3  6  4
3  9  2
4  5  9
4  6  14
5  6  10
6  7  2
6  9  6

Output:
0 4 12 19 26 16 18 8 14 
*/
