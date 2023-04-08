#ifndef _FILE_H_
#define _FILE_H_
#include "build.h"

typedef struct _NUM_BOX
{
    unsigned int num[BUILD_NUM];
    unsigned int num_bin[BUILD_NUM];
}NUM_BOX;


int num_init();

void num_save();

void set_num_box_data(unsigned int num[BUILD_NUM], unsigned int num_bin[BUILD_NUM]);

#endif // _FILE_H_
