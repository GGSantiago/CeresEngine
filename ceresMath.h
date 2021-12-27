#ifndef QUATERNIONMATH_H
#define QUATERNIONMATH_H

#include <math.h>

/*quaternion_f is a quaternion of floats
  w is the real component
  x y z are the imaginary components*/
struct quaternion_f {
	float x,y,z,w;
};

struct quaternion_d {
	double x,y,z,w;
};

void multiplication_qf (const struct quaternion_f *q1, const struct quaternion_f *q2, struct quaternion_f *result);
void multiplication_qd (const struct quaternion_d *q1, const struct quaternion_d *q2, struct quaternion_d *result);

void conjugate_qf (const struct quaternion_f *q, struct quaternion_f *result);
void conjugate_qd (const struct quaternion_d *q, struct quaternion_d *result);

void normalize_qf (const struct quaternion_f *q, struct quaternion_f *result);
void normalize_qd (const struct quaternion_d *q, struct quaternion_d *result);
	
#endif /*QUATERNIONMATH_H*/
