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

int n, k;
string a[100];
int x[100];

void Init(){
    cin >> n >> k;
    set<string> s;
    for (int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        s.insert(tmp);
    }
    n = 0;
    for (auto tmp : s){
        a[++n] = tmp;
    }
}

void display(){
    for (int i = 1; i <= k; i++){
        cout << a[x[i]] << ' ';
    }
    cout << EL;
}

void Try(int i){
    for (int j = x[i - 1] + 1; j <= n; j++){
        x[i] = j;
        if (i == k){
            display();
        }
        else {
            Try(i + 1);
        }
    }
}

void solve(){
    Init();
    x[0] = 0;
    Try(1);  
}

void local(){
    #ifndef ONLINE_JUDGE
        freopen("inputf.txt", "r", stdin);
        freopen("outputf.txt", "w", stdout);
    #endif
}

int main(){
    //local();
    faster();
    solve();
    return 0;
}
/*
Kỳ thi ICPC có K đội của PTIT tham gia và đội tuyển đang rất đau đầu không biết chọn các cái tên như thế nào cho các đội. Yêu cầu phải đảm bảo tên không có khoảng trống và không được trùng nhau. Sau khi thảo luận, có N cái tên được đề xuất (có thể bị trùng nhau). Với K<15 và 4 < N < 30.

Hãy liệt kê tất cả danh sách các tổ hợp K cái tên khác nhau có thể được tạo ra theo thứ tự từ điển.

Input

Dòng đầu ghi 2 số N và K.

Tiếp theo là 1 dòng ghi N cái tên, mỗi cái tên có độ dài không quá 15 và cách nhau một khoảng trống. Tất cả đều là ký tự in hoa.

Output

Ghi ra tất cả các tổ hợp tên có thể được lựa chọn theo thứ tự từ điển.

Tức là các tên trong mỗi tổ hợp liệt kê theo thứ tự từ điển và các tổ hợp cũng được liệt kê theo thứ tự từ điển.

Ví dụ

Input
6 2
DONG TAY NAM BAC TAY BAC

Output
BAC DONG
BAC NAM
BAC TAY
DONG NAM
DONG TAY
NAM TAY
*/