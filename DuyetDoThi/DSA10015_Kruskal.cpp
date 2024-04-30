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

int n, m;
int parent[100005], Sz[100005];
vector<edge> edge_list;

void make_set(){
	for (int i = 1; i <= n; i++){
		parent[i] = i;
		Sz[i] = 1;
	}
}

int find_set(int u){
	if (u == parent[u])
		return u;
	return parent[u] = find_set(parent[u]);
}

bool union_sets(int x, int y){
	x = find_set(x);
	y = find_set(y);
	if (x != y){
		if (Sz[x] < Sz[y]) swap(x, y);
		parent[y] = x;
		Sz[x] += Sz[y];
		return true;
	}
	return false;
}

bool cmp(edge a, edge b){
	return a.w < b.w;
}

void Kruskal(){
	//Step 1: Sort edge_list tang dan theo w
	sort(edge_list.begin(), edge_list.end(), cmp);
	//Step 2: Lua chon cac canh ngan nhat dua vao cay khung neu canh do ko tao thanh chu trinh
	//		  => chon duoc n-1 canh thi dung
	vector<edge> MST; //minimum spanning tree
	int res = 0;
	for (int i = 0; i < edge_list.sz; i++){
		if (MST.sz == n-1) break;
		edge e = edge_list[i];
		if (union_sets(e.src, e.des)){
			MST.pb(e);
			res += e.w;
		}
	}
	cout << res << EL;
}

void solve(){
	cin >> n >> m;
	make_set();
	for (int i = 0; i < m; i++){
		int x, y, z; cin >> x >> y >> z;
		edge_list.pb({x, y, z});
	}
	Kruskal();
	//free memory
	edge_list.clear();
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
Muốn dùng Kruskal phải áp dụng DSU
Cho đồ thị vô hướng có trọng số G=<V, E, W>. Nhiệm vụ của bạn là hãy xây dựng một cây khung nhỏ nhất của 
đồ thị bằng thuật toán Kruskal.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào hai số V, E tương ứng với số đỉnh và số cạnh của đồ thị; phần thứ 2 đưa vào E cạnh của đồ thị, mỗi cạnh là một bộ 3: đỉnh đầu, đỉnh cuối và trọng số của cạnh.
T, S, D thỏa mãn ràng buộc: 1≤T≤100;  1≤V≤100; 1≤E, W≤10000.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
3 3
1 2 5
2 3 3
1 3 1
2 1
1 2 5

Output
4
5
*/
