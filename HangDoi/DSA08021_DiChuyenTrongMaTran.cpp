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
	int a[n+5][m+5];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	
	queue<pair<pii, int>> q;
	bool visited[n + 5][m + 5];
	memset(visited, false, sizeof(visited));
	q.push({{1, 1}, 0});
	visited[1][1] = true;
	while (!q.empty()){
		int x = q.front().fi.fi;
		int y = q.front().fi.se;
		int len = q.front().se;
		q.pop();
		if (x == n && y == m){
			cout << len << EL;
			return;
		}
		int x1 = x;
		int y1 = y + a[x][y];
		if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && !visited[x1][y1]){
		    q.push({{x1, y1}, len + 1});
		    visited[x1][y1] = true;
		}
			
		x1 = x + a[x][y];
		y1 = y;
		if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && !visited[x1][y1]){
		    q.push({{x1, y1}, len + 1});
		    visited[x1][y1] = true;
		}
	}
	
	cout << "-1\n";
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
Cho ma trận A[M][N]. Nhiệm vụ của bạn hãy tìm số bước đi ít nhất dịch chuyển 
từ vị trí A[1][1] đến vị trí A[M][N]. 
Biết mỗi bước đi ta chỉ được phép dịch chuyển đến vị trí A[i][j+A[i][j]] 
hoặc vị trí A[i+A[i][j]][j] bên trong ma trận.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số M, N; phần thứ hai là các phần tử của ma trận A[][]; các số được viết cách nhau một vài khoảng trống.
T, M, N, A[i][j] thỏa mãn ràng buộc: 1≤T≤100; 1≤M, N, A[i][j]≤103.
Output:

Đưa ra kết quả mỗi test theo từng dòng. In ra -1 nếu không tìm được đáp án.
Ví dụ:

Input
1
3  3
2  1  2
1  1  1
1  1  1

Output
2
*/