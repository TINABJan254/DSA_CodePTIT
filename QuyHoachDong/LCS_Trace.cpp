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
	string s, t; cin >> s >> t;
	int n = s.sz, m = t.sz;

	int dp[n + 5][m + 5];
	memset(dp, 0, sizeof(dp));
	s = "#" + s; t = "#" + t;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (s[i] == t[j]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << "Length of longest common subsequence = " << dp[n][m] << EL;
	string ans = "";
	int i = n, j = m;
	while (i > 0 && j > 0){
		if (s[i] == t[j]){
			ans.pb(s[i]);
			--i; --j;
		}
		else if (dp[i][j] == dp[i - 1][j]){
			--i;
		}
		else 
			--j;
	}
	reverse(ans.begin(), ans.end());
	cout << "The longest common subsequence is: " << ans;
}

int main(){
	faster();
	solve();
	return 0;
}

/*

*/