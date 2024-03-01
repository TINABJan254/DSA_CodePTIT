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
	for (int i = 1; i <= k; i++)
		cin >> root[i];
	for (int i = 1; i <= k; i++)
		x[i] = i;
}

bool checkValid() {
    for (int i = 1; i <= n; i++)
        if (x[i] != root[i])
            return false;
    return true;
}

void genNext(){
	int i = k;
	while (i >= 1 && x[i] == n - k + i){
		--i;
	}

	if (i > 0){
		x[i++]++;
		for (i; i <= k; i++)
			x[i] = x[i - 1] + 1;
	}
}

void solve(){
	Init();
	int cnt = 0;
	while (true){
		++cnt;
		if (checkValid()){
			cout << cnt << EL;
			break;
		}
		genNext();
	}
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