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

struct Job{
	int start, finish;
	ll profit;
};

bool cmp(Job x, Job y){
	return x.finish < y.finish;
}

int first_pos(Job *a, int index, int x){
	int L = 1, R = index - 1;
	int res = -1;
	while (L <= R){
		int mid = (L + R) / 2;
		if (a[mid].finish <= x){
			res = mid;
			L = mid + 1;
		}
		else
			R = mid - 1;
	}
	return res;
}

void solve(){
	int n; cin >> n;
	Job a[n + 5]; 
	for (int i = 1; i <= n; i++)
		cin >> a[i].start >> a[i].finish >> a[i].profit;
	
	//find max profit
	sort(a + 1, a + 1 + n, cmp);
	ll *dp = new ll[n+1];
	memset(dp, 0, sizeof(dp));
	dp[1] = a[1].profit;
	
	for (int i = 2; i <= n; i++){
		//Find profit including the current job
		ll inclProf = 0;
		int pos = first_pos(a, i, a[i].start - 1); //Find the latest job (in sorted array) that doesn't conflict with the job[i]
		if (pos != -1){
			inclProf = dp[pos] + a[i].profit; //Include the i job
		}
		//Store maximum of including and excluding the i job
		dp[i] = max(inclProf, dp[i - 1]);
		
		/* Ngan hon, dung chinh ct truy hoi
		if (pos == -1)
			dp[i] = max(a[i], dp[i - 1]); //Ko thay job thu i
		else
			dp[i] = max(a[i] + dp[pos], dp[i - 1]); //Lay job thu i
		*/
		
	}
	
	cout << dp[n];
	delete[] dp; 
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Weighted job scheduling DP (GFG)

dp[i] : lợi nhuận lớn nhất tính đến lúc xét job i(có thể chọn job i hoặc ko)

Có n dự án bạn có thể tham dự. Đối với mỗi dự án, bạn biết ngày bắt đầu và ngày kết thúc của 
dự án và số tiền bạn sẽ nhận được khi hoàn thành nó. Bạn chỉ có thể tham dự một dự án trong 
một ngày. Số tiền tối đa bạn có thể kiếm được là bao nhiêu?
Input Format
Dòng đầu tiên chứa số nguyên n: số lượng dự án. Sau đó, có n dòng. Mỗi dòng như vậy có ba số 
nguyên ai, bi và pi: ngày bắt đầu, ngày kết thúc và tiền thưởng.
Constraints
1≤n≤2⋅10^5; 1≤ai≤bi≤10^9; 1≤pi≤10^9;
Output Format
In ra đáp án của bài toán
Sample Input 0
4
2 4 4
3 6 6
6 8 2
5 7 3
Sample Output 0
7

*/
