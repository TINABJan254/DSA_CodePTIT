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
	int n, k; cin >> n >> k;
	int a[n + 5];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);
	int res = 0;
	for (int i = 0; i < n; i++){
		int pos = lower_bound(a + i, a + n, a[i] + k) - a;
		//cout << pos << EL;
		// if (pos == n){
		// 	continue;
		// }
		pos = pos - i;
		res += (pos * (pos - 1)) / 2;
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
Cho mảng A[] gồm n số nguyên dương và số K. Hãy đếm số các cặp phần tử có hiệu nhỏ hơn K. Ví dụ A[] = {1, 10, 4, 2 }, K=3 ta nhận được kết quả là 2 tương ứng với các cặp (1, 2), (4, 2).

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Mỗi bộ test gồm hai dòng: dòng đầu tiên ghi số n và số K; dòng tiếp theo là n số A[i] ; các số được viết cách nhau một vài khoảng trống.
T, n, k, A[i] thỏa mãn ràng buộc: 1 ≤  T  ≤ 100; 1 ≤  n  ≤ 104; 1 ≤  k ≤ 103; 1 ≤  A[i]  ≤ 105.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
4 3
1 10 4 2
3 5
2 3 4

Output
2
3
*/