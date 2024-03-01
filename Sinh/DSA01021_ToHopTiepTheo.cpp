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

int n, k;
int x[1005];
int root[1005];

void Init(){
	cin >> n >> k;
	for (int i = 1; i <= k; i++){
		cin >> root[i];
		x[i] = root[i];
	}
}

void genNext(){
	int i = k;
	while (i >= 1 && x[i] == n-k+i){
		--i;
	}

	if (i > 0){
		x[i++]++;
		for (i; i <= k; i++)
			x[i] = x[i-1] + 1;
	}
}

void compare(){
	int cnt = 0;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			if (x[i] == root[j])
				++cnt;
	if (k - cnt == 0)
		cout << k << EL;
	else
		cout << k - cnt << EL;
}

void solve(){
	Init();
	genNext();
	compare();
}

int main(){
	faster();
	int TC; cin >> TC;
	while(TC--){
		solve();
	}
	return 0;
}

/*

*/