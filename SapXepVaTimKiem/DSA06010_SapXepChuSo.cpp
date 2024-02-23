#include <bits/stdc++.h>

using namespace std;
#define EL "\n"
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second

void solve(){
	int n; cin >> n;
	set<char> ans;
	for (int i = 0; i < n; ++i){
		string s; cin >> s;
		for (auto x : s)
			ans.insert(x);
	}
	for (auto x : ans)
		cout << x << ' ';	
	cout << EL;
}

int main(){
	int TC; cin >> TC;
	while (TC--){
		solve();
	}
	return 0;
}
/*

*/
