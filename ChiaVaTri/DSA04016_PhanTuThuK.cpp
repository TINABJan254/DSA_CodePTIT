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
	int m, n, k;
	cin >> m >> n >> k;
	int a[m + 5], b[n + 5];
	for (int i = 0; i < m; i++) cin >> a[i];
	for (int j = 0; j < n; j++) cin >> b[j];

	vi v;
	int i = 0, j = 0;
	while (i < m && j < n){
		if (a[i] <= b[j])
			v.pb(a[i++]);
		else
			v.pb(b[j++]);
	}
	while (i < m) v.pb(a[i++]);
	while (j < n) v.pb(a[j++]);

	cout << v[k - 1] << EL;
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
Cho hai mảng đã được sắp xếp A[], B[] gồm M, N phần tử theo thứ tự và số K. Nhiệm vụ của bạn là tìm phần tử ở vị trí số K sau khi trộn hai mảng để nhận được một mảng được sắp xếp.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào số M, N, K; dòng tiếp theo đưa vào M số của mảng A[];dòng tiếp theo đưa vào N số của mảng B[];các số được viết cách nhau một vài khoảng trống.
T, M,N, A[i], B[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N, A[i], B[i]≤106; 1≤ K≤N+M.
Output:

Đưa ra giá trị phần tử thứ K của mỗi test theo từng dòng.
   Ví dụ:

Input
1
5 4 5
2 3 6 7 9
1 4 8 10

Output
6
*/