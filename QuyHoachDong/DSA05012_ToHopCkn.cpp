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

ll C[1005][1005];



void solve(){
	for (int i = 0; i <= 1000; i++){
		for (int j = 0; j <= i; j++){
			if (j == 0 || j == i)
				C[i][j] = 1;
			else{
				C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
				C[i][j] %= MOD;
			}
		}
	}

	int n, k;
	cin >> n >> k;
	cout << C[n][k] << EL;
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
Cho 2 số nguyên n, k. Bạn hãy tính C(n, k) modulo 109+7.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm 2 số nguyên n, k (1 ≤ k ≤ n ≤ 1000).
Output: 

Với mỗi test, in ra đáp án trên một dòng.
Ví dụ:

Input
2
5 2
10 3

Output
10
120
*/