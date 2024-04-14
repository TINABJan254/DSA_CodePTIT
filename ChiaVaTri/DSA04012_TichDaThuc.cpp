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
	int n, m; cin >> n >> m;
	int p[n + 5], q[m + 5];
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < m; i++) cin >> q[i];

	int res[n + m + 5] = {0};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			res[i + j] += p[i] * q[j];

	for (int i = 0; i < n + m - 1; i++)
		cout << res[i] << ' ';
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
Cho hai đa thức P và Q được biểu diễn như một mảng bao gồm các hệ số của đa thức. Ví dụ với P(x) = 5 + 0x1 +10x2 + 6x3 được biểu diễn như mảng P[] ={5, 0, 10, 6}. Hãy đưa ra đa thức R = P×Q theo các hệ số của R với cách biểu diễn như trên.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào hai số M, N tương ứng với lũy thừa lớn nhất của đa thức P và Q; dòng tiếp theo đưa vào M số là hệ số của đa thức P; dòng cuối cùng đưa vào M số là hệ số của đa thức Q.
T, M, N, P[i], Q[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤M, N≤100; 1≤P[i], Q[i]≤100.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
4 3
1 0 3 2
2 0 4
5 4
1 9 3 4 7
4 0 2 5

Output
2 0 10 4 12 8
4 36 14 39 79 23 34 35
*/