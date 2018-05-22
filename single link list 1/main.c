#include "list.h"

int main() {
	linklist l;
	initlist(&l);
	int a[] = { 1,3,5,7,9 };
	int i;
	for (i = 1;i <= 5;i++) listinsert1(l, i, a[i - 1]);
	//createlist1(l, 5);
	listtraverse(l, print);
	elemtype e;
	listdelete(l, 3, &e);
	printf("%d\n", e);
	getelem(l, 3, &e);
	printf("%d\n", e);
	printf("%d\n", listlength(l));
	destroylist(&l);
	system("pause");
	return 0;
}