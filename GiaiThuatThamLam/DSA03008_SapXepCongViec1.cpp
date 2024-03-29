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
	int n;
	cin >> n;
	pii a[n + 5];
	for (int i = 0; i < n; i++){
		int x; cin >> x;
		a[i].fi = x;
	}

	for (int i = 0; i < n; i++){
		int x; cin >> x;
		a[i].se = x;
	}

	sort(a, a + n, cmp);
	
	int res = 1;
	pii cur_work = a[0];
	for (int i = 1; i < n; i++){
		if (cur_work.se <= a[i].fi){
			++res;
			cur_work = a[i];
		}
	}
	cout << res;
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
Cho hệ gồm N hành động. Mỗi hành động được biểu diễn như một bộ đôi <Si, Fi> tương ứng với thời gian bắt đầu và thời gian kết thúc của mỗi hành động. Hãy tìm phương án thực hiện nhiều nhất các hành động được thực hiện bởi một máy hoặc một người sao cho hệ không xảy ra mâu thuẫn.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 3 dòng: dòng thứ nhất đưa vào số lượng hành động N; dòng tiếp theo đưa vào N số Si tương ứng với thời gian bắt đầu mỗi hành động; dòng cuối cùng đưa vào N số Fi tương ứng với thời gian kết thúc mỗi hành động; các số được viết cách nhau một vài khoảng trống.
T, N, Si, Fi thỏa mãn ràng buộc: 1≤T≤100;  1≤N, Fi, Si≤1000.
Output:

Đưa số lượng lớn nhất các hành động có thể được thực thi bởi một máy hoặc một người.
Ví dụ:

Input
1
6
1  3  0  5  8  5
2  4  6  7  9  9

Output
4
*/