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
	int n; cin >> n;
	
	int dp[n + 5] = {0};
	dp[1] = 1;
	for (int i = 2; i <= n; i++){
		dp[i] = i; //TH xau nhat n = 1^2 + ... + 1^2
		for (int j = 1; j <= sqrt(i); j++){
			dp[i] = min(dp[i], 1 + dp[i - j * j]);
		}
	}
	
	cout << dp[n] << EL;	
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
F[i] : lưu số cách phân tích số i theo ycau bài toán

vd : n = 20
20 = 2^2 + (20 - 2^2) = 2^2 + 16 = 2^2 + 4^2;

Tổng quát
n = x^2 + m (m ở đây là tập hợp nhiều cái bình phương
			 sao cho m = n - x^2 )
	=> F[n] = F[x^2] + F[m];
			  mà F của một số chính phương thì luôn = 1, vd 4 = 2^2, 9 = 3^3
			  ta sẽ đi thử từng số x, x = (1, sqrt(n));
Trường hợp tệ nhất là n = n cái 1^2 cộng lại
	=> khởi tạo F[i] = i;
Bài toán cơ sở: F[1] = 1;

Mọi số nguyên dương N đều có thể phân tích thành tổng các bình phương của các số nhỏ hơn N. 
Ví dụ số 100 = 102 hoặc 100 = 52 + 52 + 52 + 52. Cho số nguyên dương N. 
Nhiệm vụ của bạn là tìm số lượng ít nhất các số nhỏ hơn N mà có tổng bình phương bằng N.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi test là một số tự nhiên N được viết trên 1 dòng.
T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤10000.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

 

Input
3
100
6
25

Output
1
3
1
*/
