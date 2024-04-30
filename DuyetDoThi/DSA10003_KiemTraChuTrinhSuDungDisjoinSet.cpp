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
int parent[100005], Sz[100005];

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

void solve(){
	cin >> n >> m;
	make_set();
	bool flag = false;
	for (int i = 0; i < m; i++){
		int u, v; cin >> u >> v;
		if (!union_sets(u, v)){
			flag = true;
		}
	}
	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";
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
Cho đồ thị vô hướng G=<V, E> được biểu diễn dưới dạng danh sách cạnh. Sử dụng Disjoin Set, hãy kiểm tra xem đồ 
thị có tồn tại chu trình hay không?

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số |V|, |E| 
tương ứng với số đỉnh,  số cạnh của đồ thị; Dòng tiếp theo đưa vào các bộ đôi uÎV, vÎV tương ứng với một cạnh 
của đồ thị.
T, |V|, |E| thỏa mãn ràng buộc: 1≤T≤100; 1≤|V|≤103; 1≤|E|≤|V|(|V|-1)/2;
Output:

Đưa ra YES hoặc “NO” kết quả test theo từng dòng tương ứng với đồ thị tồn tại hoặc không tồn tại chu trình.
      Ví dụ:

Input:
1
6 9
1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6

Output:
YES
*/
