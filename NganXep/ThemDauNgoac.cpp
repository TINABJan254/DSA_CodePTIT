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
	stack<char> st;
	int res = 0;
	for (char c : s){
		if (c == '(')
			st.push(c);
		else{
			if (!st.empty())
				st.pop();
			else
				++res;
		}
	}
	
	res += st.sz;
	cout << res;
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
Cho một xâu kí tự chỉ bao gồm dấu đóng mở ngoặc tròn. 
Hãy tìm số lượng dấu đóng mở ngoặc cần thêm tối thiểu để tạo thành một xâu cân bằng, 
bạn có thể thêm các kí tự đóng mở ngoặc vào bất kì vị trí nào của xâu.
Input Format
Xâu kí tự S trên 1 dòng
Constraints
1<=len(S)<=10000;
Output Format
In ra số lượng dấu ngoặc cần bổ sung để xâu cân bằng
Sample Input 0
))))()
Sample Output 0
4
Sample Input 1
(((())))
Sample Output 1
0

*/
