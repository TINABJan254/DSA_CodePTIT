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
	int a[n+5];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int res = 0;
	for (int i = 0; i < n; i++){
		int idx = i;
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[idx])
				idx = j;
		if (idx != i)
			++res;
		swap(a[idx], a[i]);
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