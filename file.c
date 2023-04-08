#include "file.h"
#include <stdio.h>
#include <string.h>

NUM_BOX num_box;

int num_read()
{
    char path[256] = { 0 };

    strcat(path, "txt/ele_box_bin.txt");

    FILE *fp = fopen(path, "r+");
    if (fp == NULL)
    {
        return -1;
    }
    memset(&num_box, 0, sizeof(num_box));
    fread(num_box.num_bin, 1, sizeof(num_box.num_bin), fp);

    fclose(fp);

    return 0;
}

void num_save()
{
    char path[256] = { 0 };
    strcat(path, "txt/ele_box_bin.txt");

    FILE *fp = fopen(path, "w+");

    if (fp == NULL)
    {
        return;
    }

    fwrite(&num_box, 1, sizeof(num_box), fp);

    fclose(fp);

}

void set_num_box_data(unsigned int num[BUILD_NUM], unsigned int num_bin[BUILD_NUM])
{
    int i = 0;
    for(i = 0; i < BUILD_NUM; i++)
    {
        num_box.num[i] = num[i];
        num_box.num_bin[i] = num_bin[i];
    }

    num_save();
}
