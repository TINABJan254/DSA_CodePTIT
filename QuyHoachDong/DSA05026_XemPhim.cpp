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
	int c, n; cin >> c >> n;
	int w[n + 5];
	for (int i = 1; i <= n; i++) cin >> w[i];

	int dp[n + 5][c + 5] = {0};
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= c; j++){
			dp[i][j] = dp[i - 1][j];
			if (j >= w[i]){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + w[i]);
			}
		}
	}

	cout << dp[n][c];
}

int main(){
	faster();
	solve();
	return 0;
}

/*
John có một đàn bò. Một ngày đẹp trời, anh ta quyết định mua xe tải với khả năng 
chở được C kg (1000 ≤ C ≤ 25000) để đưa những con bò đi xem phim. 
Cho số con bò là N (20 ≤ N ≤ 100) và khối lượng w[i] của từng con (đều nhỏ hơn C), hãy cho biết khối lượng bò lớn nhất mà John có thể đưa đi xem phim là bao nhiêu.

Input:

Dòng 1: 2 số nguyên C và N cách nhau bởi dấu cách
Dòng 2..N+1:   Ghi lần lượt các số nguyên: w[i]
Output:

Một số nguyên là tổng khối lượng bò lớn nhất mà John có thể mang đi xem phim.
Ví dụ:

Input
259 5
81
58
42
33
61

Output
242
*/