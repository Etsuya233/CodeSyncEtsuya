#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> ma[21];
vector<int> s[21];
vector<int> arr[21];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        s[i] = vector<int>((1 << (n - i)) + 2);
        ma[i] = vector<int>((1 << (n - i)) + 2);
        arr[i] = vector<int>((1 << (n - i)) + 2);
        for(int j = 1; j <= 1 << (n - i); j++){
            int a;
            cin >> a;
            ma[i][j] = a;
            if(i >= 2){
                s[i][j] = max(max(s[i - 1][2 * j - 1], s[i][2 * j]), a);
            } else s[i][j] = a;
        }
    }
    int biggest, flag = 1;
    cin >> biggest;
    arr[n][1] = biggest;
    for(int i = n - 1; i >= 1; i--){
        for(int j = 1; j <= 1 << (n - i); j += 2){
            int big = arr[i + 1][(j + 1) / 2];
            int small = ma[i + 1][(j + 1) / 2];
            if(s[i][j] >= s[i][j + 1]){
                if(big < s[i][j] || small < s[i][j + 1]){
                    flag = 0;
                    break;
                }
                arr[i][j] = big;
                arr[i][j + 1] = small;
            } else {
                if(big < s[i][j + 1] || small < s[i][j]){
                    flag = 0;
                    break;
                }
                arr[i][j] = small;
                arr[i][j + 1] = big;
            }
        }
        if(flag == 0) break;
    }
    int bl = 0;
    if(flag == 1){
        for(int i = 1; i <= 1 << (n - 1); i++){
            if(bl == 1) cout << " ";
            cout << ma[1][i] << " " << arr[1][i];
            bl = 1;
        }
    } else {
        cout << "No Solution";
    }
    return 0;
}