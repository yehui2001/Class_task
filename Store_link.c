#include<stdio.h>
#include<stdlib.h>

#define N 10 //先假设超市中共有十个商品

//为了简单创建初始库，将编号和名称初始化为整型和字符型，而非字符串
typedef struct goods *goods_pointer;
struct goods{
    int No;
    char Name;
    int Num;
    goods_pointer next;
};


goods_pointer Create_goods_warehouse(){
    int No = 1;
    char Name = 'a';
    int Num = 10;
    goods_pointer header,p,q;
    header = (goods_pointer)malloc(sizeof(goods_pointer));
    // header->Name =Name;
    // header->No = No;
    // header->Num = Num;
    // header->next = NULL;
    q = header;
    for (int i = 1;i <= N; i++ ){
        p = (goods_pointer)malloc(sizeof(goods_pointer));
        p->Num = Num; 
        Num = Num +1 ;
        p->No = No;
        No = No + 1;
        p->Name  = Name;
        Name = Name + 1;
        p->next = NULL;
        q->next = p;
        q = p;
    }
    return header;
}

void goods_read(goods_pointer p){
    p = p->next;//不读头指针
    while(p->next != NULL){
        printf("Name = %c,",p->Name);
        printf("No = %d,",p->No);
        printf("Num = %d,",p->Num);
        printf("\n");
        p = p->next;
    }
        printf("Name = %c,",p->Name);
        printf("No = %d,",p->No);
        printf("Num = %d,",p->Num);//打印末节点的内容
        printf("\n");
}

void Find_goods_inventory(int flag,goods_pointer p){
    char Name;
    int No;
    goods_pointer q = p;
    switch (flag)
    {
    case 1:
        scanf("%c",&Name);
        while(q->next != NULL){
            if(q->Name == Name)
            printf("%d",q->Num);
            q = q->next;
        }  
        break;
    
    case 2:
        scanf("%d",&No);
        while(q->next != NULL){
        if(q->No == No)
        printf("%d",q->Num);
        q = q->next;
        } 
        break;
    }
}

goods_pointer Add_goods(int flag,goods_pointer p){
    char Name;
    int No;
    int Num;
    goods_pointer q = p;
    switch (flag)
    {
    case 1:/*新商品入库*/
        printf("Please input a good not existed in the warehouse\n");
        scanf("%c",&Name);
        scanf("%d",&No);
        scanf("%d",&Num);
        while(p->next!=NULL){
            //r = p;
            p = p->next;            
        }  
        p->next=(goods_pointer)malloc(sizeof(goods_pointer));
        p->next->Name = Name;
        p->next->No = No;
        p->next->Num = Num;
        p->next->next = NULL;
        return q;
        break;
    case 2:/*旧商品入库*/   //以名字入库
        printf("Please input a good existed in the warehouse");
        scanf("%c",&Name);
        scanf("%d",&No);
        scanf("%d",&Num);
        while(p->Name!=Name &&p->next!=NULL){
            p = p->next;
        }
        p->Num = p->Num + Num;
        return q;
        break;
    }
}

goods_pointer Out_goods(goods_pointer p){
    goods_pointer q = p;
    char Name;
    int No;
    int Num;
    printf("please input the out goods information \n");
    scanf("%c",&Name);
    scanf("%d",&No);
    scanf("%d",&Num);
    while(p->Name!= Name){
        p = p->next;
    }
    p->Num = p->Num - Num;
    return q;
}

goods_pointer Delete_goods(goods_pointer p){
    goods_pointer q = p,r;
    char Name;
    int No;
    int Num ;
    printf("please input the Delete goods name \n");
    scanf("%c",&Name);
    while(p->next->Name!=Name && p->next!=NULL){
        p = p->next;
    }
    printf("%c",p->Name);
    p->next  = p->next->next;
    return q;
}




int main()
{
    goods_pointer p = Create_goods_warehouse();
    goods_read(p);
    //Find_goods_inventory(1,p);//查询商品库存，1为用名字查询，2为用编号查询
    goods_read(Add_goods(1,p));
    //goods_read(Out_goods(p));
    //goods_read(Delete_goods(p));
    return 0;
}