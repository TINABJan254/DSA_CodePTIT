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
	int a[n + 5], f[n + 5] = {0};
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int res = INT_MIN;
	for (int i = 0; i < n; i++){
		f[a[i]] = f[a[i] - 1] + 1;
		res = max(res, f[a[i]]);
	}
	cout << n - res;
}

int main(){
	faster();
	solve();
	return 0;
}

/*
ta sẽ đi kiểm tra các số liền trước a[i] đã xuất hiện trước đó hay chưa, số lượng
các số liền trước a[i] đã xuất hiện tức là nó đã đúng thứ tự => ta sẽ đi tìm max
cái dãy đã xuất hiện liên tiếp => số lượng các số cần sắp xếp lại đó n - max_e
Cho một dãy số a[] có n phần tử gồm các số từ 1 đến n theo 1 thứ tự ngẫu nhiên. Nhiệm vụ của bạn là sắp xếp lại dãy số này theo thứ tự tăng dần với điều kiện : ở mỗi bước sắp xếp, bạn chỉ được chọn 1 số ở 1 vị trí bất kì và chuyển số đó lên đầu dãy hoặc về cuối dãy.

Hãy tính số bước tối thiểu cần thực hiện để hoàn thành việc sắp xếp.

Input

Dòng đầu tiên ghi 1 số n: số lượng phần tử của dãy a (1 ≤ n ≤ 100000)
Dòng tiếp theo gồm n số từ 1 đến n theo thứ tự ngẫu nhiên
Output

Một số nguyên duy nhất là số bước tối thiểu cần thực hiện để hoàn thành việc sắp xếp.
Ví dụ

Input
5
4 1 2 5 3

Output
2
*/