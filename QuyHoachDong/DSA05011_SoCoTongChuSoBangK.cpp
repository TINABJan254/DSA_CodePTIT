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

ll dp[105][50005];

void Init(){
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;
	for (int i = 1; i <= 100; i++)
		for (int j = 0; j <= 9; j++)
			for (int z = j; z <= 50000; z++)
				if (z >= j){
					dp[i][z] += dp[i - 1][z - j];
					dp[i][z] %= MOD;
				}
}

void solve(){
	int n, k;
	cin >> n >> k;
	cout << dp[n][k] << EL;
}

int main(){
	faster();
	Init();
	int TC; cin >> TC;
	while (TC--){
	    solve();
	}
	return 0;
}

/*
dp[i][j] : số lượng các số có i chữ số có tổng chữ số bằng j
Bài này sẽ có nét tương tự với bài coin2, chỉ khác 1 cái là cần lưu số lượng chữ số

Cho 2 số nguyên N và K. Bạn hãy đếm số lượng các số có N chữ số mà tổng các chữ số của 
nó bằng K. Lưu ý, chữ số 0 ở đầu không được chấp nhận.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 50).
Mỗi test gồm 2 số nguyên N và K (1 ≤ N ≤ 100, 0 ≤ K ≤ 50000).
Output: 

Với mỗi test, in ra đáp số tìm được theo modulo 109+7 trên một dòng.
 

Ví dụ:

Input:
3
2 2
2 5
3 6

Output
2
5
21
*/