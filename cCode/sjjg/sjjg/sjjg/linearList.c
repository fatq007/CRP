#include "linearList.h"

/* ��ʼ�� */
Status InitSqList(SqList *pL)
{
    pL->elem = (Elemtype *)malloc(INIT_SIZE * sizeof(Elemtype));
    if(NULL == pL->elem)
    {
        return FAILURE;
    }

    pL->length = 0;
    pL->size = INIT_SIZE;

    return SUCCESS;
}

/* ���� */
Status DestroySqList(SqList *pL)
{
    free(pL->elem);
    pL->length = 0;
    pL->size = 0;

    return SUCCESS;
}

/* ����Ϊ�ձ� */
Status ClearSqList(SqList *pL)
{
    pL->length = 0;

    return SUCCESS;
}

/* �ж��Ƿ�Ϊ�� */
BOOL isEmpty(const SqList L)
{
    if(0 == L.length)
    {
        return TRUE;
    }

    return FALSE;
}

/* ��ȡ���� */
int getSqListLength(const SqList L)
{
    return L.length;
}

/* ����λ�û�ȡ��ӦԪ�� */
Status GetSqListElem(const SqList L, int index, Elemtype *elem)
{
    if(index<0 || index>=L.length)
    {
        return FAILURE;
    }
    *elem = L.elem[index];
    return SUCCESS;
}
/* �Ƚ�����Ԫ���Ƿ���� */
BOOL SqListElemCompare(Elemtype e1, Elemtype e2)
{
    if(e1 == e2)
    {
        return TRUE;
    }
    return FALSE;
}

/* ����Ԫ�� */
int FindSqListElem(const SqList L, Elemtype e, BOOL (*compare)(Elemtype, Elemtype))
{
    int i = 0;
    for(; i < L.length; i++)
    {
        if((*compare)(L.elem[i],e))
        {
            return i;
        }
    }
    return FAILURE;
}

/* ��ȡָ��Ԫ�ص�ǰ��*/
Status GetSqListPreElem(const SqList L, Elemtype curElem, Elemtype *preElem, BOOL (*compare)(Elemtype, Elemtype))
{
     int i = 0;
     for(; i < L.length; i++)
    {
        if((*compare)(L.elem[i],curElem))
        {
            if(i > 0)
            {
                *preElem = L.elem[i-1];
                return SUCCESS;
            }
            else
            {
                return FAILURE;
            }
        }
    }
    return FAILURE;
}

/* ��ȡ���Ԫ�� */
Status GetSqListNextElem(const SqList L, Elemtype curElem, Elemtype *preElem, BOOL (*compare)(Elemtype, Elemtype))
{
    int i = 0;
     for(; i < L.length; i++)
    {
        if((*compare)(L.elem[i],curElem))
        {
            if(i < L.length - 1)
            {
                *preElem = L.elem[i+1];
                return SUCCESS;
            }
            else
            {
                return FAILURE;
            }
        }
    }
    return FAILURE;
}

/* ����Ԫ�� */
Status insertSqListElem(SqList *pL, Elemtype elem, int index)
{
    Elemtype *newElem;
    Elemtype *p = NULL;
    Elemtype *q = NULL;

    if (index < 0 || index > pL->length)
    {
        return FAILURE;
    }

    if (pL->length >= pL->size)
    {
        newElem = (Elemtype*) realloc(pL->elem, (pL->size + INCREMENT_SIZE) * sizeof(Elemtype));
        if (!newElem)
        {
            return FAILURE;
        }
        pL->elem = newElem;
        pL->size += INCREMENT_SIZE;
    }

    p = &pL->elem[index];
    q = &pL->elem[pL->length - 1]; 
    for (; q >= p; q--)
    {
        *(q + 1) = *q;
    }
    *p = elem;
    ++pL->length;
    return SUCCESS;
}

/* ɾ��Ԫ�� */
Status deleteSqListElem(SqList *pL, Elemtype *pElem, int index)
{
    Elemtype *p = NULL;
    if (0 == pL->length || index < 0 || index > pL->length)
    {
        return FAILURE;
    }

    p = &pL->elem[index];
    *pElem = *p;
    for (; p < &pL->elem[pL->length]; p++)
    {
        *(p) = *(p + 1);
    }
    --pL->length;
    return SUCCESS;
}

/* ����Ԫ�� */
void visit(Elemtype e)
{
    printf("%d \n", e);
}

/* ����Ԫ�� */
Status TraverseList(const SqList L, void (*visit)(Elemtype))
{
    int i;
    for(i = 0; i < L.length; i++)
    {
        visit(L.elem[i]);
    }
    return SUCCESS;
}
