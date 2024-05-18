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
	q.push(9);
	while (true){
		ll u = q.front(); q.pop();
		if (u > 1e18)
			break;
		res.pb(u);
		q.push(u * 10);
		q.push(u * 10 + 9);
	}
	
	int t; cin >> t;
	while (t--){
		int n; cin >> n; 
		for (ll x : res)
			if (x % n == 0){
				cout << x << EL;
				break;
			}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
	#endif
	faster();
	solve();
	return 0;
}

/*
Cho số tự nhiên N. Hãy tìm số nguyên dương X nhỏ nhất được tạo bởi số 9 và số 0 chia hết cho N. 
Ví dụ với N = 5 ta sẽ tìm ra  X = 90.

Input:

Dòng đầu tiên ghi lại số lượng test T (T≤100).
Những dòng kế tiếp mỗi dòng ghi lại một test. Mỗi test là một số tự nhiên N được ghi trên một dòng (N≤100).
Output:

Đưa ra theo từng dòng số X nhỏ nhất chia hết cho N tìm được .
Ví dụ:

Input
2
5
7

Output
90
9009
*/
