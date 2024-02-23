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
	set<int> u, its, a;
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		u.insert(x);
		a.insert(x);
	}

	for (int i = 0; i < m; i++){
		int x; cin >> x;
		if (a.find(x) != a.end())
			its.insert(x);
		u.insert(x);
	}

	for (auto x : u)
		cout << x << ' ';
	cout << EL;
	for (auto x : its)
		cout << x << ' ';
	cout << EL;
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

*/