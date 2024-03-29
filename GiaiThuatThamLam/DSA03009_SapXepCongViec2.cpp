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
	int id, profit, deadline;
};

bool cmp(Job x, Job y){
	return x.deadline > y.deadline;
}

void solve(){
	int n; cin >> n;
	Job a[n + 5];
	for (int i = 0; i < n; i++){
		cin >> a[i].id >> a[i].deadline >> a[i].profit;
	}
	sort(a, a + n, cmp);

	priority_queue<int> pq; //store job's profit (job's deadline >= cur_date)
	int cur_date = a[0].deadline;
	int total_job = 0;
	int idx = 0;
	ll total_profit = 0;
	while (cur_date >= 1){
		while (idx < n && a[idx].deadline >= cur_date){
			pq.push(a[idx].profit);
			++idx;
		}
		if (!pq.empty()){
			total_profit += pq.top();
			++total_job;
			pq.pop();
		}
		
		--cur_date;
	}
	cout << total_job << ' ' << total_profit << EL;
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
Sort giảm dần theo deadline
Ta sẽ đi lần lượt từng thời điểm từ thời điểm max(deadline) về thời điểm 1
chọn công việc có thể thực hiện tại thời điểm cur_date, chọn cviec có
deadline >= cur_date và có profit lớn nhất, cứ thế cho đến khi về thời điểm 1

PROB:
Cho N công việc. Mỗi công việc được biểu diễn như một bộ 3 số nguyên dương <JobId, Deadline, Profit>, trong đó JobId là mã của việc, Deadline là thời gian kết thúc của việc, Profit là lợi nhuận đem lại nếu hoàn thành việc đó đúng hoặc trước thời gian. Thời gian tối thiểu để hoàn thành mỗi công việc là 1 đơn vị thời gian. Hãy cho biết lợi nhuận lớn nhất có thể thực hiện các việc với giả thiết mỗi việc được thực hiện đơn lẻ.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là số lượng Job N; phần thứ hai đưa vào 3×N số tương ứng với N job.
T, N, JobId, Deadline, Profit thỏa mãn ràng buộc:1≤T≤100;  1≤N≤1000; 1≤ JobId ≤1000; 1≤ Deadline ≤1000; 1≤ Profit ≤1000.
Output:

Đưa số lượng công việc tương ứng và lợi nhuận lớn nhất có thể đạt được.
Ví dụ:

Input
2
4
1 4 20
2 1 10
3 1 40
4 1 30
5
1 2 100
2 1 19
3 2 27
4 1 25
5 1 15

Output
2 60
2 127
*/