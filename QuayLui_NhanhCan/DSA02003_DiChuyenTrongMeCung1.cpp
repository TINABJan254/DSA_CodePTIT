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

string path;
vector<string> result;
int a[105][105];
int n;
bool flag = false;

void update(){
	flag = true;
	result.pb(path);
}

void Try(int i, int j){
	if (i == n && j == n){
		update();
	}
	if (a[i + 1][j] == 1){
		path += 'D';
		Try(i + 1, j);
		path.pop_back();
	}
	if (a[i][j + 1] == 1){
		path += 'R';
		Try(i, j + 1);
		path.pop_back();
	}
}

void Init(){
	path.clear();
	result.clear();
	flag = false;
	memset(a, 0, sizeof(a));
}

void solve(){
	Init();
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];	
	}

	if (a[1][1] == 0){
		cout << "-1" << EL;
		return;
	}

	Try(1, 1);

	//result
	if (!flag)
		cout << "-1";
	sort(result.begin(), result.end());
	for (auto x : result)
		cout << x << ' ';
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
