#include "list.h"
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