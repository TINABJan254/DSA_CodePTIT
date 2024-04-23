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

int countDecodingDP(string s){
	int n = s.sz;
	int dp[n + 5];

	s = "#" + s;
	dp[0] = dp[1] = 1;
	if (s[1] == '0')
		return 0;
	for (int i = 2; i <= n; i++){
		dp[i] = 0;
		if (s[i] > '0')
			dp[i] = dp[i - 1];

		if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))
			dp[i] += dp[i - 2];

	}

	return dp[n];
}

void solve(){
	string s; cin >> s;
	cout << countDecodingDP(s) << EL;
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
dp[i] : lưu số cách tách i chữ số đầu tiên ra 
		làm dãy số với các số(x) trong dãy sao cho 1 <= x <= 26
dp[i] = dp[i - 1] : nếu như có thể tách theo kiểu chữ số cuối cùng đứng 1 mình
dp[i] += dp[i - 2] : nếu như 2 chữ số cuối có thể tạo thành số (x) có 2 chữ số (1 <= x <= 26)
					 và lại tách theo kiểu 2 chữ số cuối đứng 1 mình

Bài toán cơ sở:
dp[0] = dp[1] = 1; số cách tách 0/1 chữ số đầu tiên thành các số x 
					(1 <= x <= 26) thì chỉ có duy nhất 1 cách

Một bản tin M đã mã hóa bí mật thành các con số theo ánh xạ như sau: 
‘A’->1, ‘B’->2, .., ‘Z’->26. Hãy cho biết có bao nhiêu cách khác nhau để giải mã 
bản tin M. Ví dụ với bản mã M=”123” nó có thể được 
giải mã thành ABC (1 2 3), LC (12 3), AW(1 23).

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự số M.
T, M thỏa mãn ràng buộc: 1≤T≤100;  1≤length(M)≤40.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
123
2563

Output
3
2
*/