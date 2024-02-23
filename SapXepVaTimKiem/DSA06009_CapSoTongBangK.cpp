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
	int n, k; cin >> n >> k;
	int a[n + 5];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(a, a + n);

	ll res = 0;
	for (int i = 0; i < n; i++){
		int L = lower_bound(a + i + 1, a + n, k - a[i]) - a;
		int R = upper_bound(a + i + 1, a + n, k - a[i]) - a;
		if (L != n){
			res += R - L;
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

*/