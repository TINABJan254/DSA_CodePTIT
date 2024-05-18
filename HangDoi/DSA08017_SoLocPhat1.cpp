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
	
	for (int i = res.sz - 1; i >= 0; i--)
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
Một số được gọi là lộc phát nếu chỉ có 2 chữ số 6 và 8. Cho số tự nhiên N. Hãy liệt kê các số lộc phát có không quá N chữ số.

Input:

Dòng đầu tiên ghi lại số tự nhiên T là số lượng bộ test (T<10);
T dòng kế tiếp mỗi dòng ghi số N (1<N<15).
            Output:

In ra đáp án theo thứ tự giảm dần.
            Ví dụ:

Input
2
2
3

Output
88 86 68 66 8 6
888 886 868 866 688 686 668 666 88 86 68 66 8 6
*/
