#include <bits/stdc++.h>

using namespace std;

#define EL "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(){
	int n; cin >> n;
	int p = 0, e = 0;
	for (int i = 2; i <= sqrt(n); i++){
		if (n % i == 0){
			++e;
			int mu = 0;
			while (n % i == 0){
				n /= i;
				++mu;
			}
			p += mu;
		}
	}
	
	if (n != 1){
		e++;
		p++;
	}
	
	if (e >= 3) cout << "YES\n";
	else if (e == 2 && p >= 4) cout << "YES\n";
	else if (e == 1 && p >= 6) cout << "YES\n";
	else cout << "NO\n";
	
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Ta có pt 1 số thành tsnt là: n = e1^p1 * e2^p2 * e1^p3.....ek^pk
	gọi e là số lượng e1,...,ek
	    p = p1 + ... + pk;
-> Nếu n có thể pt thành tsnt với e >= 3 thì luôn có đáp án theo ycau bài toán
   Nếu n có thể pt thành tsnt với e = 2 thì phải check nếu p >= 4 thì ok
   Nếu n có thể pt thành tsnt với e = 1 thì phải check nếu p >= 6 thì ok

PROB:
Cho số nguyên dương N, nhiệm vụ của bạn là kiểm tra xem có thể viết N = a * b * c hay không, trong đó a, b, c là 3 số nguyên dương lớn hơn hoặc bằng 2 khác nhau.
Input Format
Dòng duy nhất chứa số nguyên dương N
Constraints
2<=N<=10^9
Output Format
In ra YES nếu có thể biểu diễn N dưới dạng tích của 3 số, ngược lại in ra NO
Sample Input 0
11
Sample Output 0
NO
Sample Input 1
24
Sample Output 1
YES

*/
