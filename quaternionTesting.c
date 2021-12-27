#include "ceresMath.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void qf_testing () {
	printf("qf_testing\n");
	struct quaternion_f qf= {.x = 4.5, .y = 7.23, .z = 100.543, .w = 2.2};
	struct quaternion_f qf2 = {.x = 20, .y = 4, .z = 10, .w = 40};
	struct quaternion_f *qf_pointer = &qf;
	printf("qf -> (x=%f, y=%f, z=%f, w=%f)\n", qf_pointer->x, qf_pointer->y, qf_pointer->z, qf_pointer->w);
  
	normalize_q(qf_pointer, qf_pointer);
	printf("qf -> (x=%f, y=%f, z=%f, w=%f)\n", qf_pointer->x, qf_pointer->y, qf_pointer->z, qf_pointer->w);
  
	qf_pointer = (struct quaternion_f*) malloc(sizeof(struct quaternion_f));
	multiplication_q(&qf, &qf2, qf_pointer);
	printf("qf -> (x=%f, y=%f, z=%f, w=%f)\n", qf_pointer->x, qf_pointer->y, qf_pointer->z, qf_pointer->w);

}


int main () {
  qf_testing();

return 0;
}
