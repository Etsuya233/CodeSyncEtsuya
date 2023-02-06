#include <cstdio>

typedef struct BinaryTree{
	BinaryTree *lchild = NULL, *rchild = NULL;
	int data = -1;
} *BTree, BTNode;

int ans = 0;
BTree bt;
void search(int data, BTree root, int depth, int newData1, int newData2);

int main(){
	bt = new BTNode;
	bt -> data = 1;
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int l, r;
		scanf("%d%d", &l, &r);
		search(i, bt, 1, l, r);
	}
	printf("%d", ans - 2);
}

void search(int data, BTree root, int depth, int newData1, int newData2){
	ans = (depth > ans)? depth: ans;
	if(root == NULL) return;
	else if(root -> data == data){
		root -> lchild = new BTNode;
		root -> lchild -> data = newData1;
		root -> rchild = new BTNode;
		root -> rchild -> data = newData2;
		return;
	} else {
		search(data, root -> lchild, depth + 1, newData1, newData2);
		search(data, root -> rchild, depth + 1, newData1, newData2);
	}
}