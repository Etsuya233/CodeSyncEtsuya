#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char arr[100001];
    while(true){
        cin >> arr;
        int len = strlen(arr);
        if(len == 2 && arr[0] == '-' && arr[1] == 'o') break;
    }
    cin >> arr;
    cout << arr << "\n";
    return 0;
    
}