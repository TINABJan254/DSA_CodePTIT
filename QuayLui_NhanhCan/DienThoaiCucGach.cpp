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

string a[100];
string s;

void Init(){
    a[2] = "abc";
    a[3] = "def";
    a[4] = "ghi";
    a[5] = "jkl";
    a[6] = "mno";
    a[7] = "pqrs";
    a[8] = "tuv";
    a[9] = "wxyz";
    cin >> s;
}

void Try(int i, string cur_str){
    if (s[i] == '7' || s[i] == '9'){
        for (int j = 0; j < 4; j++){
            cur_str.pb(a[s[i] - '0'][j]);
            if (cur_str.sz == s.sz){
                cout << cur_str << EL;
            }
            else if (i < s.sz){
                Try(i + 1, cur_str);
            }
            cur_str.pop_back();
        }
    }
    else {
        for (int j = 0; j < 3; j++){
            cur_str.pb(a[s[i] - '0'][j]);
            if (cur_str.sz == s.sz){
                cout << cur_str << EL;
            }
            else if (i < s.sz){
                Try(i + 1, cur_str);
            }
            cur_str.pop_back();
        }
    }
}

void solve(){
    Init();
    Try(0, "");
}

int main(){
    faster();
    solve();
    return 0;
}
/*
Cho xâu ký tự s gồm các số từ 2 đến 9, mỗi số này trên bàn phím của điện thoại cục gạch tương ứng với ba chữ cái.
Hãy in ra xâu ký tự có thể tạo thành bằng cách ấn mỗi số trong xâu đúng 1 lần. Bạn hãy in ra các xâu kết quả theo thứ 
tự từ điển tăng dần.

Input
    Dòng duy nhất chứa xâu s
Output
    In ra các xâu thỏa mãn
Constraints
    2 <= s[i] <= 9
    các ký tự trong s là khác nhau

Sample

Input
23

Output
ad ae af bd be bf cd ce cf
*/