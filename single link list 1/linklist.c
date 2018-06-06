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

linklist getelemp(linklist l, int i) {
	linklist p = l;
	while (i-- > 0) p = p->next;
	return p;
	
}

status listinsert1(linklist l, int i, elemtype e) {
	linklist p, new;
	if (i<1 || i>listlength(l) + 1)return ERROR;
	if (!(p = getelemp(l, i - 1))) return ERROR;
	new = malloc(sizeof(lnode));
	if (!new) return ERROR;
	new->next = p->next;
	p->next = new;
	new->data = e;
	return OK;
}

status listdelete(linklist l, int i, elemtype *e) {
	linklist p = l, q;
	int j = 0;
	while (j < i - 1 && p->next) {
		p = p->next;
		j++;
	}
	if (j > i - 1 || !p->next) return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
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

int listlength(linklist l) {
	linklist p = l->next;
	int i = 0;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}

status clearlist(linklist l) {
	linklist p = l->next, q;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	l->next = NULL;
	return OK;
}

status getelem(linklist l,int i,elemtype *e){
	linklist p = l->next;
	int j = 1;
	while (j < i&&p) {
		j++;
		p = p->next;
	}
	if (j > i || !p) return ERROR;
	*e = p->data;
	return OK;
}

status compare(elemtype a, elemtype b) {
	if (a == b)return TRUE;
	else return FALSE;
}

