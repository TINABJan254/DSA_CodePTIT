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
	int dp[n + 5][m + 5] = {0};
	for (int i = 0; i <= m; i++){
		dp[0][i] = 0;
	}
	for (int i = 0; i <= n; i++){
		dp[i][0] = 0;
	}
	s = "#" + s; t = "#" + t; //de duyet xau tu chi so 1
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++)
			if (s[i] == t[j])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j - 1]);
	}

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
Row string s
Column string t
dp[i][j] : độ dài xâu con chung dài nhất của hai xâu s[0, i] và t[0, j]

Cho 2 xâu S1 và S2. Hãy tìm xâu con chung dài nhất của 2 xâu này (các phần tử không nhất thiết phải liên tiếp nhau).

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm hai dòng, mô tả xâu S1 và S2, mỗi xâu có độ dài không quá 1000 và chỉ gồm các chữ cái in hoa.

Output:  Với mỗi test, in ra độ dài dãy con chung dài nhất trên một dòng.

Ví dụ:

Input
2
AGGTAB
GXTXAYB
AA
BB

Output
4
0
Giải thích test 1: Dãy con chung là G, T, A, B.
*/