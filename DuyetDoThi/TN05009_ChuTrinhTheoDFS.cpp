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

int n, m, dest; 
vi adj[1005];
bool visited[1005];
int parent[1005];
bool flag;

void Init(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	for (int i = 1; i <= n; i++)
		sort(adj[i].begin(), adj[i].end());
	
	memset(visited, false, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	flag = false;
	parent[1] = 1;
}

void DFS(int u){
	if (flag)
		return;
	visited[u] = true;
	for (int v : adj[u]){
		if (visited[v]){
			if (v != parent[u] && v == 1){
				dest = u;
				flag = true;
				return;
			}
		}
		else{
			parent[v] = u;
			DFS(v);
		}
	}
}

void solve(){
	Init();
	DFS(1);
	if (flag){
		cout << 1 << ' ';
		stack<int> st;
		while (dest != parent[dest]){
			st.push(dest);
			dest = parent[dest];
		}
		while (!st.empty()){
			cout << st.top() << ' ';
			st.pop();
		}
		cout << "1\n";
	}
	else {
		cout << "NO\n";
	}
	
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
Note khi sort adj, phải duyệt theo for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
Chứ khi sort theo auto là không được gì cả vd: 
	for (auto x : adj)
		sort(x.begin(), x.end()); //Như này là WA
	vì for each là nó sẽ lấy từng phần tử trong mảng/vector gán cho biến x rồi thực hiện trên biến x
	và chỉ thay đổi biến x đó, giá trị của các phần tử trong mảng/vector ko thay đổi
Cho đồ thị vô hướng G= được biểu diễn dưới dạng danh sách cạnh. 
Hãy kiểm tra xem đồ thị có chu trình từ đỉnh 1 hay không, nếu có, hãy in ra chu trình đầu tiên tìm thấy theo DFS.

Input:

Dòng đầu tiên đưa vào T là số lượng bộ test.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào hai số N, M  tương ứng với số đỉnh, số cạnh.
Dòng tiếp theo đưa vào các bộ đôi u, v tương ứng với một cạnh của đồ thị.
T, N, M thỏa mãn ràng buộc: 1≤T≤100; 1≤ N ≤103; 1≤ M ≤ N*(N-1)/2;
Output:

Đưa ra chu trình đầu tiên tìm thấy theo DFS từ đỉnh 1.
Nếu không có chu trình từ đỉnh 1, ghi ra NO

Ví dụ:
Input:
1
6 9
1 2 1 3 2 3 2 5 3 4 3 5 4 5 4 6 5 6

Output:

1 2 3 1

 
*/