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

string s, x;
int n;
vector<string> res;

void Init(){
	cin >> n >> s;
	x = "";
	res.clear();
}

void Try(int start){
	for (int j = start; j < n; j++){
		x.pb(s[j]);
		res.pb(x);
		if (x.sz < n)
			Try(j + 1);
		x.pop_back();
	}
}

void solve(){
	Init();
	//sort(s.begin(), s.end());
	Try(0);
	//sort(res.begin(), res.end());
	for (auto tmp : res)
		cout << tmp << ' ';
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
Cho một xâu ký tự S không có ký tự lặp lại. Hãy đưa ra tất cả các tập con của xâu ký tự S theo thứ tự từ điển.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự.
T, S thỏa mãn ràng buộc: 1≤T≤100; 1≤length(S)≤16.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
1
3
abc

Output
a ab abc ac b bc c
*/