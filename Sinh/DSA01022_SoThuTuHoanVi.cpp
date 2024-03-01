#include <bits/stdc++.h>

using namespace std;

#define EL "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int n;
int x[100];
int root[100];

void Init(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> root[i];
    for (int i = 1; i <= n; i++){
        x[i] = i;
    }
}

bool checkValid() {
    for (int i = 1; i <= n; i++)
        if (x[i] != root[i])
            return false;
    return true;
}

void solve(){
    Init();
    int cnt = 0;
    do{
        ++cnt;
        if (checkValid())
            cout << cnt << EL;
    }while (next_permutation(x + 1, x + n + 1));
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
Cho một hoán vị của N số nguyên dương đầu tiên.

Hãy xác định xem đó là hoán vị thứ bao nhiêu nếu liệt kê theo thứ tự tăng dần (tính từ 1).

Input

Dòng đầu ghi số T là số bộ test (T < 10)

Mỗi bộ test gồm 2 dòng

Dòng đầu ghi số nguyên dương N (3 < N < 10)
Dòng tiếp theo ghi một hoán vị của các số nguyên dương từ 1 đến N.  
Output

Với mỗi bộ test, ghi ra trên một dòng số thứ tự của hoán vị (tính từ 1, theo thứ tự liệt kê tăng dần).
*/