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
Bài này chính là bài hình chữ nhật lớn nhất nhưng được làm nhiều lần
Ta sẽ đi cắt từng lát từ hàng 1 tới hàng n
với mỗi lát cắt, ta sẽ tính từ hàng đó trở về hàng 1
Ta coi mỗi cột là một chiều cao, với chiều cao là số lượng số 1 liên tiếp tính từ hàng đc cắt
Ta sẽ phải đi tính chiều cao (tức số lượng số 1 liên tiếp) của từng cột và lưu vào mảng d

Sau đó ta sẽ đi từng là cắt một và tìm hcn lớn nhất
ví dụ với test case
000010
000110
001111
000111
000110

Lát cắt 1: 
	000010
	d[1] = 000010 (d sẽ lưu mảng 2 chiều, vậy d[1] tương ứng với mảng 1 chiều)
Lát cắt 2:
	000010
	000110 
	d[2] = 000120
Lát cắt 3:
	000010
	000110
	001111
	d[3] = 001231
Lát cắt 4:
	000010
	000110
	001111
	000111
	d[4] =  000342
Lát cắt 5:
	000010
	000110
	001111
	000111
	000110
	d[5] = 000450
còn việc tính diện tích thì tưng ứng như bài hình chữ nhật lớn nhất
sử dụng s = chiều cao * (smaller_right - smaller_left - 1) 


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
