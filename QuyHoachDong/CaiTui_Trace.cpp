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
	int n, m; cin >> n >> m;
	int w[n + 5], v[n + 5];
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) cin >> v[i];

	int dp[n + 5][m + 5];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			dp[i][j] = dp[i - 1][j]; //gia su ko chon goi thu i
			if (j >= w[i]){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}

	cout << "Max value: " << dp[n][m] << EL;
	//Trace
	while (n != 0){
		if (dp[n][m] != dp[n - 1][m]){ //chon goi thu n
			cout << "Pack: " << n << ", ";
			cout << "Weight = " << w[n] << ", ";
			cout << "Value = " << v[n] << EL;
			m -= w[n];
		}
		--n;
	}

}

int main(){
	faster();
	solve();
	return 0;
}

/*
Bài toán cái túi + trace
*/