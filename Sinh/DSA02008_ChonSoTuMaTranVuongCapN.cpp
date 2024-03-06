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

int n, k;
int a[100][100];
int x[1005];
bool column[100];
int sum;
vector<vi> res;

void Init(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	sum = 0;
	memset(column, false, sizeof(column));
}

void check(){
	if (sum == k){
		vi tmp(x + 1, x + n + 1);
		res.pb(tmp);
	}
}

void Try(int i){
	for (int j = 1; j <= n; j++){
		if (!column[j]){
			x[i] = j;
			column[j] = true;
			sum += a[i][x[i]];
			if (i == n){
				check();
			} 
			else{
				Try(i + 1);
			}
			column[j] = false;
			sum -= a[i][j];
		}
	}
}

void solve(){
	Init();
	Try(1);
	cout << res.sz << EL;
	for (auto tmp : res){
		for (auto y : tmp)
			cout << y << ' ';
		cout << EL;
	}
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cho ma trận vuông Ci,j cấp N (1<= i, j <= N<10) gồm N2 số tự nhiên và số tự nhiên K (các số trong ma trận không nhất thiết phải khác nhau và đều không quá 100, K không quá 104). Hãy viết chương trình lấy mỗi hàng, mỗi cột duy nhất một phần tử sao cho tổng các phần tử này đúng bằng K.

Dữ liệu vào: Dòng 1 ghi hai số N và K. N dòng tiếp theo ghi ma trận C. 

Kết quả: dòng đầu ghi số cách tìm được. Mỗi dòng tiếp theo ghi một cách theo vị trí của số đó trong lần lượt từng hàng của ma trận. Xem ví dụ để hiểu rõ hơn. 

Ví dụ:

INPUT
3 10
2 4 3
1 3 6
4 2 4

OUTPUT
2
1 3 2
3 2 1
*/