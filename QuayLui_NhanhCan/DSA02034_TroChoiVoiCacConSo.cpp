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
    //check is valid
    for (int i = 1; i < n; i++){
        if (abs(x[i] - x[i + 1]) == 1)
            return;
    }
    //display
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
    Try(1);
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
Nam có N thẻ bài, mỗi thẻ ghi một con số từ 1 tới N. Không có 2 thẻ nào ghi hai số trùng nhau. Nam muốn xếp thứ tự các thẻ bài sao cho không có hai con số nào liền kề nhau ở cạnh nhau.

Ví dụ với N = 4 thì cách xếp 3142 là hợp lệ nhưng cách xếp 1324 không hợp lệ.

Hãy giúp Nam liệt kê tất cả các cách xếp thỏa mãn theo thứ tự từ điển.  

Input

Dòng đầu ghi số bộ test T (không quá 10)
Mỗi bộ test ghi số N (3 < N < 10)
Output

Với mỗi bộ test, ghi ra tất cả các cách xếp thứ tự thỏa mãn, mỗi cách trên một dòng.
Ví dụ

Input
1
4

Output
2413
3142
*/