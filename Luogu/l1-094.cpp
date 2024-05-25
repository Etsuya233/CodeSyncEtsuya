#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    cin >> str;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int l, r;
        string ls, rs, ss, ds;
        cin >> l >> r >> ls >> rs;
        ss = ls + rs;
        ds = str.substr(l - 1, r - l + 1);
        str.erase(l - 1, r - l  + 1);
        int loc = str.find(ss);
        if(loc == str.npos){
            str.append(ds);
        } else {
            str.insert(loc + ls.length(), ds);
        }
    }
    cout << str;
    return 0;
}