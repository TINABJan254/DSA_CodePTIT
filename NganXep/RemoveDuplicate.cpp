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
        for (char c : s){
            if (!st.empty() && st.top() == c)
                    st.pop();
            else
                st.push(c);
        }
        
    string res = "";
    while (!st.empty()){
        res += st.top();
        st.pop();
    }
        
    reverse(res.begin(), res.end());
    if (res == "")
    	cout << "EMPTY\n";
    else
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
Cho một xâu kí tự S chỉ bao gồm kí tự in thường, nhiệm vụ của bạn là xóa các kí tự liền kề giống nhau khỏi xâu S. 
Ví dụ xâu aabbccc sau khi xóa các kí tự liền kề sẽ thành c, xâu abba sau khi xóa các kí tự liền kề sẽ thành xâu rỗng.
Input Format
Dòng duy nhất chứa xâu kí tự S
Constraints
1<=len(S)<=10000;
Output Format
In ra xâu S sau khi xóa các kí tự liền kề giống nhau, nếu xâu sau khi xóa rỗng thì in ra EMPTY.
Sample Input 0
dddbbabcb
Sample Output 0
dabcb

*/
