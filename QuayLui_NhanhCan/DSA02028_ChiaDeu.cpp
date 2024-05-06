//WA
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

int n, k, check, res;
int a[50], sum[50];

void Init(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	check = sum[n] / k;
	res = 0;
}

void Try(int i, int cnt){
	if (cnt == k){
		if (i == n){
			++res;
			return;
		}	
		else
			Try(i + 1, 0);
	}
	for (int j = i + 1; j <= n; j++)
		if (sum[j] - sum[i] == check)
			Try(j, cnt + 1);
}

void solve(){
	Init();
	if (sum[n] % k != 0){
		cout << "0";
		return;
	}
	Try(1, 0);
	cout << res;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
	#endif
	faster();
	solve();
	return 0;
}

/*
Cho dãy số A có N phần tử và số K. Hãy đếm số cách chia dãy A thành K nhóm các phần tử liên tiếp sao cho tổng 
giá trị của mỗi nhóm đều bằng nhau.

Input

Dòng đầu ghi hai số N và K (0 < N ≤ 12; 0 < K < N ).

Dòng thứ 2 ghi N số của dãy A (-10000 ≤ A[i] ≤ 10000)

Output

In ra số cách thỏa mãn

Ví dụ

Input
3 2
-2 0 -2
Output
2

Input
3 2
1 2 3
Output
1
*/
