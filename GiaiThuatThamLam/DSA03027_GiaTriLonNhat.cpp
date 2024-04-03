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
	ll res = 0;
	for (int i = 0; i < n; i++){
		ll x; cin >> x;
		if (x > 0)
			res += x * 2;
	}
	cout << res;
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Giá trị lớn nhất của f + g đó chính là khi lấy tất cả các phần tử dương
của mảng, vậy thì ở đây đó là i, j chính là 1, n. Lấy tất cả các số của mảng 
vì như vậy mới đảm bảo lấy được hết số dương, còn lại các số âm thì 
-a[i] sẽ triệt tiêu với abs(-a[i]).

PROB:
Cho dãy số nguyên A[] có N phần tử.

Gọi f(i,j) = |ai| + |ai+1| + … + |aj|
Goij g(i,j) = ai + ai+1 + … + aj
Với tất cả các cặp 1 ≤ i ≤ j ≤ N.

Hãy tính giá trị lớn nhất của f(i,j) + g(i,j).

Input

Dòng đầu ghi số N (1 ≤ N ≤ 50000)

Dòng thứ 2 ghi N số nguyên của dãy A[]

Output

Ghi ra giá trị lớn nhất của f(i,j) + g(i,j)

Ví dụ

Input
5
-3 5 -10 8 -2

Output
26
*/