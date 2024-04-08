#include <iostream>
using namespace std;

int row[100005];
int column[100005];
int opa[1005];
int opb[1005];

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    int ans = 0;
    int rowcnt = 0;
    for(int i = 1; i <= q; i++){
        cin >> opa[i] >> opb[i];
        if(opa[i] == 0){
            if(opa[i] == 0 && row[opb[i]] == 0){
                ans += m;
                rowcnt ++;
                row[opb[i]] = 1;
            }
        }
    }
    //column
    for(int i = 1; i <= q; i++){
        if(opa[i] == 1 && column[opb[i]] == 0){
            ans += n - rowcnt;
            column[opb[i]] = 1;
        }
    }
    cout << n * m - ans;
    return 0;
}