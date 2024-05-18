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
	int n; cin >> n;
	queue<string> q;
	vector<string> res;
	q.push("1"); res.pb("1");
	while (res.sz < n){
		string u = q.front(); q.pop();
		q.push(u + "0");
		q.push(u + "1");
		res.pb(u + "0");
		res.pb(u + "1");
	}
	
	for (int i = 0; i < n; i++){
		cout << res[i] << ' ';
	}
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
Đây chính là sử dụng BFS

PROB:
Cho số tự nhiên n. Hãy in ra tất cả các số nhị phân từ 1 đến n.

Input:

Dòng đầu tiên ghi lại số lượng test T (T≤100).
Mỗi test là một số tự nhiên n được ghi trên một dòng (n≤10000).
Output:

Đưa ra kết quả mỗi test trên một dòng.
Ví dụ:

Input
2
2
5

Output
1 10
1 10 11 100 101
*/
