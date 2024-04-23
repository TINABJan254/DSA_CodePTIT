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
	int n; cin >> n;
	int a[n + 5][n + 5];
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	ll dp[n + 5][n + 5];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++){
		dp[0][i] = -1e18;
		dp[n + 1][i] = -1e18;
	}
	for (int i = 1; i <= n; i++){
		dp[i][1] = a[i][1];
	}

	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= n; j++)
			dp[j][i] = max({dp[j - 1][i - 1], dp[j][i - 1], dp[j + 1][i - 1]}) + a[j][i];
	}
	ll ans = -1e18;
	for (int i = 1; i <= n; i++){
		ans = max(ans, dp[i][n]);
	}
	cout << ans;
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cho mảng 2 chiều A gồm N hàng và N cột, hàng được đánh số từ 1 đến N từ trên
xuống dưới, cột được đánh số từ 1 tới N từ trái sang phải, hãy tìm 1 đường đi từ
một ô ở cột 1 tới 1 ổ ở cột N sao cho các phần tử trên đường đi đó là lớn nhất có
thể. Biết rằng ở mỗi bước đi từ ô hiện tại (i, j) chỉ có thể đi sang phải (i, j + 1)
hoặc đi xuống ô dưới bên phải (i + 1, j + 1), ô bên trên bên phải(i - 1, j + 1). Hãy
tìm 1 đường đi có tổng các số trên đường đi là lớn nhất.

Input Format
	Dòng 1 là N
	N dòng tiếp theo mỗi dòng gồm N số
Constraints
	1<=N<=100
	-100<=A[i][j]<=100
Output Format
In ra đáp án của bài toán

Sample Input 0
	5
	2 -8 2 9 0
	-5 6 6 -1 6
	3 5 0 2 9
	9 -8 9 7 0
	-4 6 1 -2 0

Sample Output 0
	
Explanation 0
Đường đi có tổng lớn nhất : 9 + 6 + 9 + 7 + 9 = 40
*/