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
	ll dp[n + 5] = {0};
	dp[0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= 6; j++)
			if (i >= j){
				dp[i] += dp[i - j];
				dp[i] %= MOD;
			}
	}
	cout << dp[n] << EL;
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Đây chính là bài bậc thang

Tèo hiện đang học sinh lớp 10A1, vốn là một học sinh được đánh giá rất cao về
khả năng toán học nên Tèo thường được các bạn trong lớp nhờ giải các bài toán
trên tạp chí toán học và tuổi trẻ. Hôm nay Tí
là bạn thân của Tèo gặp một bài toán trên tạp chí và đã nhờ Tèo giải hộ, Tèo dù
rất giỏi toán và biết cách làm bài này nhưng bài toán này kết quả quá lớn nên
Tèo phải nhờ tới bạn lập trình thuật toán để tìm ra lời giải giúp Tèo. Bài toán có
yêu cầu rất đơn giản, cho ngẫu nhiên số N, hỏi rằng nếu được tung một con xúc
xắc không giới hạn số lần và lấy tổng số chấm trên mặt xúc xắc cộng lại với
nhau, hỏi có bao nhiêu cách tung để tổng số chấm trong mọi lần tung xúc xắc
bằng N. Bạn hãy giúp Tèo giải quyết bài toán này nhé, vì số cách tung có thể quá
lớn, nên bạn hãy chia dư kết quả với modulo 10^9 + 7
Input Format
	Dòng duy nhất chứa số nguyên dương N
Constraints
	1<=N<=10^6;
Output Format
	Kết quả của bài toán
Sample Input 0
	7
Sample Output 0
	63

Sample Input 1
	3
Sample Output 1
	4
*/