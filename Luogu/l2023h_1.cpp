#include <iostream>
#include <queue>
using namespace std;

typedef struct NNode {
    int e, val, left, right, now;
} node;

struct cmpNNode{ //重写()!!! 
    bool operator() (const node* a, const node* b){ //reverse
        if(a->e != b->e) return a->e < b->e;
        else if(a->val != b->val) return a->val > b->val;
        else if(a->now != b->now) return a->now > b->now;
        else if(a->left != b->left) return a->left > b->left;
        else return a->right < b->right;
    }
};

int n, k;
node arr[500005];
priority_queue<node*, vector<node*>, cmpNNode> qu; //对node的引用 

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> arr[i].val;
        arr[i].left = i - 1;
        arr[i].right = i + 1;
        arr[i].now = i;
        arr[i].e = 1;
    }
    for(int i = 1; i <= n; i++){
        qu.push(&arr[i]);
    }
    for(int i = 1; i <= k; i++){
        node* top = qu.top();
        int loc = top->now;
        arr[loc].e = 0;
        arr[arr[loc].left].val += arr[loc].val;
        arr[arr[loc].right].val += arr[loc].val;
        arr[arr[loc].left].right = arr[loc].right;
        arr[arr[loc].right].left = arr[loc].left;
        qu.pop();
    }
    for(int i = 1; i <= n; i++){
        if(arr[i].e == 1) cout << arr[i].val << " ";
    }
    cout << "\n";
    return 0;
}
