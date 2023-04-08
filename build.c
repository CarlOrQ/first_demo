#include "build.h"
#include <stdio.h>
#include "file.h"

static unsigned int pool[24]={
29, 18, 61, 479, 2033, 4587, 22310, 79,
565, 100211, 643, 1085, 8001, 786, 98, 911,
15, 109, 2021, 877, 243, 56, 908, 3004};


extern void set_num_box_data(unsigned int num[BUILD_NUM], unsigned int num_bin[BUILD_NUM]);

void get_randbox(unsigned int *randbox, int len)
{
    if(NULL == randbox)
    {
        return;
    }
    int index = 0;
    int random = 0;
    srand((unsigned)time(NULL));/*用时间做种，每次产生随机数不一样*/
    while(index < len)
    {
        random = rand()%24;//需要获取不重复的数

        randbox[index] = pool[random];
        index++;
    }
}

/**
* note :将一个整数转换为二进制形式
* @param : n 整数
*/
unsigned int decToBin(int n)//
{

	unsigned int result = 0;//结果
    int k = 1;
    int i = 0;
    while(n)//除到0就停止
    {
        i = n % 2;					//余数i=1	//i=1		//i=1			//i=1
		result = k * i + result;	//result=1	//result=11	//result=111	//result=1111
		k = k * 10;					//k=10		//k=100		//k=1000
		n = n / 2;					//n=7		//n=3		//n=1			//n=0退出

		if (k > (2^31))
        {
            k /= 2^8;
        }
    }
    return result;
}

/**
* note :计算一个整数的长度个数
* @param : num 整数
*/
int lenth_num(unsigned int num)
{
    int tmp = num;
    int len = 0;
    while(tmp > 0)
    {
        tmp /= 10;
        len++;
    }

    return len;
}

/**
* note :将任意一个整组倒叙放入原来的数组
* @param : p 数组
*/

void flashback_num(unsigned int p[], int len)
{
    int n = len/2;
    for(int i = 0; i < n; i++)
    {
        int temp = p[i];
        p[i] = p[len - 1 - i];
        p[len - 1 - i] = temp;
    }
}

void check_bin_len(int len)
{
    while(len>31)
    {
        len -= 8;
    }

}

void build_create(unsigned int box[BUILD_NUM][100], unsigned int ele_box_bin[BUILD_NUM])
{
    int i = 0, k = 0, k_next = 0, j = 0, z = 0;
    int count = 0; //累积共有多少个组
    int sum = 0; //计算每组的里的个数
    for(i = 0; i < BUILD_NUM; i++)
    {
        k = 0;
        count = 1;
        k_next = -1;
        z = 1;
        sum = 0;
        int len = lenth_num(ele_box_bin[i]);
        //printf("len = %d\n",len);
        //check_bin_len(len);
        for (j = 0; j < len; j++)
        {
            k = ele_box_bin[i] % 10;
            if (k_next == -1)
            {
                k_next = k;
            }
            ele_box_bin[i] /= 10;

            if (k != k_next)
            {
                count++; //计算组数
                box[i][z] = sum;
                sum = 0;
                z++;
            }
            sum++;

            k_next = k;

        }

        if (len == 0)
        {
            box[i][1] = 1;//特殊处理
            z++;
        }
        else
        {
            box[i][z] = sum;
            z++;
        }
        //printf("count = %d\n", count);
        box[i][0] = count; //先存组
        flashback_num(box[i], z);
        int t = 0;
        for (t = 0; t < z; t++)
        {
            printf("%d,", box[i][t]);
        }
        printf("\n");
    }
    printf("\n按#返回主界面,按0结束\n");
}

unsigned int randbox[BUILD_NUM] = {22310, 4, 24, 31, 100, 98, 98, 98};//存储8个数组
void init_build(int choice)
{

    if (choice == 1)
    {
        get_randbox(randbox, BUILD_NUM);
    }

    unsigned int ele_box_bin[BUILD_NUM] = { 0 }; //8个二进制数
    int i = 0;
    printf("8个元素是: ");
    for(i = 0; i < BUILD_NUM; i++)
    {
        printf("%d,", randbox[i]);
        ele_box_bin[i] = decToBin(randbox[i]);
        //printf("ele_box_bin = %d\n", ele_box_bin[i]);
    }
    printf("\n");

    if (choice == 1)
    {
        printf("\n按#返回主界面,按0结束\n");
        return ;
    }
    /*需要保存数据之后如果打开没有重新生成数据就直接实现功能就需要读取文档里的数据*/
    //set_num_box_data(randbox, ele_box_bin);
    unsigned int box[BUILD_NUM][100] = { 0 };

    build_create(box, ele_box_bin);


}


