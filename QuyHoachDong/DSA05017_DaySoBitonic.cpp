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

	int dp1[n + 5], dp2[n + 5];
	for (int i = 0; i < n; i++){
		dp1[i] = a[i];
		for (int j = 0; j < i; j++)
			if (a[j] < a[i])
				dp1[i] = max(dp1[i], dp1[j] + a[i]);
	}

	for (int i = n - 1; i >= 0; i--){
		dp2[i] = a[i];
		for (int j = n - 1; j > i; j--)
			if (a[j] < a[i])
				dp2[i] = max(dp2[i], dp2[j] + a[i]);
	}

	int res = -1;
	for (int i = 0; i < n; i++)
		res = max(res, dp1[i] + dp2[i] - a[i]);
	cout << res << EL;
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
Một dãy số được gọi là Bi-tonic nếu nó được chia thành hai dãy đầu tăng dần và dãy tiếp theo giảm dần. Nhiệm vụ của bạn là tìm tổng lớn nhất dãy con Bi-tonic của dãy số A[]. Ví dụ với dãy A[] = {1, 15, 51, 45, 33, 100, 12, 18, 9} ta có kết quả là 194 tương ứng với dãy Bi-tonic {1, 15, 51, 100, 18, 9}.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào N là số phần tử của dãy A[]; dòng tiếp theo đưa vào N số A[i]; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤100; 0≤A[i] ≤100.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
6
80 60 30 40 20 10
9
1 15 51 45 33 100 12 18 9

Output
210
194
*/