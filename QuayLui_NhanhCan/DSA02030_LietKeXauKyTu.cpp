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

int k;
char c;
string x;

void Init(){
    cin >> c >> k;
}

void Try(char start){
    for (char j = start; j <= c; j++){
        x += j;
        if (x.sz == k){
            cout << x << EL;
        }
        else
            Try(j);
        //backtrack
        x.pop_back();
    }
}

void solve(){
    Init();
    Try('A');
}

int main(){
    faster();
    solve();
    return 0;
}
/*
Cho chữ cái c in hoa (‘A’ < c < ’K’) và số nguyên K (0 < K < (c – ‘A’)).

Hãy tìm cách  liệt kê tất cả các xâu ký tự khác nhau được tạo ra bởi các chữ cái tính từ ‘A’ đến ký tự c. Các ký tự được phép lặp lại nhưng không tính các xâu là hoán vị của xâu nào đó đã liệt kê trước đó.

Xem ví dụ để hiểu thêm yêu cầu đề bài.

Input

Chỉ có một dòng ghi chữ cái c và số nguyên K thỏa mãn ràng buộc đề bài.

Output

Ghi ra lần lượt các xâu ký tự kết quả theo thứ tự từ điển, mỗi xâu trên một dòng.

Ví dụ

Input
D 2

Output
AA
AB
AC
AD
BB
BC
BD
CC
CD
DD
*/