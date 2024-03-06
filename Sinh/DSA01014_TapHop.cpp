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
int root[1005];
int n, k, s;
int res;
bool final;

void Init(){
	cin >> n >> k >> s;
	for (int i = 1; i <= n; i++)
		root[i] = i;
	res = 0;
	final = false;
	memset(x, 0, sizeof(x));
}

bool check(){
	int cnt = 0;
	int sum = 0;
	for (int i = 1; i <= n; i++){
		sum += root[i] * x[i];
		cnt += x[i];
	}
	return (cnt == k && sum == s);
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
	while(true){
		Init();
		if (n == 0 && k == 0 && s == 0)
			break;
		else{
			while (!final){
				if (check())
					++res;
				genNext();
			}
			cout << res << EL;

		}
	}
}

int main(){
	faster();
	solve();
	return 0;
}

/*

*/