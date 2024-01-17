#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> arr[100005];
int parent[100005] = {0};
int ans[100005] = {0};
int childCount[100005] = {0};
int valid = 1;
int root = 0;

void dfs(int now);
int childCountGen(int now);

int main(){
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        parent[b] = a;
    }
    for(int i = 1; i <= n; i++){
        if(parent[i] == 0){
            root = i;
            break;
        }
    }
    if(root == 0){
        cout << "-1\n";
        exit(0);
    }
    ans[0] = -2;
    childCountGen(root);
    ans[root] = 2;
    dfs(root);
    if(valid){
        for(int i = 1; i <= n; i++){
            if(ans[i] > 0) cout << "R";
            else cout << "B";
        }
    } else {
        cout << "-1";
    }
    cout << "\n";
    return 0;
}

int childCountGen(int now){
    for(int i = 0; i < arr[now].size(); i++){
        childCount[now] += childCountGen(arr[now][i]);
    }
    return ++childCount[now];
}

void dfs(int now){ 
    int p = parent[now];
    int oddCount = 0;
    for(int i = 0; i < arr[now].size(); i++){
        if(childCount[arr[now][i]] % 2) oddCount++;
    }
    if(ans[p] == ans[now]){
        if(oddCount != 0){
            valid = 0;
            return;
        }
    } else {
        if(oddCount != 1 && arr[now].size() != 0){
            valid = 0;
            return;
        }
    }
    for(int i = 0; i < arr[now].size(); i++){
        if(childCount[arr[now][i]] % 2){
            ans[arr[now][i]] = ans[now];
        } else {
            ans[arr[now][i]] = -ans[now];
        }
        dfs(arr[now][i]);
    }
}