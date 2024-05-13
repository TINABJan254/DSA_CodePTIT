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

void smaller_left(int *a, int n, int *L){
	stack<int> st;
	for (int i = n - 1; i >= 0; i--){
		while (!st.empty() && a[i] < a[st.top()]){
			L[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()){
		L[st.top()] = -1;
		st.pop();
	}
}

void smaller_right(int *a, int n, int *R){
	stack<int> st;
	for (int i = 0; i < n; i++){
		while (!st.empty() && a[i] < a[st.top()]){
			R[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()){
		R[st.top()] = n;
		st.pop();
	}
}

void solve(){
	int n; cin >> n;
	int a[n + 5], R[n + 5], L[n + 5];
	for (int i = 0; i < n; i++) cin >> a[i];
	smaller_left(a, n, L);
	smaller_right(a, n, R);
	
	ll res = -1;
	for (int i = 0; i < n; i++){
		int w = R[i] - L[i] - 1;
		ll s = 1ll * w * a[i];
		res = max(res, s);
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
Bài này ta sẽ đi tìm phần tử đầu tiên bé hơn bên trái và phần tử 
đầu tiên lớn hơn bên phải của mỗi phần tử (tức của mỗi cọc)

chiều cao chính là  : a[i]
chiều rộng chính là : R[i] - L[i] - 1
diện tích = chiều cao * chiều rộng


PROB
Cho N cột, mỗi cột có chiều cao bằng H[i]. 
Bạn hãy tìm hình chữ nhật lớn nhất bị che phủ bởi các cột?

geeksforgeeks.org/largest-rectangular-area-in-a-histogram-using-stack/

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test bắt đầu bởi số nguyên N (N ≤ 100 000).

Dòng tiếp theo gồm N số nguyên H[i] (1 ≤ H[i] ≤ 109).

Output: 

Với mỗi test, in ra diện tích hình chữ nhật lớn nhất tìm được.

Ví dụ:

Input
2
7
6 2 5 4 5 1 6
3
2 2 2

Output
12
6
*/
