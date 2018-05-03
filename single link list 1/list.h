#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int status;
typedef int elemtype;
typedef struct lnode {
	elemtype data;
	struct lnode *next;
}lnode,*linklist;
extern status initlist(linklist *);
extern status destroylist(linklist *);
extern status listinsert(linklist, int, elemtype);
extern void print(elemtype);
extern status listtraverse(linklist, void(*vi)(elemtype));
#endif