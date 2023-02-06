#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct BinaryTreeNode{
	char data;
	BinaryTreeNode *lchild, *rchild;
} BTNode, *BTree;

char PP[1000001];
char II[1000001];

BTree regenerateTreeByPreInOrder(char* P, char* I, int headP, int footP, int headI, int footI);
void postOrder(BTree root);

int main(){
	scanf("%s", II);
	scanf("%s", PP);
	int len = (int)strlen(PP) - 1;
	BTree a = regenerateTreeByPreInOrder(PP, II, 0, len, 0, len);
	postOrder(a);
}

BTree regenerateTreeByPreInOrder(char* P, char* I, int headP, int footP, int headI, int footI){
	BTree root = (BTree)malloc(sizeof(BTNode));
	root->data = P[headP];
	root->lchild = root->rchild = NULL;
	if(footP - headP < 0) return NULL;
	int cnt;
	for(cnt = headI; cnt <= footI; cnt++){
		if(I[cnt] == P[headP]) break;
	}
	cnt -= headI;
	root->lchild = regenerateTreeByPreInOrder(P, I, headP + 1, headP + cnt, headI, headI + cnt - 1);
	root->rchild = regenerateTreeByPreInOrder(P, I, headP + cnt + 1, footP, headI + cnt + 1, footI);
	return root;
}

void postOrder(BTree root){
	if(root == NULL) return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%c", root->data);
}