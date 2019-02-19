#ifdef __APPLE__
// For XCode only: New C++ terminal project. Build phases->Compile with libraries: add OpenGL and GLUT
// Import this whole code into a new C++ file (main.cpp, for example). Then run.
// Reference: https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/Mac
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif
#ifdef _WIN32
// For VS on Windows only: Download CG_Demo.zip. UNZIP FIRST. Double click on CG_Demo/CG_Demo.sln
// Run
#include "freeglut.h"
#endif
#ifdef __unix__
// For Linux users only: g++ CG_Demo.cpp -lglut -lGL -o CG_Demo
// ./CG_Demo
// Reference: https://www.linuxjournal.com/content/introduction-opengl-programming
#include "GL/freeglut.h"
#include "GL/gl.h"
#endif
#pragma once

#include <stdio.h>

#include "Block.h"
#include "Cylinder.h"
#include "Sphere.h"
#define NUMBLOCKS 15 
#define NUMCYLINDERS 5 
#define NUMSPHERES 6

class ATST
{
public:
	ATST();
	~ATST();

	void draw();
	void update();

	enum blockNames {
		L_FOOT,
		R_FOOT,
		L_CALF,
		R_CALF,
		L_THIGH,
		R_THIGH,
		BODY,
		NECK,
		HEAD,
		L_CALF_Detail,
		R_CALF_Detail,
		L_THIGH_Detail,
		R_THIGH_Detail,
		HEAD_DETAIL3,
		HEAD_DETAIL4
	};

	enum spheresNames
	{
		EAR,
		CENTRAL_CANNON,
		FEET_DETAIL,
		HEAD_DETAIL,
		HEAD_DETAIL2,
		BULLET
	};

	enum cylinderNames {
		L_KNEE,
		R_KNEE,
		CANNON1,
		CANNON2,
		CANNON3
	};

	Block* blocks[NUMBLOCKS];
	Cylinder* cylinders[NUMCYLINDERS];
	Sphere* spheres[NUMSPHERES];
	//float rotX[NUMBLOCKS];

};

