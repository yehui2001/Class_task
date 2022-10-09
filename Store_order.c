#include<stdio.h>
#define N 10 

typedef struct good{
    char Name;
    int No;
    int Num;  
}good;

typedef struct Seqlist_shop{
    good *elem;
    int length;
}*SeqList;


SeqList goods_Create(SeqList shop){
    char Name = 'a';
    int No = 1;
    int Num = 10;
    good goods[N];
    for(int i = 0;i < N;i++){
        goods[i].Name = Name;
        Name++;
        goods[i].No = No;
        No++;
        goods[i].Num = Num;
        Num++;
    }
    shop = (SeqList)malloc(sizeof(SeqList)); 
    shop->elem = (good *)malloc(sizeof(good) * N); 
    int length = 0;
    for(int i=0; i < N; i++){
        shop->elem[i] = goods[i];
        shop->length = ++length;
    }
    return shop;
}

void SeqList_read(SeqList p){
    for(int i = 0;i < 1;i++) 
    {
        printf("%c",p->elem[i].Name);
        printf("%d",p->elem[i].No);
        printf("%d",p->elem[i].Num);
        printf("\n");
    }
}


int main()
{
    SeqList shop;
    goods_Create(shop);
    SeqList_read(shop);
    return 0;
}