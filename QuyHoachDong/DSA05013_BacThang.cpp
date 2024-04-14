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

ll F[100005];

void solve(){
	int n, k;
	cin >> n >> k;
	memset(F, 0, sizeof(F));
	F[0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= k; j++)
			if (i >= j){
				F[i] += F[i - j];
				F[i] %= MOD;
			}
	}
	cout << F[n] << EL;
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
Một chiếc cầu thang có N bậc. Mỗi bước, bạn được phép bước lên trên tối đa K bước. 
Hỏi có tất cả bao nhiêu cách bước để đi hết cầu thang? (Tổng số bước đúng bằng N).

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
Mỗi test gồm hai số nguyên dương N và K(1 ≤ N ≤ 100000, 1 ≤ K ≤ 100).
Output: 

Với mỗi test, in ra đáp án tìm được trên một dòng theo modulo 109+7.
Ví dụ:

Input
2
2 2
4 2 

Output
2
5 

Giải thích test 1: Có 2 cách đó là (1, 1) và (2).

Giải thích test 2: 5 cách đó là: (1, 1, 1, 1), (1, 1, 2), (1, 2, 1), (2, 1, 1), (2, 2).
*/