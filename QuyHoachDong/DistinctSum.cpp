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

void solve(){
	int n; cin >> n;
	int maxSum = 0;
	int a[n + 5];
	for (int i = 0; i < n; i++){
		cin >> a[i];
		maxSum += a[i];
	}

	int F[maxSum + 5] = {0};
	F[0] = 1;
	for (int i = 0; i < n; i++){
		for (int j = maxSum; j >= a[i]; j--)
			if (F[j - a[i]] == 1){
				F[j] = 1;
			}
	}

	for (int i = 0; i <= maxSum; i++)
		if (F[i] == 1)
			cout << i << ' ';
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cho mảng A có N phần tử, xét all tập con của A, tính tổng các phần tử trong tập này
gồm cả tập rỗng, liệt kê các tổng khác nhau có thể tạo thành theo thứ tự tăng dần 

Input format
	Dòng 1: N
	Dòng 2: N phần tử của mảng A

Constraints
	1 <= N <= 100;
	1 <= A[i] <= 100;
Output format
	In ra các tổng khác nhau có thể tạo thành

Sample
Input
	3
	4 1 2
Output
	0 1 2 3 4 5 6 7
*/