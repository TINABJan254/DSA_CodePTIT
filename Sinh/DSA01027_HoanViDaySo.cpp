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

int x[1005];
int root[1005];
int n;

void Init(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> root[i];
	sort(root + 1, root + n + 1);
	for (int i = 0; i < n; i++)
		x[i] = i + 1;
}

void display(){
	for (int i = 0; i < n; i++)
		cout << root[x[i]] << " ";
	cout << EL;
}

void solve(){
	Init();
	do {
		display();
	} while (next_permutation(x, x + n));
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một. Hãy liệt kê tất cả các hoán vị của dãy số A[] theo thứ tự tăng dần, tức là hoán vị đầu tiên có giá trị tăng dần từ trái qua phải, hoán vị cuối cùng giảm dần từ trái qua phải.

Input

Dòng đầu ghi số N (1 < N < 9)

Dòng thứ 2 ghi N số của dãy A[] (0 < A[i] < 10000)

Output

Ghi mỗi hoán vị của dãy số trên một dòng

Ví dụ

Input


3

88 77 99

Output
77 88 99

77 99 88

88 77 99

88 99 77

99 77 88

99 88 77
*/