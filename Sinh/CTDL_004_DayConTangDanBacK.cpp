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
int root[1005];
bool final;

void Init(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> root[i];
	for (int i = 1; i <= k; i++)
		x[i] = i;
	final = false;
}

bool checkValid(){
	for (int i = 1; i < k; i++)
		if (root[x[i]] > root[x[i + 1]])
			return false;
	return true;
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
	int res = 0;
	while (!final){
		if (checkValid())
			++res;
		genNext();
	}
	cout << res;
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cho dãy gồm N số phân biệt AN = {a1, a2, .., aN } và số tự nhiên K (K<=N<=100). Ta gọi một dãy con tăng dần bậc K của dãy số AN là một dãy các số gồm K phần tử trong dãy đó thỏa mãn tính chất tăng dần. Bài toán được đặt ra là in ra màn hình  số các dãy con tăng dần bậc K của dãy số AN. Ví dụ :

Input:
5 3
2 5 15 10 20   

Dòng đầu tiên ghi lại hai số N và K tương ứng với số phần tử của dãy số và bậc của dãy con.
Dòng kế tiếp : N số của dãy số AN, các số trong dãy không lớn hơn 100. 
thì Output : 7 (số các dãy con tăng dần bậc 3 của dãy số AN)
*/