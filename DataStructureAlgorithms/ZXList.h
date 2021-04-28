#ifndef _ZXLIST_H
#define _ZXLIST_H

#include "ZXBase.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int ElemType;

typedef struct {
	ElemType * elem;
	int length;
	int list_size;	
}SqList;

// initialize the List
Status InitList_Sq(
	IN OUT SqList *L
);

Status DestroyList_Sq(
	IN OUT SqList *L
);

Status ClearList_Sq(
	IN OUT SqList *L
);

BOOLEAN ListEmpty_Sq(
	IN const SqList *L
);

int ListLength_Sq(
	IN const SqList *L
);

Status GetElem(
	IN const SqList *L, 
	IN int i, 
	OUT ElemType *e
);


#endif
