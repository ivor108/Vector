#include <iostream>
#include "Vector.h"
#include "Vector2.h"

Vector* VectorCreate(int elemsize)
{
	_Vector* v = (_Vector*)malloc(sizeof(_Vector));
	v->elemSize = elemsize;
	v->bufSize = 10 * elemsize;
	v->buf = (char*)malloc(v->bufSize);
	v->numElems = 0;
	return v;
}

void VectorPushBack(Vector* v, void* elem)
{
	_Vector* w = (_Vector*)v;

	if (w->elemSize * w->numElems >= w->bufSize)
	{
		w->bufSize = 2 * w->bufSize;
		realloc(w->buf, w->bufSize);
	}

	memcpy(w->buf + w->numElems * w->elemSize, elem, w->elemSize);
	w->numElems++;
}

void VectorPushFront(Vector* v, void* elem)
{
	_Vector* w = (_Vector*)v;
	VectorInsert(w, elem, 0);
}

void VectorInsert(Vector* v, void* elem, int position)
{
	_Vector* w = (_Vector*)v;

	if (w->elemSize * w->numElems >= w->bufSize)
	{
		w->bufSize = 2 * w->bufSize;
		realloc(w->buf, w->bufSize);
	}

	memmove(w->buf + position * w->elemSize + w->elemSize, w->buf + position * w->elemSize, w->bufSize - position* w->elemSize);
	memcpy(w->buf + position * w->elemSize, elem, w->elemSize);
	w->numElems++;
}

void* VectorGetElem(Vector* v, int position)
{
	_Vector* w = (_Vector*)v;
	return w->buf + position * w->elemSize;
}

int VectorCount(Vector* v)
{
	_Vector* w = (_Vector*)v;
	return w->numElems;
}

void VectorClear(Vector* v)
{
	_Vector* w = (_Vector*)v;
	w->numElems = 0;
}

void VectorDispose(Vector* v)
{
	_Vector* w = (_Vector*)v;
	free(w->buf);
	free(v);
}

int main()
{
	Vector* v = VectorCreate(sizeof(int));

	int m = 1;
	VectorPushBack(v, &m);
	m = 2;
	VectorPushBack(v, &m);
	m = 3;
	VectorPushBack(v, &m);
	m = 4;
	VectorPushBack(v, &m);
	m = 5;
	VectorPushBack(v, &m);
	m = 7;
	//VectorInsert(v, &m, 0);
	VectorPushFront(v, &m);
	for (int i = 0; i < VectorCount(v); i++)
	{
		int* p = (int*)VectorGetElem(v, i);
		std::cout << *p << std::endl;
	}
}

