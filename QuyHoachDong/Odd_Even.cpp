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
	int a[n + 5];
	for (int i = 0; i < n; i++) cin >> a[i];

	int dp[n + 5] = {0};
	int t = 0; //num_odd - num_even
	ll cnt = 0;
	map<int, int> mp;
	mp[0] = 1; //TH day thoa man bat dau tu 0
	for (int i = 0; i < n; i++){
		if (a[i] % 2 == 1)
			++t;
		else 
			--t;
		dp[i] = t;
		cnt += mp[dp[i]];
		mp[dp[i]]++;
	}

	cout << cnt;
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Bài này áp dụng mảng cộng dồn
dp[i] : chênh lệch của odd và even tính từ 0 -> i, dp[i] = odd - even
map để lưu có bao nhiêu lượng chênh lệch là dp[i], vd mp[dp[i]]

=> bây h việc của ta là chọn 2 trong số các lượng chênh lệch
vì cứ 2 lượng chênh lệch giống nhau sẽ tạo được thành dãy có lượng số chẵn bằng
lượng số lẻ


Bạn được cung cấp một mảng A gồm N giá trị nguyên dương. 
Một mảng con của mảng này được gọi là mảng con Chẵn lẻ nếu số lượng các số nguyên 
lẻ trong mảng con này bằng số lượng các số nguyên chẵn trong mảng con này.
Tìm số mảng con Lẻ-Chẵn cho mảng đã cho.
Input Format
Dòng đầu chứa N; Dòng thứ 2 chứa N số nguyên trong dãy
Constraints
1<=N<=2.10^5; 1<=A[i]<=10^9;
Output Format
In ra đáp án của bài toán
Sample Input 0
4
1 2 1 2
Sample Output 0
4

*/