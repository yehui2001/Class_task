#include<stdio.h>
#define N 10 //假设商店里有10件商品

typedef struct goods{
    char Name;
    int No;
    int Num;  
}*Seqlist;

Seqlist goods_Create(){
    char Name = 'a';
    int No = 1;
    int Num = 10;
    Seqlist goods[N];
    Seqlist q = goods[N];
    for(int i = 0;i < N;i++){
        goods[i]->Name = Name;
        Name++;
        goods[i]->No = No;
        No++;
        goods[i]->Num = Num;
        Num++;
    }
    return q;
}

void Seqlist_read(Seqlist p){
    for(int i = 0;i < N;i++) 
    {
        printf("%c",p[i].Name);
        printf("%d",p[i].No);
        printf("%d",p[i].Num);
    }
}


int main()
{
    Seqlist p = goods_Create();
    Seqlist_read(p);
    return 0;
}