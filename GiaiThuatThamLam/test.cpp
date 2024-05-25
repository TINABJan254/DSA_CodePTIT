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
#define pci pair<char, int>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(){
	int n; cin >> n;
	int a[n + 5];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	ll res = max({1ll*a[0] * a[1], 
				  1ll*a[n-1] * a[n-2], 
				  1ll*a[n-1] * a[n-2] * a[n-3], 
				  1ll*a[n-1] * a[0] * a[1]});
	cout << res;
}

int main(){
	faster();
	solve();
	return 0;
}

/*

*/
