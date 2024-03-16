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

int n;
int c[100][100], x[100];
bool visited[100];
int res;
int cp, cmin;

void Init(){
	cmin = INT_MAX;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++){
			cin >> c[i][j];
			cmin = min(cmin, c[i][j]);
		}
	memset(visited, false, sizeof(visited));
	res = INT_MAX;
	cp = 0;
}

void Try(int i){
	for (int j = 1; j <= n; j++){
		if (!visited[j]){
			x[i] = j;
			cp += c[x[i - 1]][x[i]];
			visited[j] = true;
			if (i == n){
				res = min(res, cp + c[x[n]][1]);
			}
			else if (cp + (n - i + 1) * cmin < res) {
				Try(i + 1);
			}
			visited[j] = false;
			cp -= c[x[i]][x[i - 1]];
		}
	}
}

void solve(){
	Init();
	x[1] = 1;
	visited[1] = true;
	Try(2);
	cout << res;
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cho n thành phố đánh số từ 1 đến n và các tuyến đường giao thông hai chiều giữa chúng, mạng lưới giao thông này được cho bởi mảng C[1…n, 1…n] ở đây C[i][j] = C[j][i] là chi phí đi đoạn đường trực tiếp từ thành phố i đến thành phố j.

Một người du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại mỗi thành phố đúng 1 lần và cuối cùng quay lại thành phố 1. Hãy chỉ ra chi phí ít nhất mà người đó phải bỏ ra.

Dữ liệu vào: Dòng đầu tiên là số nguyên n – số thành phố (n ≤ 15); n dòng sau, mỗi dòng chứa n số nguyên thể hiện cho mảng 2 chiều C.

Kết quả: Chi phí mà người đó phải bỏ ra.

Ví dụ:

INPUT
4
0 20 35 10
20 0 90 50
35 90 0 12
10 50 12 0

OUTPUT
117
*/