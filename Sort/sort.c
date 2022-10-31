/*
@File    :   sort.c
@Time    :   2022/10/31 19:40:17
@Author  :   Lev1s
@Version :   1.0
@Contact :   Lev1sStudio.cn@gmail.com
@PW      :   http://Lev1s.cn
@Github  :   https://github.com/o0Lev1s0o
    __             ___           ______
   / /   ___ _   _<  /____      / ____/
  / /   / _ \ | / / / ___/_____/ /
 / /___/  __/ |/ / (__  )_____/ /___
/_____/\___/|___/_/____/      \____/
*/

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
////////////////////
//函数列表
score rand_score(int size);
score zero_list(int size);
void print_score(score myscore);
////////////////////

//生成随机成绩单
score rand_score(int size)
{
    score list = (score)malloc(sizeof(struct score_list) + size * sizeof(int));
    srand((unsigned int)time(NULL));
    list->len = size;
    for (int i = 0; i < size; i++)
    {
        list->array[i] = rand() % 100 + 1; //生成1~100的随机数
        // printf("%d\n",list->array[i]);
    }
    return list;
}

//生成辅助数组
score zero_list(int size)
{
    score list = (score)malloc(sizeof(struct score_list) + size * sizeof(int));
    list->len = size;
    for (int i = 0; i < size; i++)
    {
        list->array[i] = 0; //生成1~100的随机数
    }
    return list;
}

//打印成绩单
void print_score(score myscore)
{
    printf("|||>>>");
    for (int i = 0; i < myscore->len; i++)
    {
        printf("%d", myscore->array[i]);
        if (i + 1 != myscore->len)
        {
            printf("-");
        }
    }
    printf("<<<|||\n");
}

//直接插入排序
score direct_sort(score myscore)
{
    int i, j, tmp;
    score sort = myscore;
    for (i = 1; i < sort->len; i++)
    {
        tmp = sort->array[i];
        for (j = i - 1; j >= 0; j--)
        {
            
        }
    }
    print_score(sort);
}

int main(void)
{
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n");
    //
    score myscore = rand_score(20);
    print_score(myscore);
    score direct = direct_sort(myscore);
    getchar();
}