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

ll L[100] = {0}; //length

void Init(){
    L[1] = 1;
    for (int i = 2; i <= 50; i++)
        L[i] = L[i - 1] * 2 + 1;
}

int find(int n, ll k){
	if (n == 1)
		return 1;
	if (k == L[n] / 2 + 1 ) 
		return n; //vi tri k chinh la so o giua, do chinh la n
	if (k <= L[n - 1])
		return find(n - 1, k);
	return find(n - 1, k - L[n - 1] - 1);
}

void solve(){
	int n; ll k;
	cin >> n >> k;
	cout << find(n, k) << EL;
}

int main(){
    Init();
	faster();
	int TC; cin >> TC;
	while (TC--){
	    solve();
	}
	return 0;
}

/*
Bài này sẽ giống với bài DSA04022_KyTuThuKTrongXau, và ở đây làm theo kiểu ko lưu
trước độ dài của dãy thứ n (sau n - 1 lần gấp đôi) nữa mà quy luật đó là độ dài của dãy 
chính là F[n] = 2^n - 1
2^n - 1 : chính là độ dài của dãy số sau n-1 lần gấp đôi, hãy độ dài của dãy thứ n
Quy luật này thì áp dụng cho cả bài ký tự đấy nữa, làm thế này thì ngắn, nhưng lưu trước
ra độ dài của dãy sẽ dễ hiểu hơn
Nhớ ép kiểu hàm pow về INT, vì hàm pow cho ra số double

PROB:
Một dãy số tự nhiên bắt đầu bởi con số 1 và được thực hiện N-1 phép biến đổi “gấp đôi” dãy số như sau:

Với dãy số A hiện tại, dãy số mới có dạng A, x, A trong đó x là số tự nhiên bé nhất chưa xuất hiện trong A.

Ví dụ với 2 bước biến đổi, ta có [1] - [1 2 1] - [1 2 1 3 1 2 1].

Các bạn hãy xác định số thứ K trong dãy số cuối cùng là bao nhiêu?

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm số nguyên dương N và K (1 ≤ N ≤ 50, 1 ≤ K ≤ 2N - 1).

Output: 

Với mỗi test, in ra đáp án trên một dòng.

Ví dụ:

Input
2
3 2
4 8

Output
2
4
Giải thích test 1: Dãy số thu được là [1, 2, 1, 3, 1, 2, 1].
Giải thích test 2: Dãy số thu được là [1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1].
*/