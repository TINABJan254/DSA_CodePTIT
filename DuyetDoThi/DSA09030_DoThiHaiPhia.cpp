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
vi adj[1005];
int color[1005];
int ok;

void DFS(int u){
	if (!ok)
		return;
	for (int v : adj[u]){
		if (color[v] == 0){
			color[v] = 3 - color[u];
			DFS(v);
		} 
		else if (color[v] == color[u]){
			ok = false;
			return;
		}
	}
}

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y); 
		adj[y].pb(x);
	}

	ok = true;
	memset(color, 0, sizeof(color));
	for (int i = 1; i <= n; i++){
	    if (color[i] == 0){
	        color[i] = 1;
	        DFS(i);
	    }
	}
	if (ok)
		cout << "YES\n";
	else
		cout << "NO\n";

	//free memory
	for (int i = 1; i <= n; i++)
		adj[i].clear();
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
Đồ thị 2 phía được định nghĩa như sau:
	Giả sử ta có 2 tập A, B chứa các đỉnh của đồ thị G
	G được định nghĩa là đồ thị hai phía nếu:
		Tập A chỉ có cạnh nối các đỉnh trong tập B
		Và tập B chỉ có cạnh nối các đỉnh trong tập A
		nếu các đỉnh trong cùng một tập có đường đi tới nhau là hỏng

Ta sẽ quy định
	0 : đỉnh chưa được gán màu
	1 : đỉnh được gán màu tập A
	2 : đỉnh được gán màu tập B
Note : chú ý trường hợp đồ thị có nhiều tplt

Đồ thị hai phía là một đồ thị đặc biệt, trong đó tập các đỉnh có thể được chia thành 
hai tập không giao nhau thỏa mãn điều kiện không có cạnh nối hai đỉnh bất kỳ thuộc cùng một tập. 
Cho đồ thị N đỉnh và M cạnh, bạn hãy kiểm tra đồ thị đã cho có phải là một đồ thị hai phía hay không?

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤  20).
Mỗi test bắt đầu bởi số nguyên N và M (1 ≤  N, M ≤  1000).
M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết có cạnh nối giữa đỉnh u và v.
Output: 

Với mỗi test, in ra “YES” nếu đồ thị đã cho là một đồ thị hai phía, in ra “NO” trong trường hợp ngược lại.
Ví dụ:

INPUT
2
5 4
1 5
1 3
2 3
4 5
3 3
1 2
1 3
2 3

OUTPUT
YES
NO
*/