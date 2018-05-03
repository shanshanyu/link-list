#include "list.h"
int main() {
	linklist l;
	initlist(&l);
	int a[] = { 1,3,5,7,9 };
	int i;
	for (i = 1;i <= 5;i++) listinsert(l, i, a[i - 1]);
	listtraverse(l, print);
	destroylist(&l);
	system("pause");
	return 0;
}