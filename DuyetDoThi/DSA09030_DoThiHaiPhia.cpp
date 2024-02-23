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

int v, e;
bool selected[1005];
int mtr[1005][1005];

void solve(){
	cin >> v >> e;

	memset(selected, false, sizeof(selected));
	memset(mtr, 0, sizeof(mtr));

	for (int i = 1; i <= e; i++){
		int x, y; cin >> x >> y;
		mtr[x][y] = 1;
		mtr[y][x] = 1;
	}

	vector<vi> vt;
	for (int i = 1; i <= v; i++){
		if (!selected[i]){
			selected[i] = true;
			vi tmp; tmp.pb(i);
			for (int j = 1; j <= v; j++){
				if (!selected[j] && mtr[i][j] == 0 && mtr[j][i] == 0){
					selected[j] = true;
					tmp.pb(j);
				}
			}

			vt.pb(tmp);
		}
	}

	if (vt.sz == 2 || vt.sz == 1){
		cout << "YES\n";
	}
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
Đồ thị hai phía là một đồ thị đặc biệt, trong đó tập các đỉnh có thể được chia thành 
hai tập không giao nhau thỏa mãn điều kiện không có cạnh nối hai đỉnh bất kỳ thuộc cùng một tập. 
Cho đồ thị N đỉnh và M cạnh, bạn hãy kiểm tra đồ thị đã cho có phải là một đồ thị hai phía hay không?

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤  20).
Mỗi test bắt đầu bởi số nguyên N và M (1 ≤  N, M ≤  1000).
M dòng tiếp theo, mỗi dòng gồm 2 số nguyên u, v cho biết có cạnh nối giữa đỉnh u và v.
Output: 

Với mỗi test, in ra “YES” nếu đồ thị đã cho là một đồ thị hai phía, in ra “NO” trong trường hợp ngược lại.
Ví dụ:

INPUT
2

5 4

1 5

1 3

2 3

4 5

3 3

1 2

1 3

2 3

OUTPUT
YES
NO
*/