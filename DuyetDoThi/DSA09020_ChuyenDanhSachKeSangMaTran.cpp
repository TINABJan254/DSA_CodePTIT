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
int a[1005][1005];

void solve(){
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++){
		string s;
		getline(cin, s);
		stringstream ss(s);
		string token;
		while (ss >> token){
			a[i][stoi(token)] = a[stoi(token)][i] = 1;
		}
	}

	for (int  i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			cout << a[i][j] << ' ';
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