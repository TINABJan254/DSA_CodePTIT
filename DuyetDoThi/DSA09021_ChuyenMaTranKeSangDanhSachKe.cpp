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
int ke[1005][1005];

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> ke[i][j];

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			if (ke[i][j] == 1)
				cout << j << ' ';
		cout << EL;
	}
}

int main(){
	faster();
	solve();
	return 0;
}

/*

*/