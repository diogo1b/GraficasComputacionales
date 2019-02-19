#include "ATST.h"

float bulletFrames;

/*
 * Se declaran las variables globales de angulo 
 */

float L_Upper_LegRA;
float R_Upper_LegRA;
float L_Under_LegRA;
float R_Under_LegRA;
float Head_Rot;
float Body_Rot;

/*
 * Se declaran las variables globales de velocidad
 */

float Upper_Speed;
float Under_Speed;
float Head_Speed;
float Body_Speed;

/*
 * Se declaran las variables globales de movimiento
 */

bool R_Upper_LegMove;
bool L_Upper_LegMove;
bool R_Under_LegMove;
bool L_Under_LegMove;
bool Head_Move;
bool Body_Move;

/*
 * Se declaran la variable global de
 * un contador de frames
 */
int frame_counter;


ATST::ATST()
{
	/*
	* Se inicializan las variables globales
	*/
	L_Upper_LegRA = -10.0f;
	R_Upper_LegRA = -10.0f;
	L_Under_LegRA = 0.0f;
	R_Under_LegRA = 0.0f;

	R_Upper_LegMove = true;
	L_Upper_LegMove = true;
	R_Under_LegMove = true;
	L_Under_LegMove = true;

	Head_Move = true;
	Head_Rot = 0.0f;

	Body_Rot = 0.0f;
	Body_Move = true;

	Upper_Speed = 0.045f;
	Under_Speed = 0.09f;
	Head_Speed = 0.035f;
	Body_Speed = 0.005f;

	frame_counter = 0;
	bulletFrames = 0;

	/*
	* Se inicializan las figuras creadas en otras clases
	*/

	for (int i = 0; i < NUMBLOCKS; i++)
	{
		blocks[i] = new Block();
		blocks[i]->r = 0.5f;
		blocks[i]->g = 0.5f;
		blocks[i]->b = 0.5f;
	}

	for (int i = 0; i < NUMCYLINDERS; i++)
	{
		cylinders[i] = new Cylinder();
		cylinders[i]->r = 0.5f;
		cylinders[i]->g = 0.5f;
		cylinders[i]->b = 0.5f;
	}

	for (int i = 0; i < NUMSPHERES; i++)
	{
		spheres[i] = new Sphere();
		spheres[i]->r = 0.0f;
		spheres[i]->g = 0.0f;
		spheres[i]->b = 0.0f;
	}

	/*
	* Se modifican las propiedades de
	* las figuras instanciadas
	*/

	blocks[L_FOOT]->sX = 1.0f;
	blocks[L_FOOT]->sY = 0.2f;
	blocks[L_FOOT]->sZ = 1.5f;

	blocks[R_FOOT]->sX = 1.0f;
	blocks[R_FOOT]->sY = 0.2f;
	blocks[R_FOOT]->sZ = 1.5f;

	blocks[L_CALF]->sX = 0.6f;
	blocks[L_CALF]->sY = 4.0f;
	blocks[L_CALF]->sZ = 0.6f;
	blocks[L_CALF]->r = 0.4705f;
	blocks[L_CALF]->g = 0.4705f;
	blocks[L_CALF]->b = 0.4705f;

	blocks[R_CALF]->sX = 0.6f;
	blocks[R_CALF]->sY = 4.0f;
	blocks[R_CALF]->sZ = 0.6f;
	blocks[R_CALF]->r = 0.4705f;
	blocks[R_CALF]->g = 0.4705f;
	blocks[R_CALF]->b = 0.4705f;

	cylinders[L_KNEE]->bR = 0.4f;
	cylinders[L_KNEE]->tR = 0.4f;
	cylinders[L_KNEE]->h = 1.0f;
	cylinders[L_KNEE]->r = 0.333f;
	cylinders[L_KNEE]->g = 0.333f;
	cylinders[L_KNEE]->b = 0.333f;


	cylinders[R_KNEE]->bR = 0.4f;
	cylinders[R_KNEE]->tR = 0.4f;
	cylinders[R_KNEE]->h = 1.0f;
	cylinders[R_KNEE]->r = 0.333f;
	cylinders[R_KNEE]->g = 0.333f;
	cylinders[R_KNEE]->b = 0.333f;

	blocks[L_THIGH]->sX = 0.6f;
	blocks[L_THIGH]->sY = 0.6f;
	blocks[L_THIGH]->sZ = 2.0f;
	blocks[L_THIGH]->r = 0.4705f;
	blocks[L_THIGH]->g = 0.4705f;
	blocks[L_THIGH]->b = 0.4705f;

	blocks[R_THIGH]->sX = 0.6f;
	blocks[R_THIGH]->sY = 0.6f;
	blocks[R_THIGH]->sZ = 2.0f;
	blocks[R_THIGH]->r = 0.4705f;
	blocks[R_THIGH]->g = 0.4705f;
	blocks[R_THIGH]->b = 0.4705f;

	blocks[BODY]->sX = 2.3f;
	blocks[BODY]->sY = 0.6f;
	blocks[BODY]->sZ = 2.6f;
	blocks[BODY]->r = 0.5145f;
	blocks[BODY]->g = 0.5145f;
	blocks[BODY]->b = 0.5145f;

	blocks[NECK]->sX = 0.5f;
	blocks[NECK]->sY = 0.5f;
	blocks[NECK]->sZ = 0.5f;
	blocks[NECK]->r = 0.333f;
	blocks[NECK]->g = 0.333f;
	blocks[NECK]->b = 0.333f;

	blocks[HEAD]->sX = 1.5f;
	blocks[HEAD]->sY = 2;
	blocks[HEAD]->sZ = 3.5;
	blocks[HEAD]->r = 0.4705f;
	blocks[HEAD]->g = 0.4705f;
	blocks[HEAD]->b = 0.4705f;


	cylinders[CANNON1]->bR = 0.1f;
	cylinders[CANNON1]->tR = 0.1f;
	cylinders[CANNON1]->h = 3.0;
	cylinders[CANNON1]->r = 0.333f;
	cylinders[CANNON1]->g = 0.333f;
	cylinders[CANNON1]->b = 0.333f;

	cylinders[CANNON2]->bR = 0.1f;
	cylinders[CANNON2]->tR = 0.1f;
	cylinders[CANNON2]->h = 2.5;
	cylinders[CANNON2]->r = 0.333f;
	cylinders[CANNON2]->g = 0.333f;
	cylinders[CANNON2]->b = 0.333f;

	cylinders[CANNON3]->bR = 0.1f;
	cylinders[CANNON3]->tR = 0.1f;
	cylinders[CANNON3]->h = 2.5;
	cylinders[CANNON3]->r = 0.333f;
	cylinders[CANNON3]->g = 0.333f;
	cylinders[CANNON3]->b = 0.333f;

	blocks[L_CALF_Detail]->sX = 0.1f;
	blocks[L_CALF_Detail]->sY = 3.0f;
	blocks[L_CALF_Detail]->sZ = 0.1f;
	blocks[L_CALF_Detail]->r = 0.0f;
	blocks[L_CALF_Detail]->g = 0.0f;
	blocks[L_CALF_Detail]->b = 0.0f;

	blocks[R_CALF_Detail]->sX = 0.1f;
	blocks[R_CALF_Detail]->sY = 3.0f;
	blocks[R_CALF_Detail]->sZ = 0.1f;
	blocks[R_CALF_Detail]->r = 0.0f;
	blocks[R_CALF_Detail]->g = 0.0f;
	blocks[R_CALF_Detail]->b = 0.0f;

	blocks[L_THIGH_Detail]->sX = 0.1f;
	blocks[L_THIGH_Detail]->sY = 0.1f;
	blocks[L_THIGH_Detail]->sZ = 1.5f;
	blocks[L_THIGH_Detail]->r = 0.0f;
	blocks[L_THIGH_Detail]->g = 0.0f;
	blocks[L_THIGH_Detail]->b = 0.0f;

	blocks[R_THIGH_Detail]->sX = 0.1f;
	blocks[R_THIGH_Detail]->sY = 0.1f;
	blocks[R_THIGH_Detail]->sZ = 1.5f;
	blocks[R_THIGH_Detail]->r = 0.0f;
	blocks[R_THIGH_Detail]->g = 0.0f;
	blocks[R_THIGH_Detail]->b = 0.0f;

	spheres[CENTRAL_CANNON]->sX = 0.5f;
	spheres[CENTRAL_CANNON]->sY = 0.5f;
	spheres[CENTRAL_CANNON]->sZ = 0.5f;

	spheres[EAR]->sX = 0.5f;
	spheres[EAR]->sY = 0.5f;
	spheres[EAR]->sZ = 0.5f;

	spheres[FEET_DETAIL]->sX = 0.5f;
	spheres[FEET_DETAIL]->sY = 0.15f;
	spheres[FEET_DETAIL]->sZ = 0.4f;

	spheres[HEAD_DETAIL]->sX = 0.7f;
	spheres[HEAD_DETAIL]->sY = 0.1f;
	spheres[HEAD_DETAIL]->sZ = 1.7f;
	spheres[HEAD_DETAIL]->r = 0.333f;
	spheres[HEAD_DETAIL]->g = 0.333f;
	spheres[HEAD_DETAIL]->b = 0.333f;

	spheres[HEAD_DETAIL2]->sX = 0.53f;
	spheres[HEAD_DETAIL2]->sY = 0.1f;
	spheres[HEAD_DETAIL2]->sZ = 1.2f;
	spheres[HEAD_DETAIL2]->r = 0.4705f;
	spheres[HEAD_DETAIL2]->g = 0.4705f;
	spheres[HEAD_DETAIL2]->b = 0.4705f;

	blocks[HEAD_DETAIL3]->sX = 0.01f;
	blocks[HEAD_DETAIL3]->sY = 0.2f;
	blocks[HEAD_DETAIL3]->sZ = 3.5f;
	blocks[HEAD_DETAIL3]->r = 0.0f;
	blocks[HEAD_DETAIL3]->g = 0.0f;
	blocks[HEAD_DETAIL3]->b = 0.0f;

	blocks[HEAD_DETAIL4]->sX =1.6f;
	blocks[HEAD_DETAIL4]->sY = 0.2f;
	blocks[HEAD_DETAIL4]->sZ = 0.01f;
	blocks[HEAD_DETAIL4]->r = 0.0f;
	blocks[HEAD_DETAIL4]->g = 0.0f;
	blocks[HEAD_DETAIL4]->b = 0.0f;

	spheres[BULLET]->sX = 0.1f;
	spheres[BULLET]->sY = 0.1f;
	spheres[BULLET]->sZ = 0.9f;
	spheres[BULLET]->r = 1.0f;
	spheres[BULLET]->g = 0.0f;
	spheres[BULLET]->b = 0.0f;
}

/*
 * Este método dibujará el ATST
 * de cabeza a pies
 */

void ATST::draw() {

	// Dibuja la pierna izquierda completa
	glPushMatrix();
	{
		glTranslatef(-1.5,4,2);
		glRotatef(L_Upper_LegRA, 1, 0, 0);
		glTranslatef(1.5, -4, -2);
	
		glTranslatef(-1.5, 4, 1.3);
		blocks[L_THIGH]->draw();
		glTranslatef(-0.5, 0, 0.2);
		blocks[L_THIGH_Detail]->draw();
		glTranslatef(0.5, 0, -0.2);

		glTranslatef(-0.4, 0, -1.3);
		glRotatef(90, 0, 1, 0);
		cylinders[L_KNEE]->draw();
		glRotatef(-90, 0, 1, 0);
		glTranslatef(0.4, 0, 0);

		glRotatef(L_Under_LegRA, -1, 0, 0);
		
		glTranslatef(0, -2, 0);
		blocks[L_CALF]->draw();
		glTranslatef(-0.5, 0, 0.2);
		blocks[L_CALF_Detail]->draw();
		glTranslatef(0.5, 0, -0.2);
		glTranslatef(0, -2, 1);
		blocks[L_FOOT]->draw();
		spheres[FEET_DETAIL]->draw();
	}
	glPopMatrix();

	// Dibuja la pierna derecha completa
	glPushMatrix();
	{
		glTranslatef(1.5, 4, 2);
		glRotatef(R_Upper_LegRA, 1, 0, 0);
		glTranslatef(-1.5, -4, -2);

		glTranslatef(1.5, 4, 1.3);
		blocks[R_THIGH]->draw();
		glTranslatef(0.5, 0, 0.2);
		blocks[R_THIGH_Detail]->draw();
		glTranslatef(-0.5, 0, -0.2);
		
		glTranslatef(-0.1, 0, -1.3);
		glRotatef(90, 0, 1, 0);
		cylinders[R_KNEE]->draw();
		glRotatef(-90, 0, 1, 0);
		glTranslatef(0.1,0,0);
		glRotatef(R_Under_LegRA, -1, 0, 0);

		glTranslatef(0, -2, 0);
		blocks[R_CALF]->draw();
		glTranslatef(0.5, 0, 0.2);
		blocks[R_CALF_Detail]->draw();
		glTranslatef(-0.5, 0, -0.2);
		glTranslatef(0, -2, 1);
		blocks[R_FOOT]->draw();
		spheres[FEET_DETAIL]->draw();
	}
	glPopMatrix();

	// Dibuja el cuerpo central

	glPushMatrix(); 
	{
		glTranslatef(0, 4, 1.6);
		glRotatef(Body_Rot, 0, 0, 1);
		blocks[BODY]->draw();
	}
	glPopMatrix();

	// Dibuja la cabeza

	glPushMatrix();
	{
		glTranslatef(0, 4.6, 2.4);
		blocks[NECK]->draw();

		glRotatef(Head_Rot, 0, 1, 0);

		glTranslatef(0, 1.3, -0.3f);
		blocks[HEAD]->draw();
		glPushMatrix();
		{
			glTranslatef(0, 1, 0);
			spheres[HEAD_DETAIL]->draw();
			glTranslatef(0, 0.1, 0);
			spheres[HEAD_DETAIL2]->draw();
		}
		glPopMatrix();
		glTranslatef(-0.2, -0.6, 1.8f);
		cylinders[CANNON1]->draw();
		spheres[CENTRAL_CANNON]->draw();

		glPushMatrix();
		{
			//glRotatef(-Head_Rot, 0, 1, 0);
			glTranslatef(0,0, 1.5 + bulletFrames);
			spheres[BULLET]->draw();
		}
		glPopMatrix();

		glPushMatrix();
		{
			glTranslatef(0.2, 1.3, 0);
			blocks[HEAD_DETAIL4]->draw();
			glTranslatef(0, -0.3, 0);
			blocks[HEAD_DETAIL4]->draw();
		}
		glPopMatrix();
		glTranslatef(0.2, 0, 0);
		glTranslatef(0, 0.6, -1.8f);
		glTranslatef(-1.0,0,0);
		cylinders[CANNON2]->draw();
		glPushMatrix();
		{
			glTranslatef(0.2, 0.7, 0);
			blocks[HEAD_DETAIL3]->draw();
			glTranslatef(0, -0.3, 0);
			blocks[HEAD_DETAIL3]->draw();
		}
		glPopMatrix();
		glTranslatef(0.3, 0, 0);
		spheres[EAR]->draw();
		glTranslatef(-0.3, 0, 0);
		glTranslatef(2.0, 0, 0);
		cylinders[CANNON3]->draw();
		glPushMatrix();
		{
			glTranslatef(-0.2, 0.7, 0);
			blocks[HEAD_DETAIL3]->draw();
			glTranslatef(0, -0.3, 0);
			blocks[HEAD_DETAIL3]->draw();
		}
		glPopMatrix();
		
		
		glTranslatef(-0.3, 0, 0);
		spheres[EAR]->draw();

	}
	glPopMatrix();
	
}

void ATST::update() {
	
	// Se realiza un update de los frames
	frame_counter += 1;
	bulletFrames += 0.2f;

	if (bulletFrames > 120.0f) {
			bulletFrames = 0;
	}
	
	/*
	 * Se realiza la suma o resta de los angulos
	 * de acuerdo al booleano de movimiento de
	 * cada parte del cuerpo
	 */
	
	if (Body_Move) {
		Body_Rot += Body_Speed;
		if (Body_Rot >= 1.5) {
			Body_Move = false;
		}
	}
	else if (!Body_Move) {
		Body_Rot -= Body_Speed;
		if (Body_Rot <= -1.5) {
			Body_Move = true;
		}
	}

	if (Head_Move) {
		Head_Rot += Head_Speed;
		if (Head_Rot >= 25) {
			Head_Move = false;
		}
	}
	else if (!Head_Move) {
		Head_Rot -= Head_Speed;
		if (Head_Rot <= -25) {
			Head_Move = true;
		}
	}

	if (R_Upper_LegMove) {
		R_Upper_LegRA += Upper_Speed;
		if (R_Upper_LegRA >= 10) {
			R_Upper_LegMove = false;
		}
	}
	else if (!R_Upper_LegMove) {
		R_Upper_LegRA -= Upper_Speed;
		if (R_Upper_LegRA <= -20) {
			R_Upper_LegMove = true;
		}
	}

	if (R_Under_LegMove) {
		R_Under_LegRA += Under_Speed;
		if (R_Under_LegRA >= 30) {
			R_Under_LegMove = false;
		}
	}
	else if (!R_Under_LegMove) {
		R_Under_LegRA -= Under_Speed;
		if (R_Under_LegRA <= -32) {
			R_Under_LegMove = true;
		}
	}

	/*
	 * Si el contador de frames llega a 451
	 * la pierna izquierda empieza a moverse
	 */

	if (frame_counter > 550) {
		if (L_Upper_LegMove) {
			L_Upper_LegRA += Upper_Speed;
			if (L_Upper_LegRA >= 10) {
				L_Upper_LegMove = false;
			}
		}
		else if (!L_Upper_LegMove) {
			L_Upper_LegRA -= Upper_Speed;
			if (L_Upper_LegRA <= -20) {
				L_Upper_LegMove = true;
			}
		}

		if (L_Under_LegMove) {
			L_Under_LegRA += Under_Speed;
			if (L_Under_LegRA >= 30) { // Este es hacía delante
				L_Under_LegMove = false;
			}
		}
		else if (!L_Under_LegMove) {
			L_Under_LegRA -= Under_Speed;
			if (L_Under_LegRA <= -32) {
				L_Under_LegMove = true;
			}
		}
	}
}

ATST::~ATST()
{
}
