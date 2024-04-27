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

int dp[1005][1005];

int count(int n, int m){
	if (n == m)
		return 0;
	if (dp[n][m] != 0)
		return dp[n][m];
	int res = 1e9;
	for (int i = 1; i <= m - 1; i++){
		res = min(res, count(n, i) + count(n, m - i) + 1); //cat doc
	}
	for (int i = 1; i <= n - 1; i++){
		res = min(res, count(i, m) + count(n - i, m) + 1); //cat ngang
	}
	dp[n][m] = res;
	return res;
}

void solve(){
	int n, m; cin >> n >> m;
	cout << count(n, m);	
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Top - down: Recur + nho
Bottom - up: QHD

Ta sẽ có 2 cách cắt : cắt dọc hoặc cắt ngang
Hình n*m
	TH cắt dọc:
		n*m = n*i + n*(m - i); 	//với i = 1...n-1 (chạy đến n - 1 vì nếu cắt ra thành n*m thì khác gì ban đầu)
	TH cắt ngang:
		n*m = i*m + (n - i)*m;  //với i = 1...m-1 
	=> ta sẽ đi tìm min của tất cả cách cắt
Ở bài này sẽ dùng đệ quy có nhớ (top - down)

Cho một hình chữ nhật a × b, nhiệm vụ của bạn là cắt nó thành các hình vuông. 
Trên mỗi lần cắt, bạn có thể chọn một hình chữ nhật và cắt nó thành hai hình chữ nhật sao cho tất 
cả độ dài các cạnh vẫn là số nguyên. Số lần di cắt tối thiểu có thể là bao nhiêu?
Input Format
Dòng duy nhất chứa 2 số nguyên a và b.
Constraints
1<=a,b<=500;
Output Format
In ra số lần cắt tối thiểu
Sample Input 0
3 5
Sample Output 0
3

*/
