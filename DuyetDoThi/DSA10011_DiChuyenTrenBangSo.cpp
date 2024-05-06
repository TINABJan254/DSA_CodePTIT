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

int n, m;
int a[505][505], d[505][505];

void Init(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
			d[i][j] = 1e9;
		}
}

bool isValid(int x, int y){
	if (x >= 1 && x <= n && y >= 1 && y <= m)
		return true;
	return false;
}

void Dijkstra(){
	d[1][1] = a[1][1];
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
	pq.push({a[1][1], {1, 1}});
	while (!pq.empty()){
		pair<int, pii> p1 = pq.top(); pq.pop();
		int dis = p1.fi;
		pii u = p1.se;
		if (dis > d[u.fi][u.se]) continue;
		for (int k = 0; k < 4; k++){
			int next_x = u.fi + dx[k];
			int next_y = u.se + dy[k];
			if (isValid(next_x, next_y) && d[next_x][next_y] > (d[u.fi][u.se] + a[next_x][next_y])){
				d[next_x][next_y] = d[u.fi][u.se] + a[next_x][next_y];
				pq.push({d[next_x][next_y], {next_x, next_y}});
			}
		}
	}
	
	cout << d[n][m] << EL;
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
Cho một bảng số kích thước N x M. Chi phí khi đi qua ô (i,j) bằng A[i][j]. 
Nhiệm vụ của bạn là hãy tìm một đường đi từ ô (1, 1) tới ô (N, M) sao cho chi phí là nhỏ nhất. 
Tại mỗi ô, bạn được phép đi sang trái, sang phải, đi lên trên và xuống dưới.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test bắt đầu bởi hai số nguyên N và M (1 ≤ N, M ≤ 500).
N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j] (0 ≤ A[i][j] ≤ 9).
Output: 

Vớii mỗi test, in ra một số nguyên là chi phí nhỏ nhất cho đường đi tìm được.

Input
3
4 5
0 3 1 2 9
7 3 4 9 9
1 7 5 5 3
2 3 4 2 5
1 6
0 1 2 3 4 5
5 5
1 1 1 9 9
9 9 1 9 9
1 1 1 9 9
1 9 9 9 9
1 1 1 1 1

Output
24
15
13
*/
