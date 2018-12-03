#ifndef SET
#define SET
#define SET_INIT_SIZE 100
#define SETINCREASENUM 10
#include "arc.h"
typedef Arc SetElemType;
typedef int Status;
#define OVERFLOW -1;
#define OK 1;
#define ERROR 0; 
typedef struct {
	int size;
	SetElemType *data;
}ArcSet;
Status InitArcSet(ArcSet &S){
	data = (SetElemType *)ralloc(SET_INIT_SIZE*sizeof(SetElemType));
	if(!data)
		exit(OVERFLOW);
	size = SET_INIT_SIZE; 
}

#endif
