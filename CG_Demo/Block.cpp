#include "Block.h"

Block::Block() {
	r = g = b = 1;
	sX = sY = sZ = 1;
}

Block::Block(float _r, float _g, float _b,
float _sX, float _sY, float _sZ)
{
	r = _r; g = _g; b = _b;
	sX = _sX; sY = _sY; sZ = _sZ;
}


Block::~Block()
{
}

void Block::draw() {
	glPushMatrix();
	{
		glColor3f(r,g,b);
		glScalef(sX,sY,sZ);
		glutSolidCube(1);
	}
	glPopMatrix();
}

void Block::update() {

}