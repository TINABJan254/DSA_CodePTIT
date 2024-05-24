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

int x[1005];
int n;

void Init(){
	cin >> n;
	for (int i = 0; i < n; i++)
		x[i] = i + 1;
}

void display(){
	for (int i = 0; i < n; i++)
		cout << x[i];
	cout << " ";
}

void solve(){
	Init();
	do {
		display();
	} while (next_permutation(x, x + n));
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