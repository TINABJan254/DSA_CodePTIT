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
	q.push("6");
	q.push("8");
	while (true){
		string u = q.front(); q.pop();
		if (u.sz > n)
			break;
		res.pb(u);
		q.push(u + "6");
		q.push(u + "8");
	}
	
	cout << res.sz << EL;
	for (string x : res)
		cout << x << ' ';
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
Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8. Cho số tự nhiên N. Hãy liệt kê các số lộc phát có không quá N chữ số.

Input:

Dòng đầu tiên ghi lại số tự nhiên T là số lượng bộ test (T<10);
T dòng kế tiếp mỗi dòng ghi số N (1<N<15).
  Output:

Dòng đầu tiên là số lượng số lộc phát tìm được. Dòng thứ hai in đáp án theo thứ tự tăng dần.
  Ví dụ:

Input
2
2
3

Output
6
6 8 66 68 86 88
14
6 8 66 68 86 88 666 668 686 688 866 868 886 888
*/
