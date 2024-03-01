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

int n, res, k;
int x[10005];
int a[10005];
bool final;

void Init(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	memset(x, 0, sizeof(x));
	final = false;
	res = 0;
}

void display(){
	++res;
	for (int i = 1; i <= n; i++)
		if (x[i] == 1)
			cout << a[i] << ' ';
	cout << EL;
}

bool check(){
	ll sum = 0;
	for (int i = 1; i <= n; i++)
		sum += a[i] * x[i];
	return (sum == k);
}

void genNext(){
	int i = n;
	while (i >= 1 && x[i] == 1){
		x[i] = 0;
		--i;
	}

	if (i == 0){
		final = true;
	}
	else {
		x[i] = 1;
	}
}

void solve(){
	Init();
	while (!final){
		if (check())
			display();
		genNext();
	}
	cout << res;
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cho dãy A[] gồm N số tự nhiên khác nhau và số tự nhiên K. 
Hãy viết chương trình liệt kê tất cả các dãy con của dãy số A[] sao cho 
tổng các phần tử trong dãy con đó đúng bằng K. 
Dữ liệu vào trên bàn phím (n=5, K=50), 
5 số dòng thứ 2 là các phần tử dãy A:

   5                      50       

   5                      10                    15                    20                    25   

Các dãy con thoả mãn điều kiện tìm được liệt kê trên màn hình:

Mỗi dòng ghi lại một dãy con. Hai phần tử khác nhau của dãy con được viết cách nhau bởi một  khoảng trống.
Dòng cuối cùng ghi lại số các dãy con có tổng các phần tử đúng bằng K tìm được.
*/