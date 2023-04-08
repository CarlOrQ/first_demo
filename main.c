#include <stdio.h>
#include <stdlib.h>
#include "window.h"
/*
a. ��������Ԫ����ÿһ��Ԫ�ز��������鲢��ӡ����Ļ�ϡ�
��ʽ: a[i]:xxx->[x,x,x,x,x]
b. ����ԭʼ������ÿ��Ԫ�� a �ı任Ԫ�� N(a),����ӡ����Ļ�ϡ�
c. ����������ÿ��ԭʼԪ�� a �ı任Ԫ�� N(a)ֵ��С��ʹ�������ڵ�Ԫ�ش���һ������
˫���������������������������Ԫ�ص���Ļ�ϡ�
d. �����黮�ֳ����������� P1,P2��ÿ����������� 4 ��Ԫ�أ�ʹ�û��ֺ������������
�����ֱ�������� P1,P2 ��ÿ��Ԫ�� a ���� N(a)��ֵ��ʹ�����������ڸ��Ե� N(a)֮��
��ֵ�ľ���ֵ������ P1,P2 ����Ԫ�ص���Ļ��
e. �����黮�ֳ����������� P1,P2��ÿ����������� 4 ��Ԫ�أ�ʹ�û��ֺ������������
�����ֱ�������� P1,P2 ��ÿ��Ԫ�ؼ��� a ���� N(a)��ֵ��ʹ�����������ڸ��Ե� N(a)
֮�Ͳ�ֵ�ľ���ֵ��С����� P1,P2 ����Ԫ�ص���Ļ��
*/


/**
* note :������һ����������
* @param : tmp_bin ����������
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
* note :�����������������������
* @param  : a_bin ���������ƣ� len_all:�����Ƴ��ȣ� a_num����������
* @param : �������鳤��
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
* note :��������
* @param : a_bin ���������ƣ� len_all:�����Ƴ��ȣ� a_num����������
*/
void build(int a_bin, int len_all, int *a_num)
{

    unsigned int tmp_bin = a_bin;
    int len_a = len_all;
    int i = 0, flag = 0, k = 0;
    int count = 1; //���������

    //��������һ�£����㱣�浽����
    //�����У���λΪ0��û������ϵͳ��Ĭ�϶�ʧ
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
    //����һ������
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
    printf("����\n");
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
