#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#define maxsize 50  //定义元素最大个数

/* 定义顺序栈 */
typedef char elemtype;//定义栈内元素类型
typedef struct{
    elemtype data[maxsize];
    int top;//定义栈顶指针
}SqStack;

/* 定义循环队列 */
typedef struct{
    int front;//定义头指针,
    int rear;//定义尾指针,若队列不空，指向队列尾元素的下一个位置
    elemtype elem[maxsize];//元素类型使用与栈内相同
    int length;//记录队列中的个数,用以判断当Q->rear = Q->front时的队内情况
}SqQueue; //顺序队列

/* 初始化栈 */
void Stack_init(SqStack *S){
    S->top = -1;//初始化栈顶指针 
}

/*初始化循环队列*/
void Queue_init(SqQueue * Q){
    Q->rear  = 0;
    Q->front = 0;
    Q->length = 0; 
}

/* 判断栈内情况 */
void Stack_empty(SqStack S){
    if(S.top == -1)
        printf("Stack is empty");
    else
        printf("Stack is not empty");
}

 /*判断 队列是否为空*/
bool Empty_Judge(SqQueue Q){
    if(Q.rear == Q.front && Q.length==0 )
        return true;
    else 
        return false;   
}

/* 进栈 */
void Push(SqStack *S, elemtype x){
    //先判断是否满栈
    if(S->top == maxsize-1){
        printf("The Stack is full,can't push");
    }
    else
    S->top++;
    S->data[S->top] = x;//栈顶指针指向栈内最上面的元素
}

/* 入队列*/
void Queue_insert(SqQueue * Q,elemtype x){//此处不传地址进去,修改不了值
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

/* 出栈 */
void Pop(SqStack *S){
    if(S->top == -1)
        printf("The Stack is empty, can't pop");
    else
        (S->top)--;//栈顶指针减一
}

/* 出队列 */
void Queue_delete(SqQueue *Q){
    Q->front  = (Q->front +1 )% maxsize;
    Q->length--;
}

/* 读取栈顶元素 */
void Stack_GetTop(SqStack S,elemtype *x){
    if(S.top == -1)
        printf("The stack is empty,can't read");
    else
    {
        *x = S.data[S.top];
    }
}

int main()
{
        int i = 0,N;
        SqStack S;
        SqQueue Q;
        printf("请输入想要输入字符串的长度:");
        scanf("%d\n",&N);

        elemtype x,Y,y[N];
        Stack_init(&S);
        Queue_init(&Q);

        while(i < N){
            scanf("%c",&x);
            getchar();
            Queue_insert(&Q,x); //入队
            Push(&S,x);//入栈
            i++;
        }

        i = 0;
        while(i < N){
            Stack_GetTop(S,&Y);//取栈顶元素
            Pop(&S); //出栈
            y[i] = Y;
            i++;
        }
        printf("出栈后的序列为:");
        for(int j = 0;j< N ; j++){
            printf("%c",y[j]);
        }
        printf("\n");

        printf("出队后的序列为:");
        for(int i = Q.front ;i<= Q.rear-1; i++){
            printf("%c",Q.elem[i]);
        }
        printf("\n");


        int k = 0;
        int exit = 1;
        while(exit){
            if(y[k] == Q.elem[k]){
                k++;
                if(k == N-1){
                    printf("该序列为回文序列\n");
                    break;//跳出当前循环
                }
            }
            else{
                exit = 0;
                printf("该序列非回文序列\n");
            }
        }
    return 0;    
}