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

void Init(){
    F[1] = 1;
	F[2] = 1;
	for (int i = 3; i <= 92; i++)
		F[i] = F[i - 1] + F[i - 2];
}

char find(int n, ll k){
	if (n == 1)
		return 'A';
	if (n == 2)
		return 'B';
	if (k <= F[n - 2])
		return find(n - 2, k);
	return find(n - 1, k - F[n - 2]);	
}

void solve(){
	int n;	ll k;
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
Với bài này ta sẽ xét 2TH có thể gọi đệ quy đến đó là:
	k thuộc F[n - 2]
	hoặc k thuộc F[n - 1]
	Vì bài này F[n-2] != F[n-1] nên ta làm khác 1 tí so với bài gấp đôi dãy số
	
PROB:
Một dãy xâu ký tự G chỉ bao gồm các chữ cái A và B được gọi là dãy xâu Fibonacci 
nếu thỏa mãn tính chất:    G(1) = A; G(2) = B; G(n) = G(n-2)+G(n-1). 
Với phép cộng (+) là phép nối hai xâu với nhau.  
Bài toán đặt ra là tìm ký tự ở vị trí thứ i (tính từ 1) của xâu Fibonacci thứ n.

Dữ liệu vào: Dòng 1 ghi số bộ test. Mỗi bộ test ghi trên một dòng 2 số nguyên 
N và i (1<N<93). Số i đảm bảo trong phạm vi của xâu G(N) và không quá 18 chữ số. 
Kết quả: Ghi ra màn hình kết quả tương ứng với từng bộ test.

Input
2
6 4
8 19

Output
A
B
*/