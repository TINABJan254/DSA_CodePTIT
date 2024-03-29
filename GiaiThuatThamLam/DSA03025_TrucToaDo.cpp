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

bool cmp(pii x, pii y){
	if (x.se != y.se)
		return x.se < y.se;
	return x.fi < y.fi;
}

void solve(){
	int n; cin >> n;
	pii Segment[n + 5];
	for (int i = 0; i < n; i++){
		cin >> Segment[i].fi >> Segment[i].se;
	} 

	sort(Segment, Segment + n, cmp);
	int total_segments = 1;
	pii cur_seg = Segment[0];
	for (int i = 1; i < n; i++){
		if (cur_seg.se <= Segment[i].fi){
			cur_seg = Segment[i];
			++total_segments;
		}
	}
	cout << total_segments << EL;
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
Trên trục Ox tính từ vị trí 0, người ta muốn xếp nhiều nhất các đoạn thẳng sao 
cho không đoạn nào chồng lấn lên nhau. Đoạn thẳng thứ i có vị trí bắt đầu là 
X1[i] và kết thúc tại X2[i], với X1[i] <= X2[i].

Hãy tính số đoạn thẳng nhiều nhất có thể được lựa chọn để đưa lên trục Ox và 
không có đoạn nào chồng lấn lên nhau.

Input

Dòng đầu tiên ghi số bộ test, không quá 10.
Với mỗi bộ test: dòng đầu ghi số N là số đoạn thẳng (không quá 105)
Tiếp theo là N dòng, mỗi dòng có 2 số nguyên mô tả đoạn thẳng. 
Các giá trị tọa độ đều là các số nguyên không âm và không quá 106.

Output

Với mỗi test, viết trên 1 dòng số lượng đoạn thẳng nhiều nhất có thể được lựa chọn thỏa mãn điều kiện đề bài.

Ví dụ

Input
1
10
39 55
37 74
0 1
19 25
65 76
51 52
19 21
5 94
46 65
32 40

Output
5
*/