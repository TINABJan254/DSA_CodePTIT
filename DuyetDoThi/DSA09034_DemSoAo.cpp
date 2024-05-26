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

int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

int n, m;
char a[555][555];
bool visited[555][555];

bool isValid(int x, int y){
	if (x < 1 || x > n || y < 1 || y > m || a[x][y] == '.' || visited[x][y])
		return false;
	return true;
}

void BFS(int i, int j){
	queue<pii> q;
	q.push({i, j});
	visited[i][j] = true;
	while (!q.empty()){
		pii x = q.front();
		q.pop();
		for (int k = 0; k < 8; k++){
			int next_x = x.fi + dx[k];
			int next_y = x.se + dy[k];
			if (isValid(next_x, next_y)){
				q.push({next_x, next_y});
				visited[next_x][next_y] = true;
			}
		}
	}
}

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	memset(visited, false, sizeof(visited));

	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!visited[i][j] && a[i][j] == 'W'){
				++res;
				BFS(i, j);
			}
	cout << res << EL;
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Sau khi thi trượt môn Cấu trúc dữ liệu và giải thuật, một số sinh viên D19 CNTT - PTIT quyết định bỏ học, đầu tư thuê đất để trồng rau. 
Mảnh đất thuê là một hình chữ nhật N x M (1≤ N≤ 100; 1≤ M≤ 100) ô đất hình vuông. 
Nhưng chỉ sau đó vài ngày, trận lụt khủng khiếp đã diễn ra làm một số ô đất bị ngập. 
Mảnh đất bỗng biến thành các cái ao. Và sinh viên D19 lại dự định chuyển sang nuôi cá. 
Các bạn ấy muốn biết mảnh đất được chia thành bao nhiêu cái ao để có thể tính toán nuôi cá cho hợp lý. 
Hãy giúp các bạn ấy nhé. Chú ý: Ao là gồm một số ô đất bị ngập có chung đỉnh. Dễ nhận thấy là một ô đất có thể có tối đa 8 ô chung đỉnh.

Dữ liệu vào: Dòng1: 2 số nguyên cách nhau bởi dấu cách: N và M. Dòng 2..N+1: M kí tự liên tiếp nhau mỗi dòng đại diện cho 1 hàng các ô đất.  
Mỗi kí tự là 'W' hoặc '.' tương ứng với ô đất đã bị ngập và ô đất vẫn còn nguyên.

Kết quả:  Một dòng chứa 1 số nguyên duy nhất là số ao tạo thành.

INPUT:
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.

Output
3
*/