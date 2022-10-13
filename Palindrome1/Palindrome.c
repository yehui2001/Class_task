#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h> //bool值

#define maxsize 50//定义元素的最大个数


typedef struct patient{
  char name;
  int no;
  char sick;  
}datatype;

typedef struct{
    int front;//定义头指针,
    int rear;//定义尾指针,若队列不空，指向队列尾元素的下一个位置
    datatype elem[maxsize];
    int length;//记录队列中的个数,用以判断当Q->rear = Q->front时的队内情况
}SqQueue; //顺序队列

void Queue_init(SqQueue * Q){
    Q->rear  = 0;
    Q->front = 0;
    Q->length = 0; 
}

/*判断 队列是否为空*/
bool Empty_Judge(SqQueue Q){
    if(Q.rear == Q.front && Q.length==0 )
        return true;
    else 
        return false;   
}

/*查看正在排队的人数*/
void Queue_length(SqQueue Q){
    printf("当前正在排队的人数:%d",(Q.rear-Q.front + maxsize)% maxsize);
    //printf("当前正在排队的人数:%d",Q.length);
    //return 返回值貌似不太好用
}

/*登记单*/
void Queue_view(SqQueue Q){
    printf("\n------------登记表------------\n");
    for(int i = Q.front ;i<= Q.rear-1; i++){
        printf("Name = %c,",Q.elem[i].name);
        printf("No = %d,",Q.elem[i].no);
        printf("Sick = %c\n",Q.elem[i].sick);
    }
    printf("------------------------------\n");
}

/*病人登记候诊*/
void Queue_insert(SqQueue * Q,datatype x){//此处不传地址进去,修改不了值
    if(Q->length == maxsize){
        printf("Full queue \n");
    }
    else
    {
        Q->elem[Q->rear] = x;
        Q->rear =(Q->rear + 1)%maxsize;//尾指针向后移一个位置,求余是为了让尾指针进行循环
        Q->length++;
    }
}

void Queue_delete(SqQueue *Q){
    Q->front  = (Q->front +1 )% maxsize;
    Q->length--;
}

void menu()
{
    printf("\n**********************************\n");
    printf("*          医院候诊系统          *\n");
    printf("* 1-----------------病人进行登记 *\n");
    printf("* 2-----------------查看候诊登记信息 *\n");
    printf("* 3-----------------病人进行就诊*\n");
    printf("* 4-----------------查看正在排队的人数*\n");
    printf("* 0-------------------------退出 *\n");
    printf("**********************************\n");
}


int main()
{
    int i = 0;
    int exit = 1;
    SqQueue Q;
    datatype x;
    Queue_init(&Q);
while(exit){
    menu();
    int flag;
    scanf("%d",&flag);
    switch (flag)
    {
        case 1://开始登记
            i = 0;
            int N;//准备登记的人数
            printf("请输入想要登记的人数:");
            scanf("%d",&N);
            getchar();
            while(i<N){
                printf("请登记个人信息: 姓名 编号 病症\n");
                scanf("%c %d %c",&x.name,&x.no,&x.sick);
                getchar();//接一下缓存内容
                Queue_insert(&Q,x); 
                printf("登记成功\n");
                i++;   
            }
        break;

        case 2:
            Queue_view(Q);
        break;

        case 3:
            Queue_delete(&Q);
        break;

        case 4:
            Queue_length(Q);
        break;

        case 0:
            exit = 0;
        break;
    }
}
    return 0;
}