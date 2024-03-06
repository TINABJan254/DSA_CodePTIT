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

vector<ll> v;
int n;
string s;
bool final;

void Init(){
	final = false;
	s = "";
	for (int i = 0; i < n; i++)
		s += "0";
	s[n - 1] = '9';
}

void genNext(){
	int i = n - 1;
	while (i >= 0 && s[i] == '9'){
		s[i] = '0';
		--i;
	}

	if (i == -1){
		final = true;
	}
	else {
		s[i] = '9';
	}

}

void solve(){
	//sinh ra san cac dap an cho cac so tu 1 -> 500
	n = 18;
	Init();
	while (!final){
		v.pb(stoll(s));
		genNext();
	}

	ll ans[505];
	for (int i = 1; i <= 500; i++){
		for (auto x : v){
			if (x % i == 0){
				ans[i] = x;
				break;
			}
		}
	}

	//solve voi tung testcase
	int TC; cin >> TC;
	while (TC--){
		int m; cin >> m;
		cout << ans[m] << EL;
	}
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cho số nguyên N. Nhiệm vụ của bạn cần tìm số nguyên X nhỏ nhất là bội của N, và X chỉ chứa hai chữ số 0 và 9.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 10000). Mỗi bộ test chứa số nguyên N trên một dòng (1 ≤ N ≤ 500).

Output:  Với mỗi test in ra đáp án tìm được trên một dòng.

Ví dụ:
Input
3
2
5
11

Output
90
90
99

 
*/