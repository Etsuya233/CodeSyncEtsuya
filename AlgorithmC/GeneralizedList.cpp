#include <cstdio>
#include <cstdlib>

typedef struct GeneralizedNode{
	int tag;
	union{
		int atom;
		struct GeneralizedNode* hp;
	} un;
	struct GeneralizedNode* tp;
} node, *gList;

typedef struct GeneralizedNode2{
	int tag;
	union{
		int atom;
		struct{
			GeneralizedNode2 *hp, *tp;
		};
	} un;
} node2, *gList2;

int readNum(char* str, int loc);

gList CreateList();
gList CreateNode(int tag);
void Traverse(gList a);
int GListDepth(gList a);
gList CreateGListStr(char* str);
gList CreateGListStrOpera(char* str, int pos);

gList2 CreateList2();
gList2 CreateGListStr2(char* str);
gList2 CreateGListStrOpera2(char* str, int loc);
gList2 CreateNode2(int tag);
void Traverse2(gList2 a);
int GListDepth2(gList2 a);

int main(){
	char str[] = "(1,2,(1,3,7),2,(2,(2,3)))";
	gList a = CreateGListStr(str);
	printf("\n------------\n");
	Traverse(a);
	printf("\n------------\n");
	gList b = CreateNode(0);
	b->un.atom = 1;
	b->tp = CreateNode(1);
	b->tp->un.hp = CreateNode(0);
	b->tp->un.hp->un.atom = 2;
	b->tp->un.hp->tp = CreateNode(0);
	b->tp->un.hp->tp->un.atom = 3;
	b->tp->un.hp->tp->tp = CreateNode(1);
	b->tp->un.hp->tp->tp->un.hp = CreateNode(0);
	b->tp->un.hp->tp->tp->un.hp->un.atom = 5;
	b->tp->tp = CreateNode(0);
	b->tp->tp->un.atom = 4;
	Traverse(b);
	printf("\n%d", GListDepth(b));
	printf("\n------------\n");
	gList2 aa = CreateGListStr2(str);
	printf("\n");
	Traverse2(aa);
	printf("\n%d", GListDepth2(aa));
}

gList CreateList(){
	gList temp = (gList)malloc(sizeof(node));
	temp->tag = 0;
	temp->un.atom = 0;
	temp->un.hp = NULL;
	temp->tp = NULL;
	return temp;
}

gList2 CreateList2(){
	gList2 temp = (gList2)malloc(sizeof(node2));
	temp->tag = 0;
	temp->un.atom = 0;
	temp->un.hp = NULL;
	temp->un.tp = NULL;
	return temp;
}

gList CreateNode(int tag){
	gList temp = CreateList();
	if(tag) temp->tag = 1;
	return temp;
}

gList2 CreateNode2(int tag){
	gList2 temp = CreateList2();
	if(tag) temp->tag = 1;
	return temp;
};

void Traverse(gList a){
	if(a == NULL) return;
	if(a->tag == 0){
		printf("%d ", a->un.atom);
	} else {
		Traverse(a->un.hp);
	}
	Traverse(a->tp);
}

void Traverse2(gList2 a){
	if(!a) return;
	if(!(a->tag)){
		printf("%d ", a->un.atom);
		return;
	} else {
		Traverse2(a->un.hp);
		Traverse2(a->un.tp);
	}
}

int GListDepth(gList a){
	if(!a) return 0;
	int max = 0;
	for(gList i = a; i != NULL; i = i->tp){
		if(i->tag){
			int depth = GListDepth(i->un.hp);
			max = (depth > max)? depth: max;
		}
	}
	return max + 1;
}

int GListDepth2(gList2 a){
	if(!a) return 0;
	int max = 0;
	if(!a->tag){
		return 0;
	} else {
		for(gList2 i = a; i != NULL; i = i->un.tp){
			int depth = GListDepth2(i->un.hp);
			if(depth > max) max = depth;
		}
		return max + 1;
	}
}

gList CreateGListStr(char* str){
	return CreateGListStrOpera(str, 1);
}

gList CreateGListStrOpera(char* str, int loc){
	//loc表示某一层括号内的第一个字符，不包括'('，
	//也就是说，算法从这个地方开始，遇到一个不成对的')'结束（再算法中会去除成对的括号）。
	gList head = CreateList();	//记录头部节点
	gList now = head;	//记录当前操作节点
	while(str[loc] != ')'){	 //遇到一个不成对的')'结束算法
		if(str[loc] != '('){	//判断当前字符是否为'('
			now->tag = 0;	//令当前操作节点的tag为0
			int number = readNum(str, loc);	//读入数字
			//移动loc到完整数字的下一位？
			// 如果数字后是','，则移动到在下一位，如果是')'，则在此停下，因为当前while要判断广义表的结束）
			while(str[++loc] == ',' && str[loc] == ')');
			if(str[loc] == ',') loc++;
			now->un.atom = number; //写入数字
		} else {
			now->tag = 1; //令当前操作节点的tag为1
			now->un.hp = CreateGListStrOpera(str, loc + 1);	//当前操作节点的hp获得当前广义表的地址，loc+1的原因函数头部注释有说明
			int numOfBracket = 1; //令loc走到代表广义表元素的字符串的下一位
			while(numOfBracket){
				++loc;
				if(str[loc] == ')') numOfBracket--;
				if(str[loc] == '(') numOfBracket++;
			}
			loc++;
			if(str[loc] == ',') loc++; //如果这一位是','，则再走一位（为了解决"(1,2,3),2"的情况）
		}
		if(str[loc] != ')'){//如果当前loc不为')'（因为如果是')'的话就不能再继续创建节点了）
			now->tp = CreateList();
			now = now->tp;
		}
	}
	return head;
}

gList2 CreateGListStr2(char* str){
	return CreateGListStrOpera2(str, 1);
}

gList2 CreateGListStrOpera2(char* str, int loc){
	gList2 origin = CreateNode2(1);
	gList2 now = origin;
	while(str[loc] != ')'){
		if(str[loc] != '('){
			gList2 atom = CreateNode2(0);
			int number = readNum(str, loc);
			atom->un.atom = number;
			now->un.hp = atom;
			while(str[++loc] == ',' && str[loc] == ')');
			if(str[loc] == ',') loc++;
		} else {
			gList2 list = CreateGListStrOpera2(str, loc + 1);
			now->un.hp = list;
			int numOfBracket = 1; //令loc走到代表广义表元素的字符串的下一位
			while(numOfBracket){
				++loc;
				if(str[loc] == ')') numOfBracket--;
				if(str[loc] == '(') numOfBracket++;
			}
			loc++;
			if(str[loc] == ',') loc++; //如果这一位是','，则再走一位（为了解决"(1,2,3),2"的情况）
		}
		if(str[loc] != ')'){//如果当前loc不为')'（因为如果是')'的话就不能再继续创建节点了）
			now->un.tp = CreateNode2(1);
			now = now->un.tp;
		}
	}
	return origin;
}

int readNum(char* str, int loc){
	int ret = 0;
	while(str[loc] != ',' && str[loc] != ')'){
		ret = ret * 10 + (int)(str[loc] - '0');
		loc++;
	}
	printf("%d ", ret);
	return ret;
}










//gList CreateNode(int tag);
//gList CreateList1Opera(char* str, int loc);
//int readNumber(char* str, int loc);

//gList CreateList1(char* str){
//    gList origin = CreateList1Opera(str, 0);
//	return origin;
//}
//
//gList CreateList1Opera(char* str, int loc){
//    gList origin = CreateList();
//    gList now = origin;
//    while(str[loc] != ')'){
//        if(str[loc] != '('){
//            int number = readNumber(str, loc);
//            while(str[loc] != ',') loc ++;//Jump out to behind the ,
//            loc ++;
//            gList temp = CreateNode(0);
//            temp->un.atom = number;
//			now->tp = temp;
//			now = temp;
//        } else {
//            now->tp = CreateNode(1);
//            gList temp = CreateList1Opera(str, loc + 1);
//            now->tp->un.hp = temp;
//            while(loc != ')') loc++;
//            if(str[++ loc] == ',') loc ++;
//        }
//    }
//    return origin;
//}
//
//int readNumber(char* str, int loc){
//    int isMinus = 0;
//    if(str[loc] == '-'){
//        isMinus = 1;
//        loc ++;
//    }
//    int cnt = 0;
//    while(str[loc] != ',' && str[loc] != ')'){
//        int number = str[loc] - '0';
//        cnt = cnt * 10 + number;
//		loc ++;
//    }
//    if(isMinus) cnt = -cnt;
//    return cnt;
//}