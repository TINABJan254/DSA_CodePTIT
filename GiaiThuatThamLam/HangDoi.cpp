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
	int a[n + 5];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int t = 0, cnt = 0;
	for (int i = 0; i < n; i++){
		if (a[i] >= t){ //neu a[i] <= t => ko phuc vu nguoi a[i]
			t += a[i];
			++cnt;
		}	
	}
	cout << cnt;
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Cô bé Anna đi mua sắm cùng mẹ và cô băn khoăn không biết làm thế nào để cải thiện chất lượng dịch vụ.
Có n người trong hàng đợi. Đối với mỗi người, chúng tôi biết thời gian cần thiết t để phục vụ anh ta. Một người sẽ thất vọng nếu thời gian anh ta chờ đợi nhiều hơn thời gian cần thiết để phục vụ anh ta. Thời gian một người chờ là tổng thời gian tất cả những người đứng trong hàng đợi trước mặt anh ta được phục vụ. Anna nghĩ rằng nếu chúng ta hoán đổi một số người trong hàng đợi, thì chúng ta có thể giảm số người thất vọng.
Giúp Anna tìm ra con số tối đa mà những người không thất vọng có thể đạt được bằng cách hoán đổi những người trong hàng đợi.
Input Format
Dòng đầu tiên chứa số N là số người trong hàng đợi; Dòng thứ 2 chứa N số là thời gian cần phục vụ của N người
Constraints
1<=N<=10^5; 1<=t<=10^9;
Output Format
In ra đáp án của bài toán
Sample Input 0
7
4 3 17 4 5 14 20 
Sample Output 0
3

*/
