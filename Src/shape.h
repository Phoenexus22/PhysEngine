#include <iostream>
#include "vector.h"
using namespace std;
struct shape 
{
	vec3 **vtc;
	vec3 offset;
};

shape operator+(const shape &u, const vec3 &v)
{
	shape tshap = u;
	for (u16 i =0; i < sizeof(tshap.vtc)/sizeof(tshap.vtc[0]); i++)
	{
		for (u8 n = 0; n < sizeof(tshap.vtc[0])/sizeof(tshap.vtc[0][0]); n++)
		{
			tshap.vtc[i][n] += v;
		}
	}
	return tshap;
}
void operator+=(shape &u, const vec3 &v)
{
	u=u+v;
}
shape operator-(const shape &u, const vec3 &v)
{
	shape tshap = u;
	for (u16 i =0; i < sizeof(tshap.vtc)/sizeof(tshap.vtc[0]); i++)
	{
		for (u8 n = 0; n < sizeof(tshap.vtc[0])/sizeof(tshap.vtc[0][0]); n++)
		{
			tshap.vtc[i][n] -= v;
		}
	}
	return tshap;
}
void operator-=(shape &u, const vec3 &v)
{
	u=u-v;
}

void outShape(shape tshap)//function may only be needed while headless //currently non-functional, sizes out of whack
{
	cout << "\n{" << sizeof(tshap.vtc) << "\n"<<sizeof (tshap.vtc[0]) <<"\n" <<sizeof(tshap.vtc[0][0]);
	for (u16 i =0; i < sizeof(tshap.vtc)/sizeof(tshap.vtc[0]); i++)
	{
		cout << "{" << sizeof(tshap.vtc[0])/sizeof(tshap.vtc[0][0]);
		for (u8 n = 0; n < sizeof(tshap.vtc[0])/sizeof(tshap.vtc[0][0]); n++)
		{
			cout << "{" << tshap.vtc[i][n].x << ", " << tshap.vtc[i][n].y << ", " << tshap.vtc[i][n].z << "}";
		}
		cout << "}";
	}

	cout << "}" << "(" << tshap.offset.x << ", " << tshap.offset.y << ", " << tshap.offset.z << ")\n";
}




vec3 **createUnitCube()//should optimise later after I figure out how to do this //ordered top, bottom, front, back, left, right
{
	//bottom, left, front = 0
	//top, right, back = 1
	vec3 topleftfront = newVec3(1, 0, 0);
	vec3 toprightfront = newVec3(1, 1, 0);
	vec3 topleftback = newVec3(1, 0, 1);
	vec3 toprightback = newVec3(1, 1, 1);
	vec3 bottomleftfront = newVec3(0, 0, 0);
	vec3 bottomrightfront = newVec3(0, 1, 0);
	vec3 bottomleftback = newVec3(0, 0, 1);
	vec3 bottomrightback = newVec3(0, 1, 1);
	vec3** tvec = 0;
	tvec = new vec3*[2048];
	tvec[0] = new vec3[64];
	tvec[1] = new vec3[64];
	tvec[2] = new vec3[64];
	tvec[3] = new vec3[64];
	tvec[4] = new vec3[64];
	tvec[5] = new vec3[64];
	vec3* top[64] = {&topleftfront, &toprightfront, &topleftback, &toprightback};
	vec3* bottom[64] = {&bottomleftfront, &bottomrightfront, &bottomleftback, &bottomrightback};
	vec3* front[64] = {&topleftfront, &toprightfront, &bottomleftfront, &bottomrightfront};
	vec3* back[64] = {&topleftback, &toprightback, &bottomleftback, &bottomrightback};
	vec3* left[64] = {&topleftfront, &bottomleftfront, &topleftback, &bottomleftback};
	vec3* right[64] = {&toprightfront, &bottomrightfront, &toprightback, &bottomrightback};
	tvec[0] = *top;
	tvec[1] = *bottom;
	tvec[2] = *front;
	tvec[3] = *back;
	tvec[4] = *left;
	tvec[5] = *right;
	/*vec3 tempvec[2048][64] = 
	{
		{&topleftfront, &toprightfront, &topleftback, &toprightback},
		{&bottomleftfront, &bottomrightfront, &bottomleftback, &bottomrightback},
		{&topleftfront, &toprightfront, &bottomleftfront, &bottomrightfront},
		{&topleftback, &toprightback, &bottomleftback &bottomrightback},
		{&topleftfront, &bottomleftfront, &topleftback, &bottomleftback},
		{&toprightfront, &bottomrightfront, &toprightback, &bottomrightback}
	};*/
	return tvec;
}
