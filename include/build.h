#ifndef _BUILD_H_
#define _BUILD_H_
#include "window.h"

#define BUILD_NUM 8
void get_randbox(unsigned int *randbox, int len);
unsigned int decToBin(int n);
int lenth_num(unsigned int num);
void flashback_num(unsigned int p[], int len);
void check_bin_len(int len);
void build_create(unsigned int box[BUILD_NUM][100], unsigned int ele_box_bin[BUILD_NUM]);
void init_build(int choice);


#endif // _BUILD_H_
