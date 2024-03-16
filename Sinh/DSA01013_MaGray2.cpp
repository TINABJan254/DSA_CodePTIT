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

string s;

void Init(){
	cin >> s;
}

void gray_to_bin(){
	for (int i = 1; i < s.sz; i++)
		if (s[i] == s[i - 1])
			s[i] = '0';
		else
			s[i] = '1';
	cout << s;
}

void solve(){
	Init();
	gray_to_bin();
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
Chuyển từ gray về bin thì làm giống như bin to gray chỉ khác là so sánh thay thay đổi ngay xâu gốc
	s[0] giữ nguyên
	s[i] == s[i - 1] thì s[i] = 0;
	s[i] != s[i - 1] thì s[i] = 1;
		Note : (ko dùng mảng res nữa, mà thay đổi s[i] thành 0/1 ngay trên xâu s);
Số nhị phân được xem là cách mặc định biểu diễn các số. Tuy nhiên, trong nhiều ứng dụng của điện tử và truyền thông lại dùng một biến thể của mã nhị phân đó là mã Gray. Mã Gray độ dài n có mã đầu tiên là n số 0, mã kế tiếp của nó là một xâu nhị phân độ dài n khác biệt với xâu trước đó một bít. Ví dụ với n=3 ta có 23 mã Gray như sau: 000, 001, 011, 010, 110, 111, 101, 100. Hãy viết chương trình chuyển đổi một xâu mã Gray X có độ dài n thành một xâu mã nhị phân.

Input::

Dòng đầu tiên là số lượng test T.
T dòng kế tiếp ghi lại mỗi dòng một test. Mỗi test là một xâu mã Gray độ dài n.
T, n thỏa mãn ràng buộc: 1≤T, n≤10.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Input:
2
01101
01011

Output:
01001
01101
*/