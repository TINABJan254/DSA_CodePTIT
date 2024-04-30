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

ll dp[100005][105];

void solve(){
	int n, m; cin >> n >> m;
	int a[n + 5];
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	if (a[1] != 0){
		dp[1][a[1]] = 1; //vi tri dau tien de da cho so
	}
	else{
		for (int j = 1; j <= m; j++) //vi tri dau tien la so chua xac dinh
			dp[1][j] = 1;
	}
	for (int i = 2; i <= n; i++){
		if (a[i] == 0){
			for (int j = 1; j <= m; j++){
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
				dp[i][j] %= MOD;
			}
				
		}
		else {
			dp[i][a[i]] = dp[i - 1][a[i] - 1] + dp[i - 1][a[i]] + dp[i - 1][a[i] + 1];
			dp[i][a[i]] %= MOD;
		}
	}
	
	int res = 0;
	for (int j = 1; j <= m; j++){
		res += dp[n][j];
		res %= MOD;
	}
	cout << res;
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Bài toán này sẽ giải theo tư tưởng số đang điền sẽ phù hợp với số ngay phía trước, tức là 
a[i] chênh a[i - 1] ko quá 1 đvi (đang điền tại vị trí i). 

dp[i][j] : lưu số cách điền tại vị trí i điền số j
Ta có công thức truy hồi
	dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]; 
		Tức là vị trí i muốn điền số j, thì ví trí phía trước là i-1 phải có các giá trị j-1, j, j+1
		chênh với j ko quá 1 đvi
	đấy là công thức với trường hợp vị trí đó chưa phù hợp
	còn nếu vị trí đó đã phù hợp thì
		dp[i][a[i]] = dp[i-1][a[i]-1] + dp[i-1][a[i]] + d[i-1][a[i]+1];
Chú ý với trường hợp vị trí đầu tiên là số vô định hoac số đã đc đề cho
Bạn biết rằng một mảng có n số nguyên chỉ gồm các số từ 1 đến m và độ lệch giữa 2 phần tử liền kề 
trong mảng không được vượt quá 1 đơn vị. Bài toán đặt ra đó là cho bạn một mảng trong đó một 
số giá trị trong mảng chưa được xác định giá trị, nhiệm vụ của bạn là đếm số mảng phù hợp với 
mô tả, đó là các số liền kề trong mảng không lệch nhau quá 1 đơn vị và các giá trị trong mảng 
chỉ được nằm trong đoạn từ 1 tới m.
Input Format
Dòng nhập đầu tiên có hai số nguyên n và m: kích thước mảng và giới hạn trên cho mỗi giá trị.
Dòng tiếp theo có n số nguyên x1, x2,…, xn: nội dung của mảng. Giá trị 0 biểu thị một giá trị 
không xác định.
Constraints
1≤n≤10^5;
1≤m≤100; 0≤xi≤m;
Output Format
In ra số lượng mảng phù hợp sau khi chia dư cho 1e9 + 7
Sample Input 0
3 5
2 0 2
Sample Output 0
3
Explanation 0
Các mảng có thể thỏa mãn : [2, 1, 2], [2, 2, 2], [2, 3, 2]

*/
