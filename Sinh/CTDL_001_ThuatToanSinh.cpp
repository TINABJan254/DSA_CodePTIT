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
int x[100005];
bool final;

void Init(){
	cin >> n;
	memset(x, 0, sizeof(x));
	final = false;
}

bool ThuanNghich(){
	int L = 1, R = n;
	while (L <= R){
		if (x[L] != x[R])
			return false;
		++L;
		--R;
	}
	return true;
}

void display(){
	for (int i = 1; i <= n; i++)
		cout << x[i] << ' ';
	cout << EL;
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
	else {
		x[i] = 1;
	}
}

void solve(){
	Init();
	while (!final){
		if (ThuanNghich()){
			display();
		}
		genNext();
	}
}

int main(){
	solve();
	return 0;
}

/*

*/
