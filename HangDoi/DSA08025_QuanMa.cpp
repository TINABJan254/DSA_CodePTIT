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

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int s, t, u, v;
bool visited[10][10];

int BFS(){
	queue<pair<pii, int>> q;
	q.push({{s, t}, 0});
	visited[s][t] = true;
	while (!q.empty()){
		int x = q.front().fi.fi;
		int y = q.front().fi.se;
		int len = q.front().se;
		if (x == u && y == v)
			return len;
		q.pop();
		for (int k = 0; k < 8; k++){
			int x1 = x + dx[k];
			int y1 = y + dy[k];
			if (x1 >= 1 && x1 <= 8 && y1 >= 1 && y1 <= 8 && !visited[x1][y1]){
				q.push({{x1, y1}, len+1});
				visited[x1][y1] = true;
			}
				
		}
	}
	return -1;
}

void solve(){
	string ST, EN; cin >> ST >> EN;
	s = ST[0] - 'a' + 1;
	t = ST[1] - '0';
	u = EN[0] - 'a' + 1;
	v = EN[1] - '0';
	memset(visited, false, sizeof(visited));
	cout << BFS() << EL;
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
Cho một quân mã trên bàn cờ vua tại vị trí ST. 
Nhiệm vụ của bạn là hãy tìm số bước di chuyển ít nhất để đưa quân mã tới vị trí EN.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm 2 xâu dạng “xy” và “uv”, trong đó x, y là kí tự trong “abcdefgh” còn y, v là số thuộc 1, 2, 3, 4, 5, 6, 7, 8.

Output: 

Với mỗi test, in ra đáp án tìm được trên một dòng.

Ví dụ:

 

Input:
8
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6

Output
2
4
2
6
5
6
1
0
*/
