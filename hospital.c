#include<stdio.h>
#include<stdlib.h> 
//定义队列结构体
typedef struct QNode{
	int data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
	QueuePtr front;    //队头指针
	QueuePtr rear;     //队尾指针 
}LinkQueue;

//遍历队列
void output(LinkQueue *S)
{
	QueuePtr p;
	p=S->front->next;
	while(p != S->rear)
	{
		printf("%d ",p->data);
		p=p->next;
	}
		printf("%d\n",p->data);
 } 

//创建一个空队列 
int InitQueue(LinkQueue *S)
{
	S->front = S->rear = (QueuePtr)malloc(sizeof(QNode)); 
	if(!S->front)
		return 0;
	S->front->next = NULL;
	return 0;
 } 
 
 //入队
 int EnQueue(LinkQueue *S,int e)
 {
 	QueuePtr p;
 	p=(QueuePtr)malloc(sizeof(QNode));
 	if(!p)
 		return 0;    //分配失败 
 	p->data = e;
 	p->next = NULL;
 	S->rear->next = p;
 	S->rear = p;
 	return 0;
  } 
 
 //出队
 int DeQueue(LinkQueue *S) 
 {
 	int e;
 	if(S->front  ==  S->rear)   	//判断队列为空 
 		return 0;
 	QueuePtr p;
 	p = S->front->next;
 	e = p->data;
 	S->front->next = p->next;    			//p指向首元节点 
	 if(p  == S->rear)
	 	S->front == S->rear ; 
	free(p);
	return e;
 }
 
 //1.挂号
 int guahao(LinkQueue S)
 {
 	int n; 
 	printf(">>请输入病历号：");
 	scanf("%d",&n);
 	EnQueue(&S,n);
 	return 0;
  } 
 
 //2.就诊
 int jiuzhen(LinkQueue S)
 {
 	int n;
 	n=DeQueue(&S);
 	printf(">>请病人%d就诊！\n",n);
	 return 0; 
  } 
 
 //3.查看排队
int paidui(LinkQueue S)
 {
 	printf(">>排队病人：");
 	output(&S);
 	return 0;
  } 
  
// 4.不在排队，余下依次就诊
int yici(LinkQueue S)
{
	printf(">>依次就诊：");
	output(&S);
	return 0; 
 } 
 
 //5.下班 
int xiaban(LinkQueue S)
 {
 	printf("现已下班，请以下患者明日再来：");
	output(&S);
	return 0;
 }
 //医院挂号算法
 int suanfa()
 {
 	LinkQueue S;
 	InitQueue(&S);
 	int n=1; 
 	printf("欢迎使用本医院挂号平台:\n1.挂号  2.就诊  3.查看排队  4.不在排队，余下依次就诊  5.下班\n");
	 while(n != 5)
	 {
	 	printf("请选择功能：");
	 	scanf("%d",&n);
	 	switch(n)
	 	{
	 		case 1:
			 	guahao(S);
	 			break;
			case 2:
				jiuzhen(S);
				break;
			case 3:
				paidui(S);
				break;
			case 4:
				yici(S);
				break;
		 }
		 if(n == 5)
		 {
		 	xiaban(S);
		 	return 0;
		 }
	  } 
	  return 0;
  } 
 int main()
 {
 	suanfa();
 	return 0;
 }
