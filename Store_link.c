#include<stdio.h>
#include<stdlib.h>

#define N 10 //�ȼ��賬���й���ʮ����Ʒ

//Ϊ�˼򵥴�����ʼ�⣬����ź����Ƴ�ʼ��Ϊ���ͺ��ַ��ͣ������ַ���
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
    for (int i = 1;i < N; i++ ){
        p = (goods_pointer)malloc(sizeof(goods_pointer));
        p->Num = Num; 
        Num++;
        p->No = No;
        No++;
        p->Name  = Name;
        Name++;
        p->next = NULL;
        q->next = p;
        q = p;
    }
    return header;
}

void goods_read(goods_pointer p){
    p = p->next;//����ͷָ��
    while(p->next != NULL){
        printf("Name = %c,",p->Name);
        printf("No = %d,",p->No);
        printf("Num = %d,",p->Num);
        printf("\n");
        p = p->next;
    }
        printf("Name = %c,",p->Name);
        printf("No = %d,",p->No);
        printf("Num = %d,",p->Num);//��ӡĩ�ڵ������
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
    scanf("%c",&Name);
    scanf("%d",&No);
    scanf("%d",&Num);
    goods_pointer q = p;
    goods_pointer r;
    switch (flag)
    {
    case 1:/*����Ʒ���*/
        while(p->next->next!=NULL){
            r = p;
            p = p->next;            
        }
        ///  p->Name = Name;
        //  p->No = No;
        //  p->Num = Num;
        //  p->next = NULL;
        
        r->next->next->next->Name = Name;
        printf("%c",r->next->Name);
        // p->next->next->Name = Name;
        // p->next->next->No = No;
        // p->next->next->Num = Num;
        // p->next->next->next = NULL;
        return q;
        break;
    case 2:/*����Ʒ���*/
        break;
    }



}





int main()
{
    goods_pointer p = Create_goods_warehouse();
    goods_read(p);
    //Find_goods_inventory(1,p);//��ѯ��Ʒ��棬1Ϊ�����ֲ�ѯ��2Ϊ�ñ�Ų�ѯ
    goods_read(Add_goods(1,p));
    return 0;
}