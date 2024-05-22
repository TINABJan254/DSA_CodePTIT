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
int x[100];
bool cot[100], xuoi[100], nguoc[100];
int res;

void Init(){
	cin >> n;
	memset(cot, false, sizeof(cot));
	memset(xuoi, false, sizeof(xuoi));
	memset(nguoc, false, sizeof(nguoc));
	res = 0;
}

void Try(int i){
	for (int j = 1; j <= n; j++){
		if (!cot[j] && !xuoi[i - j + n] && !nguoc[i + j - 1]){
			cot[j] = true;
			xuoi[i - j + n] = true;
			nguoc[i + j - 1] = true;
			x[i] = j;
			if (i == n)
				++res;
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
Xuoi : dau huyen i-j+n
Nguoc : dau sac  i+j-1
Cho một bàn cờ vua có kích thước n * n, ta biết ràng quân hậu có thể di chuyển theo chiều ngang, dọc, chéo. Vấn đề đặt ra rằng, có n quân hậu, bạn cần đếm số cách đặt n quân hậu này lên bàn cờ sao cho với 2 quân hậu bất kì, chúng không “ăn” nhau.

Input: Dòng đầu ghi số bộ test T (T<5). Mỗi bộ test ghi một số nguyên dương n duy nhất (không quá 10)

Output:  Ghi kết quả mỗi bộ test trên một dòng. Số cách đặt quân hậu.

Ví dụ:

Input
1
4

Output
2
*/