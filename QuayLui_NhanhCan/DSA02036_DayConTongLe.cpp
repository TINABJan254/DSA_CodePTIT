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

int a[100];
int n;
int x[100];
int sum;
vector<vi> res;

void Init(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sum = 0;
	res.clear();
}

void Try(int i, int start){
	for (int j = start; j <= n; j++){
		sum += a[j];
		x[i] = a[j];
		if (sum % 2 != 0){
			vi tmp(x + 1, x + i + 1);
			res.pb(tmp);
		}
		if (i < n){
			Try(i + 1, j + 1);
		}
		sum -= a[j];
	}
}

void solve(){
	Init();	
	sort(a + 1, a + n + 1, greater<int>());
    Try(1, 1);
	sort(res.begin(), res.end());
	for (auto tmp : res){
		for (auto tmp2 : tmp)
			cout << tmp2 << ' ';
		cout << EL;
	}
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
Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một.

Hãy sắp xếp dãy theo thứ tự giảm dần, sau đó liệt kê tất cả các dãy con (đúng thứ tự trước sau) của A[] có tổng các phần tử là số lẻ.

Các dãy con được liệt kê theo thứ tự từ điển tăng dần.

Input

Dòng đầu ghi số bộ test, mỗi test có 2 dòng:

Dòng đầu ghi số N (2 < N <15)
Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, nhỏ hơn 100 và khác nhau từng đôi một.
Output

Với mỗi test, liệt kê tất cả các dãy con có tổng các phần tử là số lẻ theo thứ tự từ điển tăng dần, mỗi dãy con trên một dòng.  

Ví dụ

Input
1
4
2 3 4 5

Output
3
3 2
4 3
4 3 2
5
5 2
5 4
5 4 2
*/