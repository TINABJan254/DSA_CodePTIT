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

int n, p, s;
int sum;
int x[105];
vector<vi> res;

void Init(){
	cin >> n >> p >> s;
	sum = 0;
	res.clear();
}

bool isPrime(int m){
	for (int i = 2; i <= sqrt(m); i++)
		if (m % i == 0)
			return false;
	return m > 1;
}



void Try(int i, int start){
	if (i > n)
		return;
	for (int j = start; j <= s; j++){
		if (isPrime(j) && sum + j <= s){
			sum += j;
			x[i] = j;
			if (i == n){
				if (sum == s){
					vi tmp(x + 1, x + n + 1);
					res.pb(tmp);
				}
			}
			else{
				Try(i + 1, j + 1);
			}
			sum -= j;
		}
	}
}

void solve(){
	Init();
	Try(1, p + 1);
	sort(res.begin(), res.end());
	cout << res.sz << EL;
	for (auto tmp : res){
		for (auto tmp2 : tmp)
			cout << tmp2 << ' ';
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
Cho ba số N, P, S. Trong đó, P là một số nguyên tố. Nhiệm vụ của bạn là đưa ra tất cả N số nguyên tố lớn hơn P có tổng bằng S. Ví dụ với S = 28, P=7, N =2 ta có kết quả 11 + 17 = 28. Với N = 3, P = 2, S = 23 ta có kết quả : {3, 7, 13}, {5, 7, 11}

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là bộ ba số S, P, N được viết trên một dòng.
S, P, N thỏa mãn ràng buộc: 1≤T ≤100; 1 ≤ N ≤ 10; 2≤S, P≤200.
Output:

Với mỗi test, dòng đầu tiên in ra số lượng đáp án tìm được. Mỗi dòng tiếp theo in ra kết quả tìm được theo thứ tự từ điển.
Input
2
2  7  28
3  2  23

Output
1
11 17
2
3 7 13
5 7 11
*/