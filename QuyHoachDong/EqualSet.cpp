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

ll powMod(ll a, ll b, ll m){
	ll res = 1;
	a %= m;
	while (b){
		if (b % 2 != 0){
			res *= a;
			res %= m;
		}
		a *= a;
		a %= m;
		b /= 2;
	}
	return res;	
}

ll Inverse(ll a, ll m){
	return powMod(a, m - 2, m);
}

void solve(){
	int n; cin >> n;
	int s = n*(n + 1) / 2;
	if (s % 2 == 0){
		s /= 2;
		int dp[s + 5] = {0};
		dp[0] = 1;
		for (int i = 1; i <= n; i++){
			for (int j = s; j >= i; j--){
				dp[j] += dp[j - i];
				dp[j] %= MOD;
			}
		}
		
		cout << (dp[s] * Inverse(2, MOD)) % MOD;
	}
	else{
		cout << 0;
	}
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Note phai dung modulo inverse
Nhiệm vụ của bạn là đếm số cách các số 1,2,…, n có thể chia thành hai tập có tổng bằng nhau. Các phần tử trong tập không xét đến thứ tự Ví dụ, nếu n = 7, có bốn nghiệm: {1,3,4,6} và {2,5,7}. {1,2,5,6} và {3,4,7}. {1,2,4,7} và {3,5,6}. {1,6,7} và {2,3,4,5}.
Input Format
Dòng duy nhất chứa số nguyên dương n
Constraints
1<=n<=500
Output Format
In ra kết quả sau khi chia dư với 10^9 + 7
Sample Input 0
7
Sample Output 0
4

*/
