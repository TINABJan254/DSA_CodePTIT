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
	int a[n + 5];
	for (int i = 0; i < n; i++) cin >> a[i];

	sort(a, a + n);
	int cnt = 0; //count pair	
	int L = n >> 1, mid = n >> 1, R = n - 1;
	while (L >= 0 && R >= mid){
		if (a[R] >= a[L] << 1){
			++cnt;
			--L; --R;
		}
		else{
			--L;
		}
	}

	cout << n - cnt*2 + cnt << EL;
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
 n >> 1 : n / 2;
 n << 1 : n * 2;
 ~L 	: L >= 0
Có N con kanguru trong vườn thú, con thứ i có chiều cao bằng A[i]. 
Con kanguru có chiều cao X có thể chứa được một con có chiều cao bằng Y trong túi của nó nếu như X >= 2*Y.

Một con đã chứa một con kanguru rồi, thì không thể nhảy vào túi một con kanguru khác.

Bầy Kanguru rất thích chơi trốn tìm, vì vậy chúng thường xuyên nhảy vào túi của nhau. Các bạn hãy tính toán xem trong trường hợp tối ưu, số con kanguru nhìn thấy trong vườn thú ít nhất bằng bao nhiêu?

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm số nguyên N (1 ≤ N ≤ 100 000).

Dòng tiếp theo gồm N số nguyên A[i] (1 ≤ A[i] ≤ 100 000).

Output: 

Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:
Input
2
8
2 5 7 6 9 8 4 2
8
9 1 6 2 6 5 8 3

Output
5
5
Giải thích test 1: Nhóm 2 – 5, 2 – 6, 4 – 8, 7, 9.
*/	