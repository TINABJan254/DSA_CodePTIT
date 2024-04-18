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

    int F[S + 1] = {0};
    F[0] = 0;
    for (int i = 1; i <= S; i++){
        F[i] = 1e9;
        for (int coin : c){
            if (i >= coin)
                F[i] = min(F[i], F[i - coin] + 1);
        }
    }

    if (F[S] == 1e9)
        cout << "-1";
    else
        cout << F[S];
}

int main(){
    faster();
    solve();
    return 0;
}

/*
dp[i] : số tờ tiền cần thiết khi đổi số tiền mệnh giá i
=> dp[i] = min(dp[i - a[j]]) + 1 //j = 0->n

PROB:
Ngân hàng XYZ hiện có N tờ tiền có mệnh giá khác nhau lưu 
trong mảng C[], hãy tìm cách đổi số tiền là S sao cho cần
dùng ít tờ tiền nhất. Bạn được sử dụng một mệnh giá không
giới hạn số lần.

Input format
    Dòng 1: N và S
    Dòng 2: N số là mệnh giá các tờ tiền
Constraints
    1 <= N <= 100; 1 <= S <= 10^6
    1 <= C[i] <= 10^6
Output format
    In ra số tờ tiền nhỏ nhất cần đổi. Nếu ko thể
    đổi hãy in ra -1

Sample
Input
    3 10
    4 5 8
Output
    2
*/