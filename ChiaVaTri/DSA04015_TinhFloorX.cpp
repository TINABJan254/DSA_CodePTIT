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
	int n, x; cin >> n >> x;
	int a[n + 5];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	auto pos = lower_bound(a, a + n, x) - a;
	
	if (pos == 0 && a[pos] > x){
		cout << "-1\n";
	}
	else if (a[pos] == x){
		cout << pos + 1 << EL;
	}
	else {
		cout << pos << EL;
	}
}

int firstPos(ll *a, int L, int R, ll x){
	int res = -1;
	while (L <= R){
		int mid = (L + R) / 2;
		if (a[mid] <= x){
			res = mid;
			L = mid + 1;
		}
		else {
			R = mid - 1;
		}
	}
	return res;
}

void solve2(){
	int n;
	ll x; 
	cin >> n >> x;
	ll a[n + 5];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int fp = firstPos(a, 0, n, x);
	if (fp == -1){
		cout << fp << EL;
	}
	else {
		cout << fp + 1 << EL;
	}
}

int main(){
	faster();
	int TC; cin >> TC;
	while (TC--){
	    solve2();
	}
	return 0;
}

/*
Cho mảng đã được sắp xếp A[] gồm N phần tử không có hai phần tử giống nhau và số X. Nhiệm vụ của bạn là tìm floor(X). Trong đó, K=floor(X) là phần tử lớn nhất trong mảng A[] nhỏ hơn hoặc bằng X.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào số N là số phần tử của mảng A[] và số X; dòng tiếp theo đưa vào N số của mảng A[]; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤107; 1≤ A[i]≤1018.
Output:

Đưa ra vị trí của  floor(X) trong mảng A[] hoặc -1 nếu không tồn tại floor(X) của mỗi test theo từng dòng.
   Ví dụ:

Input
3
7 0
1 2 8 10 11 12 19
7 5
1 2 8 10 11 12 19
7 10
1 2 8 10 11 12 19

Output
-1
2
4
*/