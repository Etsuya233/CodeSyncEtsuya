#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int ans = 0;
        char t[1000005] = {'2'}, s[1000005] = {'2'};
        cin >> t + 1 >> s + 1;
        int len = strlen(t);
        for(int i = 1; i < len; i++){
            if(t[i] != s[i]){
                if(s[i - 1] == s[i + 1] && s[i] != s[i - 1]){
                    s[i] = t[i];
                    ans++;
                } else {
                    ans = -1;
                    break;
                }
                // if(i == 1 || i == len - 1 || s[i] == s[i - 1] || s[i] == s[i + 1]){
                //     ans = -1;
                //     break;
                // }
                // ans++;
                // s[i] = t[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}