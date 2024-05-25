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
	int k;
	string s;
	cin >> k >> s;
	int fre[256] = {0};
	for (char c : s)
		fre[c]++;

	priority_queue<int> pq;
	for (int i = 0; i < 256; i++){
		if (fre[i]){
			pq.push(fre[i]);
		}
	}

	while (k-- && !pq.empty()){
		int x = pq.top(); pq.pop();
		--x;
		if (x > 0)
			pq.push(x);
	}

	ll res = 0;
	while (!pq.empty()){
		int x = pq.top(); pq.pop();
		res += 1ll * x * x;
	}

	cout << res << EL;
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
Cho xâu s, gồm các ký tự in hoa. Ta định nghĩa
s là tổng bình phương số lần xuất hiện mỗi ký tự trong xâu.
Vd: s = "AAABBCD" ta có F(s) = 3^2 + 2^2 + 1^2 + 1^2 = 15
Hãy tìm giá trị nhỏ nhất của xâu s sau khi loại bỏ k ký tự trong xâu.

Input format
Dòng 1: số lượng testcase
Mỗi testcase gồm 2 dòng:
	dòng 1: số k
	dòng 2: xâu s

Constraints
T <= 100; 1 <= k <= 10^6;
1 <= len(s) <= 10^6;
xâu s gồm các ký tự in hoa/ thường

Output format
Đưa ra giá trị nhỏ nhất của mỗi test

Sample

Input
2
0
ABCC
1
ABCC

Output

*/