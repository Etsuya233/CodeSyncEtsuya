#include <iostream>
#include <string>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    string ansa, ansb;
    for(int i = 1; i < a.length(); i++){
        if((a[i] - '0') % 2 == (a[i - 1] - '0') % 2){
            char c = max(a[i], a[i - 1]);
            ansa += c;
        }
    }
    for(int i = 1; i < b.length(); i++){
        if((b[i] - '0') % 2 == (b[i - 1] - '0') % 2){
            char c = max(b[i], b[i - 1]);
            ansb += c;
        }
    }
    if(ansa == ansb){
        cout << ansa << "\n";
    } else {
        cout << ansa << "\n" << ansb << "\n";
    }
    return 0;
}