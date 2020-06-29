/*
 * driver for Graham's scan
 *
 * project: hw5
 * name: 
 * user??
 * date: 
 * file: hw5.c
 */


#include "hw5.h"



Point *createData(int seed,int n){

    FILE *f = fopen("points.csv", "w");
	TEST_FILE(f,"createData","points.csv");
	srand48(seed); /* seeding the pseudorandom number generator */
	Point *data = malloc(sizeof(Point) * n);
	for (int i = 0; i < n; i++) {
		data[i].x = drand48();data[i].y = drand48();
		fprintf(f, "%f,%f\n",data[i].x,data[i].y);
	}

	fclose(f);
	return data;
}



