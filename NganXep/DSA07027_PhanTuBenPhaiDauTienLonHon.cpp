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

void NGE(int *a, int n, int *d){
	stack<int> st;
	for (int i = 0; i < n; i++){
		while (!st.empty() && a[i] > a[st.top()]){
			d[st.top()] = a[i];
			st.pop();
		}
		st.push(i);
	}

	while (!st.empty()){
		d[st.top()] = -1;
		st.pop();
	}
}

void solve(){
	int n; cin >> n;
	int a[n + 5], d[n + 5];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	NGE(a, n, d);
	
	for (int i = 0; i < n; i++)
		cout << d[i] << ' ';
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
Có 1 cái note cho các bài như này:
	Phần tử đầu tiên bên phải là duyệt từ trái sang phải
						 trái là duyệt từ phải qua trái
						 	  lớn hơn thì điền dấu >
						 	  bé hơn thì điền  dấu <	
Next greater element (NGE)
Để làm bài này thì chỉ cần nhớ những thao tác: 
	B1: Đi tìm con (tức đi tìm xem nó có thể làm bố của ai bằng cách duyệt stack)
	B2: push vào stack để đợi xem bố của mình là ai
Các phần tử vẫn đang còn trong stack là vẫn chưa tìm được bố, tìm đc bố rồi thì pop ra

Phần tử lớn hơn đầu tiên bên phải của a[i] tạm gọi là bố của a[i]
stack ta sẽ lưu chỉ số của a[i], d[i] sẽ lưu phần tử đầu tiên lớn hơn bên phải
của a[i].
Mỗi phần tử của a[i] ta sẽ đi kiểm tra xem nó có thể làm bố của thằng nào đang nằm trong
stack hay không (các phần tử trong stack sẽ tăng dần)
Nếu a[i] có thể làm bố của đứa nào thì d[st.top()] = a[i];
Sau cùng phải cho a[i] vào trong stack để nó còn đi tìm bố

Sau khi lặp hết tất cả, các phần tử còn sót lại trong stack là những phần tử
không tìm được bố, các phần tử đó sẽ có d[] = -1

Cho dãy số A[] gồm N phần tử. Với mỗi A[i], bạn cần tìm phần tử bên phải đầu tiên lớn hơn nó. 
Nếu không tồn tại, in ra -1.

Input:

Dòng đầu tiên là số lượng bộ test T (T ≤ 20).

Mỗi test bắt đầu bởi số nguyên N (1 ≤ N ≤ 100000).

Dòng tiếp theo gồm N số nguyên A[i] (0 ≤ A[i] ≤ 109).

Output: 

Với mỗi test, in ra trên một dòng N số R[i], với R[i] là giá trị phần tử đầu tiên lớn hơn A[i].

Ví dụ

Input
3
4
4 5 2 25
3
2 2 2
4
4 4 5 5

Output
5 25 25 -1
-1 -1 -1
5 5 -1 -1
*/
