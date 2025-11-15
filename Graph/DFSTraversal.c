#include <stdio.h>
#include <stdlib.h>

// DFS Implementation
int visited[7] = {0,0,0,0,0,0,0};  // 7 represents the number of nodes in graph and initialize it with zero
// Take the example graph from the image.png file
int arr[7][7] = {
    //0 1 2 3 4 5 6 
    {0,1,1,1,0,0,0},   // 0
    {1,0,0,1,0,0,0},   // 1
    {1,0,0,1,1,0,0},   // 2
    {1,1,1,0,1,0,0},   // 3
    {0,0,1,1,0,1,1},   // 4
    {0,0,0,0,1,0,0},   // 5
    {0,0,0,0,1,0,0}    // 6
};

void DFS(int i){
    printf("%d ", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if(arr[i][j] == 1 && !visited[j]){
            DFS(j);
        }
    }
}

int main(){
    DFS(0);
    return 0;
}