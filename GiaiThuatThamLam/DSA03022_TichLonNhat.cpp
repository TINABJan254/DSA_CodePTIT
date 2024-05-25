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
#define pci pair<char, int>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(){
	int n; cin >> n;
	int a[n + 5];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	ll res = max({1ll*a[0] * a[1], 
				  1ll*a[n-1] * a[n-2], 
				  1ll*a[n-1] * a[n-2] * a[n-3], 
				  1ll*a[n-1] * a[0] * a[1]});
	cout << res;
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Note: Phải tính cả trường hợp tồn tại số âm
	2 số dương lớn nhất
	2 số âm bé nhất
	3 số dương lớn nhất
	2 số âm bé nhất * 1 số dương lớn nhất.
	
PROB:
Cho dãy số A gồm N phần tử là các số nguyên. 
Hãy tính tích lớn nhất của 2 hoặc 3 phần tử trong dãy.

Input

Dòng đầu tiên ghi số N (3 ≤ N ≤ 10000)

Dòng thứ 2 ghi N số của dãy A (|Ai| ≤ 1000)

Outpput

Ghi ra kết quả trên một dòng

Ví dụ

Input
6
5 10 -2 3 5 2

Output
250
*/