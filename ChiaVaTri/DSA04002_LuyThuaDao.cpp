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

ll dao(ll n){
	ll res = 0;
	while (n != 0){
		res = res * 10 +  n % 10;
		n /= 10;
	}
	return res;
}

ll powMod(ll a, ll b){
	ll res = 1;
	while (b != 0){
		if (b % 2 != 0){
			res *= a;
			res %= MOD;
		}
		a *= a;
		a %= MOD;
		b /= 2;
	}
	return res;
}

ll powMod2(ll a, ll b){ 
	if (b == 0)
		return 1;
	ll res = powMod2(a, b / 2);
	if (b % 2 == 0){
		return res * res % MOD;
	}
	return a * (res * res % MOD ) % MOD;
}

void solve(){
	ll n; cin >> n;
	cout << powMod2(n, dao(n)) << EL;
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
Nên học viết binPowMod theo 2 cách đệ quy và vòng while để cho thuộc, áp dụng được
nhiều trường hợp của bài toán

PROB:
Cho mảng số N. Ta gọi số đảo của N là R. Hãy tìm lũy thừa R của N. Đưa ra kết quả của bài toán dưới dạng modulo với 109 + 7.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm là số N được ghi trên một dòng.
T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤1010.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
2
12

Output
4
864354781
*/