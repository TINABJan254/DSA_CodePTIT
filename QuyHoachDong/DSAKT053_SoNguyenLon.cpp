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
	string s, t; cin >> s >> t;

	int dp[s.sz + 5][t.sz + 5];
	memset(dp, 0, sizeof(dp));
	s = "#" + s; t = "#" + t;
	for (int i = 1; i < s.sz; i++){
		for (int j = 1; j < t.sz; j++){
			if (s[i] == t[j]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[s.sz - 1][t.sz - 1] << EL;
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
Khi khởi tạo giá trị cho mảng hai chiều bắt buộc phải dùng memset chứ k thể khởi
tạo lúc khai báo được
Cho hai số nguyên lớn N và M có không quá 1000 chữ số. 
Người ta muốn tính xem liệu có thể lấy ra nhiều nhất bao nhiêu chữ số trong N 
(không cần liên tiếp) và giữ nguyên thứ tự của nó để tạo ra một số X sao cho ta 
cũng có thể tìm thấy X trong số M theo cách tương tự.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20). Mỗi test gồm hai dòng, 
dòng thứ nhất ghi số N, dòng thứ 2 ghi số M.

Output:  Với mỗi test, hãy in ra số chữ số nhiều nhất có thể của X.

Ví dụ:

Input
2
144615
4976135
44
88

Output
4
0

Giải thích test 1: số X tìm được là 4615.
*/
