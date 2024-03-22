//WA
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

bool flag;

bool check(string s){
	if (s == "")
		return false;
	stack<char> st;
	for (auto c : s){
		if (c == '(' )
			st.push(c);
		else if (c == ')'){
			if (st.empty())
				return false;				
			st.pop();
		}
	}
	return st.empty();
}

void Try(int num, string x){
	if (x.sz == 1 && isalpha(x[0])){
		cout << "-1";
		return;
	}
	if (x.find(")") == string::npos && x.find("(") == string::npos){
		cout << x;
		flag = true;
		return;
	}
	set<string> res;
	for (int i = 0; i <= x.sz - num; i++){
		string s = x;
		if (s[i] == ')' || s[i] == '('){
			s.erase(i, num);
			if (check(s)){
				flag = true;
				res.insert(s);
			}
		}
	}
	if (res.sz == 0)
		cout << "-1";
	for (auto tmp : res)
		cout << tmp << ' ';
}

void solve(){
	string s;
	cin >> s;
	if (check(s)){
		cout << s << EL;
		return;
	}
	flag = false;
	for (int i = 1; i <= s.sz; i++){
		if (!flag)
			Try(i, s);
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
Cho biểu thức P chỉ chứa các ký tự ‘(’, ‘)’ và các ký tự. Không có phép toán nào trong biểu thức P. Nhiệm vụ của bạn là thực hiện ít nhất các phép loại bỏ các ký tự ‘(’, ‘)’ để P trở thành biểu thức đúng. Chú ý: một biểu thức chỉ có 1 ký tự chữ (không có dấu ngoặc) hoặc một biểu thức rỗng thì không được xem là biểu thức đúng.

Nếu có nhiều hơn một biểu thức đúng với cùng số phép loại bỏ ít nhất hãy đưa ra tất cả các biểu thức đúng theo thứ tự từ điển.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một biểu thức P được viết trên một dòng.
T, P thỏa mãn ràng buộc: 1≤T ≤100; 1≤length(P)≤100.
Output:

Đưa ra kết quả mỗi test theo từng dòng. Nếu không có đáp án, in ra -1.
Input
2
()())()
(u)())()

Output
(())() ()()()
(u())() (u)()() 
*/