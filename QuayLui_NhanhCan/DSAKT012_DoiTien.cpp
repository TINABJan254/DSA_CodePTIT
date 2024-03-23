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

int t[105];
int n, s, res;
bool flag;

void Init(){
	cin >> n >> s;
	for (int i = 1; i <= n; i++){
		cin >> t[i];
	}
	sort(t + 1, t + n + 1, greater<int>());
	res = INT_MAX;
	flag = false;
}

void Try(int i, int cur_sum, int start){
	for (int j = start; j <= n; j++){
		if (cur_sum + t[j] == s){
			res = min(res, i);
			flag = true;
			return;
		}
		else if (i < n && cur_sum + t[j] < s){
			Try(i + 1, cur_sum + t[j], j + 1);
		}
	}
}

void solve(){
	Init();
	Try(1, 0);
	if (!flag)
		cout << -1;
	else
		cout << res;
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Có n tờ tiền có giá trị t[1], t[2], …, t[n].

Hãy tìm cách trả ít tờ tiền nhất với số tiền đúng bằng S

Chú ý: Các tờ tiền có giá trị bất kỳ và có thể bằng nhau, mỗi tờ tiền chỉ được dùng một lần.

Input

Mỗi bộ test gồm 2 số nguyên n và S (n ≤ 30; S  ≤  109).

Dòng thứ hai chứa n số nguyên t[1], t[2], …, t[n] (t[i] ≤ 109)

Output: 

Ghi ra trên một dòng số tờ tiền ít nhất phải trả.

Nếu không thể tìm được kết quả, in ra -1.

Ví dụ

Input
3 5
1 4 5

Output
1
*/