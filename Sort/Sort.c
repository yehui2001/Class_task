#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
////////////////////
//成绩单结构体
typedef struct score_list
{
    int len;
    int array[0];
} * score;
//成绩单链表
typedef struct score_node
{
    int key;
    struct score_node *next;
} * node;
////////////////////
//函数列表
void bowowa();                    //分隔符
score rand_score(int size);       //生成随机成绩单
score help_list(score myscore);   //生成辅助数组
void print_score(score myscore);  //打印成绩单
score direct_sort(score myscore); //直接插入排序
score bi_sort(score myscore);     //二分排序
node array2node(score myscore);   //顺序表转链表
void print_node(node head);       //打印链表
node table_sort(score myscore);   //表插法
score pop_sort(score myscore);    //冒泡排序
score choose_sort(score myscore); //直接选择排序
////////////////////

//分隔符
void bowowa()
{
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
}

//生成随机成绩单
score rand_score(int size)
{
    score list = (score)malloc(sizeof(struct score_list) + size * sizeof(int));
    srand((unsigned int)time(NULL));
    list->len = size;
    for (int i = 0; i < size; i++)
    {
        list->array[i] = rand() % 51 + 50; //生成1~100的随机数
        // printf("%d\n",list->array[i]);
    }
    return list;
}

//生成辅助数组
score help_list(score myscore)
{
    score list = (score)malloc(sizeof(struct score_list) + myscore->len * sizeof(int));
    list->len = myscore->len;
    for (int i = 0; i < myscore->len; i++)
    {
        list->array[i] = myscore->array[i]; //生成1~100的随机数
    }
    return list;
}

//打印成绩单
void print_score(score myscore)
{
    printf("|||>>>");
    for (int i = 0; i < myscore->len; i++)
    {
        printf(" %d ", myscore->array[i]);
        if (i + 1 != myscore->len)
        {
            printf("-");
        }
    }
    printf("<<<|||\n");
}

//直接插入排序
// score direct_sort(score myscore)
// {
//     bowowa();
//     printf("直接插入排序\n");
//     int i, j, tmp;
//     score sort = help_list(myscore);
//     for (i = 1; i < sort->len; i++)
//     {
//         tmp = sort->array[i];
//         for (j = i - 1; tmp < sort->array[j] && j >= 0; j--)
//         {
//             sort->array[j + 1] = sort->array[j];
//         }
//         sort->array[j + 1] = tmp;
//         print_score(sort);
//     }
//     return sort;
// }

//二分排序
score bi_sort(score myscore)
{
    bowowa();
    printf("二分排序\n");
    int i, j, tmp, left, right, mid;
    score sort = help_list(myscore);
    for (i = 1; i < sort->len; i++)
    {
        if (sort->array[i] < sort->array[i - 1])
        {
            tmp = sort->array[i];
            left = 0;
            right = i - 1;
            while (left <= right)
            {
                mid = (left + right) / 2;
                if (sort->array[mid] < tmp)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            for (j = i - 1; j >= left; j--)
            {
                sort->array[j + 1] = sort->array[j];
            }
            sort->array[left] = tmp;
        }
        print_score(sort);
    }
    return sort;
}

//直接插入排序
score direct_sort(score myscore)
{
    bowowa();
    printf("直接插入排序:\n");
    score sort = myscore;
    int i,j,temp;
    for(i=1;i < sort->len;i++)
    {
        temp = sort->array[i];
        for(j=i-1;j>=0 && sort->array[j] > temp;j--)
        {
            sort->array[j+1] = sort->array[j];
        }
        if(j!=i-1)
        {
            sort->array[j+1] = temp;
        }
        print_score(sort);
    }
    return sort;
}


//顺序表转链表
node array2node(score myscore)
{
    int i;
    node head, p, q;
    head = (node)malloc(sizeof(node));
    q = head;
    q->key = myscore->array[0];
    q->next = NULL;
    for (i = 1; i < myscore->len; i++)
    {
        p = (node)malloc(sizeof(node));
        p->key = myscore->array[i];
        p->next = NULL;
        q->next = p;
        q = p;
    }
    return head;
}

//打印链表
void print_node(node head)
{
    printf("|||>>>");
    while (head->next != NULL)
    {
        printf(" %d -", head->key);
        head = head->next;
    }
    printf(" %d ", head->key);
    printf("<<<|||\n");
}

//表插法
node table_sort(score myscore)
{
    bowowa();
    printf("表插法\n");
    node ghost, head, now, pre, p, q;
    head = array2node(myscore);
    ghost = (node)malloc(sizeof(node));
    ghost->key = -1;
    ghost->next = head;
    pre = head;
    now = pre->next;
    print_node(ghost->next);
    while (now != NULL)
    {
        p = ghost;
        q = p->next;
        while (q != now && q->key <= now->key)
        {
            p = q;
            q = q->next;
        }
        if (q == now)
        {
            pre = pre->next;
            now = pre->next;
            continue;
        }
        pre->next = now->next;
        now->next = q;
        p->next = now;
        //if(pre==NULL)break;
        now = pre->next;
        print_node(ghost->next);
    }
    print_node(ghost->next);
    return head;
}

//直接选择排序
score choose_sort(score myscore)
{
    bowowa();
    printf("直接选择排序\n");
    score sort =  help_list(myscore);
    for(int i = 0;i < sort->len;i++)
    {
        print_score(sort);
        int min_index = i;
        for(int j = i+1;j < sort->len;j++)
        {
            if(sort->array[j]<sort->array[min_index])
            {
                min_index = j;//记录更新目前最小值的下标
            }
        }
        int temp = sort->array[i];
        sort->array[i] = sort->array[min_index];//将找到的最小值放到排序好的序列中
        sort->array[min_index] = temp;
    }
    return sort;
}

//冒泡排序
score pop_sort(score myscore)
{
    bowowa();
    printf("冒泡排序\n");
    score sort = help_list(myscore);
    for (int i = 0; i < sort->len-1; i++)
    {
        print_score(sort);
        for (int j = 0; j < sort->len-i-1; j++)
        {
            if (sort->array[j+1] < sort->array[j])//遇见比前一个小的交换，交换位置。
            {
                int temp;
                temp = sort->array[j];
                sort->array[j] = sort->array[j+1];
                sort->array[j+1] = temp;
            }//将最大的数浮到表尾
        }
    }
    return sort;
}

//快速选择 整体采取从两边向内收敛,依次将比temp值大或者小的数分居两侧
score quick_sort(score myscore,int l ,int r)//l代表数组下标左值,r代表数组下标右值
{
    //score sort = help_list(myscore);
    score sort = myscore;
    print_score(sort);
    int i,j,temp;
    i = l; j = r; temp = sort->array[i];
    if(l>=r)return 0;//此处很重要
    while(i != j){//找到temp的值的真实坐标
        while(i < j && sort->array[j] >= temp)//查找比temp更小的数
            j--;
        if(i<j) sort->array[i++] = sort->array[j];
        while(i < j && sort->array[i] <= temp)
            i++;
        if(i<j) sort->array[j--] = sort->array[i];
    }
    sort->array[i] = temp;
    quick_sort(sort,l,i-1);
    quick_sort(sort,i+1,r);
    return sort;
}

int main(void)
{
    bowowa();
    score myscore = rand_score(20);
    print_score(myscore);
    score direct = direct_sort(myscore);
    score bi = bi_sort(myscore);
    node table = table_sort(myscore);
    score pop = pop_sort(myscore);
    score choose = choose_sort(myscore);
    printf("快速排序 \n");
    bowowa();
    score quick = quick_sort(myscore,0,19);
    getchar();
}