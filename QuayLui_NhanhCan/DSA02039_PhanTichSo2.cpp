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
vector<vi> res;

void Init(){
    cin >> n;
    res.clear();
}

void Try(int i, int k, int cur_sum){
    for (int j = k; j >= 1; j--){
        x[i] = j;
        if (cur_sum + j == n){
            vi tmp(x + 1, x + i + 1);
            res.pb(tmp);
        }
        else if (cur_sum + j < n){
            Try(i + 1, j, cur_sum + j);
        }
    }
}

void display(vi v){
    cout << "(";
    for (int i = 0; i < v.sz - 1; i++)
        cout << v[i] << ' ';
    cout << v[v.sz - 1] << ") ";
}

void solve(){
    Init();
    Try(1, n, 0);
    cout << res.sz << EL;
    for (vi tmp : res){
        display(tmp);
    }
    cout << EL;
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
Cho số nguyên dương N. Nhiệm vụ của bạn là hãy liệt kê tất cả các cách phân tích số tự nhiên N thành tổng các số tự nhiên 
nhỏ hơn hoặc bằng N. Phép hoán vị của một cách được xem là giống nhau. 
Ví dụ với N = 5 ta có kết quả là: (5), (4, 1), (3, 2), (3, 1, 1), (2, 2, 1), (2, 1, 1, 1), (1, 1, 1, 1, 1) .

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số tự nhiên N được viết trên một dòng.
T, n thỏa mãn ràng buộc: 1≤T, N≤10.
Output:

Dòng đầu tiên là số lượng cách phân tích thỏa mãn. Dòng tiếp theo liệt kê đáp án theo mẫu ví dụ đã cho.

Ví dụ:

Input
2
4
5

Output
5
(4) (3 1) (2 2) (2 1 1) (1 1 1 1)
7
(5) (4 1) (3 2) (3 1 1) (2 2 1) (2 1 1 1) (1 1 1 1 1)
*/