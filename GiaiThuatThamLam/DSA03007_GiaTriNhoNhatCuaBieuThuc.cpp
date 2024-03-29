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
	int a[n + 5], b[n + 5];
	for (int i = 0; i < n; i++)	cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	sort(a, a + n);
	sort(b, b + n, greater<int>());
	ll res = 0;
	for (int i = 0; i < n; i++){
		res += 1ll * a[i] * b[i];
	}
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
Cho mảng A[], B[] đều có N phần tử. Nhiệm vụ của bạn là tìm giá trị nhỏ nhất của  biểu thức P = A[0]*B[0] + A[1]*B[1] + ..+A[N-1]*B[N-1] bằng cách tráo đổi vị trí các phần tử của cả mảng A[] và B[].

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào số phần tử của mảng N; dòng tiếp theo đưa vào N số A[i]; dòng cuối cùng đưa vào N số B[i] các số được viết cách nhau một vài khoảng trống.
T, N, A[i], B[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N ≤107; 0≤A[i], B[i] ≤1018.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
7
1 6 3 4 5 2 7
1 1 1 2 3 4 3
7
1 6 3 5 5 2 2
0 1 9 0 1 2 3

Output
45
27
*/