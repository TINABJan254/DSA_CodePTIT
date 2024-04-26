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
	int a[n + 5][m + 5];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	// int dp[n + 5][m + 5] = {0};
	// for (int i = 0; i < n; i++)
	// 	dp[i][0] = a[i][0];
	// for (int i = 0; i < m; i++) 
	// 	dp[0][i] = a[0][i];
	// co the luu mang tu 0 de tranh viec bi vuot bien

	int res = 0;
	for (int i = 1; i < n; i++){
		for (int j = 1; j < m; j++){
			if (a[i][j] == 1){
				dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
				res = max(res, dp[i][j]);
			}
			else {
				dp[i][j] = 0;
			}
		}
	}

	cout << res << EL;
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
coppy hàng 0 và cột 0 của a sang matrix dp và xét từ hàng 1 cột 1 trở đi để
tránh hàng 0, cột 0 bị vượt qua biên
Đối với mỗi ô, xét một hình vuông 4 ô sao cho ô đang xét là ô phía dưới bên phải

dp[i][j] : hình vuông lớn nhất mà ô (i, j) làm trọng tâm

Một hình là hình vuông nếu như 3 ô xung quanh là 1 trọng tâm của 1 hình vuông
(trọng tâm của 1 hình vuông là ô dưới cùng bên phải)
Và độ lớn của hình vuông hiện tại sẽ bằng min(3 hình vuông xung quanh + 1)
	1 2
	2 x
	=> x = 1 + 1 = 2 tức hình vuông có trọng tâm là x sẽ có độ lớn 2x2
Cho một bảng số N hàng, M cột chỉ gồm 0 và 1. 
Bạn hãy tìm hình vuông có kích thước lớn nhất, sao cho các số trong hình vuông toàn 
là số 1.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test bắt đầu bởi 2 số nguyên N, M (1 ≤ N, M ≤ 500).
N dòng tiếp theo, mỗi dòng gồm M số mô tả một hàng của bảng.
Output: 

Với mỗi test, in ra đáp án là kích thước của hình vuông lớn nhất tìm được trên một dòng.
Ví dụ:

Input:
2
6 5
0 1 1 0 1
1 1 0 1 0
0 1 1 1 0
1 1 1 1 0
1 1 1 1 1
0 0 0 0 0
2 2
0 0
0 0

Output
3
0
*/