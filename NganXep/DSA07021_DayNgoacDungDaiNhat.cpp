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

int findMaxLen(string s){
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
	
	int res = 0, last = s.sz;
	while (!st.empty()){
		int now = st.top();
		st.pop();
		res = max(res, last - now - 1);
		last = now;
	}
	
	return max(res, last);
}

void solve(){
	string s; cin >> s;
	cout << findMaxLen(s) << EL;
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
Length of the longest valid substring (GFG)

Cách làm sẽ giống với kiểm tra dấu ngoặc hợp lệ, nhưng ở đây ta sẽ lưu thêm vị trí của những dấu
ngoặc đóng ko hợp lệ
Vd: ) ( ) ( ) )	
	0 1 2 3 4 5
1. i = 0, dấu ngoặc mở nên push chỉ số 0. Ngăn xếp chứa: 0
2. i = 1, dấu ngoặc mở nên push chỉ mục 1. Ngăn xếp chứa: 0 1
3. i = 2, dấu ngoặc đóng. Ngăn xếp không trống và trên cùng là chỉ mục của dấu ngoặc mở. 
		  Vì vậy, pop. Ngăn xếp chỉ chứa 0
4. i = 3, lại mở và tại i = 4 đóng ngoặc để nhấn lại rồi pop. Ngăn xếp chứa : 0
5. i = 5, dấu ngoặc đóng. Ngăn xếp không trống nhưng trên cùng là chỉ mục dấu ngoặc đóng. 
		  Vì vậy push chỉ số 5. Ngăn xếp chứa: 0 5

Qua đó ta có thể thấy được khoảng giữa 2 dấu đóng ko hợp lệ chính là độ dài dãy ngoặc hợp lệ
Tuy nhiên cần chú ý trường hợp
	- Sau chỉ số cuối là 1 dãy hợp lệ
	- Trước chỉ số đầu tiên là 1 dãy hợp lệ
	=> Với 2TH này sẽ ko có dấu ngoặc đóng ko hợp lệ để kết thúc nên ko được lưu vào stack, ta phải xử lý riêng
	(ví dụ như này: ()() )()()) ()()()
Với TH sau chỉ số cuối là 1 dãy hợp lệ thì ta sẽ đi xét một biến last, khởi tạo bằng N (độ dài xâu)
để xét độ dài từ vị trí cuối xâu đến vị trí top trên stack
mỗi bước lặp last gán lại bằng now (tức đỉnh stack)
Với TH có dãy dấu ngoặc hợp lệ phía bên phải stack thì chỉ cần trả về max(last, res)
vì chỉ số đầu tiên đến last chính là độ dài dãy con hợp lệ từ vị trí đầu tiên tới vị trí dấu ngoặc đóng
ko hợp lệ đầu tiên (xem code để hiểu rõ hơn)
vd như này: 
	()())())
	thì stack chỉ lưu: 4 6
	=> mà ở đây còn có TH chỉ số 0->4 là dãy thỏa mãn nên ta cần xét

Cho một xâu chỉ gồm các kí tự ‘(‘ và ‘)’. Một dãy ngoặc đúng được định nghĩa như sau:

-     Xâu rỗng là 1 dãy ngoặc đúng.
-     Nếu A là 1 dãy ngoặc đúng thì (A) là 1 dãy ngoặc đúng.

-     Nếu A và B là 2 dãy ngoặc đúng thì AB là 1 dãy ngoặc đúng.

Cho một xâu S. Nhiệm vụ của bạn là hãy tìm dãy ngoặc đúng dài nhất xuất hiện trong xâu đã cho.

Input: Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test gồm một xâu S có độ dài không vượt quá 105 kí tự.

Output:  Với mỗi test in ra một số nguyên là độ dài dãy ngoặc đúng dài nhất tìm được.

Ví dụ:

Input:
3
((()
)()())
()(()))))
 
Output
2
4
6
*/
