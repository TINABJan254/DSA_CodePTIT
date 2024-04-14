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
	int a[n+5];
	int dp[n+5];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}

	for (int i = 0; i < n; i++){
		dp[i] = 1;
		for (int j = 0; j < i; j++){
			if (a[j] < a[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	cout << *max_element(dp, dp + n);
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cho một dãy số nguyên gồm N phần tử A[1], A[2], ... A[N]. 

Biết rằng dãy con tăng là 1 dãy A[i1],... A[ik]

thỏa mãn i1 < i2 < ... < ik và A[i1] < A[i2] < .. < A[ik].

Hãy cho biết dãy con tăng dài nhất của dãy này có bao nhiêu phần tử? 

Input: Dòng 1 gồm 1 số nguyên là số N (1 ≤ N ≤ 1000). Dòng thứ 2 ghi N số nguyên A[1], A[2], .. A[N] (1 ≤ A[i] ≤ 1000). 

Output: Ghi ra độ dài của dãy con tăng dài nhất.

Ví dụ:

Input
6
1 2 5 4 6 2

Output
4
*/