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

void solve(){
	string s; cin >> s;
	stack<ll> st;
	for (int i = s.sz - 1; i >= 0; i--){
		if (isdigit(s[i]))
			st.push(stoll(string(1, s[i])));
		else{
			ll op1 = st.top(); st.pop();
			ll op2 = st.top(); st.pop();
			
			if (s[i] == '+')
				st.push(op1 + op2);
			if (s[i] == '-')
				st.push(op1 - op2);
			if (s[i] == '*')
				st.push(op1 * op2);
			if (s[i] == '/')
				st.push(op1 / op2);
		}
	}
	
	cout << st.top() << EL;
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
Hãy viết chương trình tính toán giá trị của biểu thức tiền tố.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T;
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức tiền tố exp. 
Các số xuất hiện trong biểu thức là các số đơn có 1 chữ số.
Output:

Đưa ra kết quả mỗi test theo từng dòng, chỉ lấy giá trị phần nguyên.
Ràng buộc:

T, exp thỏa mãn ràng buộc: 1≤T≤100; 2≤length(exp)≤20.
Ví dụ:

Input
2
-+8/632
-+7*45+20

Output
8
25
*/
