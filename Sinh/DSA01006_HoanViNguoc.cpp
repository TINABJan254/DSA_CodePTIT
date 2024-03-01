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

int n;
int x[1005];
bool final;

void Init(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		x[i] = i;
	final = false;
}

void genNext(){
	int i = n - 1;
	while (i >= 1 && x[i] > x[i + 1]){
		--i;
	}

	if (i == 0){
		final = true;
	}
	else {
		int pos;
		for (pos = n; pos > i; pos--)
			if (x[pos] > x[i])
				break;

		swap(x[pos], x[i]);
		reverse(x + i + 1, x + n + 1);
	}
}

void solve(){
	Init();
	vector<vi> rev_permutation;
	while (!final){
		vi tmp(x + 1, x + n + 1);
		rev_permutation.pb(tmp);
		genNext();
	}

	for (int i = rev_permutation.sz - 1; i >= 0; i--){
		for (auto v : rev_permutation[i])
			cout << v;
		cout << " ";
	}
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