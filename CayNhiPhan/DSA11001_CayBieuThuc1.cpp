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

bool isOperator(char c){
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

void solve(){
	string s; cin >> s;
	stack<string> st;
	for (char c : s){
		if (isOperator(c)){
			string op1 = st.top(); st.pop();
			string op2 = st.top(); st.pop();
			
			string tmp = op2 + c + op1;
			st.push(tmp);
		}
		else
			st.push(string(1, c));
	}
	
	cout << st.top() << EL;
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
Cây biểu thức là một cây nhị phân trong đó mỗi node trung gian là một phép toán, mỗi node lá là một toán hạng. 
Ví dụ với biểu thức P = 3 + ((5+9)*2) sẽ được biểu diễn như cây dưới đây.

Đối với cây biểu thức, duyệt theo thứ tự trước ta sẽ được biểu thức tiền tố, duyệt theo thứ tự sau ta sẽ được biểu thức hậu tố, duyệt theo thứ tự giữa ta được biểu thức trung tố. Chú ý, cây biểu thức luôn là cây nhị phân đầy (mỗi node trung gian đều có hai node con).

Cho biểu thức hậu tố P, hãy sử dụng cây biểu thức để đưa ra biểu thức trung tố tương ứng với biểu thức P.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test là một biểu thức hậu tố P.
T, P thỏa mãn ràng buộc : 1≤T≤100; 1≤lengh(P)≤100.
Output:

Đưa ra biểu thức trung tố tương ứng với P.

Ví dụ:
Input
2
ab+ef*g*-
wlrb+-*

Output
a + b - e * f * g
w * l - r + b
*/
