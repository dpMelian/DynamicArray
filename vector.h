#ifndef VECTOR_H
#define VECTOR_H
typedef union {
	char c;
	int i;
	long long l;
	double d;
	void * p;
} tItem;

typedef enum {
	CHAR, INT, LONG_LONG, DOUBLE, POINTER
} tItemTypes;

typedef struct {
	tItem * array;
	int capacity;
	int lastIndex;
	int itemSize;
} tVector;

tVector Vector_Create(int initialCapacity, tItemTypes type);
void Vector_Init(tVector * v, int initialCapacity, tItemTypes type);
void Vector_Append(tVector * v, tItem item);
tItem Vector_Get(tVector *v, int index);
void Vector_Put(tVector * v, int index, tItem item);
void Vector_Destroy();
#endif