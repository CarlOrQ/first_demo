#include <stdio.h>
#include <stdlib.h>
#include "window.h"
/*
a. 计算数组元素中每一个元素拆解出的数组并打印到屏幕上。
格式: a[i]:xxx->[x,x,x,x,x]
b. 计算原始数组中每个元素 a 的变换元素 N(a),并打印到屏幕上。
c. 根据数组中每个原始元素 a 的变换元素 N(a)值大小，使用数组内的元素创建一个降序
双向链表，并按降序输出排序后的数组元素到屏幕上。
d. 将数组划分成两个子数组 P1,P2，每个子数组具有 4 个元素，使得划分后的数组满足条
件：分别针对数组 P1,P2 中每个元素 a 计算 N(a)的值，使得两个数组内各自的 N(a)之和
差值的绝对值最大。输出 P1,P2 数组元素到屏幕上
e. 将数组划分成两个子数组 P1,P2，每个子数组具有 4 个元素，使得划分后的数组满足条
件：分别针对数组 P1,P2 中每个元素计算 a 计算 N(a)的值，使得两个数组内各自的 N(a)
之和差值的绝对值最小。输出 P1,P2 数组元素到屏幕上
*/


/**
* note :将任意一个整数倒叙
* @param : tmp_bin 整数二进制
*/
int flashback(unsigned int tmp_bin)
{
    int flag = lenth_num(tmp_bin);
    int *p = (int *)malloc(flag * sizeof(int));
    int i = 0;

    for(i = 0; i < flag; i++)
    {
        int temp = tmp_bin % 10;
        *(p + i) = temp;
        tmp_bin /= 10;
    }

    int ret = 0;

    for (i = 0; i < flag; i++)
    {
        ret = (10 * ret) + (*(p + i));
    }

    if(NULL != p)
    {
        free(p);
        p = NULL;
    }

    return ret;
}

/**
* note :计算二进制连续个数并保存
* @param  : a_bin 整数二进制， len_all:二进制长度， a_num：返回数组
* @param : 返回数组长度
*/
int cal_num(int a_bin, int len_all, int *a_num)
{
    int len = 0;
    int i = 0, k = 0;
    int tmp = a_bin;
    int count = 0, flag = 0;
    for(i = 0; i < len_all; i++)
    {
        k = tmp % 10;
        tmp /= 10;
        if (k == flag)
        {
            count++;
        }
        else
        {
            a_num[len] = count;
            len++;
            count = 0;
            flag = !flag;
        }
    }

    for(i = 0; i < len; i++)
    {
        printf("%d\n",a_num[i]);
        //2,1,2,2
    }
    return len;
}

/**
* note :生成数组
* @param : a_bin 整数二进制， len_all:二进制长度， a_num：返回数组
*/
void build(int a_bin, int len_all, int *a_num)
{

    unsigned int tmp_bin = a_bin;
    int len_a = len_all;
    int i = 0, flag = 0, k = 0;
    int count = 1; //计算组个数

    //将数倒叙一下，方便保存到数组
    //好像不行，首位为0不没有意义系统会默认丢失
    //int bin_tmp = flashback(tmp_bin);
    //printf("%d\n", bin_tmp);

    for(i = 0; i < len_a; i++)
    {
        k = tmp_bin % 10;
        tmp_bin /= 10;
        if (k != flag)
        {
            count++;
        }
    }

    int len_num =cal_num(a_bin, len_all, a_num);
    //倒叙一下数组
    flashback_num(a_num, len_num);
    a_num[len_num+1] = count;

    for(i = 0; i < 5 ; i++)
    {
        printf("a_num[%d]=%d \n", i,a_num[i]);
    }
    printf("count:%d\n", count);
}



int main()
{
    int ret;
    ret = init();
    while(1)
    {
        ret = getchar();
        if (ret == '#')
        {
            system("cls");
            init();
        }
        if (ret == '0')
        {
            break;
        }
    }
    printf("结束\n");
//    unsigned int a;
//    scanf("%d", &a);
//    unsigned int a_bin = decToBin(a);
//    int a_len = lenth_num(a_bin);
//    int i = 0;
//    int a_num[1024] = { 0 };
//
//
//    build(a_bin, a_len, a_num);
//
//    printf("a_bin = %d\n", a_bin);
//    printf("a_len = %d\n", a_len);
//
//    for(i = 0; i < 5 ; i++)
//    {
//        //printf("a_num[%d]=%d \n", i,a_num[i]);
//    }
    return 0;
}
