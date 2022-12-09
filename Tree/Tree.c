#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#define M 100
struct tree //定义树结点结构
{
    char data;
    struct tree *left;
    struct tree *right;
};

typedef struct tree treenode,*btree;
/*定义队列*/
btree que[M];
int front = 0 , rear = 0;
btree root = NULL;
int count = 0;
/*先根遍历方法创建二叉树*/
btree createtree(){
    btree pdnode;
    char ch;
    scanf("%c",&ch);
        if(ch == '@')
            pdnode = NULL; /*遇到‘@’，不分配新结点*/
        else{
            pdnode = (btree) malloc (sizeof(treenode));
            if(pdnode==NULL){
                printf("Out of space ! \n");
                return pdnode;
            }
            pdnode->data = ch;
            pdnode->left = createtree();
            pdnode->right = createtree();
            }
    return pdnode;
}


int main(){
    printf("请输入带@的二叉树序列:");
    root = createtree();
    printf("%c \n",root->right->data);
    return 0;
}