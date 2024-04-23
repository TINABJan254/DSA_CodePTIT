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
	string s; cin >> s;
	int n = s.sz;
	s = "#" + s;

	int dp[n + 5][n + 5];
	memset(dp, 0, sizeof(dp));
	//Bai toan co so voi len = 1
	for (int i = 1; i <= n; i++)
		dp[i][i] = 1;

	int ans = 1;
	for (int len = 2; len <= n; len++){
		for (int start = 1; start <= n - len + 1; start++){
			int i = start; //chi so bat dau
			int j = start + len - 1; //chi so ket thuc
			if (len == 2){
				dp[i][j] = (s[i] == s[j]);
			}
			else {
				dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
			}
			if (dp[i][j])
				ans = max(ans, len);
		}
	}
	
	cout << ans << EL;
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
dp[i][j] = 1   nếu xâu con từ i->j là đối xứng
		 = 0   nếu ngược lại
Công thức:
	dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]) ; //hai kí tự đầu cuối giống nhau và xâu ở giữa đối xứng
Bài toán cơ cở: dp[i][i] = 1;
TH đặc biệt: xâu con có độ dài 2 thì chỉ cần xét s[i] và s[j] bởi vì xâu con có độ
 dài là 2 thì làm gì có xâu ở giữa




Cho xâu S chỉ bao gồm các ký tự viết thường và dài không quá 1000 ký tự.

Hãy tìm xâu con đối xứng dài nhất của S.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test gồm một xâu S có độ dài không vượt quá 1000, chỉ gồm các kí tự thường.
Output:  Với mỗi test, in ra đáp án tìm được.

Ví dụ:

Input
2
abcbadd
aaaaa

Output
5
5
*/