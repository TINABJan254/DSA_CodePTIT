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

int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

int a[555][555];
int n, m;
bool visited[555][555];

void BFS(int i, int j){
	queue<pii> q;
	q.push({i, j});
	visited[i][j] = true;
	while (!q.empty()){
		pii x = q.front();
		q.pop();
		for (int i = 0; i < 8; i++){
			int next_x = x.fi + dx[i];
			int next_y = x.se + dy[i];
			if (next_x >= 1 && next_x <= n && next_y >= 0 && next_y <= m && a[next_x][next_y] == 1 && !visited[next_x][next_y]){
				q.push({next_x, next_y});
				visited[next_x][next_y] = true;
			}
		}
	}
}

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	memset(visited, false, sizeof(visited));
	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; ++j)
			if (!visited[i][j] && a[i][j] == 1){
				++res;
				BFS(i, j);
			}
	cout << res << EL;
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
Cho một bản đồ kích thước N x M được mô tả bằng ma trận A[][].A[i][j] = 1 
có nghĩa vị trí (i, j) là nổi trên biển. 2 vị trí (i, j) và (x, y) được coi 
là liền nhau nếu như nó có chung đỉnh hoặc chung cạnh. 
Một hòn đảo là một tập hợp các điểm (i, j) mà A[i][j] = 1 và có thể 
di chuyển giữa hai điểm bất kì trong đó.

Nhiệm vụ của bạn là hãy đếm số lượng đảo xuất hiện trên bản đồ.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test bắt đầu bởi 2 số nguyên N và M (1 ≤ N, M ≤ 500).

N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j].

Output:  Với mỗi test, in ra số lượng hòn đảo tìm được.

INPUT
1
5 5
1 1 0 0 0
0 1 0 0 1
1 0 0 1 1
0 0 0 0 0
1 0 1 0 1

OUTPUT
5
*/