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

ll binPow(ll n, ll k){
	n %= MOD;
	ll res = 1;
	while (k != 0){
		if (k % 2 != 0){
			res *= n;
			res %= MOD;
		}
		n *= n;
		n %= MOD;
		k /= 2;
	}
	return res;
}

ll binPow2(ll n, ll k){
	if (k == 0)
		return 1;
	ll res = binPow2(n, k / 2);
	if (k % 2 != 0)
		return ( (res * res) % MOD * n) % MOD;
	return (res * res) % MOD;
}

void solve(){
	ll n, k;
	cin >> n >> k;
	cout << binPow(n, k) << EL;
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
Cho số nguyên dương N và K. Hãy tính NK modulo 109+7.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm 1 số nguyên N và K (1 ≤ N ≤ 1000, 1 ≤ K ≤ 109).

Output: 

Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:

Input:
2
2 3
4 2

Output
8
16
*/