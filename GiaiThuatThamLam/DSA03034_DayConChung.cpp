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
	int n, m, k;
	cin >> n >> m >> k;
	int a[n + 5], b[m + 5], c[k + 5];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	for (int i = 0; i < k; i++) cin >> c[i];
	int idx_a = 0, idx_b = 0, idx_c = 0;
	bool flag = false;
	while (idx_a < n && idx_b < m && idx_c < k){
		if (a[idx_a] == b[idx_b] && a[idx_a] == c[idx_c]){
			cout << a[idx_a] << " ";
			flag = true;
			++idx_a; ++idx_b; ++idx_c;
		}
		else if (a[idx_a] < b[idx_b]) ++idx_a;
		else if (b[idx_b] < c[idx_c]) ++idx_b;
		else ++idx_c;
	}
	if (!flag)
		cout << "NO";
	cout << EL;
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
Cho dãy số A[], B[] và C[] là dãy không giảm và có lần lượt N, M, K phần tử. Nhiệm vụ của bạn là hãy tìm các phần tử chung của 3 dãy số này.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm số nguyên N, M và K (1≤ N, M, K ≤ 100 000).

Dòng tiếp theo gồm N số nguyên A[i], rồi M số nguyên B[i] và K số nguyên C[i].

(0 ≤ A[i], B[i], C[i] ≤ 10^9).

Output: 

Với mỗi test, in ra trên một dòng là đáp án thu được. Nếu không tìm được đáp án, in ra “NO”.

 

Ví dụ:
Input:
3
6 5 8
1 5 10 20 40 80
5 7 20 80 100
3 4 15 20 30 70 80 120
3 5 4
1 5 5
3 4 5 5 10
5 5 10 20
3 3 3
1 2 3
4 5 6
7 8 9

Output
20 80
5 5
NO
*/