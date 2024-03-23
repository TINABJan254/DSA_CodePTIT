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

int count_step(int n){
    queue<pii> q;
    q.push({n, 0});
    while (!q.empty()){
        pii f;
        f = q.front();
        q.pop();

        if (f.fi == 1){
            return f.se;
        }

        if (f.fi % 3 == 0){
            q.push({f.fi / 3, f.se + 1});
        }   

        if (f.fi % 2 == 0){
            q.push({f.fi / 2, f.se + 1});
        }
        q.push({f.fi - 1, f.se + 1});
    }
    return 0;
}

void solve(){
    int n;
    cin >> n;
    cout << count_step(n) << EL;
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
Cho số nguyên dương N. Hãy đếm số bước ít nhất để đưa N về 1 bằng cách thực hiện ba thao tác dưới đây:

Nếu N chia hết cho 2 bạn có thể giảm N = N/2.
Nếu N chia hết cho 3 bạn có thể giảm N = N/3.
Giảm N đi 1.
Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số N được viết trên một dòng.
T, N thỏa mãn ràng buộc: 1≤T≤100;  1≤N ≤100000.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:
Input
2
10
6

Output
3
2
*/