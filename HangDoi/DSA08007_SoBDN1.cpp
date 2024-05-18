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
	queue<ll> q;
	vector<ll> res;
	q.push(1);
	while (true){
		ll u = q.front(); q.pop();
		if (u > 1e18)
			break;
		res.pb(u);
		q.push(u * 10);
		q.push(u * 10 + 1);
	}

	int t; cin >> t;
	while (t--){
		ll n; cin >> n;
		int cnt = 0;
		for (ll x : res){
			if (x <= n)
				++cnt;
		}
		cout << cnt << EL;
	}
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Ta gọi số nguyên dương K là một số BDN nếu các chữ số trong K chỉ bao gồm các 0 hoặc 1 có nghĩa. Ví dụ số K = 1, 10, 101. Cho số tự nhiên N (N<2^63). Hãy cho biết có bao nhiêu số BDN nhỏ hơn N. Ví dụ N=100 ta có 4 số BDN bao gồm các số: 1, 10, 11, 100.

Input:

Dòng đầu tiên ghi lại số tự nhiên T là số lượng Test;
T dòng kế tiếp mỗi dòng ghi lại một bộ Test. Mỗi test là một số tự nhiên N.
            Output:

Đưa ra kết quả mỗi test theo từng dòng.
            Ví dụ:

Input
3
10
100
200

Output
2
4
7
*/
