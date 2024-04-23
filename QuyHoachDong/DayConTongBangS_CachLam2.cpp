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
	int s, n; cin >> n >> s;
	int a[n + 5];
	int F[s + 5] = {0};
	for (int i = 1; i <= n; i++) cin >> a[i];

	int dp[n + 5][s + 5];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= s; j++){
			dp[i][j] = dp[i - 1][j]; //gia su ko chon phan tu thu i
			if (j >= a[i])
				dp[i][j] = dp[i - 1][j - a[i]] || dp[i - 1][j]; 
		}
	}

	if (dp[n][s])
		cout << "YES\n";
	else
		cout << "NO\n";
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
Sub set sum

dp[i][j] = 1 nếu i phần tử đầu tiên có thể tạo thành tập con tổng bằng j
		 = 0 trong TH còn lại
Bài này tư tưởng sẽ giống với bài cái túi:
	mỗi phần tử chỉ chọn 1 lần => vòng for ngoài là chạy để chọn a[i]
	với mỗi a[i] ta sẽ kiểm tra xem 
		- i - 1 phần tử trước đã tạo thành dãy con tổng bằng j hay chưa
		- hoặc là i - 1 phần tử trước đã tạo thành dãy con tổng bằng j - a[i] hay chưa
	nếu 1 trong 2 điều kiện trên thỏa mãn thì chắc chắn sẽ tạo được thành dãy con tổng bằng j
	nên ta sẽ gán dp[i][j] = 1;
	ngược lại thì dp[i][j] = 0;
    Cứ tiếp tục như thế đến khi giải được bài toán cuối cùng đó là dp[n][s]; n phần tử có tạo được thành dãy con tổng bằng s hay ko

Cho N  số nguyên dương tạo thành dãy A={A1, A2, ..., AN}. Tìm ra một dãy con của dãy A (không nhất thiết là các phần tử liên tiếp trong dãy) có tổng bằng S cho trước.

Input: Dòng đầu ghi số bộ test T (T<10).  Mỗi bộ test có hai dòng, dòng đầu tiên ghi hai số nguyên dương N và S (0 < N ≤ 200) và S (0 < S ≤ 40000). Dòng tiếp theo lần lượt ghi N số hạng của dãy A là các số A1, A2, ..., AN (0 < Ai ≤ 200).

Output:  Với mỗi bộ test, nếu bài toán vô nghiệm thì in ra “NO”, ngược lại in ra “YES”

Ví dụ:

Input
2
5 6
1 2 4 3 5
10 15
2 2 2 2 2 2 2 2 2 2

Output
YES
NO
*/