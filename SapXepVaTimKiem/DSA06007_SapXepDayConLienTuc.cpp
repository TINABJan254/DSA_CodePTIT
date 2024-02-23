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
	int a[n + 5], sorted_a[n + 5];
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sorted_a[i] = a[i];
	}

	sort(sorted_a, sorted_a + n);
	int L = 0, R = n - 1;
	while (a[L] == sorted_a[L]){
		++L;
	}
	while (a[R] == sorted_a[R]){
		--R;
	}	
	cout << L + 1 << ' ' << R + 1 << EL;
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