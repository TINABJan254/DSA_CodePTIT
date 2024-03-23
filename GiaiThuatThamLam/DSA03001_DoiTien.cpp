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

int root[20] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

void solve(){
	int n; cin >> n;
	int res = 0;
	int idx = 0;
	while (n != 0){
		while (root[idx] <= n){
			++res;
			n -= root[idx];
		}
		++idx;
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
Tại ngân hàng có các mệnh giá bằng 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000. Tổng số tiền cần đổi có giá trị bằng N.  
Hãy xác định xem có ít nhất bao nhiêu tờ tiền sau khi đổi tiền?

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 50).  Mỗi test gồm 1 số nguyên N ( 1 ≤ N ≤ 100 000).

Output:  Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:

Input:
2
70
121

Output
2
3
*/