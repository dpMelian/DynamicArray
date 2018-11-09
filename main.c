#include <stdio.h>
#include "vector.h"

int main(int argc, char **argv)
{
	tVector v = Vector_Create(10, INT);
	tItem item;
	for(int i = 0; i < 10000; i++){
		item.i = i;
		Vector_Append(&v, item);
		item = Vector_Get(&v, i);
		printf("vector[%d]=%d\n", i, item.i);
	}
	printf("hello world\n");
	return 0;
}
