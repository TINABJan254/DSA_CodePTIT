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
int a[100];
bool used[100];
int s;
bool flag;

void Init(){
    s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        s += a[i];
    }
    memset(used, false, sizeof(used));
    flag = false;
}

void Try(int cur_sum, int cnt){
    if (flag)
        return;
    if (cnt == 2){
        flag = true;
        return;
    }
    for (int j = 1; j <= n; j++){
        if (!used[j]){
            used[j] = true;
            if (cur_sum + a[j] == s){
                Try(0, cnt + 1);
                return;
            }
            else if (cur_sum + a[j] < s){
                Try(cur_sum + a[j], cnt);
            }
        }
        used[j] = false;
    }
}

void solve(){
    Init();
    if (s % 2 != 0){
        cout << "NO\n";
        return;
    }
    else {
        s /= 2;
        Try(0, 0);
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
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
Cho tập các số A[] = (a1, a2, .., an). Hãy kiểm tra xem ta có thể chia tập A[] thành hai tập con sao cho tổng các phần tử của hai tập con bằng nhau hay không. 
Đưa ra YES nếu có thể thực hiện được, ngược lại đưa ra NO.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm hai phần: phần thứ nhất đưa vào số N là số lượng phần tử của dãy số A[]; 
dòng tiếp theo đưa vào N phần tử của dãy số A[].
T, N, A[i] thỏa mãn ràng buộc: 1≤T ≤100; 1≤N≤100; 1≤ A[i] ≤100.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input
2
4
1 5 11 5
3
1 3 5 

Output
YES
NO
*/