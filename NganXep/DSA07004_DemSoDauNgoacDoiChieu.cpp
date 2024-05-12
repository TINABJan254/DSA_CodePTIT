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
			if (st.empty()){ //TH1
				++res;
				st.push('(');
			}
			else
				st.pop();
		}	
	}
	
	res += (st.sz / 2); //TH2
	cout << res << EL;
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
Sẽ có 2 TH thừa
TH1 : Thừa dấu đóng ngoặc
	khi trong stack đã hết dấu mở ngoặc mà ta lại gặp dấu đóng ngoặc thì
	ta sẽ đổi chiều dấu đóng ngoặc đó và push nó vào stack 
TH2 : Thừa dấu mở ngoặc
	ta thừa n dấu mở ngoặc thì ta sẽ đổi chiều n/2 dấu là được
	Và để xác định xem thừa bao nhiêu dấu mở ngoặc đó chính là stack.size khi kết thúc duyệt
	(vì ta chỉ push dấu mở ngoặc vào stack thôi mà)
Cho một xâu chỉ gồm các kí tự ‘(‘, ‘) và có độ dài chẵn. 
Hãy đếm số lượng dấu ngoặc cần phải đổi chiều ít nhất, sao cho xâu mới thu được là một dãy ngoặc đúng.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm 1 xâu S có độ dài không vượt quá 100 000, chỉ gồm dấu ( và ).

Output: 

Với mỗi test, in ra đáp án tìm được trên một dòng.

Ví dụ:

Input:
4
))((
((((
(((())
)(())(((

Output
2
2
1
3
*/
