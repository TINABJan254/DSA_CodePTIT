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

vector<string> res;

void Init(){
	queue<string> q;
	q.push("1");
	q.push("2");
	q.push("3");
	q.push("4");
	q.push("5");
	while (!q.empty()){
		string u = q.front(); q.pop();
		if (u.sz > 5)
			break;
		res.pb(u);
		int d[256];
		memset(d, 0, sizeof(d));
		for (char c : u)
			d[c] = 1;
		for (char c = '0'; c <= '5'; c++)
			if (d[c] == 0)
				q.push(u + string(1, c));
	}
}

void solve(){
	int L, R; cin >> L >> R;
	int cnt = 0;
	for (string x : res)
		if (stoi(x) >= L && stoi(x) <= R)
			++cnt;
			//cout << x << " ";
	cout << cnt << EL;
}

int main(){
	faster();
	Init();
	int TC; cin >> TC;
	while (TC--){
	    solve();
	}
	return 0;
}

/*
Cho hai số nguyên L, R. Hãy đưa ra số các số K nguyên dương trong khoảng [L, R] thỏa mãn điều kiện: • Tất cả các chữ số của K đều khác nhau. • Tất cả các chữ số của K đều nhỏ hơn hoặc bằng 5. Ví dụ với L = 4, R = 13 ta có 5 số thỏa mãn yêu cầu là 4, 5, 10, 12, 13,
Input Format
• Dòng đầu tiên đưa vào số lượng test T. • Dòng tiếp theo đưa vào các bộ test. Mỗi bộ test được là một cặp L, R được viết trên một dòng.
Constraints
• T, L, R thỏa mãn ràng buộc: 1≤T≤100; 0≤L≤R≤10^5.
Output Format
• Đưa ra kết quả mỗi test theo từng dòng.
Sample Input 0
8
9 41
91 163
28 59
12 38
72 127
48 68
50 101
22 100
Sample Output 0
17
20
15
14
8
5
5
18

*/
