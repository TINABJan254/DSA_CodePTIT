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

bool isPrime(int m){
	for (int i = 2; i <= sqrt(m); i++){
		if (m % i == 0)
			return false;
	}
	return m > 1;
}

void Try(int i, int start){
	for (int j = start; j <= n; j++){
		sum += a[j];
		x[i] = a[j];
		if (isPrime(sum)){
			vi tmp(x + 1, x + i + 1);
			sort(tmp.begin(), tmp.end(), greater<int>());
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
Cho dãy số A[] có N phần tử là các số nguyên dương khác nhau từng đôi một. Hãy liệt kê tất cả các dãy con của A[] có tổng các phần tử là số nguyên tố.

Các dãy con được liệt kê theo thứ tự từ điển tăng dần.

Input

Dòng đầu ghi số bộ test, mỗi test có 2 dòng:

Dòng đầu ghi số N (2 < N <15)
Dòng thứ 2 ghi N số của dãy A[], các số đều nguyên dương, nhỏ hơn 100 và khác nhau từng đôi một.
Output

Với mỗi test, liệt kê tất cả các dãy con có tổng các phần tử là số nguyên tố theo thứ tự từ điển tăng dần, mỗi dãy con trên một dòng. 

Ví dụ

Input
1
4
3 2 5 4

Output
2
3
3 2
4 3
5
5 2
5 4 2
*/