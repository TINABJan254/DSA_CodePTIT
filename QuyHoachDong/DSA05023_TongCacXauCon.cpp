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

void solve(){
	string s; cin >> s;
	ll res = 0;
	for (int i = 0; i < s.sz; i++){
		string tmp = "";
		for (int j = i; j < s.sz; j++){
			tmp += s[j];
			res += stoll(tmp);
		}
	}

	cout << res << EL;
}

void solve_DP(){
	string s; cin >> s;
	int n = s.sz;

	s = "0" + s;
	ll res = 0;
	ll dp[n + 5] = {0};
	for (int i = 1; i <= n; i++){
		dp[i] = dp[i - 1] * 10 + i * (s[i] - '0');
		res += dp[i];
	}
	cout << res << EL;
}

int main(){
	faster();
	int TC; cin >> TC;
	while (TC--){
	    solve_DP();
	}
	return 0;
}

/*
Nếu làm theo DP thì
vd về ct truy hồi s = 235
F1: 2
F2: 23 3
F3: 235 35 5

s = 1234
F1: 1
F2: 12 2
F3: 123 23 3
F4: 1234 234 34 4

dễ thấy ct: F[i] = F[i - 1] * 10 + i * s[i]

Vậy res = sum(F[1], F[s.sz]);


Cho số nguyên dương N được biểu diễn như một xâu ký tự số. 
Nhiệm vụ của bạn là tìm tổng của tất cả các số tạo bởi các xâu con của N. 
Ví dụ N=”1234” ta có kết quả là 1670 = 1 + 2 + 3 + 4 + 12 + 23 + 34 + 123 + 234 + 1234.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số N.
T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤1012.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
1234
421

Output
1670
491
*/