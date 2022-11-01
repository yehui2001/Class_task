#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10

//定义排序树的结点
typedef struct BST_node node,*node_pointer;
struct BST_node{
    int data;
    node_pointer left;
    node_pointer right;
};

//初始化创建二叉排序树
node_pointer Create_BST(int x){
    node_pointer p;
    p = (node_pointer)malloc(sizeof(node));
    p->data = x;
    p->right = NULL;
    p->left = NULL;
    return p;
}

//结点插入,查询插入位置，递归！
node_pointer insert_node(node *p,int x){
    node_pointer q;
    if(p == NULL){
        p = Create_BST(x);
    }
    else{
        if(p->data < x){
            p->right = insert_node(p->right,x);
        }
        else{
            p->left = insert_node(p->left,x);
        }
    }
    return p;
}

//查找某个值
node_pointer search_node(node *p,int x){
    if(p->data == x){
        return p;
        printf("Find");
    }
    else{
        if(p->data < x){
            p->right = search_node(p->right,x);
            return p->right;
        }
        else{
            p->left = search_node(p->left,x);
            return p->left;
        }
    }
}


int main()
{
    node *p,*q;
    int data[] = {10,20,3,230,233,13,20,41,141,0};
    int x,i = 0;
    while(i!=10){
        x = data[i];
        p = insert_node(p,x);
        i++;
    }
    int y = 141;
    q = search_node(p,y);
    printf("查询到的值为%d \n",q->data);
    return 0;
}