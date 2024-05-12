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

bool isOperator(char x){
	if (x == '+' || x == '-' || x == '*' || x == '/')
		return true;
	return false;
}

string PrefixToInfix(string s){
	stack<string> st;
	for (int i = s.sz - 1; i >= 0; i--){
		if (isOperator(s[i])){
			string op1 = st.top(); st.pop();
			string op2 = st.top(); st.pop();
			
			string tmp = "(" + op1 + s[i] + op2 + ")";
			st.push(tmp);
		}
		else
			st.push(string(1, s[i])); //string's contructor
	}
	return st.top();
}

void solve(){
	string s; cin >> s;
	cout << PrefixToInfix(s) << EL;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
	#endif
	faster();
	int TC; cin >> TC;
	while (TC--){
	    solve();
	}
	return 0;
}

/*
Hãy viết chương trình chuyển đổi biểu thức biểu diễn dưới dạng tiền tố về dạng trung tố.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T;
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức tiền tố exp.
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ràng buộc:

T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤106.
Ví dụ:

Input
2
*+AB-CD
*-A/BC-/AKL

Output
((A+B)*(C-D))
((A-(B/C))*((A/K)-L)
*/
