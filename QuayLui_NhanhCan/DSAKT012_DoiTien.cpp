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

int n, s;
int a[105];
int res;
vi v;

void Init(){
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	res = INT_MAX;
	v.clear();
}

void Try(int start, int cur_sum){
	for (int j = start; j <= n; j++){
		if (cur_sum + a[j] <= s){
			v.pb(a[j]);
			if (cur_sum + a[j] == s){
				res = min(res, (int)v.sz);
			}
			else if (v.sz < res)
				Try(j + 1, cur_sum + a[j]);
			v.pop_back();
		}
	}
}

void solve(){
	Init();
	Try(1, 0);
	if (res == INT_MAX)
		cout << "-1";
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