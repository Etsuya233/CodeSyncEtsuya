#include <iostream>
using namespace std;

int main(){
    char lan[10000];
    int str[10000];
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> str[i];
    }
    cin >> lan + 1;
    for(int i = 1; i <= n; i++){
        cout << lan[str[i]];
    }
    cout << "\n";
    return 0;
}