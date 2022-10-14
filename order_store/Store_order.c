#include<stdio.h>
#include<stdlib.h>
#define maxsize 100
#define N 10 

typedef struct{
    char Name;
    int No;
    int Num;  
}goods;

typedef struct Seqlist_shop{
    goods data[maxsize];
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
        //printf("%d",shop->data[i].No);
        shop->data[i].Num = Num;
        Num++;
        shop->length = ++length;
    }
    return shop;
}

void SeqList_read(SeqList shop){
    for(int i = 0;i < shop->length; i++) 
    {
        printf("Name = %c,",shop->data[i].Name);
        printf("No = %d,",shop->data[i].No);
        printf("Num = %d",shop->data[i].Num);
        printf("\n");
    }
}

void SeqList_Find(SeqList shop,int flag){
    switch (flag)
    {
    case 1:
    {
        char name;
        getchar();
        printf("输入你想要查找商品的名称:");
        scanf("%c",&name);
        int i = 0;
        while(shop->data[i].Name != name && i != N){
            i++;
        }
        printf("Name = %c,",shop->data[i].Name);
        printf("No = %d,",shop->data[i].No);
        printf("Num = %d,",shop->data[i].Num);
        printf("\n");
        break;
    }   
    case 2:
    {
        int no;
        printf("输入你想要查找商品的编号");
        scanf("%d",&no);
        int i = 0;
        while(shop->data[i].No != no && i != N){
        i++;
        }
        printf("Name = %c,",shop->data[i].Name);
        printf("No = %d,",shop->data[i].No);
        printf("Num = %d",shop->data[i].No);
        break;
    }
    default:
    break;
    }

}

SeqList SeqList_add(SeqList shop,int flag){
    getchar();
    char name;
    int no;
    int num;
    printf("输入你想要添加商品的信息:");
    scanf("%c",&name);
    scanf("%d",&no);
    scanf("%d",&num);
    switch (flag)
    {
    case 1:/*新商品入库*/
        shop->data[shop->length].Name = name;
        shop->data[shop->length].No = no;
        shop->data[shop->length].Num = num;
        shop->length++;
    return shop;
        break;
    
    case 2:/*旧商品入库*/
    int i=0;
    while (shop->data[i].Name!= name)
    {
        i++;
    }
    shop->data[i].Num += num;
    return shop;
    break;
    }
}

SeqList SeqList_out(SeqList shop){
    char name;
    int no;
    int num;
    int i=0;
    getchar();
    printf("输入出库的信息:");
    scanf("%c",&name);
    scanf("%d",&no);
    scanf("%d",&num);
    while (shop->data[i].Name!= name)
    {
        i++;
    }
    shop->data[i].Num -= num;
    return shop;
    }  

SeqList SeqList_delete(SeqList shop){
    char name;
    getchar();
    printf("输入你想删除的商品名称:");
    scanf("%c",&name);
    goods temp;
    int i=0,j;
    while (shop->data[i].Name!= name)
    {
        i++;
    }
    shop->length--;
    for(j = i;j< shop->length;j++){
        shop->data[j] = shop->data[j+1]; 
    }
    return shop;
}

void menu()
{
    printf("**********************************\n");
    printf("*          商品管理系统          *\n");
    printf("* 1-----------------录入商品信息 *\n");
    printf("* 2-----------------浏览商品清单 *\n");
    printf("* 3-----------------查找商品信息 *\n");
    printf("* 4---------------------商品入库 *\n");
    printf("* 5---------------------商品出库 *\n");
    printf("* 6---------------------商品删除 *\n");
    printf("* 0-------------------------退出 *\n");
    printf("**********************************\n");
}


int main()
{
    int exit = 1;
    int option;
    char name;
    int no;
    int num;
    char n='a';
    SeqList shop = goods_Create();
    //SeqList_read(shop);
    while(exit)
{
    menu();
    printf("输入你的选择:");
    scanf("%d",&option);
    switch (option)
    {
        case 1:
            printf("Created successfully \n");
            break;
        case 2:
            SeqList_read(shop);
            break;  
        case 3:
            int h;
            printf("\n 1代表用名称查找,2代表用编号查找\n");
            scanf("%d",&h);
            SeqList_Find(shop,h);
            break;
        case 4:
            int y;
            printf("\n 1代表加入新商品,2代表加入旧商品 \n");
            scanf("%d",&y);
            SeqList_read(SeqList_add(shop,y));
            break;
        case 5:
            SeqList_read(SeqList_out(shop));
        case 6:
            SeqList_read(SeqList_delete(shop));
            break;
        case 0:
            printf("Exit successfully");
            exit = 0;
            break;
    }
}
    return 0; 
}