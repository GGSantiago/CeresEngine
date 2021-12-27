#include "ceresMath.h"
//Operation with "points"

void translate_v(const struct vector *t, struct vector *result){
	
}

//Operation with quaternions
void multiplication(const struct quaternion *q1, const struct quaternion *q2, struct quaternion *result)
{
	result->x = (q1->x * q2->w) + (q1->y * q2->z) - (q1->z * q2->y) + (q1->w * q2->x);
	result->y = -(q1->x * q2->z) + (q1->y * q2->w) + (q1->z * q2->x) + (q1->w * q2->y);
	result->z = (q1->x * q2->y) - (q1->y * q2->x) + (q1->z * q2->w) + (q1->w * q2->z);
	result->w = (q1->w * q2->w) - (q1->x * q2->x) - (q1->y * q2->y) - (q1->z * q2->z);
}

void conjugate(const struct quaternion *q, struct quaternion *result)
{
	result->x = -q->x;
	result->y = -q->y;
	result->z = -q->z;
	result->w = q->w;
}

void normalize(const struct quaternion *q, struct quaternion *result) 
{
	const float lenght = sqrt(q->x*q->x + q->y*q->y + q->z*q->z + q->w*q->w);
	result->x = q->x / lenght;
	result->y = q->y / lenght;
	result->z = q->z / lenght;
	result->w = q->w / lenght; 
}

void lerp(const struct quaternion *q1, const struct quaternion *q2, float beta, struct quaternion *result)
{
	//Interpolation
	result->x = (1.0f - beta) * q1->x + beta * q2->x; 
	result->y = (1.0f - beta) * q1->y + beta * q2->y; 
	result->z = (1.0f - beta) * q1->z + beta * q2->z; 
	result->w = (1.0f - beta) * q1->w + beta * q2->w; 
	
	//Normalization
	normalize_q(result, result);
}

void slerp(const struct quaternion *q1, const struct quaternion *q2, float beta, float angle, struct quaternion *result)
{
	//Interpolation
	const float weight_q1 = sin((1.0f - beta) * angle)/sin(angle);
	const float weight_q2 = sin(beta*angle)/sin(angle);
	
	result->x = weight_q1*q1->x + weight_q2*q2->x;
	result->y = weight_q1*q1->y + weight_q2*q2->y;
	result->z = weight_q1*q1->z + weight_q2*q2->z;
	result->w = weight_q1*q1->w + weight_q2*q2->w;
	
	//Normalization
	normalize_q(result, result);
}

//Operation with vectors
void addition_v(const struct vector *v1, const struct vector *v2, struct vector *result)
{
	result->x = v1->x + v2->x;
	result->y = v1->y + v2->y;
	result->z = v1->z + v2->z;
}

void normalize_v(const struct vector *v, struct vector *result)
{
	const float lenght = sqrt(v->x*v->x + v->y*v->y + v->z*v->z);
	result->x = v->x / lenght;
	result->y = v->y / lenght;
	result->z = v->z / lenght;
}

void crossproduct_v(const struct vector *v1, const struct vector *v2, struct vector *result)
{
	result->x = v1->y*v2->z - v1->z*v2->y;
	result->y = v1->z*v2->x - v1->x*v2->z;
	result->z = v1->x*v2->y - v1->y*v2->x;
}
float dotproduct_v(const struct vector *v1, const struct vector *v2) 
{
	return v1->x*v2->x + v1->y*v2->y + v1->z*v2->z;
}

void lerp_v(const struct vector *v1, const struct vector *v2, float beta, struct vector *result)
{
	//Interpolation. Normalization not needed
	result->x = (1.0f - beta)*v1->x + beta*v2->x;
	result->y = (1.0f - beta)*v1->y + beta*v2->y;
	result->z = (1.0f - beta)*v1->z + beta*v2->z;
			
}
