#pragma once

typedef void Vector;
Vector* VectorCreate(int elemsize);
void VectorPushBack(Vector* v, void* elem);
void VectorPushFront(Vector* v, void* elem);
void VectorInsert(Vector* v, void* elem, int position);
void* VectorGetElem(Vector* v, int position);
int VectorCount(Vector* v);
void VectorClear(Vector* v);
void VectorDispose(Vector* v);