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

ll F[100] = {0};

void Init(){
    F[1] = 1;
	F[2] = 1;
	for (int i = 3; i <= 92; i++)
		F[i] = F[i - 1] + F[i - 2];
}

char find(int n, ll k){
	if (n == 1)
		return '0';
	if (n == 2)
		return '1';
	if (k <= F[n - 2])
		return find(n - 2, k);
	return find(n - 1, k - F[n - 2]);
}

void solve(){
	int n; ll k;
	cin >> n >> k;
	
	cout << find(n, k) << EL;
}

int main(){
    Init();
	faster();
	int TC; cin >> TC;
	while (TC--){
	    solve();
	}
	return 0;
}

/*
Người ta tạo ra một dãy xâu ký tự nhị phân X[] trong đó:

X[1] = “0”

X[2] = “1”

X[i] = X[i-2] + X[i-1] với i>2

Với phép cộng (+) là phép nối hai xâu với nhau. 

Cho hai số tự nhiên N và K (1<N<93; K đảm bảo trong phạm vi của xâu X[N]).

Hãy xác định ký tự thứ K trong xâu X[N] là ký tự ‘0’ hay ký tự ‘1’.

Input: Dòng 1 ghi số bộ test. Mỗi bộ test ghi trên một dòng 2 số nguyên N và K.

Output: Ghi ra màn hình kết quả tương ứng với từng bộ test.

Ví dụ:

Input
2
3 1
4 3

Output
0
1
 
*/