#include <iostream>
#include "vector.h"
#include "typedef.h"
#include <math.h>
using namespace std;
struct object//memprint = 32 + 4 + 100 + 128 = 264 bytes
{
	u32 uniqueId;
	u8 name[32]={};
	//vec3[32768][64] shape;
	struct physics //memprint 4 + 24*4 = 100 bytes
	{
		f32 updInt;
		f32 mass;
		vec3 position;//memprint 24 bytes
		vec3 velocity;
		vec3 acceleration;
		struct drag
		{
			vec3 acceleration;
			vec3 coeff;
			vec3 medDensity;
			vec3 area;
		}drag;

	} physics;

	struct collisions //memprint 128 bytes
	{
		u32 collidingWith[32];
	} collisions;
};

//find instantaneous drag equation
vec3 calcDrag(object thisobject)
{
	thisobject.physics.drag.acceleration = (thisobject.physics.drag.coeff * thisobject.physics.drag.medDensity * 0.5)  * thisobject.physics.velocity * thisobject.physics.velocity * thisobject.physics.drag.area * pow(thisobject.physics.mass, -1);
	return thisobject.physics.drag.acceleration;
}

void physUpd(object &thisobject)
{
		thisobject.physics.velocity += (thisobject.physics.acceleration + calcDrag(thisobject)) * thisobject.physics.updInt;
		thisobject.physics.position += thisobject.physics.velocity * thisobject.physics.updInt;
}
/*shapes should be represented by a multidimentional array of vectors with each child array being a plane. 
 * refrences should be used for points that are identical, pointers can be used to confirm that these points are indeed the same*/
/*shapes should probably be gpu processed*/

u1 cubetest()//tests should migrate elsewhere
{
	object testobject;
	testobject.physics.updInt = 0.3;
	testobject.physics.drag.coeff.z = 2.1;
	testobject.physics.mass = 10;
	testobject.physics.drag.area.z = 1;
	testobject.physics.drag.medDensity.z = 1.225;
	testobject.physics.acceleration.z = -9.8f;
	testobject.physics.velocity *= 0.0f;
	testobject.physics.position *= 0.0f;
	for(i8 i = 0; i < 100; i++)
	{
		physUpd(testobject);	
		cout << testobject.physics.velocity.z << "\n";
	}
	return ((testobject.physics.velocity.z < -8.72871f)&&(testobject.physics.velocity.z > -8.72873f ));

}

/*struct medium //migrate
{
	u8[32] name = {};
	u32 uniqueId;
	f64 density;
	//variable describing shape and location
}*/
