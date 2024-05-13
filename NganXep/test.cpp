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

void smaller_left(int *a, int n, int *SL){
	stack<int> st;
	for (int i = n - 1; i >= 0; i--){
		while (!st.empty() && a[i] < a[st.top()]){
			SL[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()){
		SL[st.top()] = -1;
		st.pop();
	}
}

void smaller_right(int *a, int n, int *SR){
	stack<int> st;
	for (int i = 0; i < n; i++){
		while (!st.empty() && a[i] < a[st.top()]){
			SR[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()){
		SR[st.top()] = n;
		st.pop();
	}
}

void solve(){
	int n, m; cin >> n >> m;
	int a[n + 5][m + 5];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	
	int d[n + 5][m + 5];
	memset(d, 0, sizeof(d));
	for (int i = 0; i < m; i++)
		if (a[0][i] == 1) d[0][i] = 1;
		
	for (int i = 1; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 1){
				d[i][j] = d[i - 1][j] + 1;
			}
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++)
			cout << d[i][j] << ' ';
		cout << EL;
	}
		
	
	
	ll res = -1;
	for (int i = 0; i < n; i++){
		int SL[m + 5] = {0};
		int SR[m + 5] = {0};
		
		smaller_left(d[i], m, SL);
		smaller_right(d[i], m, SR);
	
		for (int j = 0; j < m; j++){
			ll w = SR[j] - SL[j] - 1;
			ll s = 1ll * d[i][j] * w;
			res = max(res, s);
			
		}
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
Cho một bảng kích thước NxM, được chia thành lưới ô vuông đơn vị N dòng M cột. 
Trên các ô của bảng ghi số 0 hoặc 1. Các dòng của bảng được đánh số 1, 2... N 
theo thứ tự từ trên xuống dưới và các cột của bảng được đánh số 1, 2..., M theo 
thứ tự từ trái qua phải

Yêu cầu: Hãy tìm một hình chữ nhật gồm các ô của bảng thoả mãn các điều kiện sau:

1 - Hình chữ nhật đó chỉ gồm các số 1

2 - Cạnh hình chữ nhật song song với cạnh bảng

3 - Diện tích hình chữ nhật là lớn nhất có thể

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test bắt đầu bởi hai số nguyên N và M (1 ≤ M, N ≤ 500).

N dòng tiếp theo, mỗi dòng gồm M số nguyên 0 hoặc 1.

Output: 

Với mỗi test, in ra diện tích hình chữ nhật lớn nhất tìm được.

Ví dụ:

Input
1
11 13
0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 1 1 1 0 0 0 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0 0
0 1 1 1 1 1 1 1 1 1 0 0 0
1 1 1 1 1 1 1 1 1 1 1 0 0
0 1 1 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0 0
0 0 0 0 1 1 1 0 0 0 0 1 1
0 0 0 0 0 1 0 0 0 0 0 1 1

Output
49
*/
