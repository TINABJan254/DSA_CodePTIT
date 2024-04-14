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

int findPos(ll *a, ll *b, int L, int R){
	int res = -1;
	while (L <= R){
		int mid = (L + R) / 2;
		if (a[mid] != b[mid]){
			res = mid;
			R = mid - 1;
		}
		else if (a[mid] == b[mid]){
			L = mid + 1;
		}
	}

	return res + 1;
}

void solve(){
	int n; cin >> n;
	ll a[n + 5], b[n + 5];

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n -1; i++)
		cin >> b[i];
	cout << findPos(a, b, 0, n) << EL;
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
Cho hai mảng đã được sắp xếp A[] và B[] gồm N và N-1 phần tử. Các phần tử của mảng A[] chỉ khác mảng B[] một phần tử duy nhất. Hãy tìm vị trí của phần tử khác nhau giữa A[] và B[].

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào số N; dòng tiếp theo đưa vào N số của mảng A[];dòng tiếp theo đưa vào N-1 số của mảng B[]; các số được viết cách nhau một vài khoảng trống.
T, N, A[i], B[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤ N≤107; 0≤ A[i]≤1018.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
2
7
2 4 6 8 9 10 12
2 4 6 8 10 12
6
3 5 7 9 11 13
3 5 7 11 13

Output
5
4
*/