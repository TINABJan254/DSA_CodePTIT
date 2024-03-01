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

int n, k;
int x[1005];
char root[1005];

bool final;

void Init(){
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
		x[i] = i;
	char st = 'A';
	for (int i = 1; i <= n; i++)
		root[i] = st++;
	final = false;
}

void display(){
	for (int i = 1; i <= k; i++)
		cout << root[x[i]];
	cout << EL;
}

void genNext(){
	int i = k;
	while (i >= 1 && x[i] == n-k+i){
		--i;
	}

	if (i == 0){
		final = true;
	}
	else {
		x[i++]++;
		for (i; i <= k; i++)
			x[i] = x[i - 1] + 1;
	}
}

void solve(){
	Init();
	while (!final){
		display();
		genNext();
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
Vương quốc PTIT sử dụng bảng chữ cái gồm N chữ cái Latinh viết hoa. Quy tắc đặt tên của gia đình Hoàng gia  PTIT là chọn ra K chữ cái (không trùng nhau) và sắp xếp lại theo thứ tự từ điển.

Hãy liệt kê tất cả các cái tên có thể có của gia đình Hoàng gia PTIT

Input

Dòng đầu ghi số bộ test T (không quá 10)
Mỗi bộ test ghi 2 số N và K (3 < K < N < 16)
Output

Với mỗi bộ test, ghi ra tất cả các cái tên có thể được tạo ra, mỗi kết quả viết trên một dòng.

Input
1
4 2

Output
AB
AC
AD
BC
BD
CD
*/