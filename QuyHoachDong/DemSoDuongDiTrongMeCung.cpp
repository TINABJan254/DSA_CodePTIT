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

ll F[1005][1005];

void solve(){
	int n; cin >> n;
	char a[n + 5][n + 5];
	for (int i = 1; i <= n; i++)	
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	F[0][1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (a[i][j] == '.'){
				F[i][j] = F[i - 1][j] + F[i][j - 1];
				F[i][j] %= MOD;
			}
			else 
				F[i][j] = 0;

	cout << F[n][n];

}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cho mê cung được mô tả bởi một ma trận kí tự gồm N hàng và N cột. 
Mỗi ô trên ma trận chứa kí tự '.' tương ứng với đường đi và dấu * tương ứng 
với bẫy. Một con chuột muốn đi từ ô (1, 1) tới ô (N, N) và chỉ được di 
chuyển khi một ô nào đó là đường đi và nó được di chuyển sang phải hoặc 
xuống dưới. Hãy đếm số cách con chuột có thể di chuyển tới đích. 
Vì kết quả quá lớn nên hãy lấy dư với 10^9 + 7
Input Format
Dòng đầu tiên là N; N dòng tiếp theo mỗi dòng là N kí tự
Constraints
1<=N<=1000
Output Format
Số đường đi tối đa
Sample Input 0
4
....
.*..
...*
*...
Sample Output 0
3

*/