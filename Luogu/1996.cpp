#include <iostream>
using namespace std;

int main(){
    int hashTable[101] = {0};
    int n, m, walked = 0;
    cin >> n >> m;
    int loc = 1, poi = 1;
    while(walked < n){
        loc ++;
        if(loc > n){
            loc -= n;
        }
        if(!hashTable[loc]) poi ++;
        if(poi == m){
            cout << loc << " ";
            poi = 0;
            walked ++;
            hashTable[loc] = 1;
        }
    }
}