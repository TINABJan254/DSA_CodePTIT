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

int n;
int t[100];
vi x;
ll sum, s;
int minE;

void Init(){
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	sum = 0;
	minE = INT_MAX;
	x.clear();
}

void Try(int start){
	for (int j = start; j <= n; j++){
		if (sum + t[j] <= s){
			sum += t[j];
			x.pb(t[j]);
			if (sum == s){
				int tmp = x.sz;
				minE = min(minE, tmp);
			}
			else if (sum < s && x.sz < minE){
				Try(j + 1);
			}
			//backtrack
			sum -= t[j];
			x.pop_back();
		}
	}
}

void solve(){
	Init();
	Try(1);
	if (minE == INT_MAX){
		cout << "-1\n";
	}
	else
		cout << minE << EL;
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
Một máy ATM hiện có n (n ≤ 30) tờ tiền có giá trị t[1], t[2], …, t[n]. Hãy tìm cách trả ít tờ nhất với số tiền đúng bằng S (các tờ tiền có giá trị bất kỳ và có thể bằng nhau, mỗi tờ tiền chỉ được dùng một lần).

Input: Dòng đầu tiên ghi số bộ test T (T<10). Mỗi bộ test gồm 2 số nguyên n và S (S ≤ 109). Dòng thứ hai chứa n số nguyên t[1], t[2], …, t[n] (t[i] ≤ 109)

Output: Với mỗi bộ test ghi ra số tờ tiền ít nhất phải trả.

     Nếu không thể tìm được kết quả, in ra -1.

Ví dụ

Input
1
3 5
1 4 5

Output
1
*/