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

string x;

void Init(){
	cin >> x;	
}

void genNext(){
	int i = x.sz - 2;
	while (i >= 0 && x[i] >= x[i + 1]){
		--i;
	}

	if (i < 0){
		cout << "BIGGEST\n";
	}
	else {
		int pos;
		for (pos = x.sz - 1; pos >= i; pos--)
			if (x[pos] > x[i])
				break;
		swap(x[pos], x[i]);
		reverse(x.begin() + i + 1, x.end());
		cout << x << EL;
	}
}

void solve(){
	Init();
	genNext();
}

int main(){
	faster();
	int TC; cin >> TC;
	while (TC--){
		int stt; cin >> stt; cout << stt << " ";
		solve();
	}
	return 0;
}

/*
Hãy viết chương trình nhận vào một chuỗi (có thể khá dài) các ký tự số và đưa ra màn hình hoán vị kế tiếp của các ký tự số đó (với ý nghĩa là hoán vị có giá trị lớn hơn tiếp theo nếu ta coi chuỗi đó là một giá trị số nguyên). Chú ý: Các ký tự số trong dãy có thể trùng nhau.

Ví dụ:               123 -> 132

279134399742 -> 279134423799  

Cũng có trường hợp sẽ không thể có hoán vị kế tiếp. Ví dụ như khi đầu vào là chuỗi 987.  

Dữ liệu vào: Dòng đầu tiên ghi số nguyên  t là số bộ test (1 ≤ t ≤ 1000).  Mỗi bộ test có một dòng, đầu tiên là số thứ tự bộ test, một dấu cách, sau đó là chuỗi các ký tự số, tối đa 80 phần tử.  

Kết quả: Với mỗi bộ test hãy đưa ra một dòng gồm thứ tự bộ test, một dấu cách, tiếp theo đó là hoán vị kế tiếp hoặc chuỗi “BIGGEST” nếu không có hoán vị kế tiếp. 

Ví dụ:

INPUT

3

1 123

2 279134399742

3 987

OUTPUT

1 132

2 279134423799

3 BIGGEST
*/