#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

int Vector_Item_Size(tItemTypes type)
{
	// CHAR, INT, LONG_LONG, DOUBLE, POINTER
	int table[] = {
		sizeof(char), sizeof(int), sizeof(long long),
		sizeof(double), sizeof(void*)
	};
	return table[type];
}
tVector Vector_Create(int initialCapacity, tItemTypes type)
{
	tVector v;
	v.itemSize = Vector_Item_Size(type);
	v.array = malloc(initialCapacity * v.itemSize);
	v.capacity = initialCapacity;
	return v;
}
void Vector_Init(tVector * v, int initialCapacity, tItemTypes type)
{
	v->itemSize = Vector_Item_Size(type);
	v->array = malloc(initialCapacity * v->itemSize);
	v->capacity = initialCapacity;
}
void Vector_Put_Item(tVector * v, tItem item, int index)
{
	char * ptr = (char *)v->array;
	mempcpy(ptr + index * v->itemSize, &item, v->itemSize);
}
void Vector_Append(tVector * v, tItem item)
{
	if (v->lastIndex >= v->capacity) { // is realloc needed?
		tItem * p = realloc(v->array, 2*v->capacity*v->itemSize);
		if(p==NULL) return;
		v->array = p;
		v->capacity = 2*v->capacity;
	}
	
	Vector_Put_Item(v, item, v->lastIndex++);
}
tItem Vector_Get(tVector *v, int index)
{
	char * ptr = (char *)v->array;
	tItem item;
	if (index <= v->lastIndex) {
		mempcpy(&item, ptr + index * v->itemSize, v->itemSize);
		return item;
	}
	fprintf(stderr, "Vector_Get: index %d is out of range (%d)\n",
					index, v->capacity);
	exit(EXIT_FAILURE);
}
void Vector_Put(tVector * v, int index, tItem item)
{
	if (index >= v->capacity) { // is realloc needed?
		
		tItem * p = realloc(v->array, (index + v->capacity) * v->itemSize);
		if(p==NULL)
			return;
		v->array = p;
		v->capacity = index + v->capacity;
	}
	v->lastIndex = index + 1;
	Vector_Put_Item(v, item, index);
}
void Vector_Destroy(tVector * v)
{
	free(v->array);
}