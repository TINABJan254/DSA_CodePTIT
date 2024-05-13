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

int findLen(string s){
	stack<int> st;
	for (int i = 0; i < s.sz; i++){
		if (s[i] == '(')
			st.push(i);
		else{
			if (!st.empty() && s[st.top()] == '(')
				st.pop();
			else
				st.push(i);
		}
	}
	
	return s.sz - st.sz;
}

void solve(){
	string s; cin >> s;
	cout << findLen(s) << EL;
	
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
Cho biểu thức P chỉ bao gồm các ký tự mở ngoặc ‘(’ hoặc đóng ngoặc ‘)’. 
Biểu thức P có thể viết đúng hoặc không đúng. 
Nhiệm vụ của bạn là tìm tổng độ dài lớn nhất của các biểu thức con 
viết đúng trong P (các biểu thức đúng không nhất thiết phải liên tiếp nhau).

Chú ý: Độ dài của biểu thức đúng ngắn nhất là 2.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T (không quá 100)
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là một biểu thức P được viết trên một dòng (độ dài của P không quá 100).
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input
4
(()(
()()((
((()()())))
()(())(

Output
2
4
10
6
*/
