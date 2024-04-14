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
	int a[n + 5];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cout << (upper_bound(a, a + n, 0) - a) << EL;
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
Cho mảng A[] gồm N phần tử chỉ bao gồm các số 0 và 1. 
Các số 0 được đặt trước các số 1. Hãy đếm các số 0 với thời gian log(N).

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng thứ nhất đưa vào số N; dòng tiếp theo đưa vào N số của mảng A[]; các số được viết cách nhau một vài khoảng trống.
T, N, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤1000; 0≤ A[i]≤1.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
  Ví dụ:

Input
3
12
0 0 0 0 0 0 0 0 0 1 1 1 
5
0 0 0 0 0
6
1 1 1 1 1 1

Output
9
5
0
*/