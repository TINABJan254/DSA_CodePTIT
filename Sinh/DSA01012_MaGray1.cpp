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

int x[100];
int n;
bool final;

void Init(){
	cin >> n;
	final = false;
	memset(x, 0, sizeof(x));
}

void change_to_gray_and_display(){
	string res = "";
	res += to_string(x[1]);
	for (int i = 2; i <= n; i++){
		if (x[i] == x[i - 1])
			res += "0";
		else
			res += "1";
	}
	cout << res << ' ';
}

void genNext(){
	int i = n;
	while (i >= 1 && x[i] == 1){
		x[i] = 0;
		--i;
	}

	if (i == 0){
		final = true;
	}
	else {
		x[i] = 1;
	}
}

void solve(){
	Init();
	while (!final){
		change_to_gray_and_display();
		genNext();
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
sinh xâu nhị phân, sau đó biến đổi như sau:
	kí tự đầu tiên giữ nguyên	res[1] = x[1]
	từ ký tự thứ 2 trở đi (xét trên xâu gốc nha)
		x[i] == x[i - 1] thì res[i] = 0;
		x[i] != x[i - 1] thì res[i] = 1;
			với i = [2, n];
	note: sự thay đổi chỉ làm trên xâu res, xâu s giữ nguyên


Số nhị phân được xem là cách mặc định biểu diễn các số. Tuy nhiên, trong nhiều ứng dụng của điện tử và truyền thông lại dùng một biến thể của mã nhị phân đó là mã Gray. Mã Gray độ dài n có mã đầu tiên là n số 0, mã kế tiếp của nó là một xâu nhị phân độ dài n khác biệt với xâu trước đó một bít. Ví dụ với n=3 ta có 23 mã Gray như sau: 000, 001, 011, 010, 110, 111, 101, 100. Hãy viết chương trình liệt kê các mã Gray có độ dài n.

Input:

Dòng đầu tiên là số lượng test T.
T dòng kế tiếp ghi lại mỗi dòng một test. Mỗi test là một số tự nhiên n.
T, n thỏa mãn ràng buộc: 1≤T, n≤10.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
 

Input:
2
3
4

Output
000 001 011 010 110 111 101 100
0000 0001 0011 0010 0110 0111 0101 0100 1100 1101 1111 1110 1010 1011 1001 1000
*/