#include <iostream>
#include <algorithm>
using namespace std;

typedef struct competitor{
    int id, score, power;
} Com;

int n, r, q;
Com arr[200005];

bool cmpCom(Com a, Com b);
void myMergeSort(int l, int r);

int main(){
    cin >> n >> r >> q;
    for(int i = 0; i < 2 * n; i++){
        arr[i].id = i + 1;
        cin >> arr[i].score;
    }
    for(int i = 0; i < 2 * n; i++){
        cin >> arr[i].power;
    }
    for(int i = 0; i < r; i++){
        myMergeSort(0, 2 * n - 1);
        for(int j = 0; j < n; j++){
            if(arr[j * 2].power < arr[j * 2 + 1].power) arr[j * 2 + 1].score++;
            else arr[j * 2].score++;
        }
    }
    myMergeSort(0, 2 * n - 1);
    cout << arr[q - 1].id;
}

bool cmpCom(Com a, Com b){
    if(a.score > b.score) return true;
    if(a.score == b.score && a.id < b.id) return true;
    return false;
}

void myMergeSort(int l, int r){
    if(l == r) return;
    int mid = (l + r) / 2;
    myMergeSort(l, mid);
    myMergeSort(mid + 1, r);
    merge(arr + l, arr + mid + 1, arr + mid + 1, arr + r + 1, arr + l, cmpCom);
}
