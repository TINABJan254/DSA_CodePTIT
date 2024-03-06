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

int n, m, k;
vi adj[1005];
bool visited[1005];
int cnt[1005]; //count number person visited 
int pos_person[1005];

void DFS(int u){
	cnt[u]++;
	visited[u] = true;
	for (int v : adj[u]){
		if (!visited[v])
			DFS(v);
	}
}

void Init(){
	cin >> k >> n >> m;
	for (int i = 0; i < k; i++)
		cin >> pos_person[i];
	for (int i = 0; i < m; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y);
	}
}

void solve(){
	Init();
	for (int i = 0; i < k; i++){
		memset(visited, false, sizeof(visited));
		DFS(pos_person[i]);
	}
	//result
	int res = 0;
	for (int i = 1; i <= n; i++)
		if (cnt[i] == k)
			++res;
	cout << res;
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Có K người (1 ≤ K ≤ 100) đứng tại vị trí nào đó trong N địa điểm cho trước (1 ≤ N ≤ 1,000) được đánh số từ 1..N. Các điểm được nối với nhau bởi M đoạn đường một chiều (1 ≤ M ≤ 10,000) (không có đoạn đường nào nối một điểm với chính nó).

Mọi người muốn cùng tụ họp tại một địa điểm nào đó. Tuy nhiên, với các đường đi cho trước, chỉ có một số địa điểm nào đó có thể được chọn là điểm họp mặt. Cho trước K, N, M và vị trí ban đầu của K người cùng với M đường đi một chiều, hãy xác định xem có bao nhiêu điểm có thể được chọn làm điểm họp mặt. 

Input
Dòng 1: Ghi 3 số: K, N, và M
Dòng 2 đến K+1: dòng i+1 chứa một số nguyên trong khoảng (1..N) cho biết địa điểm mà người thứ i đang đứng.
Dòng K+2 đến M+K+1: Mỗi dòng ghi một cặp số A và B mô tả một đoạn đường đi một chiều từ A đến B (cả hai trong khoảng 1..N và A != B).

Output
Số địa điểm có thể được chọn là điểm họp mặt.

Example
Input:
2 4 4
2
3
1 2
1 4
2 3
3 4
Output:
2
Giải thích test ví dụ: có thể họp mặt tại điểm 3 và điểm 4.
*/