#include <iostream>
#include <algorithm>
using namespace std;

int ii, jj, lim;
int arr[82][100002];
int minc[82], maxc[100002];

int main(){
    cin >> ii >> jj;
    for(int i = 1; i <= ii; i++){
        for(int j = 1; j <= jj; j++){
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    cin >> lim;
    for(int i = 1; i <= ii; i++){
        for(int j = 1; j <= jj; j++){
            fill(minc, minc + 100002, 1000004);
            fill(maxc, maxc + 100002, -1);
            for(int k = i; k <= ii; k++){
                int minx = 1000004, maxx = -1;
                for(int p = j; p <= jj; p++){
                    minc[p] = min(minc[p], arr[k][p]);
                    maxc[p] = max(maxc[p], arr[k][p]);
                    minx = min(minx, minc[p]);
                    maxx = max(maxx, maxc[p]);
                    if(maxx - minx <= lim){
                        ans = max(ans, (k - i + 1) * (p - j + 1));
                    } else {
                        break;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}