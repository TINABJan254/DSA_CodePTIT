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
vector<vi> res;

void takeRes(int n){
	vi tmp(a, a + n);
	res.pb(tmp);
}

void display(vi v){
	cout << "[";
	for (int i = 0; i < v.sz - 1; i++){
		cout << v[i] << ' ';
	}
	cout << v[v.sz - 1] << "] ";
}

void backTracking(int n){
	takeRes(n);
	for (int i = 0; i < n-1; i++){
		a[i] = a[i] + a[i + 1];
	}
	if (n != 1){
		backTracking(n - 1);
	}
}

void solve(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	res.clear();
	backTracking(n);
	//display result
	for (int i = res.sz - 1; i >= 0; i--){
		display(res[i]);
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
Cho dãy số A[] gồm n số nguyên dương. Tam giác đặc biệt của dãy số A[] là tam giác được tạo ra bởi n hàng, trong đó hàng thứ n là dãy số A[], hàng i là tổng hai phần tử liên tiếp của hàng i+1 (1≤i≤n-1). Ví dụ A[] = {1, 2, 3, 4, 5}, khi đó tam giác được tạo nên như dưới đây:

[48]

[20, 28]

[8, 12, 16]     

[3, 5, 7, 9 ]

[1, 2, 3, 4, 5 ]

            Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào N là số lượng phần tử của dãy số A[]; dòng tiếp theo đưa vào N số của mảng A[].
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤N, A[i] ≤10;
Output:

Đưa ra kết quả mỗi test theo từng dòng. Mỗi dòng của tam giác tổng được bao bởi ký tự [, ].
Input
1
5
1 2 3 4 5

Output
[48] [20 28] [8 12 16] [3 5 7 9 ] [1 2 3 4 5 ]
*/