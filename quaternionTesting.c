#include "quaternionMath.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void qf_testing () {
	printf("qf_testing\n");
	struct quaternion_f qf= {.x = 4.5, .y = 7.23, .z = 100.543, .w = 2.2};
	struct quaternion_f qf2 = {.x = 20, .y = 4, .z = 10, .w = 40};
	struct quaternion_f *qf_pointer = &qf;
	printf("qf -> (x=%f, y=%f, z=%f, w=%f)\n", qf_pointer->x, qf_pointer->y, qf_pointer->z, qf_pointer->w);
  
	normalize_qf (qf_pointer, qf_pointer);
	printf("qf -> (x=%f, y=%f, z=%f, w=%f)\n", qf_pointer->x, qf_pointer->y, qf_pointer->z, qf_pointer->w);
  
	qf_pointer = (struct quaternion_f*) malloc(sizeof(struct quaternion_f));
	multiplication_qf (&qf, &qf2, qf_pointer);
	printf("qf -> (x=%f, y=%f, z=%f, w=%f)\n", qf_pointer->x, qf_pointer->y, qf_pointer->z, qf_pointer->w);
	printf("qf -> (x=%f, y=%f, z=%f, w=%f)\n\n", qf.x, qf.y, qf.z, qf.w);
}

void qd_testing () {
	printf("qd_testing\n");
	struct quaternion_d qd = {.x = 4.5, .y = 7.23, .z = 100.543, .w = 2.2};
	struct quaternion_d qd2 = {.x = 20, .y = 4, .z = 10, .w = 40};
	struct quaternion_d *qd_pointer, *qd_pointer2, *result;
	qd_pointer = (struct quaternion_d*) malloc(sizeof(struct quaternion_d));
	qd_pointer2 = (struct quaternion_d*) malloc(sizeof(struct quaternion_d));
	result = (struct quaternion_d*) malloc(sizeof(struct quaternion_d));
	
	printf ("qf -> (x=%lf, y=%lf, z=%lf, w=%lf)\n", qd.x, qd.y, qd.z, qd.w);
	
	normalize_qd(&qd, qd_pointer);
	printf("qf -> (x=%lf, y=%lf, z=%lf, w=%lf)\n", qd_pointer->x, qd_pointer->y, qd_pointer->z, qd_pointer->w);
	normalize_qd(&qd2, qd_pointer2);
	

	multiplication_qd(qd_pointer, qd_pointer2, result);
	
	printf("qf -> (x=%lf, y=%lf, z=%lf, w=%lf)\n", result->x, result->y, result->z, result->w);
	printf("qf -> (x=%lf, y=%lf, z=%lf, w=%lf)\n\n", qd.x, qd.y, qd.z, qd.w);
}

int main () {
  qf_testing();
  qd_testing();

return 0;
}
