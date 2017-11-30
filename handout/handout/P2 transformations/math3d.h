//
//  VECTOR3D.h
//  StereoRendering
//
//  Created by Jose Maria Benito on 09/12/13.
//  Copyright (c) 2013 Jose Maria. All rights reserved.
//

#ifndef StereoRendering_VECTOR3D_h
#define StereoRendering_VECTOR3D_h

#define ABS(x) (x < 0 ? -(x) : (x))
#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)
#define TRUE  1
#define FALSE 0
#define ESC 27
#define PI 3.141592653589793238462643
#define DTOR            0.0174532925    // degrees to radians
#define RTOD            57.2957795      // radians to degrees


typedef struct {
    double x,y,z;
} VECTOR3D;


typedef struct {
    double r,g,b;
} COLOUR;

typedef struct {
    VECTOR3D column0;
    VECTOR3D column1;
    VECTOR3D column2;
} MATRIX3;


typedef struct {
    float m[16];
} MATRIX4;

typedef struct {
	float  w;
	VECTOR3D v;
}QUATERNION;

static const COLOUR grey = {0.7,0.7,0.7};
static const COLOUR red = {1,0,0};
static const COLOUR green = {0,1,0};
static const COLOUR blue = {0,0,1};

static const COLOUR darkred = {0.6,0,0};
static const COLOUR darkgreen = {0,0.6,0};

// TODO

VECTOR3D Add(VECTOR3D a, VECTOR3D b)
{
    VECTOR3D ret;
    ret.x = a.x+b.x;
    ret.y = a.y+b.y;
    ret.z = a.z+b.z;
    return ret;
}
//
VECTOR3D Substract(VECTOR3D a, VECTOR3D b) {
	VECTOR3D ret;
	ret.x = a.x - b.x;
	ret.y = a.y - b.y;
	ret.z = a.z - b.z;
	return ret;
}

VECTOR3D Multiply(VECTOR3D a, VECTOR3D b) {
	VECTOR3D ret;
	ret.x = a.x * b.x;
	ret.y = a.y * b.y;
	ret.z = a.z * b.z;
	return ret;

}

VECTOR3D MultiplyWithScalar(float scalar, VECTOR3D a) {
	VECTOR3D ret;
	ret.x = a.x * scalar;
	ret.y = a.y * scalar;
	ret.z = a.z * scalar;
	return ret;
}

double Magnitude(VECTOR3D a) {
	return sqrt(powf(a.x, 2) + powf(a.y, 2)+ powf(a.z, 2));
	
}

VECTOR3D Normalize(VECTOR3D a) {
	VECTOR3D ret;
	double mag = Magnitude(a);
	ret.x = a.x / mag;
	ret.y = a.y / mag;
	ret.z = a.z / mag;
	return ret;
}

VECTOR3D CrossProduct(VECTOR3D a, VECTOR3D b) {
	VECTOR3D ret;
	
	ret.x = (a.y * b.z) - (a.z * b.y);
	ret.y = (a.z * b.x) - (a.x * b.z);
	ret.z = (a.x * b.y) - (a.y * b.x);
	return ret;
}

double DotProduct(VECTOR3D a, VECTOR3D b) {
	return ((a.x * b.x) + (a.y * b.y) + (a.z * a.z));
}

MATRIX3 Transpose(MATRIX3 m) {
	MATRIX3 mat;

	mat.column0.x = m.column0.x;
	mat.column0.y = m.column1.x;
	mat.column0.z = m.column2.x;

	mat.column1.x = m.column0.y;
	mat.column1.y = m.column1.y;
	mat.column1.z = m.column2.y;

	mat.column2.x = m.column0.z;
	mat.column2.y = m.column1.z;
	mat.column2.z = m.column2.z;

	return mat;

}

VECTOR3D Transform(MATRIX3 m, VECTOR3D a) {
	
	VECTOR3D res;

	res.x = m.column0.x*a.x + m.column1.x*a.y + m.column2.x*a.z;
	res.y = m.column0.y*a.x + m.column1.y*a.y + m.column2.y*a.z;
	res.z = m.column0.z*a.x + m.column1.z*a.y + m.column2.z*a.z;

	return res;

}


//local res = [0, 0, 0];
//res.x = mat.row1.x*x + mat.row2.x*y + mat.row3.x*z + mat.row4.x*w;
//res.y = mat.row1.y*x + mat.row2.y*y + mat.row3.y*z + mat.row4.y*w;
//res.z = mat.row1.z*x + mat.row2.z*y + mat.row3.z*z + mat.row4.z*w;
//return res;

MATRIX4 InverseOrthogonalMatrix(MATRIX3 A, VECTOR3D t) {
	
	MATRIX3 aT = Transpose(A);
	VECTOR3D transf = Transform(aT, t);
	MATRIX4 mat = {1,2,4};

	mat.m[0] = aT.column0.x;
	mat.m[1] = aT.column0.y;
	mat.m[2] = aT.column0.z;
	mat.m[3] = 0;

	mat.m[4] = aT.column1.x;
	mat.m[5] = aT.column1.y;
	mat.m[6] = aT.column1.z;
	mat.m[7] = 0;

	mat.m[8]  =	aT.column2.x;
	mat.m[9]  =	aT.column2.y;
	mat.m[10] = aT.column2.z;
	mat.m[11] = 0;

	mat.m[12] = transf.x;
	mat.m[13] = transf.y;
	mat.m[14] = transf.z;
	mat.m[15] = 1;

	return mat;
}

//QUATERNIONS
QUATERNION ScaleQuat(QUATERNION q, float s) {
	QUATERNION qS;
	qS.w = q.w*s;
	qS.v.x = q.v.x*s;
	qS.v.y = q.v.y*s;
	qS.v.z = q.v.z*s;
	
	return qS;

}

QUATERNION NormalizeQuat(QUATERNION q) {
	QUATERNION norm;

	norm.w	 = q.w*q.w;
	norm.v.x = q.v.x*q.v.x;
	norm.v.y = q.v.y*q.v.y;
	norm.v.z = q.v.z*q.v.z;

	return norm;
}

QUATERNION QuaternionFromAngleAxis(float angle, VECTOR3D axis) {
	axis = Normalize(axis);
	QUATERNION q;

	q.v.x = sin(angle / 2) * axis.x;

	q.v.y = sin(angle / 2) * axis.y;

	q.v.z = sin(angle / 2) * axis.z;

	q.w = cos(angle / 2);

	return q;
}

QUATERNION QuaternionFromToVectors(VECTOR3D from, VECTOR3D to) {

	float cos_angle = DotProduct(Normalize(from), Normalize(to));
	VECTOR3D v;

	if (cos_angle < -1 + 0.001f) {
		VECTOR3D aux;
		aux.x = 0.0f;
		aux.y = 0.0f;
		aux.z = 1.0f;
		v = CrossProduct(aux, from);
		if (Magnitude(v) < 0.01) {
			aux.x = 1.0f;
			aux.y = 0.0f;
			aux.z = 0.0f;

			v = CrossProduct(aux, from);
		}		

		v = Normalize(v);
		return  QuaternionFromAngleAxis(3.141516, v);
	}
	v = Normalize(CrossProduct(from, to));
	float angle = acos(cos_angle);
	
	return QuaternionFromAngleAxis(angle, v);
}

QUATERNION Multiply(QUATERNION a, QUATERNION b) {
	QUATERNION quat;
	/*quat.w = a.w*b.w - a.v.x*b.v.x - a.v.y*b.v.y - a.v.z*b.v.z;
	quat.v.x = a.w*b.v.x + a.v.x*b.w + a.v.y*b.v.z - a.v.z*b.v.y;
	quat.v.y = a.w*b.v.y + a.v.y*b.w + a.v.z*b.v.x - a.v.x*b.v.z;
	quat.v.z = a.w*b.v.z + a.v.z*b.w + a.v.x*b.v.y - a.v.y*b.v.x;
	return quat;*/
	
	float s = (a.w * b.w) - (DotProduct(a.v, b.v));
	VECTOR3D vec = Add(Add(CrossProduct(a.v, b.v), MultiplyWithScalar(a.w, b.v)), MultiplyWithScalar(b.w, a.v));
	quat.w = s;
	quat.v = vec;

	return quat;
}

QUATERNION Conjugate(QUATERNION a) {
	QUATERNION q;
	q.w = a.w;
	q.v.x = -a.v.x;
	q.v.y = -a.v.y;
	q.v.z = -a.v.z;
	return q;
}

VECTOR3D RotateWithQuaternion(VECTOR3D v, QUATERNION q) {

	QUATERNION p;
	QUATERNION pq;
	QUATERNION pqInv;
	VECTOR3D rot;

	p.w = 0;
	p.v.x = v.x;
	p.v.y = v.y;
	p.v.z = v.z;

	pq = Multiply(p, q);
	pqInv = Multiply(pq, Conjugate(q));
		
	rot.x = pqInv.v.x;
	rot.y = pqInv.v.y;
	rot.z = pqInv.v.z;
	
	return rot;
}


#endif
