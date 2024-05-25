#include <bits/stdc++.h>

using namespace std;

#define EL "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

void solve(){
	string s; cin >> s;
	s += '0';
	vector<int> v;
	int cnt = 0;
	for (int i = 0; i < s.sz; i++){
		if (s[i] == '1')
			++cnt;
		else {
			if (cnt != 0)
				v.pb(cnt);
			cnt = 0;
		}
	}
	
	sort(v.begin(), v.end(), greater<int>());
	ll res = 0;
	for (int i = 0; i < v.sz; i += 2){
		res += v[i];
	}
	cout << res;
}

int main(){
	faster();
	solve();
	return 0;
}

/*Tí vào Tèo cùng chơi một trò chơi với xâu nhị phân S. Xâu nhị phân S chỉ bao gồm các kí tự 0 và 1. Ở mỗi bước đi, 2 bạn nhỏ có thể chọn 1 xâu con liên tiếp các kí tự giống nhau ở xâu S và xóa nó khỏi xâu S. Sau khi xóa 1 xâu thì 2 xâu bên trái và phải của xâu vừa xóa sẽ trở thành liền kề. Ban đầu Tí là người đi trước, sau đó 2 bạn lần lượt thực hiện bước đi của mình cho tới khi xâu S trở thành xâu rỗng. Bạn hãy xác định xem Tí có thể xóa tối đa bao nhiêu kí tự 1 biết rằng cả 2 bạn đều chơi tối ưu
Input Format
Dòng duy nhất chứa xâu S
Constraints
1<=len(S)<=100000;
Output Format
In ra số lượng số 1 tối đa mà Tí có thể xóa được
Sample Input 0
1000101110011111
Sample Output 0
6


*/
