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
int x[100];
bool used[100];

void Init(){
    cin >> n;
    memset(used, false, sizeof(used));
}

void check_and_display(){
    for (int i = 2; i <= n; i++){
        if (abs(x[i] - x[i - 1]) == 1)
            return;
    }
    for (int i = 1; i <= n; i++)
        cout << x[i];
    cout << EL;
}

void Try(int i){
    for (int j = 1; j <= n; j++){
        if (!used[j]){
            x[i] = j;
            used[j] = true;
            if (i == n){
                check_and_display();
            }
            else{
                Try(i + 1);
            }
            used[j] = false;
        }
    }
}

void solve(){
    Init();
    if (n < 4){
        cout << EL;
    }
    else {
        Try(1);
        cout << EL;
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
Cho số nguyên dương N (2 < N <10). Một số nguyên dương K có N chữ số được gọi là số xa cách nếu thỏa mãn:

K không chứa chữ số 0
Tất cả các chữ số từ 1 đến N đều xuất hiện trong K đúng 1 lần
Không có hai chữ số liên tiếp nào trong K có hiệu bằng 1. 
Hãy liệt kê tất cả các số thỏa mãn theo thứ tự tăng dần.

Input

Dòng đầu ghi số bộ test (không quá 10)
Mỗi bộ test là 1 số nguyên dương N (2 < N < 10)
Output

Liệt kê tất cả các số thỏa mãn, mỗi số trên một dòng.

Sau mỗi test in ra một khoảng trống.

Ví dụ

Input
2
3
4

Output

2413
3142
*/