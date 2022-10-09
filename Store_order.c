#include<stdio.h>
#include<stdlib.h>
#define N 10 

typedef struct{
    char Name;
    int No;
    int Num;  
}goods;

typedef struct Seqlist_shop{
    goods data[N];
    int length;
}*SeqList;


SeqList goods_Create(){
    SeqList shop;
    shop = (SeqList)malloc(sizeof(SeqList));
    char Name = 'a';
    int No = 1;
    int Num = 10;
    int length = 0;
    for(int i = 0;i < N;i++){
        shop->data[i].Name = Name;
        Name++;
        shop->data[i].No = No;
        No++;
        shop->data[i].Num = Num;
        Num++;
        shop->length = ++length;
    }
    return shop;
}

void SeqList_read(SeqList shop){
    for(int i = 0;i < N; i++) 
    {
        printf("%c",shop->data[i].Name);
        printf("%d",shop->data[i].No);
        printf("%d",shop->data[i].Num);
        printf("\n");
    }
}


int main()
{
    SeqList shop = goods_Create();
    SeqList_read(shop);
    return 0;
}