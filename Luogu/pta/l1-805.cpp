#include <iostream>
using namespace std;

int main(){
    int used[7];
    int now[7] = {7, 7, 7, 7, 7, 7, 7};
    for(int i = 1; i <= 6; i++){
        cin >> used[i];
    }
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            int ima = now[j] - 1;
            if(used[j] == ima){
                ima--;
            }
            now[j] = ima;
        }
    }
    for(int i = 1; i <= 5; i++) cout << now[i] << " ";
    cout << now[6] << "\n";
    return 0;
}

