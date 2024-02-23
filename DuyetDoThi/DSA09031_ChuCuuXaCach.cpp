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

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int a[105][105];
int visited[105][105];
map<pii, pii> f;

int n, m, k;
int order = 0;

bool isValid(int x, int y, int next_x, int next_y){
	int f1 = f[{next_x, next_y}].fi;
	int f2 = f[{next_x, next_y}].se;
	if (a[next_x][next_y] == 0 || (f1 == x && f2 == y) || visited[next_x][next_y] != 0)
		return false;
	return true;
}

void DFS(int x, int y){
	visited[x][y] = order;
	for (int k = 0; k < 4; k++){
		int next_x = x + dx[k];
		int next_y = y + dy[k];
		if (isValid(x, y, next_x, next_y))
			DFS(next_x, next_y);
	}
}

void solve(){
	cin >> n >> m >> k;	
	memset(a, 0, sizeof(a));
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= m; i++){
		int x, y, u, v;
		cin >> x >> y >> u >> v;
		f[{x, y}] = {u, v};
		f[{u, v}] = {x, y};
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = 1;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			if (!visited[i][j]){
				++order;
				DFS(i, j);
			}
		}
	}

	pii L[105];
	for (int i = 0; i < k; i++){
		int x, y;
		cin >> x >> y;
		L[i] = {x, y};
	}

	ll res = 0;
	for (int i = 0; i < k; i++){
		int x = L[i].fi;
		int y = L[i].se;
		cout << visited[x][y] << EL;
		for (int j = i + 1; j < k; j++){
			if (visited[x][y] != visited[L[j].fi][L[j].se])
				++res;
		}
	}

	cout << res;
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Trường học X có N sinh viên, trong đó có M cặp là bạn bè của nhau. 
Bạn của bạn cũng là bạn, tức là nếu A là bạn của B, B là bạn của C thì A và C cũng là bạn bè của nhau.
Trên cánh đồng kích thước N x N có K chú cừu. 
Người nông dân sợ các chú cừu đi lạc nên đã làm một số rào chắn giữa các khu vực. 
Các chú cừu chỉ có thể di chuyển lên trên, xuống dưới, sang trái, sang phải khu vực bên cạnh, và không thể vượt qua được hàng rào.

Hai chú cừu A và B được gọi là ‘xa cách’ nếu như chúng không thể di chuyển tới vị trí của nhau. 
Các bạn hãy xác định xem số cặp chú cừu xa cách bằng nhau nhiêu?

Input:  Dòng đầu tiên gồm 3 số nguyên dương N, K và M (1 ≤  N ≤  100, K ≤  100, M ≤  N^2). 
M dòng tiếp theo, mỗi dòng gồm 4 số nguyên u, v, x, y 
cho biết có rào chắn ở giữa hai khu vực (u, v) và (x, y) 
(2 ô này cạnh nhau). K dòng cuối, mỗi dòng chứa 2 số nguyên là tọa độ của mỗi chú cừu.

Output: In ra số cặp chú cừu bị xa cách tìm được.

Ex
INPUT
3 3 3
2 2 2 3
3 3 3 2
3 3 2 3
3 3
2 2
2 3

OUTPUT
2
*/