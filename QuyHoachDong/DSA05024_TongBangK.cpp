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
	int n, S; cin >> n >> S;
    int c[n];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    ll F[S + 1] = {0};
    F[0] = 1;
    for (int i = 1; i <= S; i++){
        F[i] = 0;
        for (int coin : c){
            if (i >= coin)
                F[i] = F[i] + F[i - coin];
            F[i] %= MOD;
        }
    }

    cout << F[S] << EL;
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
dp[i] : lưu số cách phân tích i ra các phần tử trong tập đã cho

bài toán cơ sở: dp[0] = 1; 	//số 0 thì có 1 cách phân tích

Cho một mảng A[] gồm N số nguyên và số K. 
Tính số cách lấy tổng các phần tử của A[] để bằng K. 
Phép lấy lặp các phần tử hoặc sắp đặt lại các phần tử được chấp thuận. 
Ví dụ với mảng A[] = {1, 5, 6}, K = 7 ta có 6 cách sau:

7 = 1 + 1 + 1+1 + 1 + 1+1 (lặp số 1 7 lần)

7 = 1 + 1 + 5 (lặp số 1)

7 = 1 + 5 + 1 (lặp và sắp đặt lại số 1)

7 = 1 + 6

7 = 6 + 1

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào N và K; dòng tiếp theo đưa vào N số của mảng A[]; các số được viết cách nhau một vài khoảng trống.
T, N, K, A[i] thỏa mãn ràng buộc: 1≤T≤100;  1≤N≤1000; 1≤A[i]≤100.
Output:

Đưa ra kết quả mỗi test theo từng dòng. Khi kết quả quá lớn đưa ra kết quả dưới dạng modulo với 109+7.
Ví dụ:

Input
2
3 7
1 5 6
4 14
12 3 1 9

Output
6
150
*/