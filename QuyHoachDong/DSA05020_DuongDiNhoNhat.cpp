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

void solve(){
	int n, m;
	cin >> n >> m;
	int a[n + 5][m + 5];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	ll dp[n + 5][m + 5];
	memset(dp, 0, sizeof(dp));
	dp[1][1] = a[1][1];
	for (int i = 1; i <= m; i++)
		dp[1][i] = dp[1][i - 1] + a[1][i];
	for (int i = 1; i <= n; i++)
		dp[i][1] = dp[i - 1][1] + a[i][1];

	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= m; j++)
			dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + a[i][j];

	cout << dp[n][m] << EL;
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
Cho bảng A[] kích thước N x M (N hàng, M cột). Bạn được phép đi xuống dưới, đi sang phải và đi xuống ô chéo dưới. Khi đi qua ô (i, j), điểm nhận được bằng A[i][j].

Hãy tìm đường đi từ ô (1, 1) tới ô (N, M) sao cho tổng điểm là nhỏ nhất.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm số nguyên dương N và M.
N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j] (0 ≤ A[i] ≤ 1000).
Output: 

Với mỗi test, in ra kết quả trên một dòng.
Ví dụ:

Input
1
3 3
1 2 3
4 8 2
1 5 3

Output
8
*/