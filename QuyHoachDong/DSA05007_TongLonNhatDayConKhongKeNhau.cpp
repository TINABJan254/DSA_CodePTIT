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
	for (int i = 1; i <= n; i++) cin >> a[i];

	ll dp[n + 5];
	dp[0] = 0;
	dp[1] = a[1];
	for (int i = 2; i <= n; i++)
		dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
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
Cho dãy số A[] gồm N phần tử. Hãy tìm tổng lớn nhất của dãy con của dãy số A[] sao cho 
dãy con không có hai số cạnh nhau trong A[]. 
Ví dụ với A[] = {6, 7, 1, 3, 8, 2, 4} ta có kết quả là 19 tương ứng với tổng của 
dãy con {6, 1, 6, 4} không có haI phần tử nào kề nhau trong A[].

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất là một số N; dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤106; 1≤A[i] ≤107.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
6
5 5 10 100 10 5
4
3 2 7 10

Output
110
13
*/