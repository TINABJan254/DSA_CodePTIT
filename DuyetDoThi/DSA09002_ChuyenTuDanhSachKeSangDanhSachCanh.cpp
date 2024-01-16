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

void solve(){
	cin >> n; 
	cin.ignore();
	for (int i = 1; i <= n; i++){
		string s; 
		getline(cin, s);
		stringstream ss(s);
		string token;
		while (ss >> token){
			if (i < stoi(token))
				cout << i << ' ' << token << "\n";
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