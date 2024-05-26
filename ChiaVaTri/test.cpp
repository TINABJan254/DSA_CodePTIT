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

ll F[1005];
char c;

void Init(){
	F[1] = 1;
	for (int i = 2; i <= 26; i++)
		F[i] = F[i - 1] * 2 + 1;
	c = 'A';
}

char find(int n, ll k){
	if (n == 1)
		return 'A';
	if (k == F[n] / 2 + 1)
		return (char)(c + n - 1);
	if (k <= F[n - 1])
		return find(n - 1, k);
	return find(n - 1, k - F[n - 1] - 1);
	
}

void solve(){
	int n; 
	ll k;
	cin >> n >> k;
	cout << find(n, k) << EL;	
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
	#endif
	Init();
	faster();
	int TC; cin >> TC;
	while (TC--){
	    solve();
	}
	return 0;
}
