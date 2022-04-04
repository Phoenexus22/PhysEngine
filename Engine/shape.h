#include "vector.h"
struct shape 
{
	vec3[][] vtc;
	vec3 origin;
}
shape unitCube;
unitCube.vtc = {{vec3 {}}};
//f64 uncub = 
//{{{0,0,0}{0, 0, 1}{0, 1, 0}{0, 1, 1}}
//{{&uncub[0][0]}{&uncub[0][2]}{1, 0, 0}{1, 1, 0}}
//{{&uncub[1][2]}{&uncub[1][3]}{1, 0, 1}{1, 1, 1}}
//{{}{}{}{}}
//{{}{}{}{}}
//{{}{}{}{}}};
