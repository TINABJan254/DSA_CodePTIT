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

void merge(int *a, int L, int mid, int R){
	vector<int> v1(a + L, a + mid + 1);
	vector<int> v2(a + mid + 1, a + R + 1);
	int i = 0, j = 0;
	while (i < v1.sz && j < v2.sz){
		if (v1[i] <= v2[j]){
			a[L++] = v1[i++];
		}
		else{
			a[L++] = v2[j++];
		}
	}

	while (i < v1.sz){
		a[L++] = v1[i++]; 
	}
	while (j < v2.sz){
		a[L++] = v2[j++];
	}
}

void mergeSort(int *a, int L, int R){
	if (L < R){
		int mid = (L + R) / 2;
		mergeSort(a, L, mid);
		mergeSort(a, mid + 1, R);
		merge(a, L, mid, R);
	}
}

void solve(){
	int a[100] = {0, 9, 4, 7, 2, 9, 2, 8, 5, 1};
	mergeSort(a, 0, 9); //note: truyen 0 -> n - 1

	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';
}

int main(){
	faster();
	solve();
	return 0;
}

/*

*/