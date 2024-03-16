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
char c;
string x;
bool used[100];

void Init(){
    cin >> c;
    memset(used, false, sizeof(used));
    n = c - 'A' + 1;
}

bool check(){
    if (n < 5){
        if (x[0] != 'A' && x.back() != 'A')
            return false;
        return true;
    }
    else{
        //check first_last
        if (x[0] == 'A' && x[x.sz - 1] == 'E')
            return true;
        if (x[0] == 'E' && x[x.sz - 1] == 'A')
            return true;
        //check middle
        for (int i = 0; i < x.sz - 1; i++){
            if (x[i] == 'A' && x[i + 1] == 'E')
                return true;
            if (x[i] == 'E' && x[i + 1] == 'A')
                return true;
        }
        return false;
    }
}

void Try(){
    for (char j = 'A'; j <= c; j++){
        if (!used[j - 'A']){
            x += j;
            used[j - 'A'] = true;
            if (x.sz == n){
                if (check())
                    cout << x << EL;
            }
            else 
                Try();
            x.pop_back();
            used[j - 'A'] = false;
        }
    }
}

void solve(){
    Init();
    Try();
}

int main(){
    faster();
    solve();
    return 0;
}
/*
Trong 8 chữ cái Tiếng Anh đầu tiên (ABCDEFGH) thì có 2 nguyên âm là ‘A’, ‘E’, còn lại là phụ âm.

Người ta muốn ghép các chữ cái bắt đầu từ chữ cái ‘A’ cho đến chữ cái c (‘D’ <= c <= ‘H’) sao cho mỗi chữ cái được sử dụng đúng một lần và xâu kết quả không có nguyên âm nào bị kẹp giữa bởi hai phụ âm.

Hãy liệt kê các xâu thỏa mãn theo thứ tự từ điển.

Input

Chỉ có một dòng ghi chữ cái c (đảm bảo từ ‘D’ đến ‘H’).

Output

Liệt kê các xâu thỏa mãn, mỗi xâu trên một dòng.

Ví dụ

Input
D

Output
ABCD
ABDC
ACBD
ACDB
ADBC
ADCB
BCDA
BDCA
CBDA
CDBA
DBCA
DCBA
*/