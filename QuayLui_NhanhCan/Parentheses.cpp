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
string root = "()[]{}";

bool check(string s){
	stack<char> st;
	for (char c : s){
		if (c == '(' || c == '[' || c == '{'){
			st.push(c);
		}
		else {
			if (st.empty())
				return false;
			if (c == ')'){
				if (st.top() != '(')
					return false;
				st.pop();
			}
			if (c == '}'){
				if (st.top() != '{')
					return false;
				st.pop();
			}
			if (c == ']'){
				if (st.top() != '[')
					return false;
				st.pop();
			}
		}
	}
	return st.empty();
}

void Try(string s){
	if (s.sz == n){
		if (check(s))
			cout << s << ' ';
		return;
	}
	for (auto c : root)
		Try(s + c);
}

void solve(){
	cin >> n;
	if (n % 2 != 0){
		cout << "NOT FOUND";
	}
	else {
		Try("");
	}
}

int main(){
	faster();
	solve();
	return 0;
}

/*
Bạn hãy sinh ra các biểu thức dấu ngoặc hợp lệ, từ các cặp dấu ngoặc "()", "[]", "{}"
có độ dài N. Kết quả in ra theo thứ tự từ điển tăng dần, nếu không tồn tại biểu thức
hợp lệ thỏa mãn thì in ra NOT FOUND.

Input format
 . Dòng duy nhất chứa số nguyên N
Output format
 . In ra đáp án theo yêu cầu của đề bài
Constraints
 . 2 <= N <= 15

Sample:
Input
2

Output
() [] {}


**Cách kiểm tra với trường hợp chỉ có 1 loại dấu ngoặc:

bool check(string s){
	int cnt = 0;
	for (auto x : s){
		if (x == '(' )
			++cnt;
		else
			--cnt;
		if (cnt < 0) //trường hợp xuất hiện dấu ngoặc đóng trước dấu ngoặc mở
			return false;
	}
	return cnt == 0; //số lượng ngoặc đóng bằng ngoặc mở
}

bool check_with_stack(string s){
	stack<char> st;
	for (auto x : s){
		if (x == '('){
			s.push(x);
		}
		else {
			if (st.empty()) //ko con dau mo nao 
				return false;
			else
				st.pop();
		}
	}
	return st.empty();
}

*/