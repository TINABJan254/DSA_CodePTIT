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

ll F[100] = {0};
char R[25];

void Init(){
    F[1] = 1;
	for (int i = 2; i <= 25; i++)
		F[i] = F[i - 1] * 2 + 1;

	R[1] = 'A';
	for (int i = 2; i <= 25; i++)
		R[i] = (char)(R[i - 1] + 1);
}

char find(int n, ll k){
	if (n == 1)
		return 'A';
	if (k == F[n]/2 + 1)
		return R[n];
	if (k <= F[n-1])
	    return find(n - 1, k);    
	return find(n - 1, k - F[n - 1] - 1);
	
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
Xâu ký tự S được tạo ra bằng cách bổ sung dần các ký tự chữ cái Tiếng Anh in hoa như sau.

Bước 1: Chỉ có chữ cái A
Bước 2: Thêm chữ cái B vào giữa 2 chữ A => S = "ABA"
Bước 3: Thêm chữ cái C vào giữa 2 xâu đã có ở bước 2: S = "ABACABA"
Cứ như vậy cho đến bước thứ N (0 < N < 26)

Hãy xác định ký tự thứ K trong bước biến đổi thứ N là chữ cái gì?

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm số nguyên dương N và K (1 ≤ N ≤ 25, 1 ≤ K ≤ 2N - 1).
Output: 

Với mỗi test, in ra đáp án trên một dòng.
Ví dụ:

Input:
2
3 2
4 8

Output
B
D
*/