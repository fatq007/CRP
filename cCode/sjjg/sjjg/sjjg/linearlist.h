#ifndef LINEAR_LIST_H
#define LINEAR_LIST_H

#include "baseType.h"

#define INIT_SIZE 10        //��ʼ����
#define INCREMENT_SIZE 5    //��������

typedef int Status;
typedef int Elemtype;

/* �洢�ṹ */
typedef struct
{
    Elemtype *elem;
    int length;
    int size;
}SqList;

#endif //LINEAR_LIST_H