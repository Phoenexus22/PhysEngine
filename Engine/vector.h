#include "typedef.h"
struct vec3 //memprint 24 bytes
{
	f64 x = 0.0f;
	f64 y = 0.0f;
	f64 z = 0.0f;
};

/*REGION vector addition and subtraction*/
vec3 operator+(const vec3 &u,const vec3 &v)
{
	vec3 tvec;
	tvec.x = u.x + v.x; 
	tvec.y = u.y + v.y;
	tvec.z = u.z + v.z;
	return tvec; 
}

void operator+=(vec3 &u,const vec3 &v)
{
	u = u + v;
}
vec3 operator-(const vec3 &u,const vec3 &v)
{
	vec3 tvec;
	tvec.x = u.x - v.x; 
	tvec.y = u.y - v.y;
	tvec.z = u.z - v.z;
	return tvec; 
}

void operator-=(vec3 &u,const vec3 &v)
{
	u = u - v;
}
/*ENDREGION*/

//cross and dot products are going to be absolute pain

/*REGION multiplying by scalars*/
vec3 operator*(const vec3 &u,const f64 &v)
{
	vec3 tvec;
	tvec.x = u.x  * v; 
	tvec.y = u.y * v;
	tvec.z = u.z * v;
	return tvec;  
}

vec3 operator*(const vec3 &u,const f32 &v){vec3 tvec;tvec.x=u.x*v;tvec.y=u.y*v;tvec.z=u.z*v;return tvec;}
vec3 operator*(const vec3 &u,const i8 &v){vec3 tvec;tvec.x=u.x*v;tvec.y=u.y*v;tvec.z=u.z*v;return tvec;}
vec3 operator*(const vec3 &u,const i16 &v){vec3 tvec;tvec.x=u.x*v;tvec.y=u.y*v;tvec.z=u.z*v;return tvec;}
vec3 operator*(const vec3 &u,const i32 &v){vec3 tvec;tvec.x=u.x*v;tvec.y=u.y*v;tvec.z=u.z*v;return tvec;}
vec3 operator*(const vec3 &u,const i64 &v){vec3 tvec;tvec.x=u.x*v;tvec.y=u.y*v;tvec.z=u.z*v;return tvec;}
vec3 operator*(const vec3 &u,const u1 &v){vec3 tvec;tvec.x=u.x*v;tvec.y=u.y*v;tvec.z=u.z*v;return tvec;}
vec3 operator*(const vec3 &u,const u8 &v){vec3 tvec;tvec.x=u.x*v;tvec.y=u.y*v;tvec.z=u.z*v;return tvec;}
vec3 operator*(const vec3 &u,const u16 &v){vec3 tvec;tvec.x=u.x*v;tvec.y=u.y*v;tvec.z=u.z*v;return tvec;}
vec3 operator*(const vec3 &u,const u32 &v){vec3 tvec;tvec.x=u.x*v;tvec.y=u.y*v;tvec.z=u.z*v;return tvec;}
vec3 operator*(const vec3 &u,const u64 &v){vec3 tvec;tvec.x=u.x*v;tvec.y=u.y*v;tvec.z=u.z*v;return tvec;}
/*ENDREGION*/

/*REGION Equals multiplying by scalars*/
void operator*=(vec3 &u,const f64 &v){u=u*v;}
void operator*=(vec3 &u,const f32 &v){u=u*v;}
void operator*=(vec3 &u,const i8 &v){u=u*v;}
void operator*=(vec3 &u,const i16 &v){u=u*v;}
void operator*=(vec3 &u,const i32 &v){u=u*v;}
void operator*=(vec3 &u,const i64 &v){u=u*v;}
void operator*=(vec3 &u,const u1 &v){u=u*v;}
void operator*=(vec3 &u,const u8 &v){u=u*v;}
void operator*=(vec3 &u,const u16 &v){u=u*v;}
void operator*=(vec3 &u,const u32 &v){u=u*v;}
void operator*=(vec3 &u,const u64 &v){u=u*v;}
/*ENDREGION*/

/*REGION false scalar addition*/
vec3 operator+(const vec3 &u,const f64 &v)
{
	vec3 tvec;
	tvec.x = u.x + v; 
	tvec.y = u.y + v;
	tvec.z = u.z + v;
	return tvec;  
}

vec3 operator+(const vec3 &u,const f32 &v){vec3 tvec;tvec.x=u.x+v;tvec.y=u.y+v;tvec.z=u.z+v;return tvec;}
vec3 operator+(const vec3 &u,const i8 &v){vec3 tvec;tvec.x=u.x+v;tvec.y=u.y+v;tvec.z=u.z+v;return tvec;}
vec3 operator+(const vec3 &u,const i16 &v){vec3 tvec;tvec.x=u.x+v;tvec.y=u.y+v;tvec.z=u.z+v;return tvec;}
vec3 operator+(const vec3 &u,const i32 &v){vec3 tvec;tvec.x=u.x+v;tvec.y=u.y+v;tvec.z=u.z+v;return tvec;}
vec3 operator+(const vec3 &u,const i64 &v){vec3 tvec;tvec.x=u.x+v;tvec.y=u.y+v;tvec.z=u.z+v;return tvec;}
vec3 operator+(const vec3 &u,const u1 &v){vec3 tvec;tvec.x=u.x+v;tvec.y=u.y+v;tvec.z=u.z+v;return tvec;}
vec3 operator+(const vec3 &u,const u8 &v){vec3 tvec;tvec.x=u.x+v;tvec.y=u.y+v;tvec.z=u.z+v;return tvec;}
vec3 operator+(const vec3 &u,const u16 &v){vec3 tvec;tvec.x=u.x+v;tvec.y=u.y+v;tvec.z=u.z+v;return tvec;}
vec3 operator+(const vec3 &u,const u32 &v){vec3 tvec;tvec.x=u.x+v;tvec.y=u.y+v;tvec.z=u.z+v;return tvec;}
vec3 operator+(const vec3 &u,const u64 &v){vec3 tvec;tvec.x=u.x+v;tvec.y=u.y+v;tvec.z=u.z+v;return tvec;}
/*ENDREGION*/
/*REGION equals false scalar addition*/
void operator+=(vec3 &u,const f64 &v){u=u+v;}
void operator+=(vec3 &u,const f32 &v){u=u+v;}
void operator+=(vec3 &u,const i8 &v){u=u+v;}
void operator+=(vec3 &u,const i16 &v){u=u+v;}
void operator+=(vec3 &u,const i32 &v){u=u+v;}
void operator+=(vec3 &u,const i64 &v){u=u+v;}
void operator+=(vec3 &u,const u1 &v){u=u+v;}
void operator+=(vec3 &u,const u8 &v){u=u+v;}
void operator+=(vec3 &u,const u16 &v){u=u+v;}
void operator+=(vec3 &u,const u32 &v){u=u+v;}
void operator+=(vec3 &u,const u64 &v){u=u+v;}
/*ENDREGION*/

/*REGION false multiplication*/

vec3 operator*(const vec3 &u,const vec3 &v)
{
	vec3 tvec;
	tvec.x = u.x * v.x; 
	tvec.y = u.y * v.y;
	tvec.z = u.z * v.z;
	return tvec; 
}
void operator*=(vec3 &u,const vec3 &v)
{
	u = u * v;
}
/*ENDREGION*/

/*REGION newvec*/
vec3 newVec3(f64 x, f64 y, f64 z)
{
	vec3 tvec;
	tvec.x = x;
	tvec.y = y;
	tvec.z = z;
	return tvec;
}
/*ENDREGION*/
