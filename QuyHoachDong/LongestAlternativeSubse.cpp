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

int LAS(int *a, int n){
	int inc = 1, dec = 1;

	for (int i = 1; i < n; i++){
		if (a[i] > a[i - 1]){
			inc = dec + 1;
		}
		else if (a[i] < a[i - 1]){
			dec = inc + 1;
		}
	}

	return max(inc, dec);
}

void solve(){
	int n; cin >> n;
	int a[n + 5];
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << LAS(a, n);
}

int main(){
	faster();
	solve();
	return 0;
}

/*
A sequence {X1, X2, .. Xn} is an alternating sequence if its elements 
satisfy one of the following relations : 

  X1 < X2 > X3 < X4 > X5 < …. xn or 
  X1 > X2 < X3 > X4 < X5 > …. xn

Input: arr[] = {10, 22, 9, 33, 49, 50, 31, 60}
Output: 6
Explanation: The subsequences {10, 22, 9, 33, 31, 60} or
{10, 22, 9, 49, 31, 60} or {10, 22, 9, 50, 31, 60}
are longest subsequence of length 6
*/