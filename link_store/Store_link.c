#include <stdio.h>
#include <stdlib.h>

#define N 10 //定义最大

typedef struct goods *goods_pointer, goods; //定义指针类，跟结构体类方便分配空间时调用
struct goods
{
    int No;
    char Name;
    int Num;
    goods_pointer next;
};

goods_pointer Create_goods_warehouse()
{
    int No = 1;
    char Name = 'a';
    int Num = 10;
    goods_pointer header, p, q;
    q = (goods_pointer)malloc(sizeof(goods));
    // header->Name =Name;
    // header->No = No;
    // header->Num = Num;
    // header->next = NULL;
    header = q;
    for (int i = 1; i <= N; i++)
    {
        p = (goods_pointer)malloc(sizeof(goods));
        p->Num = Num;
        Num = Num + 1;
        p->No = No;
        No = No + 1;
        p->Name = Name;
        Name = Name + 1;
        p->next = NULL;
        q->next = p;
        q = p;
    }
    return header;
}

void goods_read(goods_pointer p)
{
    p = p->next;
    while (p->next != NULL)
    {
        printf("Name = %c,", p->Name);
        printf("No = %d,", p->No);
        printf("Num = %d,", p->Num);
        printf("\n");
        p = p->next;
    }
    printf("Name = %c,", p->Name);
    printf("No = %d,", p->No);
    printf("Num = %d,", p->Num);
    printf("\n");
}

void Find_goods_inventory(int flag, goods_pointer p)
{
    char Name;
    int No;
    goods_pointer q = p;
    switch (flag)
    {
    case 1:
        getchar(); //此处不加getchar会无法录入Name
        printf("请输入加入商品的名称\n");
        scanf("%c", &Name);
        while (q->next != NULL)
        {
            if (q->Name == Name)
            {
                printf("Name = %c,", q->Name);
                printf("No = %d,", q->No);
                printf("Num = %d\n", q->Num);
            }
            q = q->next; //继续前行查找
        }
        break;

    case 2:
        scanf("%d", &No);
        while (q->next != NULL)
        {
            if (q->No == No)
            {
                printf("Name = %c,", q->Name);
                printf("No = %d,", q->No);
                printf("Num = %d\n", q->Num);
            }
            q = q->next;
        }
        break;
    }
}

goods_pointer Add_goods(int flag, goods_pointer p)
{
    char Name;
    int No;
    int Num;
    goods_pointer q = p;
    switch (flag)
    {
    case 1: /*加入新商品*/
        getchar();
        printf("请输入新商品的相关信息:\n");
        scanf("%c", &Name);
        scanf("%d", &No);
        scanf("%d", &Num);
        while (p->next != NULL)
        {
            // r = p;
            p = p->next;
        }
        p->next = (goods_pointer)malloc(sizeof(goods_pointer));
        p->next->Name = Name;
        p->next->No = No;
        p->next->Num = Num;
        p->next->next = NULL;
        return q;
        break;
    case 2: /*加入旧商品*/
        getchar();
        printf("请输入旧商品的相关信息:\n");
        scanf("%c", &Name);
        scanf("%d", &No);
        scanf("%d", &Num);
        while (p->Name != Name && p->next != NULL)
        {
            p = p->next;
        }
        p->Num = p->Num + Num;
        return q;
        break;
    }
}

goods_pointer Out_goods(goods_pointer p)
{
    goods_pointer q = p;
    char Name;
    int No;
    int Num;
    getchar();
    printf("请输入你想要出库的商品信息:\n");
    scanf("%c", &Name);
    scanf("%d", &No);
    scanf("%d", &Num);
    while (p->Name != Name)
    {
        p = p->next;
    }
    p->Num = p->Num - Num;
    return q;
}

goods_pointer Delete_goods(goods_pointer p)
{
    goods_pointer q = p, r;
    char Name;
    int No;
    int Num;
    getchar();
    printf("你要删除商品的名字:\n");
    scanf("%c", &Name);
    while (p->next->Name != Name && p->next != NULL)
    {
        p = p->next;
    }
    p->next = p->next->next;
    return q;
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
    int exit = 1; //
    goods_pointer p = Create_goods_warehouse();
    while (exit)
    {
        menu();
        int option;
        printf("\n 请输入你的选择:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Created successfully \n");
            break;
        case 2:
            goods_read(p);
            break;
        case 3:
            int flag;
            printf("\n 1代表用名字查找,2代表用编号查找 \n");
            scanf("%d", &flag);
            Find_goods_inventory(flag, p);
            break;

        case 4:
            printf("\n 1代表加入新商品,2代表加入旧商品\n");
            scanf("%d", &flag);
            goods_read(Add_goods(flag, p));
            break;

        case 5:
            goods_read(Out_goods(p));
            break;

        case 6:
            goods_read(Delete_goods(p));
            break;

        case 0:
            printf("Exit successfully");
            exit = 0;
            break;
        }
    }
    return 0;
}