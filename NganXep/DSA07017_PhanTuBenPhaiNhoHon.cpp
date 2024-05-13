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

void greater_right(int *a, int n, int *GR){
	stack<int> st;
	for (int i = 0; i < n; i++){
		while (!st.empty() && a[i] > a[st.top()]){
			GR[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()){
		GR[st.top()] = -1;
		st.pop();
	}
}

void smaller_right(int *a, int n, int *SR){
	stack<int> st;
	for (int i = 0; i < n; i++){
		while (!st.empty() && a[i] < a[st.top()]){
			SR[st.top()] = a[i];		
			st.pop();
		}
		st.push(i);
	}
	while (!st.empty()){
		SR[st.top()] = -1;
		st.pop();
	}
}

void solve(){
	int n; cin >> n; 
	int a[n + 5];
	int GR[n + 5];//greater right
	int SR[n + 5];//smaller right
	for (int i = 0; i < n; i++) cin >> a[i];
	
	greater_right(a, n, GR);
	smaller_right(a, n, SR);
	
	for (int i = 0; i < n; i++){
		if (GR[i] == -1)
			cout << "-1 ";
		else
			cout << SR[GR[i]] << ' ';
	}
	cout << EL;
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
Ở bài này ta phải đi tìm chỉ số của phần tử đầu tiên LỚN hơn bên phải của a[i] lưu vào GR (mảng này bắt buộc phải lưu index)
				  đi tìm chỉ số của phần tử đầu tiên NHỎ hơn bên phải của a[i] lưu vào SR (mảng này có thể lưu index hoặc value)
=> Để tìm phần tử đầu tiên NHỎ hơn của greater thì ta sẽ duyệt mảng greater và in ra SR[GR[i]]
	nếu GR[i] = -1 thì in ra -1 luôn ko cần truy xuất tới SR nữa.

Cho mảng A[] gồm n phần tử. Hãy đưa ra các phần tử nhỏ hơn tiếp theo của phần tử lớn hơn 
đầu tiên phần tử hiện tại. Nếu phần tử hiện tại không có phần tử lớn hơn tiếp theo ta xem là -1. 
Nếu phần tử không có phần tử nhỏ hơn tiếp theo ta cũng xem là -1. 
Ví dụ với mảng A[] = {5, 1, 9, 2, 5, 1, 7} ta có kết quả là ans = {2, 2, -1, 1, -1, -1, -1} vì:

Next Greater                        		 Right Smaller

5 ->  9                                        9  ->  2

1 ->  9                                        9  ->  2

9 -> -1                                       -1 -> -1

2 -> 5                                         5   -> 1

5 -> 7                                         7  -> -1

1 ->  7                                        7 -> -1

7 -> -1                                        7 -> -1

Input:

Dòng đầu tiên đưa vào số lượng bộ test T;
Những dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test gồm hai dòng: dòng thứ nhất đưa vào n là số phần tử của mảng A[], dòng tiếp theo đưa vào n số A[i].
Output:

Đưa ra kết quả mỗi test theo từng dòng.
Ràng buộc:

T, n, A[i] thỏa mãn ràng buộc: 1≤T≤100; 1≤n, A[i] ≤106.
Ví dụ:

Input

2
7
5 1 9 2 5 1 7
8
4 8 2 1 9 5 6 3

Output
2 2 1 1 -1 -1 -1
2 5 5 5 -1 3 -1 -1
*/
