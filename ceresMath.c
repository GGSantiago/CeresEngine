#include "ceresMath.h"

void multiplication_qf (const struct quaternion_f *q1, const struct quaternion_f *q2, struct quaternion_f *result){
	result->x = (q1->x * q2->w) + (q1->y * q2->z) - (q1->z * q2->y) + (q1->w * q2->x);
	result->y = -(q1->x * q2->z) + (q1->y * q2->w) + (q1->z * q2->x) + (q1->w * q2->y) ;
	result->z = (q1->x * q2->y) - (q1->y * q2->x) + (q1->z * q2->w) + (q1->w * q2->z);
	result->w = (q1->w * q2->w) - (q1->x * q2->x) - (q1->y * q2->y) - (q1->z * q2->z);
}

void multiplication_qd (const struct quaternion_d *q1, const struct quaternion_d *q2, struct quaternion_d *result){
	result->x = (q1->x * q2->w) + (q1->y * q2->z) - (q1->z * q2->y) + (q1->w * q2->x);
	result->y = -(q1->x * q2->z) + (q1->y * q2->w) + (q1->z * q2->x) + (q1->w * q2->y) ;
	result->z = (q1->x * q2->y) - (q1->y * q2->x) + (q1->z * q2->w) + (q1->w * q2->z);
	result->w = (q1->w * q2->w) - (q1->x * q2->x) - (q1->y * q2->y) - (q1->z * q2->z);
}

void conjugate_qf (const struct quaternion_f *q, struct quaternion_f *result){
	result->x = -q->x;
	result->y = -q->y;
	result->z = -q->z;
	result->w = q->w;
}

void conjugate_qd (const struct quaternion_d *q, struct quaternion_d *result){
	result->x = -q->x;
	result->y = -q->y;
	result->z = -q->z;
	result->w = q->w;
}

void normalize_qf (const struct quaternion_f *q, struct quaternion_f *result) {
	const double lenght = sqrt(q->x*q->x + q->y*q->y + q->z*q->z + q->w*q->w);
	result->x = q->x / lenght;
	result->y = q->y / lenght;
	result->z = q->z / lenght;
	result->w = q->w / lenght; 
}

void normalize_qd (const struct quaternion_d *q, struct quaternion_d *result) {
	const double lenght = sqrt(q->x*q->x + q->y*q->y + q->z*q->z + q->w*q->w);
	result->x = q->x / lenght;
	result->y = q->y / lenght;
	result->z = q->z / lenght;
	result->w = q->w / lenght; 
}
