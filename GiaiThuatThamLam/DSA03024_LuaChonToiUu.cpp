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

bool cmp(pii x, pii y){
	if (x.se != y.se)
		return x.se < y.se;
	return x.fi < y.fi;
}

void solve(){
	int n; cin >> n;
	pii Task[n + 5];
	for (int i = 0; i < n; i++){
		cin >> Task[i].fi >> Task[i].se;
	}
	sort(Task, Task + n, cmp);

	int num = 1;
	pii cur_task = Task[0];
	for (int i = 1; i < n; i++){
		if (cur_task.se <= Task[i].fi){
			++num;
			cur_task = Task[i];
		}
	}

	cout << num << EL;
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
Bạn được giao cho N công việc, công việc thứ i có thời gian bắt đầu là A[i] và kết thúc tại B[i]. 
Tại một thời điểm, bạn chỉ có thể làm một công việc.

Bạn hãy lựa chọn các công việc một cách tối ưu sao cho số công việc làm được là nhiều nhất.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 10).

Mỗi test gồm 1 số nguyên N ( 1 ≤ N ≤ 100 000).

N dòng tiếp theo, mỗi dòng gồm 2 số A[i] và B[i] (0 ≤ A[i] < B[i] ≤ 106).

Output:  Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:
Input
1
6
5 9
1 2
3 4
0 6
5 7
8 9

Output
4
*/