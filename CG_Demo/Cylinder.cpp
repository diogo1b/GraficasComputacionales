#include "Cylinder.h"

Cylinder::Cylinder() {
	r = g = b = 1.0f;
	bR = tR = 1.0f;
	h = 1.0f;
}

Cylinder::Cylinder(float _r, float _g, float _b,
float _bR, float _tR, float _h)
{
	r = _r; g = _g; b = _b;
	bR = _bR; tR = _tR;
	h = _h;
}


Cylinder::~Cylinder()
{
}

void Cylinder::draw() {
	glPushMatrix();
	{
		glColor3f(r,g,b);
		//glScalef(sX,sY,sZ);
		
		glBegin(GL_POLYGON);
		GLUquadricObj *obj = gluNewQuadric();
		gluCylinder(obj, bR, tR, h, 32, 32);

		glEnd();
	}
	glPopMatrix();
}

void Cylinder::update() {

}