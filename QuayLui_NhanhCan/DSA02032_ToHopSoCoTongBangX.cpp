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

int n, s;
int sum;
int a[105];
int x[105];
bool flag;
vector<vi> res;

void Init(){
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sum = 0;
    flag = false;
    res.clear();
}

void display(vi v){
    cout << "{";
    for (int j = 0; j < v.sz - 1; j++)
        cout << v[j] << ' ';
    cout << v[v.sz - 1] << "} ";
}

void Try(int i, int start){
    for (int j = start; j <= n; j++){
        if (sum + a[j] <= s){
            sum += a[j];
            x[i] = a[j];
            if (sum == s){
                flag = true;
                vi tmp(x + 1, x + i + 1);
                res.pb(tmp);
            }
            else if (sum < s){
                Try(i + 1, j);
            }
            sum -= a[j];
        }
    }
}

void solve(){
    Init();
    sort(a + 1, a + n + 1);
    Try(1, 1);
    if (!flag){
        cout << "-1";
    }
    else {
        cout << res.sz << ' ';
        for (auto tmp : res)
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
Cho mảng A[] gồm N số nguyên dương phân biệt và số X. Nhiệm vụ của bạn là tìm phép tổ hợp các số trong mảng A[] có tổng bằng X. Các số trong mảng A[] có thể được sử dụng nhiều lần. Mỗi tổ hợp các số của mảng A[] được in ra theo thứ tự không giảm các số. Ví dụ với A[] = {2, 4, 6, 8}, X = 8 ta có các tổ hợp các số như sau:

{2, 2, 2, 2}, {2, 2, 4}, {2, 6}, {4, 4}, {8}.

Input: Dòng đầu tiên đưa vào số lượng bộ test T. Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất là hai số N và X; dòng tiếp theo đưa vào N số của mảng A[]; các số được viết cách nhau một vài khoảng trống. T, N, X, A[i] thỏa mãn ràng buộc: 1≤T ≤10; 1≤X, A[i]≤100. N ≤ 20.

Output: Đưa ra kết quả mỗi test theo từng dòng. Đầu tiên là số lượng  tổ hợp thỏa mãn. Mỗi tổ hợp được bao bởi cặp ký tự { } và cách nhau một dấu cách. Đưa ra -1 nếu không có tổ hợp nào thỏa mãn yêu cầu bài toán.

Ví dụ:

Input
2
4  8
2  4  6  8
2 9
10 11

Output
5 {2 2 2 2} {2 2 4} {2 6} {4 4} {8}
-1
*/