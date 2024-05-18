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

struct node{
	int data;
	node *left;
	node *right;
};

node* create_node(int x){
	node *tmp = new node;
	tmp->data = x;
	tmp->left = tmp->right = NULL;
	return tmp;
}

void makeRoot(node *root, int u, int v, char c){
	if (c == 'L')
		root->left = create_node(v);
	else
		root->right = create_node(v);
}

void insertNode(node *root, int u, int v, char c){
	if (root == NULL)
		return;
	if (root->data == u){
		makeRoot(root, u, v, c);
	} else{
		insertNode(root->left, u, v, c);
		insertNode(root->right, u, v, c);	
	}
}

void levelOrder(node *root){
	queue<node*> q;
	q.push(root);
	while (!q.empty()){
		node *u = q.front(); q.pop();
		cout << u->data << ' ';
		if (u->left != NULL) q.push(u->left);
		if (u->right != NULL) q.push(u->right);
	}
	cout << EL;
}

void solve(){
	int n; cin >> n;
	node *root = NULL;
	for (int i = 0; i < n; i++){
		int u, v; char c;
		cin >> u >> v >> c;
		if (root == NULL){
			root = create_node(u);
			makeRoot(root, u, v, c);
		}
		else {
			insertNode(root, u, v, c);
		}
	}
	
	levelOrder(root);
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
Cho cây nhị phân, nhiệm vụ của bạn là duyệt cây theo Level-order. 
Phép duyệt level-order trên cây là phép thăm node theo từng mức của cây. 
Ví dụ với cây dưới đây sẽ cho ta kết quả của phép duyệt level-order: 20  8  22  4  12  10  14.

Input:

Dòng đầu tiên đưa vào số lượng test T.
Những dòng tiếp theo đưa vào các bộ test. Mỗi bộ test gồm 2 dòng: dòng đầu tiên đưa vào số N là số lượng cạnh của cây; dòng tiếp theo đưa vào N bộ ba (u, v, x), trong đó u là node cha, v là node con, x= R nếu v là con phải, x=L nếu v là con trái; u, v, x được viết cách nhau một vài khoảng trống.
T, N, u, v, thỏa mãn ràng buộc: 1≤T≤100; 1≤N≤103; 1≤u, v≤104;
Output:

Đưa ra kết quả phép duyệt level-order theo từng dòng.
     Ví dụ:

Input
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output
1 3 2
10 20 30 40 60
*/
