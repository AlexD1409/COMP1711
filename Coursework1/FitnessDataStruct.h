#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>

typedef struct {
	char date[11];
	char time[6];
	char steps[1000];
} FITNESS_DATA;

#endif 