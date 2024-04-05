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

ll powMod(ll n, ll k){
	ll res = 1;
	while (k){
		if (k & 1){
			res *= n;
			res %= MOD;
		}
		n *= n;
		n %= MOD;
		k >>= 1;
	}
	return res;
}

void solve(){
	while (true){
		ll n, k;
		cin >> n >> k;
		if (n == 0 && k == 0)
			return;
		cout << powMod(n, k) << EL;
	}
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cho hai số nguyên không âm a và b. Hãy tính ab.

Nếu kết quả quá lớn hãy chia dư cho 109 + 7.

Input

Gồm không quá 20 bộ test, mỗi test ghi trên một dòng hai số a,b; a không quá 9 chữ số, b không quá 18 chữ số.

Input kết thúc khi a = b = 0

Output

Với mỗi test ghi ra kết quả tính được trên một dòng.

Ví dụ

Input
2 3
2 4
3 2
0 0

Output
8
16
9
*/