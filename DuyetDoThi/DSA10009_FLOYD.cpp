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

int d[1005][1005];
int n, m;
int INF = (int)1e9;

void FLOYD(){
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		}
	}
}

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = INF;
	}
	
	for (int i = 1; i <= m; i++){
		int x, y, w; cin >> x >> y >> w;
		d[x][y] = d[y][x] = w;
	}
	
	FLOYD();
	
	//Querry
	int Q; cin >> Q;
	while (Q--){
		int x, y; cin >> x >> y;
		cout << d[x][y] << EL;
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
	#endif
	faster();
	solve();
	return 0;
}

/*
Floyd áp dụng cho đồ thị có hướng, vô hướng, không có chu trình âm (có thể có cạnh âm)
Độ phức tạp O(v^3); thường chỉ áp dụng cho đồ thị có V <= 400

Floyd áp dụng để tỉnh đường đi ngắn nhất giữa 2 cặp đỉnh bất kỳ.

Cho đơn đồ thị vô hướng liên thông G = (V, E) gồm N đỉnh và M cạnh, các đỉnh được đánh số 
từ 1 tới N và các cạnh được đánh số từ 1 tới M.

Có Q truy vấn, mỗi truy vấn yêu cầu bạn tìm đường đi ngắn nhất 
giữa đỉnh X[i] tới Y[i].

Input:

Dòng đầu tiên hai số nguyên N và M (1 ≤ N ≤ 100, 1 ≤ M ≤ N*(N-1)/2).
M dòng tiếp theo, mỗi dòng gồm 3 số nguyên u, v, c cho biết có cạnh nối giữa đỉnh u và v có độ dài bằng c (1 ≤ c ≤ 1000).
Tiếp theo là số lượng truy vấn Q (1 ≤ Q ≤ 100 000).
Q dòng tiếp theo, mỗi dòng gồm 2 số nguyên X[i], Y[i].
Output: 

Với mỗi truy vấn, in ra đáp án là độ dài đường đi ngắn nhất tìm được.
Ví dụ:

Input:
5 6
1 2 6
1 3 7
2 4 8
3 4 9
3 5 1
4 5 2
3
1 5
2 5
4 3
 
Output:
8
10
3
*/
