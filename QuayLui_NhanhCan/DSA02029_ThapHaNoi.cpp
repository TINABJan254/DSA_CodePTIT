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

void move(int n, char A, char B, char C){
	if (n == 1){
		cout << A << " -> " << C << EL;
	}
	else {
		move(n - 1, A, C, B);
		move(1, A, B, C);
		move(n - 1, B, A, C);
	}
}

void HaNoi_Tower(){
	int n;
	cin >> n;
	move(n, 'A', 'B', 'C');
}

int main(){
	faster();
	HaNoi_Tower();
	return 0;
}

/*
Bài toán Tháp Hà Nội đã rất nổi tiểng. 
Bắt đầu có các đĩa xếp chồng lên cột A theo thứ tự kích thước giảm dần, nhỏ nhất ở trên cùng. 
Cột B và cột C ban đầu không có đĩa nào cả.
Mục tiêu của bạn là di chuyển toàn bộ các đĩa theo đúng thứ tự về cột C, tuân theo các quy tắc sau:

Mỗi lần chỉ có thể di chuyển một đĩa.
Mỗi lần di chuyển sẽ lấy đĩa trên từ một trong các cột và đặt nó lên trên một cột khác.
Không được đặt đĩa lên trên đĩa nhỏ hơn..
Input:

Số tự nhiên  0 < N < 10

Output:

In ra lần lượt từng bước theo mẫu trong ví dụ. Chú ý giữa các chữ cái và dấu -> có khoảng trống.

Ví dụ:

Input
3 

Ouput
A -> C
A -> B
C -> B
A -> C
B -> A
B -> C
A -> C
*/