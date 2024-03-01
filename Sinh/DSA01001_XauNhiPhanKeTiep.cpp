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

string x;

void Init(){
	cin >> x;
}

void display(){
	cout << x << EL;
}

void genNext(){
	int i = x.sz - 1;
	while (i >= 0 && x[i] == '1'){
		x[i] = '0';
		--i;
	}

	if (i < 0){
		return;
	}
	else {
		x[i] = '1';
	}
}

void solve(){
	Init();
	genNext();
	display();
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
