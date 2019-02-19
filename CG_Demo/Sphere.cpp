#include "Sphere.h"

Sphere::Sphere() {
	r = g = b = 1;
	sX = sY = sZ = 1;
}

Sphere::Sphere(float _r, float _g, float _b,
float _sX, float _sY, float _sZ)
{
	r = _r; g = _g; b = _b;
	sX = _sX; sY = _sY; sZ = _sZ;
}


Sphere::~Sphere()
{
}

void Sphere::draw() {
	glPushMatrix();
	{
		glColor3f(r,g,b);
		glScalef(sX,sY,sZ);
		glutSolidSphere(1,30,36);
	}
	glPopMatrix();
}

void Sphere::update() {

}