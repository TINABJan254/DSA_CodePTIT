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

int n;

struct Matrix{
	ll A[20][20];
	Matrix operator * (Matrix &other){
		Matrix res;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				res.A[i][j] = 0;
				for (int k = 0; k < n; k++){
					res.A[i][j] += this->A[i][k] * other.A[k][j];
					res.A[i][j] %= MOD;
				}
			}
		}
		return res;
	}
};

Matrix binPow(Matrix x, ll k){
	if (k == 1)
		return x;
	Matrix res = binPow(x, k / 2);
	if (k & 1)
		return x * res * res;
	return res * res;
}

void solve(){
	ll k;
	Matrix x;
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cin >> x.A[i][j];
	}

	x = binPow(x, k);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cout << x.A[i][j] << ' ';
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
Cho ma trận vuông A kích thước N x N. Nhiệm vụ của bạn là hãy tính ma trận X = AK với K là số nguyên cho trước. 
Đáp số có thể rất lớn, hãy in ra kết quả theo modulo 109+7.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 100).

Mỗi test bắt gồm một số nguyên N và K (1 ≤ N ≤ 10, 1 ≤ K ≤ 109) là kích thước của ma trận và số mũ.

Output: 

Với mỗi test, in ra kết quả của ma trận X.

Ví dụ:

Input:
2
2 5
1 1
1 0
3 1000000000
1 2 3
4 5 6
7 8 9

Output
8 5
5 3
597240088 35500972 473761863
781257150 154135232 527013321
965274212 272769492 580264779
*/