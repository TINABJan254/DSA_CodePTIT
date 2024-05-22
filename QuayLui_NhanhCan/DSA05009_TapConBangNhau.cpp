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
int a[105], x[105];
int t_sum;
bool used[105];
bool flag;

void Init(){
    cin >> n;
    t_sum = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        t_sum += a[i];
    }
    memset(used, false, sizeof(used));
    flag = false;
}

void Try(int i, int start, int cur_sum, int cnt){
    if (flag)
        return;
    if (cnt > 2){
        flag = true;
        return;
    }
    for (int j = start; j <= n; j++){
        if (!used[j] && (cur_sum + a[j]) <= t_sum){
            x[i] = a[j];
            used[j] = true;
            if (cur_sum + a[j] == t_sum){
                Try(1, 1, 0, cnt + 1);
            }
            else 
                Try(i + 1, j + 1, cur_sum + a[j], cnt);
            used[j] = false;
        }
    }
}

void solve(){
    Init();
    if (t_sum % 2 != 0){
        cout << "NO\n";
    }
    else{
        t_sum /= 2;
        Try(1, 1, 0, 1);
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
Ta sẽ đi xây dựng tập con với hai TH gọi đệ quy khác nhau
    TH1: Chưa xây dựng thành công tập con thỏa mãn thì ta gọi
        Try(i + 1, j + 1, cur_sum + a[j], cnt)
            cnt: tức là đang xây dựng tập thứ cnt
            j + 1: chỉ số để bắt đầu, bắt đầu từ j + 1 để ko lấy lại các ptử trước
    TH2: Đã xây dựng xong tập con thỏa mãn thì ta gọi
        Try(1, 1, 0, cnt + 1)
            ta truyền i = 1 để xây dựng lại tập con từ phần tử đầu
            ta truyền start = 1 là để vét lại các phần tử từ đầu mảng 
                => cần dùng mảng used để loại bỏ các ptử đã xây dựng cho các tập trước đó
            ta truyền cnt + 1 là để xây dựng tập tiếp theo là tập cnt + 1, cnt tập đã được xây dựng

Try(i, start, cur_sum, cnt)
Try(1, 1, 0, 1) tức là:
    Đi xây dựng tập thứ 1, bắt đầu từ phần tử thứ 1, cur_sum ktạo = 0;
Vậy thì mỗi bước là ta đang đi xây dựng tập thứ cnt
    nếu cnt = 2 tức đang xây dựng tập 2 (1 tập hợp lệ đã được xây dưng)
    nếu cnt = 3 tức đang xây dựng tập 3 (2 tập hợp lệ đã được xây dựng)
Vậy nên để kết thúc đệ quy ta cần kiểm tra cnt > 2 là được
    vì chỉ khi xây dựng được 2 tập rồi ta mới đi xây dựng tập thứ 3

PROB:
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