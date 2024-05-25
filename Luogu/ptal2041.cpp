#include <iostream>
using namespace std;

int n, m, k;
int arr[1005] = {0};
int tree[10] = {0};
int box[25] = {0};
int cnt = 0;
int ans[1005][6];

int main(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    while(arr[0] != n || box[0] != 0){
        //拿树枝
        int tr = -1;
        if(box[0] != 0 && (tree[0] == 0 || tree[tree[0]] >= box[box[0]])) tr = box[box[0]--];
        else if(arr[0] < n) tr = arr[++arr[0]];
        //用树枝
        if(tr != -1 && (tree[0] == 0 || tree[tree[0]] >= tr)){
            tree[++tree[0]] = tr;
        } else if(tr != -1 && box[0] < m){
            box[++box[0]] = tr;
        } else {
            if(tr != -1) arr[0]--;
            cnt++;
            ans[cnt][0] = tree[0];
            for(int i = 1; i <= tree[0]; i++){
                ans[cnt][i] = tree[i];
            }
            tree[0] = 0;
        }
        //判断树
        if(tree[0] == k || (arr[0] == n && box[0] == 0)){
            cnt++;
            ans[cnt][0] = tree[0];
            for(int i = 1; i <= tree[0]; i++){
                ans[cnt][i] = tree[i];
            }
            tree[0] = 0;
        }
    }
    for(int i = 1; i <= cnt; i++){
        for(int j = 1; j <= ans[i][0] - 1; j++){
            cout << ans[i][j] << " ";
        }
        cout << ans[i][ans[i][0]] << "\n";
    }
    return 0;
}