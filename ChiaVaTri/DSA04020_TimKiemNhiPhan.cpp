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

	auto pos = lower_bound(a, a + n, k) - a;
	if (a[pos] == k)
		cout << pos + 1 << EL;
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
Cho dãy số A[] gồm có N phần tử đã được sắp xếp tăng dần và số K.

Nhiệm vụ của bạn là kiểm tra xem số K có xuất hiện trong dãy số hay không. Nếu có hãy in ra vị trí trong dãy A[], nếu không in ra “NO”.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

Mỗi test bắt đầu bằng số nguyên N và K (N ≤ 100 000, 0 ≤ K ≤ 106).

Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 106), các phần tử là riêng biệt.

Output: 

Với mỗi test in ra trên một dòng đáp án tìm được.

Ví dụ:

Input:
2
5 3
1 2 3 4 5
6 5
0 1 2 3 9 10

Output
3
NO
*/