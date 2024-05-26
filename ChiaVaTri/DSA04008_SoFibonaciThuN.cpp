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

struct Matrix{
	ll A[2][2];
	Matrix operator * (Matrix &other){
		Matrix res;
		for (int i = 0; i < 2; i++){
			for (int j = 0; j < 2; j++){
				res.A[i][j] = 0;
				for (int k = 0; k < 2; k++){
					res.A[i][j] += this->A[i][k] * other.A[k][j];
					res.A[i][j] %= MOD;
				}
			} 
		}
		return res;
	}
};

Matrix binPow(Matrix a, ll n){
	if (n == 1){
		return a;	
	}
	Matrix x = binPow(a, n / 2);
	if (n % 2 == 0){
		return x * x;
	}
	else{
		return x * x * a;
	}
}

void solve(){
	ll n; cin >> n;
	Matrix x;
	x.A[0][0] = 1;
	x.A[0][1] = 1;
	x.A[1][0] = 1;
	x.A[1][1] = 0;

	x = binPow(x, n);

	cout << x.A[0][1] << EL;
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
			1 1	
Ma trận a = 
			1 0

	   Fn+1  Fn
a^n =
	   Fn    Fn-1

Dãy số Fibonacci được xác định bằng công thức như sau:

F[0] = 0, F[1] = 1;

F[n] = F[n-1] + F[n-2] với mọi n >= 2.

Các phần tử đầu tiên của dãy số là 0, 1, 1, 2, 3, 5, 8, ...

Nhiệm vụ của bạn là hãy xác định số Fibonaci thứ n. Do đáp số có thể rất lớn, 
in ra kết quả theo modulo 109+7.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 1000).

Mỗi test bắt gồm một số nguyên N (1 ≤ N ≤ 109).

Output: 

Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:

Input:
3
2
6
20

Output
1
8
6765
*/