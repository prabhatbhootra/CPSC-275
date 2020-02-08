#include <stdio.h>

void addarray(int n, int x[], int y[], int z[]){
	int i;
	for (i = 0; i < n; i++){
		z[i] = x[i] + y[i];
	}
}
