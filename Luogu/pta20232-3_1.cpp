#include <iostream>
#include <vector>
using namespace std;

int n;
int ans[562150] = {0};
vector<int> arr[22];
vector<int> id[22];

int main(){
    cin >> n;
    int flag = 0;
    for(int i = 1; i <= n; i++){
        arr[i] = vector<int>((1 << (n - i)) + 10);
        id[i] = vector<int>((1 << (n - i)) + 10);
        for(int j = 1; j <= 1 << (n - i); j++){
            cin >> arr[i][j];
            if(i == 1){
                ans[j * 2 - 1] = arr[i][j];
                id[i][j] = j * 2;
            } else {
                int maxn = max(arr[i - 1][2 * j - 1], max(arr[i - 1][2 * j], arr[i][j]));
                if(arr[i][j] < arr[i - 1][2 * j - 1] && arr[i][j] < arr[i - 1][2 * j]){
                    flag = 1;
                    break;
                } else if(arr[i][j] >= arr[i - 1][2 * j - 1]){
                    ans[id[i - 1][2 * j - 1]] = arr[i][j];
                    id[i][j] = id[i - 1][2 * j];
                } else {
                    ans[id[i - 1][2 * j]] = arr[i][j];
                    id[i][j] = id[i - 1][2 * j - 1];
                }
                arr[i][j] = maxn;
            }
            if(flag == 1) break;
        }
        if(flag == 1) break;
    }
    int biggest;
    cin >> biggest;
    if(arr[n][1] <= biggest) ans[id[n][1]] = biggest;
    else flag = 1;
    if(flag == 1){
        cout << "No Solution";
    } else {
        for(int i = 1; i <= 1 << n; i++){
            if(i != 1) cout << " ";
            cout << ans[i];
        }
    }
    return 0;
}
