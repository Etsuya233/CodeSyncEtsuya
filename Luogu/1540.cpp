#include <iostream>
#include <queue>
using namespace std;

int main(){
    int hashTable[1001] = {0};
    queue<int> memory;
    int m, n, storage = 0, ans = 0;
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        int word;
        cin >> word;
        if(!hashTable[word]){
            ans ++;
            if(storage >= m){
                hashTable[memory.front()] = 0;
                memory.pop();
                storage --;
            }
            hashTable[word] = 1;
            memory.push(word);
            storage ++;
        }
    }
    cout << ans;
}