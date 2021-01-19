#include<stdio.h>
#include<stdlib.h>

#define VERTICES 6


// 这个是自己学完以后照着写的并查集，这里详细注解一下

// parent数组相当于一个顶点集
// 元素的位置就是顶点的值，数组的值就是该节点的根节点
void initialize(int parent[]){

    // 初始化全部赋值为-1
    for(int i = 0; i<VERTICES; i++){
        parent[i] = -1;
    }
}

// 这个方法查找parent数组中，x顶点的跟节点
int find_root(int x, int parent[]){

    // 一开始先将root设置为自己，当下一步在while循环里，如果x_root在parent中的值不是-1，
    // 就应该将parent[x_root]的值赋给x_root,这样就找到他的上一层，循环直到parent[x_root]的值为-1,
    // 这样，根就一定是x_root
    int x_root = x;
    while(parent[x_root] != -1){
        x_root = parent[x_root];
    }
    return x_root;
}

// 这个方法就是将两个顶点所组成的集合合并，我们直接合并他们的根就好了，通过上一个方法，获得他们的根
// 当x_root != y_root   时，这两个集合就是独立的，就可以合并到一起，这里通过将parent[x_root] = y_root,完成合并
// 如果两个集合有相同的根，说明是有环在里面的，返回0，合并错误
// 1-union successfully, 0-union failed
int union_vertices(int x, int y, int parent[]){
    int x_root = find_root(x,parent);
    int y_root = find_root(y,parent);

    if(x_root != y_root){
        parent[x_root] = y_root;
        return 1;
    }
    else return 0;

}

int main(){
    int parent[6] = {0};

    // 这里是边集
    int edges[6][2]={
        {0, 1}, {1, 2}, {1, 3}, {2, 4}, {3, 4}, {2, 5}
    };
    initialize(parent);

    // 依次通过边连接的两个顶点，将两个顶点合并，如果发现合并失败，则必发现环在里面
    for(int i = 0; i<VERTICES; i++){
        if(union_vertices(edges[i][0],edges[i][1],parent) == 0){
            printf("Cycle detected!\n");
            exit(0);
        }
    }
    printf("No cycle found!\n");
    return 0;
}