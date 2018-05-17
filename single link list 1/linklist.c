#include "list.h"
#pragma warning (disable:4996)
status initlist(linklist *l) {
	*l = malloc(sizeof(lnode));
	if (!*l) return ERROR;
	(*l)->next = NULL;
	return OK;
}

status destroylist(linklist *l) {
	linklist p;
	while (*l) {
		p = (*l)->next;
		free(*l);
		*l = p;
	}
	return OK;
}

status listinsert(linklist l, int i, elemtype e) {
	int j = 0;
	linklist p = l;
	linklist new;
	while (p&&j<i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j>i - 1)return ERROR;
	new = malloc(sizeof(lnode));
	if (!new) return ERROR;
	new ->next = p->next;
	p->next = new;
	new->data = e;
	return OK;
}
void print(elemtype e) {
	printf("%d\n", e);
}
status listtraverse(linklist l, void(*vi)(elemtype)) {
	linklist p = l->next;
	while (p) {
		vi(p->data);
		p = p->next;
	}
	return OK;
}

status createlist(linklist l, int n) { //head insert
	linklist p;
	while (n-- > 0) {
		p = malloc(sizeof(lnode));
		if (!p) return ERROR;
		p->next = l->next;
		l->next = p;
		scanf("%d", &p->data);
	}
	return OK;
}

status createlist1(linklist l, int n) { //tail insert
	linklist p, r;
	r = l;
	while (n-- > 0) {
		p = malloc(sizeof(lnode));
		if (!p) return ERROR;
		r->next = p;
		r = p;
		scanf("%d", &p->data);
	}
	r->next = NULL;
	return OK;
}