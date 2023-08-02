#include <iostream>
#include <algorithm>
using namespace std;

typedef struct competitor{
    int id, score;
} Com;

int n, m;
Com arr[9002];
Com tempa;

bool cmpCom(Com a, Com b);

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i].id >> arr[i].score;
    }
    sort(arr, arr + n, cmpCom);
    int limitScore = arr[(int)(m * 1.5) - 1].score;
    int validNum = 0;
    for(validNum = 0; validNum < n && arr[validNum].score >= limitScore; validNum++);
    cout << limitScore << " " << validNum << "\n";
    for(int i = 0; i < validNum; i++){
        cout << arr[i].id << " " << arr[i].score << "\n";
    }
    return 0;
}

bool cmpCom(Com a, Com b){
    if(a.score > b.score) return true;
    if(a.score == b.score && a.id < b.id) return true;
    return false;
}