#ifndef CERESMATH_H
#define CERESMATH_H

#include <math.h>

/* quaternion_f is a quaternion of floats
 * w ->  real component
 * x y z -> imaginary components
 */
struct quaternion {
	float x,y,z,w;
};

struct vector {
	float x, y, z;
};

struct srt {
	struct vector scale;
	struct quaternion rotation;
	struct vector translation;
};


//Operation for "points"
void translate_v(const struct vector *t, struct vector *result);

void rotate_v(const struct quaternion *r, struct vector *result);

void scale_v(const struct vector *s, struct vector *result);

//Operations with quaternions
void multiplication_q(const struct quaternion *q1, const struct quaternion *q2, struct quaternion *result);

void conjugate_q(const struct quaternion *q, struct quaternion *result);

void normalize_q(const struct quaternion *q, struct quaternion *result);

void lerp_q(const struct quaternion *q1, const struct quaternion *q2, float beta, struct quaternion *result);

void slerp_q(const struct quaternion *q1, const struct quaternion *q2, float beta, float angle, struct quaternion *result);

//Operations with vectors
void addition_v(const struct vector *v1, const struct vector *v2, struct vector *result);

void normalize_v(const struct vector *v, struct vector *result);

void crossproduct_v(const struct vector *v1, const struct vector *v2, struct vector *result);

float dotproduct_v(const struct vector *v1, const struct vector *v2);

void lerp_v(const struct vector *v1, const struct vector *v2, float beta, struct vector *result);


	
#endif /*CERESMATH_H*/
