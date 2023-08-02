#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Soilder{
    int id = 0, val = 0;
} so;

int n;
int canWin = 0;
int maxScore = 0;
so arr[505][505];

bool cmpSo(so a, so b);
int getVal(int a, int b);

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            cin >> arr[i][j].val;
            arr[i][j].id = j;
            arr[j][i].val = arr[i][j].val;
            arr[j][i].id = i;
        }
    }
    for(int i = 1; i <= n; i++){
        sort(arr[i] + 1, arr[i] + n + 1, cmpSo);
    }
    for(int i = 1; i <= n; i++){
        int myScore = 0;
        int aiScore = 0;
        int my1 = i, my2, ai1, ai2, ai3;
        //ai1
        ai1 = arr[my1][1].id;
        //my2
        my2 = arr[my1][2].id;
        //ai2
        ai2 = arr[my1][3].id;
        ai3 = arr[my2][1].id;//ai3 == my1 || my2 || ai1
        for(int j = 2; ai3 == my1 || ai3 == my2 || ai3 == ai1; j++){
            ai3 = arr[my2][j].id;
        }
        if(getVal(my2, ai3) > getVal(my1, ai2)) ai2 = ai3;
        //res
        myScore = getVal(my1, my2);
        aiScore = getVal(ai1, ai2);
        if(myScore > aiScore){
            canWin = 1;
            maxScore = max(myScore, maxScore);
        }
    }
    if(canWin){
        cout << 1 << "\n" << maxScore;
    } else cout << 0;
    return 0;
}

bool cmpSo(so a, so b){
    if(a.val >  b.val) return true;
    else return false;
}

int getVal(int a, int b){
    for(int i = 1; i <= n; i++){
        if(arr[a][i].id == b) return arr[a][i].val;
    }
    return 0;
}