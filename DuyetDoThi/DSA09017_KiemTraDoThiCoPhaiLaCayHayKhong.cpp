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

int n;
vi adj[1005];
bool visited[1005];

void DFS(int u){
	visited[u] = true;
	for (int v : adj[u]){
		if (!visited[v])
			DFS(v);
	}
}

int cnt_tplt(){
	int res = 0;
	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			++res;
			DFS(i);
		}
	}
	return res;
}

void solve(){
	cin >> n;
	for (int i = 1; i <= n-1; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	memset(visited, false, sizeof(visited));

	if (cnt_tplt() == 1){
		cout << "YES\n";
	}
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

Kiểm tra: N - 1 cạnh (N là số đỉnh) + đồ thị LIÊN THÔNG
hoặc kiểm tra: N - 1 cạnh (N là số đỉnh) + không có chu trình
Một đồ thị N đỉnh là một cây, nếu như nó có đúng N-1 cạnh và giữa 2 đỉnh bất kì, chỉ tồn tại duy nhất 1 đường đi giữa chúng. 
Cho một đồ thị vô hướng N đỉnh và M cạnh, hãy kiểm tra đồ thị đã cho có phải là một cây hay không?

Một đồ thị N đỉnh là một cây, nếu như nó có đúng N-1 cạnh và giữa 2 đỉnh bất kì, chỉ tồn tại duy nhất 1 đường đi giữa chúng.

Cho một đồ thị N đỉnh và N-1 cạnh, hãy kiểm tra đồ thị đã cho có phải là một cây hay không?

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test bắt đầu bởi số nguyên N (1 ≤ N ≤ 1000).
N-1 dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết có cạnh nối giữa đỉnh u và v.
Output: 

Với mỗi test, in ra “YES” nếu đồ thị đã cho là một cây, in ra “NO” trong trường hợp ngược lại.
Ví dụ:
Input
2
4
1 2
1 3
2 4
4
1 2
1 3
2 3

Output
YES
NO

*/