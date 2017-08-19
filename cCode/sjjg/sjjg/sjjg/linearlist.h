#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

#include "baseType.h"

#define INIT_SIZE 10        //初始化表长
#define INCREMENT_SIZE 5    //分配增量

typedef int Status;
typedef int Elemtype;

/* 存储结构 */
typedef struct
{
    Elemtype *elem;
    int length;
    int size;
}SqList;

#endif //LINEAR_LIST_H