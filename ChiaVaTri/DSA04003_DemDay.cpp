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

ll powMod(ll a, ll b){
	a %= 123456789;
	ll res = 1;
	while (b){
		if (b & 1){
			res *= a;
			res %= 123456789;
		}
		a *= a;
		a %= 123456789;
		b >>= 1;
	}
	return res;
}

void solve(){
	ll n;
	cin >> n;
	cout << powMod(2, n - 1) << EL;
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
Bài này sẽ áp dụng bài toán chia kẹo euler có n cái kẹo chia cho k người, mỗi người ít nhất 1 cái 
công thức là (n - 1)C(k - 1)

Dãy ở đây có thể có  i = (1,2,...,n) phần tử sao cho tổng các phần tử bằng n
=> áp dụng bài toán chia kẹo euler cho từng trường hợp có i phần tử với phát biểu đó
   là chia n cái kẹo cho i người
	vd: i = 1; bài toán đặt ra đó là chia n cái kẹo cho 1 người 
			   mỗi người ít nhất 1 cái => (n-1)C0 cách
	    i = 2; bài toán đặt ra đó là chia n cái kẹo cho 2 người 
	           mỗi người ít nhất 1 cái => (n-1)C1 cách
	    ....
	    i = n; bài toán đặt ra đó là chia n cái kẹo cho n người 
	    	   mỗi người ít nhất 1 cái => (n-1)C(n-1) cách
	tổng các bài toán nhỏ đó là đáp án
		(n-1)C0 + (n-1)C1 + (n-2)C2 + .... + (n-1)C(n-1) = 2^(n-1)
=> Quy về toán toán tính lũy thừa 

Cho số nguyên dương n. Hãy cho biết có bao nhiêu dãy số nguyên dương có tổng các phần tử trong dãy bằng n. 

Dữ liệu vào: dòng đầu tiên chứa số nguyên T là số bộ dữ liệu, mỗi bộ dữ liệu ghi một số nguyên dương n duy nhất không qua 1018. 

Kết quả: Mỗi bộ dữ liệu ghi ra một số nguyên duy nhất là số dư của kết quả tìm được khi chia cho 123456789.

Ví dụ:

Input
1
3

Output
4
*/