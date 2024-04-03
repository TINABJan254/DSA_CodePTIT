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
	string s;
	cin >> s;
	vector<int> pos; //store pos of '['
	for (int i = 0; i < s.sz; i++){
		if (s[i] == '[')
			pos.pb(i);
	}

	int p = 0; //index of vector pos
	int sum = 0; //number of swap necessary
	int count = 0; //count number of '['

	for (int i = 0; i < s.sz; i++){
		if (s[i] == '['){
			++count;
			++p; //Vì dấu ngoặc tại vị trí pos[p] này chắc chắn 
				 //sẽ khớp với một dấu ngoặc đóng sau đó nên sẽ ko nằm trong diện đổi chỗ
		}
		else {
			--count;
		}
		if (count < 0){ 
			sum += pos[p] - i;
			swap(s[i], s[pos[p]]);
			++p; //dấu ngoặc mở tại vtri pos[p] đã được đổi chỗ nên ko nằm trong diện đổi nữa
			
			//reset count
			count = 1; // = 1 thì sau khi đổi chỗ có thể dấu ngoặc tiếp theo sẽ bị thành ']' như thế nếu coutn = 0 thì count sẽ < 0 và lại đổi 1 lần nữa dẫn đến sai
		}
	}
	cout << sum << EL;
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
Cho một mảng S gồm 2×N ký tự, trong đó có N ký tự ‘[’ và N ký tự ‘]’. 
Xâu S được gọi là viết đúng nếu S có dạng S2[S1] trong đó S, S2 là các 
xâu viết đúng. Nhiệm vụ của bạn là tìm số các phép đổi chỗ ít nhất các 
ký tự kề nhau của xâu S viết sai để  S trở thành viết đúng. 
	Ví dụ với xâu S =”[]][][” ta có số phép đổi chỗ kề nhau ít nhất là 2.

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu S viết sai theo nguyên tắc kể trên.
T, S thòa mãn ràng buộc: 1≤T≤100; 1≤length(S)≤100000.
Output:

Đưa kết quả trên một dòng.
Ví dụ:
Input
2
[]][][
[][][]

Output
2
0
*/