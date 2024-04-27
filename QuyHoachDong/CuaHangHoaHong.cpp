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
	int a[n + 5], dp[n + 5];
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		dp[i] = 1;
	}
	
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++){
		if (a[i] > a[i - 1]){
			dp[i] = max(dp[i], dp[i - 1] + 1);
		}
		if (a[i] > a[i - 2]){
			dp[i] = max(dp[i], dp[i - 2] + 1);
		}
	}
	
	cout << *max_element(dp + 1, dp + n + 1);
}

void solve_AC(){
	int n; cin >> n;
	int a[n + 5];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
		
	int F[n + 5] = {0}, G[n + 5] = {0};
	F[1] = 1;
	int res = 1;
	for (int i = 2; i <= n; i++){
		if (a[i] > a[i - 1])
			F[i] = F[i - 1] + 1;
		else
			F[i] = 1;
		res = max(F[i], res);
	}
	
	G[n] = 1;
	for (int i = n - 1; i >= 1; i--){
		if (a[i] < a[i + 1])
			G[i] = G[i+1] + 1;
		else
			G[i] = 1;
	}
	
	for (int i = 2; i <= n - 1; i++){
		if (a[i - 1] < a[i + 1]){
			res = max(res, F[i - 1] + G[i + 1]);
		}	
	}
	cout << res;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
	#endif
	faster();
	solve();
	return 0;
}

/*
Có hoa hồng trong một cửa hàng. Mỗi bông hồng được chỉ định một ID. 
Những bông hồng này được sắp xếp theo thứ tự 1, 2, 3... n. 
Mỗi bông hồng có một hệ số mùi được ký hiệu là smell[i] . 
Bạn muốn mua hoa hồng ở cửa hàng này với điều kiện phải mua hoa hồng theo phân khúc. 
Nói cách khác, bạn có thể mua hoa hồng từ đến l đến r. 
Bạn có thể loại bỏ nhiều nhất một hoa hồng khỏi phân đoạn hoa hồng này. 
Như vậy, chiều dài cuối cùng của hoa hồng là n hoặc n - 1. 
Nhiệm vụ của bạn là tính toán độ dài tối đa có thể có của dãy liền kề tăng dần các hệ số 
mùi của những bông hoa hồng này.
Input Format
Dòng 1 chứa số nguyên n; Dòng thứ 2 chứa n số smell[1], smell[2], .. smell[n]
Constraints
2<=n<=2.10^5; 1<=smell[i]<=10^9
Output Format
In ra đáp án của bài toán
Sample Input 0
5
1 2 5 3 4
Sample Output 0
4

*/
