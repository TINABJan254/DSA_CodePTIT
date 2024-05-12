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

void solve(){
	string s; cin >> s;
	stack<string> st;
	for (int i = s.sz - 1; i >= 0; i--){
		if (isOperator(s[i])){
			string op1 = st.top(); st.pop();
			string op2 = st.top(); st.pop();
			
			string tmp = "(" + op1 + s[i] + op2 + ")";
			st.push(tmp);
		}
		else {
			st.push(string(1, s[i])); //string's constructor 
		}
	}
	
	cout << st.top();
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("inputf.txt", "r", stdin);
	#endif
	faster();
	solve();
	return 0;
}

/*
Prefix to Infix

string(num, char) : tạo string có độ dài num, có các phần tử bằng char

Cho biểu thức S ở dạng tiền tố, hãy biến đổi S về dạng trung tố và in ra màn hình
Input Format
Dòng duy nhất chứa biểu thức S
Constraints
1<=len(S)<=1000
Output Format
In ra biểu thức trung tố tương ứng
Sample Input 0
-*AB+CD
Sample Output 0
((A*B)-(C+D))

*/
