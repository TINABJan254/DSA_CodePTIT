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
bool final;
int x[1005];

void Init(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		x[i] = 0;
	final = false;
}

bool check(){
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (x[i] == 1)
			++cnt;
	return cnt == k;
}

void display(){
	for (int i = 1; i <= n; i++){
		cout << x[i];
	}
	cout << "\n";
}

void genNext(){
	int i = n;
	while (i >= 1 && x[i] == 1){
		x[i] = 0;
		--i;
	}
	if (i == 0){
		final = true;
	}
	else{
		x[i] = 1;
	}
}

void solve(){
	Init();
	while (!final){
		if (check())
			display();
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