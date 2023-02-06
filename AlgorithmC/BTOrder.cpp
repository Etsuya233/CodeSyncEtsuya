#include <cstdio>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;

typedef struct BinaryTreeNode{
	int data;
	BinaryTreeNode *lchild, *rchild;
} BTNode, *BTree;

typedef struct ThreadBinaryTreeNode{
	int data;
	int ltag, rtag;
	ThreadBinaryTreeNode *lchild, *rchild;
} TBNode, *TBTree;

BTree regenerateTreeByPreInOrder(int* P, int* I, int headP, int footP, int headI, int footI);
void inOrderIteration(BTree root);
void preOrder(BTree root);
void inOrder(BTree root);
void postOrder(BTree root);
void inOrderIterator2(BTree root);
void levelTravesal(BTree root);
void copyBinaryTree(BTree root, BTree *dest);
BTree copyBinaryTree2(BTree ori);
BTree createNode(int value);
int depthOfBinaryTree(BTree root);
int amountOfBTNode(BTree root);
int amountOfLeafNode(BTree root);	//It would be great if we name this function leafCount().
void genTBTree(TBTree root);
void genTBTreeCore(TBTree root, TBTree pre);

int main(){
	int pre[] = {1, 3, 2, 7, 8, 5, 6, 0};
	int in[] = {2, 3, 7, 8, 1, 5, 0, 6};
	BTree a = regenerateTreeByPreInOrder(pre, in, 0, 7, 0, 7);
	inOrderIteration(a);
	printf("\n");
	inOrderIterator2(a);
	printf("\n");
	levelTravesal(a);
	printf("\n");
	BTree b;
	copyBinaryTree(a, &b);
	preOrder(b);
	printf("\n");
	BTree c = copyBinaryTree2(a);
	preOrder(c);
	printf("\n");
	printf("%d \n", depthOfBinaryTree(a));
	printf("%d \n", amountOfBTNode(b));
	printf("%d \n", amountOfLeafNode(a));
}

BTree regenerateTreeByPreInOrder(int* P, int* I, int headP, int footP, int headI, int footI){
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

void inOrderIteration(BTree root){
	stack<BTree> my;
	BTree p = root;
	while(!my.empty() || p){
		if(p){
			my.push(p);
			p = p -> lchild;
		} else {
			BTree q = my.top();
			my.pop();
			printf("%d ", q -> data);
			p = q -> rchild;
		}
	}
}

void preOrder(BTree root){
	if(root == NULL) return;
	printf("%d ", root->data);
	preOrder(root->lchild);
	preOrder(root->rchild);
}

void inOrder(BTree root){
	if(root == NULL) return;
	inOrder(root->lchild);
	printf("%d ", root->data);
	inOrder(root->rchild);
}

void postOrder(BTree root){
	if(root == NULL) return;
	postOrder(root->lchild);
	postOrder(root->rchild);
	printf("%d ", root->data);
}

void inOrderIterator2(BTree root){
	stack<BTree> my;
	BTree p = root;
	while(! my.empty() || p){
		if(p){
			my.push(p);
			p = p -> lchild;
		} else {
			p = my.top() -> rchild;
			printf("%d ", my.top() -> data);
			my.pop();
		}
	}
}

void levelTravesal(BTree root){
	queue<BTree> my;
	my.push(root);
	while(!my.empty()){
		printf("%d ", my.front()->data);
		if(my.front()->lchild) my.push(my.front()->lchild);
		if(my.front()->rchild) my.push(my.front()->rchild);
		my.pop();
	}
}

void copyBinaryTree(BTree root, BTree *dest){
	if(root){
		*dest = (BTree)malloc(sizeof(BTNode));
		(*dest) -> data = root -> data;
		copyBinaryTree(root -> lchild, &((*dest) -> lchild));
		copyBinaryTree(root -> rchild, &((*dest) -> rchild));
	} else {
		(*dest) = NULL;
	}
}

BTree createNode(int value){
	BTree ret = (BTree)malloc(sizeof(BTNode));
	ret -> data = value;
	ret -> lchild = NULL;
	ret -> rchild = NULL;
	return ret;
}

BTree copyBinaryTree2(BTree ori){
	if(ori){
		BTree a = (BTree)malloc(sizeof(BTNode));
		a -> data = ori -> data;
		a -> lchild = copyBinaryTree2(ori -> lchild);
		a -> rchild = copyBinaryTree2(ori -> rchild);
		return a;
	} else {
		return NULL;
	}
}

int depthOfBinaryTree(BTree root){
	if(root){
		int a = depthOfBinaryTree(root -> lchild);
		int b = depthOfBinaryTree(root -> rchild);
		return (a > b)? a + 1: b + 1;
	} else {
		return 0;
	}
}

int amountOfBTNode(BTree root){
	if(root){
		int a = amountOfBTNode(root -> lchild);
		int b = amountOfBTNode(root -> rchild);
		return a + b + 1; 
	} else {
		return 0;
	}
}

int amountOfLeafNode(BTree root){
	int a = 0, b = 0, halfLeafNode = 0;
	if(root -> lchild) a = amountOfLeafNode(root -> lchild);
	else halfLeafNode ++;
	if(root -> rchild) b = amountOfLeafNode(root -> rchild);
	else halfLeafNode ++;
	if(halfLeafNode == 2) a ++;
	return a + b;
}

void genTBTreeCore(TBTree root, TBTree pre){
	if(!root) return;
	genTBTreeCore(root -> lchild, pre);
	if(root -> lchild == NULL){
		root -> lchild = pre;
		root -> ltag = 1;
	}
	if(pre != NULL && pre -> rchild == NULL){
		pre -> rchild = root;
		pre -> rtag = 1;
	}
	pre = root;
	genTBTreeCore(root -> rchild, pre);
}

void genTBTree(TBTree root){
	if(root){
		root -> lchild = NULL;
		root -> ltag = 1;
		genTBTreeCore(root, NULL);
	}
}

void inOrderTBTree(TBTree root){
	root = inOrderTBTreeFirst(root);
	while(!root == NULL){
		printf("%d ", root -> data);
		root = inOrderTBTreeNext(root);
	}
}

void inOrderTBTreeCore(TBTree root){
	if(root){
		printf("%d ", root -> data);
		inOrderTBTree(root -> rchild);
	} else {
		return;
	}
}

TBTree inOrderTBTreeFirst(TBTree root){
	while(root -> ltag = 0) root = root -> lchild;
	return root;
}

TBTree inOrderTBTreeNext(TBTree root){
	if(root -> rtag){
		return root -> rchild;
	} else {
		return inOrderTBTreeFirst(root -> rchild);
	}
}