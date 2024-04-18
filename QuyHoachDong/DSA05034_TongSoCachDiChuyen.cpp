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
	int n, k; cin >> n >> k;
	
	ll dp[n + 5];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k; j++)
			if (i >= j){
				dp[i] += dp[i - j];
				dp[i] %= MOD;
			}
	}

	cout << dp[n] << EL;
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
Khu vui chơi trẻ em thiết kế một cầu thang có N bậc để di chuyển lên đỉnh tháp. Sinh viên PTIT cũng được phép leo lên cầu thang này nhưng nhìn chung chân sinh viên PTIT khá là dài nên có thể đi từ 1 đến K bậc mỗi bước (chứ không chỉ là 1 bậc như trẻ em).

Hãy tính xem sinh viên PTIT có bao nhiêu cách để leo lên đến đỉnh.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
Mỗi test gồm hai số nguyên dương N và K (1 ≤ N ≤ 100000, 1 ≤ K ≤ 100).
Output: 

Với mỗi test, in ra đáp án tìm được trên một dòng theo modulo 109+7.
Ví dụ:

Input
2
2 2
4 2

Output
2
5

Giải thích test 2: Có 5 cách lần lượt là: (1, 1, 1, 1), (1, 1, 2), (1, 2, 1), (2, 1, 1), (2, 2).
*/