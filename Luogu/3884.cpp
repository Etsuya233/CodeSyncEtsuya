#include <iostream>
using namespace std;

typedef struct Node{
    int depth, l = -1, r = -1, f = -1;
} Node;

Node arr[105];
int width[105] = {0};
int maxDepth = 1, maxWidth = 1;

void calc(int loc, int depth);

int main(){
    arr[1].depth = 1;
    arr[1].f = -1;
    width[1] = 1;
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int father, son;
        cin >> father >> son;
        if(arr[father].l == -1){
            arr[father].l = son;
        } else {
            arr[father].r = son;
        }
        arr[son].f = father;
        // arr[son].depth = arr[father].depth + 1;
        // width[arr[son].depth] ++;
        // // if(width[arr[son].depth] > maxWidth) maxWidth = width[arr[son].depth];
        // // if(arr[son].depth > maxDepth) maxDepth = arr[son].depth;
    }
    calc(1, 1);
    int src, dest, dist = 0, onTheRoad = 0;
    cin >> src >> dest;
    if(src == dest) dist = 0;
    else {
        int sameFather = -1, loc = src;
        while(loc != -1){
            width[loc = arr[loc].f] = 10000;
            if(loc == dest) onTheRoad = 1;
        }
        loc = dest;
        while(loc != -1){
            if(loc == src) onTheRoad = 2;
            if(width[loc = arr[loc].f] == 10000){
                sameFather = loc;
                break;
            }
        }
        if(onTheRoad == 0){
            dist = (arr[src].depth - arr[sameFather].depth) * 2 + (arr[dest].depth - arr[sameFather].depth);
        } else if(onTheRoad == 1){
            dist = 2 * (arr[src].depth - arr[dest].depth);
        } else {
            dist = arr[dest].depth - arr[src].depth;
        }
    }
    cout << maxDepth << "\n" << maxWidth << "\n" << dist;
    
}

void calc(int loc, int depth){
    if(loc == -1) return;
    arr[loc].depth = depth;
    if(depth > maxDepth) maxDepth = depth;
    width[depth] ++;
    if(width[depth] > maxWidth) maxWidth = width[depth];
    calc(arr[loc].l, depth + 1);
    calc(arr[loc].r, depth + 1);
}