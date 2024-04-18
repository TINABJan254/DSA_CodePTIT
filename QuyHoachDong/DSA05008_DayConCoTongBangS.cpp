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
	int s, n; cin >> n >> s;
	int a[n + 5];
	int F[s + 5] = {0};
	for (int i = 0; i < n; i++) cin >> a[i];

	F[0] = 1; //luon ton tai tap con co tong bang 0 (tap rong)
	for (int i = 0; i < n; i++){
		//dung a[i] => xay dung tap con co tong bang [0->s];
		for (int j = s; j >= a[i]; j--){
			if (F[j-a[i]] == 1){
				F[j] = 1;
			}
		}
	}

	if (F[s] == 1){
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
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
Sub set sum

Khi dùng a[i] để xây dựng tập con tổng bằng s
	có thể nếu: đã tồn tại s-a[i] hay f[s-a[i]] = 1
	ko thể nếu: ngược lại
Cho N  số nguyên dương tạo thành dãy A={A1, A2, ..., AN}. Tìm ra một dãy con của dãy A (không nhất thiết là các phần tử liên tiếp trong dãy) có tổng bằng S cho trước.

Input: Dòng đầu ghi số bộ test T (T<10).  Mỗi bộ test có hai dòng, dòng đầu tiên ghi hai số nguyên dương N và S (0 < N ≤ 200) và S (0 < S ≤ 40000). Dòng tiếp theo lần lượt ghi N số hạng của dãy A là các số A1, A2, ..., AN (0 < Ai ≤ 200).

Output:  Với mỗi bộ test, nếu bài toán vô nghiệm thì in ra “NO”, ngược lại in ra “YES”

Ví dụ:

Input
2
5 6
1 2 4 3 5
10 15
2 2 2 2 2 2 2 2 2 2

Output
YES
NO
*/