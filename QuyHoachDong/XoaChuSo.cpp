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

int F[1000005];

int count_recursion(int n){
	if (n == 0) return 0;
	if (F[n] != 0) return F[n];
	int m = n;
	int res = 1e9;
	while (m){
		int r = m % 10;
		if (r != 0){
			res = min(res, count_recursion(n - r) + 1);
		}
		m /= 10;
	}
	F[n] = res;
	return res;
}

int count_DP(int n){
	memset(F, 0, sizeof(F));
	for (int i = 1; i <= n; i++){
		int m = i;
		F[i] = 1e9;
		while (m){
			int r = m % 10;
			if (r != 0)
				F[i] = min(F[i], F[i - r] + 1);
			m /= 10;
		}
	}
	return F[n];
}
void solve(){
	int n; cin >> n;
	cout << count_DP(n);	
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Đệ quy + nhớ = QHD

Ta sẽ đi thử trừ từng chữ số 1 và tìm min
Bạn được cung cấp một số nguyên n. Trên mỗi bước, bạn có thể trừ một trong các chữ số khỏi số. Cần thực hiện bao nhiêu bước để số đó bằng 0?
Input Format
Dòng duy nhất chứa số nguyên n
Constraints
1<=n<=10^6;
Output Format
In ra số bước tối thiểu
Sample Input 0
4
Sample Output 0
1
Sample Input 1
27
Sample Output 1
5
Explanation 1
Các bước thực hiện : 27→20→18→10→9→0

*/
