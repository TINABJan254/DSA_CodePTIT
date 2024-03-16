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
int x[1000];
int a[1000][1000];
bool cot[1000], xuoi[1000], nguoc[1000];
int res;

void Init(){
	n = 8;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];
	memset(cot, false, sizeof(cot));
	memset(xuoi, false, sizeof(xuoi));
	memset(nguoc, false, sizeof(nguoc));
	res = -1;
}

void update(){
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += a[i][x[i]];
	res = max(res, sum);
}

void Try(int i){
	for (int j = 1; j <= n; j++){
		if (!cot[j] && !xuoi[i - j + n] && !nguoc[i + j - 1]){
			cot[j] = true;
			xuoi[i - j + n] = true;
			nguoc[i + j - 1] = true;
			x[i] = j;
			if (i == n)
				update();
			else{
				Try(i + 1);
			}
			//backtrack
			cot[j] = false;
			xuoi[i - j + n] = false;
			nguoc[i + j - 1] = false;
		}
	}
}

void solve(){
	Init();
	Try(1);
	cout << res << EL;
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
Cho một bàn cờ 8 x 8, mỗi ô có một giá trị A[i][j] nhất định (0 ≤ A[i][j] ≤ 100), tương ứng với điểm số đạt được nếu như bạn đặt một quân cờ vào đó.

Nhiệm vụ của bạn là đặt 8 quân hậu lên bàn cờ, sao cho không có 2 quân nào ăn nhau, và số điểm đạt được là lớn nhất.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm 8 dòng, mỗi dòng 8 số nguyên mô tả bàn cờ.

Output:  Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:

Input
1
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64

Output
260
*/