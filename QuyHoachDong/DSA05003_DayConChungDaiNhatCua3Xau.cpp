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
	int n, m, p;
	string x, y, z;
	cin >> n >> m >> p;
	cin >> x >> y >> z;

	int dp[n + 5][m + 5][p + 5];
	memset(dp, 0, sizeof(dp));
	x = "#" + x; y = "#" + y; z = "#" + z;

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			for (int k = 1; k <= p; k++)
				if (x[i] == y[j] && x[i] == z[k])
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
				else
					dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
		}
	}

	cout << dp[n][m][p] << EL;
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
Cho ba xâu ký tự X, Y, Z. Nhiệm vụ của bạn là tìm độ dài dãy con chung dài nhất có mặt trong cả ba xâu.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào độ dài xâu X, Y, X; dòng tiếp theo đưa vào ba xâu X, Y, Z.
T, X, Y, Z thỏa mãn ràng buộc: 1 ≤ T ≤ 100;  1 ≤ size(X), size(Y), size(Z) ≤ 100.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
5 8 13
geeks geeksfor geeksforgeeks
7 6 5
abcd1e2 bc12ea bd1ea

Output
5
3
*/