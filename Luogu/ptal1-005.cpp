#include <iostream>
#include <cstring>
using namespace std;

typedef struct SeatLSAD{
    char num[17];
    int s, k;
} seat;

int n, k;
seat arr[1005];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        char now[17];
        int s, k;
        cin >> now >> s >> k;
        strcpy(arr[s].num, now);
        arr[s].k = k;
    }
    cin >> k;
    for(int i = 1; i <= k; i++){
        int need;
        cin >> need;
        cout << arr[need].num << " " << arr[need].k << "\n";
    }
    return 0;
}